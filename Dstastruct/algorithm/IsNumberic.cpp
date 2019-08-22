#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == nullptr)
            return true;
        char * cur = string;
        if(*cur == '+' || *cur == '-'){
            cur++;
        }
        while(*cur != '\0'){
            char ch = *cur;
            if(ch >= '0' && ch <= '9'){
                cur++;
                continue;
            }
            else if(ch == 'e'){
                char *next = cur + 1;
                if(*next == '\0'){
                    return false;
                }
                while(*next != '\0'){
                    if(*next == '+'){
                        next++;
                        continue;
                    }
                    else if((*next) > '9' || (*next) < '0'){
                        return false;
                    }
                    next++;
                }
                return true;
            }
            else if(ch == 'E'){
                char *next = cur + 1;
                while(*next != '\0'){
                    if(*next == '-'){
                        next++;
                    }
                    else if(*next == '+'){
                        next++;
                    }
                    else if((*next) < '0' || (*next) > '9'){
                        return false;
                    }
                    else{
                        next++;
                    }
                }
                return true;
            }
            else if(ch == '.'){
                char *pre = cur - 1;
                while(pre != string){
                    if(*pre == '.'){
                        return false;
                    }
                    pre--;
                }
                cur++;
                continue;
            }
            else{
                return false;
            }
            cur++;
        }
        return true;
    }

};

class Solution2 {
public:
    bool isNumeric(char* string)
    {
        if(string==NULL)
            return false;
        if(*string=='+'||*string=='-')
            string++;
        if(*string=='\0')
            return false;
        int dot=0,num=0,nume=0;//分别用来标记小数点、整数部分和e指数是否存在
        while(*string!='\0'){
            if(*string>='0'&&*string<='9')
            {  
                string++;
                num=1;
            }
            else if(*string=='.'){
                if(dot>0||nume>0)
                    return false;
                string++;
                dot=1;
            }
            else if(*string=='e'||*string=='E')
                {
                  if(num==0||nume>0)
                      return false;
                  string++;
                  nume++;
                  if(*string=='+'||*string=='-')
                      string++;
                 if(*string=='\0')
                     return false;
                }
            else
                return false;
        }
        return true;
    }
 
};
//注意表示数值的字符串遵循的规则；
//在数值之前可能有一个“+”或“-”，接下来是0到9的数位表示数值的整数部分，如果数值是一个小数，那么小数点后面可能会有若干个0到9的数位
//表示数值的小数部分。如果用科学计数法表示，接下来是一个‘e’或者‘E’，以及紧跟着一个整数（可以有正负号）表示指数。

int main()
{
    Solution s;
    char input[] = "-1E--16";
    cout << s.isNumeric(input) << endl;
    return 0;
}

