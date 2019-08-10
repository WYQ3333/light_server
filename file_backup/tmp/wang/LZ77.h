#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "HashTable.h"
#include <string>




class LZ77{
private:
	UCH* _pWin;    //滑动窗口
	HashTable _ht;
	USH _start;
	size_t _lookAhead;
public:
	LZ77();
	~LZ77();
	void CompressFile(const std::string& filePath);
	void UNCompressFile(const std::string& filePath);
	UCH LongMatch(USH matchHead, USH& curMatchDist);
	void WriteFlag(FILE* fOutF, UCH& chFlag, UCH& bitCount,bool IsChar);
	void GetLine(FILE* fIn, std::string& str);
	void FillWindow(FILE* fIn);     //填充数据
};
