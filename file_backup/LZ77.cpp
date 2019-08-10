#include "LZ77.h"
#include <iostream>
#include <assert.h>




const USH MIN_LOOKAHEAD = MAX_MATCH + 1;
const USH MAX_DIST = WSIZE - MIN_LOOKAHEAD;

LZ77::LZ77()
	:_pWin(new UCH[WSIZE*2])
	,_ht(WSIZE)
	, _start(0)
	, _lookAhead(0)
{}

LZ77::~LZ77(){
	if (_pWin){
		delete[] _pWin;
	}
}

void LZ77::CompressFile(const std::string& filePath){
	FILE* fIn = fopen(filePath.c_str(), "rb");
	if (nullptr == fIn){
		std::cout << "���ļ�ʧ��" << std::endl;
		return;
	}

	//��ȡ�ļ��Ĵ�С,���ļ�ָ���ƶ���ĩβ���ù�ftell��ȡ�ļ���С
	fseek(fIn, 0, SEEK_END);
	ULL fileSize = ftell(fIn);
	fseek(fIn, 0, SEEK_SET);

	//�ļ���СС�������ֽڣ�����Ҫ����ѹ��
	if (fileSize < 3){
		fclose(fIn);
		return;
	}
	//�ȶ�ȡһ���������ڵ�����
	_lookAhead = fread(_pWin, 1, 2 * WSIZE, fIn);

	USH hashAddr = 0;
	for (size_t i = 0; i < MIN_MATCH; ++i){
		_ht.HashFunc(hashAddr, _pWin[i]);
	}

	//��ѹ������ļ�
	std::string file_name = filePath.substr(0, filePath.find('.'));
	file_name += ".lzp";
	FILE* fOutD = fopen(file_name.c_str(),"wb");

	assert(fOutD);
	std::string postFix = filePath.substr(filePath.rfind('.'));
	postFix += '\n';

	//дԴ�ļ��ĺ�׺
	fwrite(postFix.c_str(), 1, postFix.size(), fOutD);

	//д��ǵ��ļ�
	FILE* fOutF = fopen("2_flag_filename.lzp", "wb");
	assert(fOutF);
	//����ѹ����start��ʾ�������ڵ���ʼλ��
	USH matchHead = 0;
	UCH chFlag = 0;
	UCH bitCount = 0;

	//��������û���ݣ�ѭ��ֹͣ
	while (_lookAhead){
		//����startΪ�׵������ַ����뵽��ϣ����
		_ht.Insert(hashAddr, _pWin[_start + 2], _start, matchHead);
		
		USH curMatchDist = 0;
		UCH curMatchLen = 0;
		if (matchHead && _lookAhead > MIN_LOOKAHEAD){
			curMatchLen = LongMatch(matchHead, curMatchDist);
		}
		
		if (curMatchLen < MIN_MATCH){
			//û��ƥ��
			fputc(_pWin[_start], fOutD);

			++_start;
			--_lookAhead;
			WriteFlag(fOutF, chFlag, bitCount, false);
		}
		else{
			//д���볤�ȶ�
			//fputc(curMatchDist, fOutD);  �����ֽڲ�����fputc
			fwrite(&curMatchDist, 2, 1, fOutD);
			fputc(curMatchLen, fOutD);

			WriteFlag(fOutF, chFlag, bitCount, true);
			_lookAhead -= curMatchLen;
			//���¹�ϣ��,ƥ�䳤��Ϊabc 3�� a�Ѿ����ˣ�����ֻ��� 3-1
			
			curMatchLen -= 1;
			while (curMatchLen){
				++_start;
				_ht.Insert(hashAddr, _pWin[_start + 2], _start, matchHead);
				curMatchLen--;
			}
			++_start;
		}

		if (_lookAhead <= MIN_LOOKAHEAD){
			//���������ݲ�������������
			FillWindow(fIn);
		}
	}
	//���һ����ǲ���8����λ��Ҫ���⴦��
	if (bitCount > 0 && bitCount < 8){
		chFlag <<= (8 - bitCount);
		fputc(chFlag, fOutF);
	}

	fclose(fIn);
	//��ѹ�������ѹ���ļ��ϲ�Ϊһ���ļ���ѹ�����λ��ѹ���ļ�֮��ѹ����ǵĴ�С
	//ѹ������  ���  ��Ǵ�СԴ�ļ���С
	fclose(fOutF);
	FILE* fInF = fopen("2_flag_filename.lzp", "rb");
	assert(fInF);
	UCH* pReadBuff = new UCH[1024];
	//��Ǵ�С
	size_t flagSize = 0;
	while (true){
		size_t rdSize = fread(pReadBuff, 1, 1024, fInF);
		if (0 == rdSize){
			break;
		}
		flagSize += rdSize;
		fwrite(pReadBuff, 1, rdSize, fOutD);
	}

	fclose(fInF);

	fwrite(&fileSize, sizeof(fileSize), 1, fOutD);
	fwrite(&flagSize, sizeof(flagSize), 1, fOutD);

	fclose(fOutD);
	//ɾ�������ļ�
	remove("2_flag_filename.lzp");
}

void LZ77::WriteFlag(FILE* fOutF, UCH& chFlag, UCH& bitCount, bool IsChar){
	chFlag <<= 1;
	//��⵱ǰ����Ƿ�Ϊ���볤�ȶ�
	if (IsChar)
		chFlag |= 1;
	bitCount++;
	if (8 == bitCount){
		fputc(chFlag, fOutF);
		chFlag = 0;
		bitCount = 0;
	}
}

