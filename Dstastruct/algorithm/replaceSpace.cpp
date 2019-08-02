/*
 *替换字符串中的空格
 */


#include <iostream>

class Solution{
public:
    void replaceSpace(char *str,int length) {
        if(str == nullptr){
            return;
        }
        //统计str中出现的空格的次数
        int count_space = 0;
        for(int i = 0; i < length; ++i){
            if(*(str + i) == ' '){
                count_space++;
            }
        }
        //计算出向后移动的距离
        int distance = 2*count_space;
        char *p = str + length + distance - 1;
        char *q = str + length - 1;
        for(int i = length + distance - 1; i >= 0; --i){
            if(*q == ' '){
                *p-- = '3';
                *p-- = '2';
                *p-- = '%';
            }
            else{
                *p = *q;
                p--;
            }
            q--;
        }
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

