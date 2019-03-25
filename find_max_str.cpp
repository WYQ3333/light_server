#include <iostream>
#include<string>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    string str_max = "";
    if(s1.size() < s2.size()){
        for(size_t i = 0; i < s1.size(); ++i){
            string temp = "";
            size_t j = i;
            for(size_t index = 0; index < s1.size(); ++index){
                size_t h = index;
                while(j < s1.size() && s1[j] == s2[h]){
                    temp += s1[j];
                    j++;
                    h++;
                }
                if(temp.size() > str_max.size()){
                    str_max = temp;
                }
            }
        }

    }
    else{
        for(size_t i = 0; i < s2.size(); ++i){
            string temp = "";
            size_t j = i;
            for(size_t index = 0; index < s2.size(); ++index){
                size_t h = index;
                while(j < s2.size() && s1[j] == s2[h]){
                    temp += s1[j];
                    j++;
                    h++;
                }
                if(temp.size() > str_max.size()){
                    str_max = temp;
                }
            }
        }
    }

    cout << str_max << endl;
    return 0;
}

