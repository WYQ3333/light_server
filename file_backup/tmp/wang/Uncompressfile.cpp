#include <getopt.h>
#include <signal.h>
#include "mygzip.hpp"

void InitSignal(){
    signal(SIGPIPE, SIG_IGN);
}

void UsagePrint(){
    std::cout << "***************************************" << std::endl;
    std::cout << "Usage: ./UNcompressfile -f test.lzp" << std::endl;
    std::cout << "\tf\tfilename need to be UNCompressed" << std::endl;
    std::cout << "***************************************" << std::endl;
}

int main(int argc, char* argv[])
{
        const char *ptr = "f:";
        char *_file_dir;
        int opt;
        opt = getopt(argc, argv, ptr);
        if(opt == -1){
            UsagePrint();
            return 1;
        }
        _file_dir = optarg;
        if(!_file_dir){
            std::cout << "please input the file which you need UNCompress!!!" << std::endl;
            return 1;
        }

        //FileCompressHuffman f;
        //f.UNCompressFile(_file_dir);
        
        MyGzip gz;
        gz.geginUNGzip(_file_dir);

    return 0;
}

