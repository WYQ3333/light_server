#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>
#include "HuffmanTree.hpp"


typedef unsigned char UCH;

struct Char_info{
    //记录当前字符
    UCH _ch;
    //当前字符在文件中的次数
    long long _char_count;
    //记录当前字符的Huffman编码
    std::string _str_code;
    Char_info(size_t char_count = 0)
        :_char_count(char_count)
    {}

    //+号重载
    Char_info operator+(const Char_info& temp)const{
        return Char_info(temp._char_count + _char_count);
    }

    bool operator>(const Char_info& temp)const{
        return _char_count > temp._char_count;
    }

    bool operator<(const Char_info& temp)const{
        return _char_count < temp._char_count;
    }

    bool operator==(const Char_info& temp)const{
        return _char_count == temp._char_count;
    }

    bool operator!=(const Char_info& temp)const{
        return _char_count != temp._char_count;
    }

    bool operator!()const{
        return !_char_count;
    }

};


class FileCompressHuffman
{
private:
    std::vector<Char_info> _char_info;
public:
    FileCompressHuffman(); 
    void CompressFile(const std::string& strPath);
    void GetHuffmanCode(HuffmanTreeNode<Char_info>* pRoot);
    void WriteHead(FILE* DestFile, const std::string& strPath);
    void UNCompressFile(const std::string& strPath);
    void GetLine(FILE* fIn, std::string& str);
    ~FileCompressHuffman();
};

//构造函数
FileCompressHuffman::FileCompressHuffman(){
    _char_info.resize(256);
    for(size_t i = 0; i < _char_info.size(); ++i){
        _char_info[i]._ch = i;
        _char_info[i]._char_count = 0;
    }
}

//析构函数
FileCompressHuffman::~FileCompressHuffman(){
}

void FileCompressHuffman::CompressFile(const std::string& strPath){
    if(strPath.empty()){
        std::cout << "文件目录错误" << std::endl;
    }

    //创建一个文件流，并打开名为strPath的文件, 以二进制读的方式打开文件
    FILE* Source_File = fopen(strPath.c_str(), "rb");
    if(nullptr == Source_File){
        std::cout << "打开文件失败" << std::endl;
    }

    UCH ReadBuff[1024] = {0};
    while(true){
        size_t ReadSize = fread(ReadBuff, 1, 1024, Source_File);
        if(0 == ReadSize){
            //读取文件结束
            break;
        }
        //统计文档中字符出现的次数
        for(size_t i = 0; i < ReadSize; ++i){
            _char_info[ReadBuff[i]]._char_count++;
        }
    }

    //将char_info 的数据进行排序，取权值最小的，建立Huffman树
    HuffmanTree<Char_info> ht;
    ht.CreateHuffmanTree(_char_info, _char_info[0]);


    //获取Huffman编码
    GetHuffmanCode(ht.GetRoot());

    std::string profix = ".hzp";
    std::string compressFilename = strPath.substr(0, strPath.find('.')) + profix;

    //打开压缩文件
    FILE* DestFile = fopen(compressFilename.c_str(), "wb");
    if(DestFile == nullptr){
        std::cout << "创建压缩文件失败" << std::endl;
        return;
    }

    //组织压缩文件头
    WriteHead(DestFile, strPath);

    //写压缩文件
    //要将文件指针重定位到文件开始
    fseek(Source_File, 0, SEEK_SET);

    char ch = 0;
    int bitcount = 0;
    while(true){
        size_t Read_Size = fread(ReadBuff, 1, 1024, Source_File);
        if(0 == Read_Size){
            break;
        }

        for(size_t i = 0; i < Read_Size; ++i){
            std::string& char_code = _char_info[ReadBuff[i]]._str_code;
            for(size_t j = 0; j < char_code.size(); ++j){
                ch <<= 1;
                if('1' == char_code[j]){
                    ch |= 1;
                }
                bitcount++;
                if(8 == bitcount){
                    fputc(ch, DestFile);
                    bitcount = 0;
                }
            }
        }
    }
    //写完之后还有未写入的部分
    if(bitcount > 0 && bitcount < 8){
        ch <<= (8 - bitcount);
        fputc(ch, DestFile);
    }

    fclose(DestFile);
    fclose(Source_File);
}

