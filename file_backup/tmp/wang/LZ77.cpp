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
		std::cout << "打开文件失败" << std::endl;
		return;
	}

	//获取文件的大小,将文件指针移动到末尾，用过ftell获取文件大小
	fseek(fIn, 0, SEEK_END);
	ULL fileSize = ftell(fIn);
	fseek(fIn, 0, SEEK_SET);

	//文件大小小于三个字节，不需要进行压缩
	if (fileSize < 3){
		fclose(fIn);
		return;
	}
	//先读取一个滑动窗口的数据
	_lookAhead = fread(_pWin, 1, 2 * WSIZE, fIn);

	USH hashAddr = 0;
	for (size_t i = 0; i < MIN_MATCH; ++i){
		_ht.HashFunc(hashAddr, _pWin[i]);
	}

	//解压缩后的文件
	std::string file_name = filePath.substr(0, filePath.find('.'));
	file_name += ".lzp";
	FILE* fOutD = fopen(file_name.c_str(),"wb");

	assert(fOutD);
	std::string postFix = filePath.substr(filePath.rfind('.'));
	postFix += '\n';

	//写源文件的后缀
	fwrite(postFix.c_str(), 1, postFix.size(), fOutD);

	//写标记的文件
	FILE* fOutF = fopen("2_flag_filename.lzp", "wb");
	assert(fOutF);
	//进行压缩，start表示滑动窗口的起始位置
	USH matchHead = 0;
	UCH chFlag = 0;
	UCH bitCount = 0;

	//滑动窗口没数据，循环停止
	while (_lookAhead){
		//将以start为首的三个字符插入到哈希表中
		_ht.Insert(hashAddr, _pWin[_start + 2], _start, matchHead);
		
		USH curMatchDist = 0;
		UCH curMatchLen = 0;
		if (matchHead && _lookAhead > MIN_LOOKAHEAD){
			curMatchLen = LongMatch(matchHead, curMatchDist);
		}
		
		if (curMatchLen < MIN_MATCH){
			//没有匹配
			fputc(_pWin[_start], fOutD);

			++_start;
			--_lookAhead;
			WriteFlag(fOutF, chFlag, bitCount, false);
		}
		else{
			//写距离长度对
			//fputc(curMatchDist, fOutD);  两个字节不能用fputc
			fwrite(&curMatchDist, 2, 1, fOutD);
			fputc(curMatchLen, fOutD);

			WriteFlag(fOutF, chFlag, bitCount, true);
			_lookAhead -= curMatchLen;
			//更新哈希表,匹配长度为abc 3， a已经插了，所以只需插 3-1
			
			curMatchLen -= 1;
			while (curMatchLen){
				++_start;
				_ht.Insert(hashAddr, _pWin[_start + 2], _start, matchHead);
				curMatchLen--;
			}
			++_start;
		}

		if (_lookAhead <= MIN_LOOKAHEAD){
			//窗口中数据不够，补充数据
			FillWindow(fIn);
		}
	}
	//最后一个标记不满8比特位需要特殊处理
	if (bitCount > 0 && bitCount < 8){
		chFlag <<= (8 - bitCount);
		fputc(chFlag, fOutF);
	}

	fclose(fIn);
	//将压缩标记与压缩文件合并为一个文件，压缩标记位于压缩文件之后，压缩标记的大小
	//压缩数据  标记  标记大小源文件大小
	fclose(fOutF);
	FILE* fInF = fopen("2_flag_filename.lzp", "rb");
	assert(fInF);
	UCH* pReadBuff = new UCH[1024];
	//标记大小
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
	//删除辅助文件
	remove("2_flag_filename.lzp");
}

