#pragma once
#include <string>
#include <string.h>
#include "common_compress.h"




class HashTable{
private:
	USH* _prev;
	USH* _head;
	size_t _hashSize;

	//¹þÏ£º¯Êý

public:
	USH H_SHIFT();

	void HashFunc(USH& hashAddr,UCH ch);
	HashTable(size_t size);
	~HashTable();
	void Insert(USH& hashAddr, UCH ch, USH pos, USH& matchHead);
	USH GetNext(USH matchPos);
	void Update();
};