void FileCompressHuffman::GetHuffmanCode(HuffmanTreeNode<Char_info>* pRoot){
    if(nullptr == pRoot){
        //递归出口
        return;
    }

    //从叶子节点开始获取字符编码
    GetHuffmanCode(pRoot->_pLeft);
    GetHuffmanCode(pRoot->_pRight);

    if(pRoot->_pLeft == nullptr && pRoot->_pRight == nullptr){
        HuffmanTreeNode<Char_info>* pCur = pRoot;
        HuffmanTreeNode<Char_info>* pParent = pCur->_pParent;

        std::string& strCode = _char_info[pCur->_weight._ch]._str_code;
        while(pParent != nullptr){
            //左子树为0，右子树为1
            if(pCur == pParent->_pLeft){
                strCode += '0';
            }
            else{
                strCode += '1';
            }
            pCur = pParent;
            pParent = pCur->_pParent;
        }
        //获取到的编码为倒叙，因此需要reverse一下
        reverse(strCode.begin(), strCode.end());
    }
}

void FileCompressHuffman::WriteHead(FILE* DestFile, const std::string& strPath){
    std::string str_suffix = strPath.substr(strPath.rfind('.'));
    str_suffix += '\n';

    std::string str_charinfo;
    int linecount = 0;
    for(size_t i = 0; i < 256; ++i){
        if(_char_info[i]._char_count){
            str_charinfo += _char_info[i]._ch;
            str_charinfo += '/';
            str_charinfo += std::to_string(_char_info[i]._char_count);
            str_charinfo += '\n';
            linecount++;
        }
    }

    str_suffix += std::to_string(linecount);
    str_suffix += '\n';

    str_suffix += str_charinfo;
    fwrite(str_suffix.c_str(), 1, str_suffix.size(), DestFile);
}

//读取一行的数据
void FileCompressHuffman::GetLine(FILE* fIn, std::string& str){
    //检测fIn是否到达文件末尾
    while(!feof(fIn)){
        UCH ch = fgetc(fIn);
        if(ch == '\n'){
            return;
        }
        str += ch;
    }
}

//解压文件
void FileCompressHuffman::UNCompressFile(const std::string& strPath){
    std::string str_suffix = strPath.substr(strPath.rfind('.'));
    if(".hzp" != str_suffix){
        std::cout << "文件格式不匹配" << std::endl;
        return;
    }

    FILE* fIn = fopen(strPath.c_str(), "rb");
    if(nullptr == fIn){
        return;
    }

    //获取源文件的后缀
    std::string strfix = "";
    GetLine(fIn, strfix);

    //读取共有多少行
    std::string strChar = "";
    GetLine(fIn, strChar);
    int linecount = atoi(strChar.c_str());

    for(int i = 0; i < linecount; ++i){
        strChar = "";
        GetLine(fIn, strChar);
        if(strChar.empty()){
            //换行需要手动将换行加上,换行需要再读一次
            strChar += '\n';
            GetLine(fIn, strChar);
        }
        //获得每个字符出现的次数，+2跳过分隔字符与字符
        _char_info[(UCH)strChar[0]]._char_count = atoi(strChar.c_str() + 2);
    }

    HuffmanTree<Char_info> ht;
    ht.CreateHuffmanTree(_char_info, _char_info[0]);

    std::string UNCompress = strPath.substr(0, strPath.find('.'))+ "_backup" + strfix;

    FILE* fOut = fopen(UNCompress.c_str(), "wb");
    if(nullptr == fOut){
        std::cout << "打开解压文件失败" << std::endl;
        return;
    }

    char ReadBuff[1024] = {0};
    HuffmanTreeNode<Char_info>* pCur = ht.GetRoot();
    char pos = 7;
    //文件总大小为huffman树的根节点的权值中的_char_count
    long long filesize = pCur->_weight._char_count;

    while(true){
        size_t ReadSize = fread(ReadBuff, 1, 1024, fIn);
        if(ReadSize == 0){
            break;
        }
        for(size_t i = 0; i < ReadSize; ++i){
            pos = 7;
            char ch = ReadBuff[i];
            for(size_t j = 0; j < 8; ++j){
                //Huffman树的左子树为0， 右子树为1
                if(ch & (1 << pos)){
                    pCur = pCur->_pRight;
                }
                else{
                    pCur = pCur->_pLeft;
                }
                if(nullptr == pCur->_pLeft && nullptr == pCur->_pRight){
                    fputc(pCur->_weight._ch, fOut);
                    pCur = ht.GetRoot();
                    filesize--;
                    if(filesize == 0){
                        //总文件大小为0，解压完成
                        break;
                    }
                }

                pos--;
            }
        }
    }
    fclose(fIn);
    fclose(fOut);
}