void LZ77::WriteFlag(FILE* fOutF, UCH& chFlag, UCH& bitCount, bool IsChar){
	chFlag <<= 1;
	//检测当前标记是否为距离长度对
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
	//最长匹配链
	int Matchchainlen = 255;
	USH limit = _start > MAX_DIST ? _start - MAX_DIST : 0;
	do{
		//多次循环使得pstart归位
		UCH* pStart = _pWin + _start;
		UCH* pEnd = pStart + MAX_MATCH;
		//在查找缓冲区找到匹配串的起始位置
		UCH* pCurStart = _pWin + matchHead;
		curMatchLen = 0;
		//找单挑链的匹配长度,防止链构成循环
		while (pStart < pEnd && *pStart == *pCurStart){
			curMatchLen++;
			pStart++;
			pCurStart++;
		}
		if (curMatchLen > maxLen){
			pos = matchHead;
			maxLen = curMatchLen;
		}
		//获取下一个匹配链，为0终止循环
		//((hashHead = _hash._prev[hashHead & WMASK]) > limit && --chain_length != 0);
	} while (((matchHead = _ht.GetNext(matchHead)) > limit) &&(--Matchchainlen != 0));
	curMatchDist = _start - pos;
	return maxLen;
}

//填充数据
void LZ77::FillWindow(FILE* fIn){
	//将右窗口中的数据搬移到左边的窗口
	if (_start >= WSIZE + MAX_DIST){
		memcpy(_pWin, _pWin + WSIZE, WSIZE);
		memset(_pWin + WSIZE, 0, WSIZE);
		_start -= WSIZE;
		//更新哈希表
		_ht.Update();
	}
	//向右窗口中填充数据
	if (!feof(fIn)){
		_lookAhead += fread(_pWin + WSIZE, 1, WSIZE, fIn);
	}
}

void LZ77::UNCompressFile(const std::string& filePath){
	std::string strPostFix = filePath.substr(filePath.rfind('.'));
	if (strPostFix != ".lzp"){
		std::cout << "压缩文件的格式不支持" << std::endl;
	}
	//读数据
	FILE* fInD = fopen(filePath.c_str(),"rb");
	if (nullptr == fInD){
		std::cout << "打开压缩文件失败" << std::endl;
		return;
	}
	//获取标记的大小
	size_t flagSize = 0;
	int offset = 0 - sizeof(flagSize);
	fseek(fInD, offset, SEEK_END);		//朝前偏移4个字节读取标记的大小
	fread(&flagSize, sizeof(flagSize), 1, fInD);
	
	//获取源文件的大小
	ULL fileSize = 0;
	offset = 0 - sizeof(flagSize)-sizeof(fileSize);
	fseek(fInD, offset, SEEK_END);
	fread(&fileSize, sizeof(fileSize), 1, fInD);

	//读标记文件的文件指针
	FILE* fInF = fopen(filePath.c_str(), "rb");
	assert(fInF);
	offset = 0 - (sizeof(flagSize)+sizeof(fileSize)+ flagSize);
	fseek(fInF, offset, SEEK_END);		//将文件指针指向标记文件的开始部分
	
	//读取原文件的后缀
	fseek(fInD, 0, SEEK_SET);
	std::string strUNComFileName = filePath.substr(0,filePath.find('.')) + "_lz";
	strPostFix = "";
	GetLine(fInD, strPostFix);
	strUNComFileName += strPostFix;

	//进行解压缩
	FILE* fOut = fopen(strUNComFileName.c_str(), "wb");  
	assert(fOut);
	FILE* fWin = fopen(strUNComFileName.c_str(), "rb");   //处理距离长度对
	assert(fWin);
	UCH charFlag = 0;
	int bitCount = -1;
	while (fileSize){
		//读取标记
		if (bitCount < 0){
			charFlag = fgetc(fInF);
			bitCount = 7;
		}
		
		if (charFlag & (1 << bitCount)){
			//位置为1是距离长度对,读距离长度对，在之前的里面进行查找
			USH dist = 0;
			fread(&dist, 2, 1, fInD);
			UCH length = fgetc(fInD);
			//文件io写数据先写到缓冲区中了，如果在刷新之前读，只会读到空白字符
			fflush(fOut);
			fseek(fWin, 0 - dist, SEEK_END);
			fileSize -= length;
			while (length){
				UCH ch = fgetc(fWin);
				fputc(ch, fOut);
				length--;
				//压缩时有可能重叠
				fflush(fOut);
			}
			fseek(fOut, 0, SEEK_END);
		}
		else{
			//源字符,直接写到输出文件中
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