UCH LZ77::LongMatch(USH matchHead, USH& curMatchDist){
	
	
	UCH curMatchLen = 0;
	UCH maxLen = 0;
	USH pos = 0;
	//�ƥ����
	int Matchchainlen = 255;
	USH limit = _start > MAX_DIST ? _start - MAX_DIST : 0;
	do{
		//���ѭ��ʹ��pstart��λ
		UCH* pStart = _pWin + _start;
		UCH* pEnd = pStart + MAX_MATCH;
		//�ڲ��һ������ҵ�ƥ�䴮����ʼλ��
		UCH* pCurStart = _pWin + matchHead;
		curMatchLen = 0;
		//�ҵ�������ƥ�䳤��,��ֹ������ѭ��
		while (pStart < pEnd && *pStart == *pCurStart){
			curMatchLen++;
			pStart++;
			pCurStart++;
		}
		if (curMatchLen > maxLen){
			pos = matchHead;
			maxLen = curMatchLen;
		}
		//��ȡ��һ��ƥ������Ϊ0��ֹѭ��
		//((hashHead = _hash._prev[hashHead & WMASK]) > limit && --chain_length != 0);
	} while (((matchHead = _ht.GetNext(matchHead)) > limit) &&(--Matchchainlen != 0));
	curMatchDist = _start - pos;
	return maxLen;
}

//�������
void LZ77::FillWindow(FILE* fIn){
	//���Ҵ����е����ݰ��Ƶ���ߵĴ���
	if (_start >= WSIZE + MAX_DIST){
		memcpy(_pWin, _pWin + WSIZE, WSIZE);
		memset(_pWin + WSIZE, 0, WSIZE);
		_start -= WSIZE;
		//���¹�ϣ��
		_ht.Update();
	}
	//���Ҵ������������
	if (!feof(fIn)){
		_lookAhead += fread(_pWin + WSIZE, 1, WSIZE, fIn);
	}
}

void LZ77::UNCompressFile(const std::string& filePath){
	std::string strPostFix = filePath.substr(filePath.rfind('.'));
	if (strPostFix != ".lzp"){
		std::cout << "ѹ���ļ��ĸ�ʽ��֧��" << std::endl;
	}
	//������
	FILE* fInD = fopen(filePath.c_str(),"rb");
	if (nullptr == fInD){
		std::cout << "��ѹ���ļ�ʧ��" << std::endl;
		return;
	}
	//��ȡ��ǵĴ�С
	size_t flagSize = 0;
	int offset = 0 - sizeof(flagSize);
	fseek(fInD, offset, SEEK_END);		//��ǰƫ��4���ֽڶ�ȡ��ǵĴ�С
	fread(&flagSize, sizeof(flagSize), 1, fInD);
	
	//��ȡԴ�ļ��Ĵ�С
	ULL fileSize = 0;
	offset = 0 - sizeof(flagSize)-sizeof(fileSize);
	fseek(fInD, offset, SEEK_END);
	fread(&fileSize, sizeof(fileSize), 1, fInD);

	//������ļ����ļ�ָ��
	FILE* fInF = fopen(filePath.c_str(), "rb");
	assert(fInF);
	offset = 0 - (sizeof(flagSize)+sizeof(fileSize)+ flagSize);
	fseek(fInF, offset, SEEK_END);		//���ļ�ָ��ָ�����ļ��Ŀ�ʼ����
	
	//��ȡԭ�ļ��ĺ�׺
	fseek(fInD, 0, SEEK_SET);
	std::string strUNComFileName = filePath.substr(0,filePath.find('.')) + "_lz";
	strPostFix = "";
	GetLine(fInD, strPostFix);
	strUNComFileName += strPostFix;

	//���н�ѹ��
	FILE* fOut = fopen(strUNComFileName.c_str(), "wb");  
	assert(fOut);
	FILE* fWin = fopen(strUNComFileName.c_str(), "rb");   //������볤�ȶ�
	assert(fWin);
	UCH charFlag = 0;
	int bitCount = -1;
	while (fileSize){
		//��ȡ���
		if (bitCount < 0){
			charFlag = fgetc(fInF);
			bitCount = 7;
		}
		
		if (charFlag & (1 << bitCount)){
			//λ��Ϊ1�Ǿ��볤�ȶ�,�����볤�ȶԣ���֮ǰ��������в���
			USH dist = 0;
			fread(&dist, 2, 1, fInD);
			UCH length = fgetc(fInD);
			//�ļ�ioд������д�����������ˣ������ˢ��֮ǰ����ֻ������հ��ַ�
			fflush(fOut);
			fseek(fWin, 0 - dist, SEEK_END);
			fileSize -= length;
			while (length){
				UCH ch = fgetc(fWin);
				fputc(ch, fOut);
				length--;
				//ѹ��ʱ�п����ص�
				fflush(fOut);
			}
			fseek(fOut, 0, SEEK_END);
		}
		else{
			//Դ�ַ�,ֱ��д������ļ���
			UCH ch = fgetc(fInD);
			fputc(ch, fOut);
			fflush(fOut);
			fileSize -= 1;
		}
		bitCount--;
	}

	fclose(fInD);
	fclose(fInF);
	fclose(fOut);
	fclose(fWin);
}

void LZ77::GetLine(FILE* fIn, std::string& str){
	while (!feof(fIn)){
		char ch = fgetc(fIn);
		if ('\n' == ch){
			return;
		}
		str += ch;
	}
}
