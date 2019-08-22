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

int main()
{
    Solution s;
    char input[] = "-1E--16";
    cout << s.isNumeric(input) << endl;
    return 0;
}

