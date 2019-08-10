#include"HashTable.h"

//表示左移多少位，左移15刚好是32k
const USH HASH_BITS = 15;
const USH HASH_SIZE = (1 << HASH_BITS);
const USH HASH_MASK = HASH_SIZE - 1;


HashTable::HashTable(size_t size)
:_prev(new USH[size * 2])
, _head(_prev + size)
, _hashSize(size * 2){
	memset(_head, 0, sizeof(USH)*size);
}

HashTable::~HashTable(){
	if (nullptr != _prev){
		delete[] _prev;
		_prev = _head = nullptr;
	}
}

void HashTable::HashFunc(USH& hashAddr, UCH ch){
	hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}

USH HashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}

void HashTable::Insert(USH& hashAddr, UCH ch, USH pos, USH& matchHead){
	HashFunc(hashAddr, ch);
	//pos有可能越位，因此需要相保证不越界
	_prev[pos & HASH_MASK] = _head[hashAddr];
	matchHead = _head[hashAddr];
	_head[hashAddr] = pos;
}

USH HashTable::GetNext(USH matchPos){
	return _prev[matchPos];
}

void HashTable::Update(){
	//将右窗口的匹配位置更新到左窗
	//更新head
	for (int i = 0; i < HASH_SIZE; ++i){
		if (_head[i] >= WSIZE){
			_head[i] -= WSIZE;
		}
		else{
			_head[i] = 0;
		}
	}
	//更新prev
	for (int i = 0; i < WSIZE; ++i){
		if (_prev[i] >= WSIZE){
			_prev[i] -= WSIZE;
		}
		else{
			_prev[i] = 0;
		}
	}
}
