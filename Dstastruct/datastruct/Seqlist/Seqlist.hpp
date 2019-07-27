#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include <errno.h>

template <typename T>
class Seqlist
{
public:
    Seqlist() 
        :_array(nullptr)
        ,_size(0)
        ,_capacity(0)
    {}
    void array_init(int size);
    int Seq_find(T data, int begin = 0);
    bool Seq_PushBack(T data);
    bool Seq_PopBack();
    bool Seq_PushFront(T data);
    bool Seq_PopFront();
    bool BuyNewArray(int size);
    T Seq_GetFront();
    int Seq_Size();
    bool Seq_Insert(int pos, T data);
    bool Seq_Erase(T data);
    void Seq_Print();
    ~Seqlist() {
        if(_array != nullptr){
            delete _array;
            _array = nullptr;
        }
    }
private:
    T* _array;      //顺序表
    int _size;      //顺序表中元素的个数
    int _capacity;  //顺序表的容量
};

template <typename T>
void Seqlist<T>::array_init(int size){
    //new[]写成了new()!!!导致实际上只分配了1字节的空间，
    //却想写一个字符串完全超过了实际的大小，自然在析构的时候会出现内存错误。
    assert(size);
    _capacity = size;
    _array = new T[size];
    assert(_array);
}

template <typename T>
//设置缺省值时只能在定义和声明的地方出现其中的一个即可
int Seqlist<T>::Seq_find(T data, int begin){
    for(size_t i = begin; i < _size; ++i){
        if(_array[i] == data){
            return i;
        }
    }
    return -1;
}

template <typename T>
int Seqlist<T>::Seq_Size(){
    return _size;
}

template <typename T>
bool Seqlist<T>::BuyNewArray(int size){
    T* temp = new T[size];
    if(temp == nullptr){
        perror("new error");
        return false;
    }
    for(int i = 0; i < _size; ++i){
        temp[i] = _array[i];
    }
    delete(_array);
    _array = nullptr;
    _array = temp;
    _capacity = size;
    return true;
}

template <typename T>
bool Seqlist<T>::Seq_PushBack(T data){
    if(_size < _capacity){
        _array[_size] = data;
        _size++;
    }
    else{
        //容量不够，扩充容量
        if(BuyNewArray(2*_capacity)){
            _array[_size] = data;
            _size++;
        }
        else{
            return false;
        }
    }
    return true;
}
template <typename T>
bool Seqlist<T>::Seq_PopBack(){
    if(_size == 0){
        perror("seqlist is empty!!");
        return false;
    }
    _size--;
    return true;
}
template <typename T>
bool Seqlist<T>::Seq_PushFront(T data){
    if(_size < _capacity){
        for(int i = _size; i > 0; --i){
            _array[i] = _array[i - 1];
        }
        _array[0] = data;
        _size++;
    }
    else{
        //扩充容量
        if(!BuyNewArray(2*_capacity)){
           return false;
        }
        for(int i = _size; i > 0; --i){
            _array[i] = _array[i - 1];
        }
        _array[0] = data;
        _size++;
    }
    return true;
}
template <typename T>
bool Seqlist<T>::Seq_PopFront(){
    if(_size == 0){
        perror("seqlist is empty!!");
        return false;
    }
    for(int i = 0; i < _size - 1; ++i){
        _array[i] = _array[i + 1];
    }
    _size--;
    return true;
}
template <typename T>
T Seqlist<T>::Seq_GetFront(){
    return _array[0];
}
template <typename T>
bool Seqlist<T>::Seq_Insert(int pos, T data){
    if(pos >= _capacity || pos < 0){
        perror("insert index is invalid!!");
        return false;
    }
    if(_size < _capacity){
        for(int i = _size; i > pos; --i){
            _array[i] = _array[i - 1];
        }
        _array[pos] = data;
        _size++;
    }
    else{
        //扩充容量
        if(!BuyNewArray(2*_capacity)){
            return false;
        }
        for(int i = _size; i > pos; --i){
            _array[i] = _array[i - 1];
        }
        _array[pos] = data;
        _size++;
    }
    return true;
}
template <typename T>
bool Seqlist<T>::Seq_Erase(T data){
    int pos = Seq_find(data);
    for(int i = pos; i < _size - 1; ++i){
        _array[i] = _array[i + 1];
    }
    _size--;
    return true;
}
template <typename T>
void Seqlist<T>::Seq_Print(){
    std::cout << "seq size >> " << _size;
    std::cout << "     ";
    std::cout << "seq capacity >> " << _capacity;
    std::cout << std::endl;
    std::cout << "seq value:";
    for(int i = 0; i < _size; ++i){
        std::cout << _array[i] << " ";
    }
    std::cout << std::endl;
}

