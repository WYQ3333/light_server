#include "FileCompressHuffman.hpp"
#include "LZ77.h"

class MyGzip{
public:
    LZ77 lz;
    FileCompressHuffman hz;
    void beginGzip(const std::string& filePath){
        if(filePath.empty()){
            std::cout << "文件不存在！！" << std::endl;
            return;
        }

        hz.CompressFile(filePath.c_str());
        std::string tempfile1 = filePath.substr(0, filePath.find('.'));
        tempfile1 += ".hzp";
        lz.CompressFile(tempfile1.c_str());
        remove(tempfile1.c_str());
    }

    void geginUNGzip(const std::string& filePath){
        if(filePath.empty()){
            std::cout << "文件不存在" << std::endl;
        }
        std::string tempfile2 = filePath.substr(0, filePath.find('.'));
        tempfile2 += ".lzp";
        lz.UNCompressFile(tempfile2.c_str());
        std::string tempfile3 = filePath.substr(0, filePath.find('.'));
        tempfile3 += "_lz.hzp";
        hz.UNCompressFile(tempfile3.c_str());
        remove(tempfile3.c_str());
    }
};

