#include <iostream>
#include <string>
#include <vector>
using namespace std;

int KMP_search(const string& str1, const string& str2){
    if(str2.size() > str1.size() || str1.empty() || str2.empty())
        return -1;
    vector<int> array(str2.size(), 0);
    array[0] = -1;
    int j = 0;
    int k = 0;
    int lenstr2 = str2.size();
    //初始化array数组
    while(j < lenstr2){
        if(j == -1 || str2[j] == str2[k]){
            j++;
            k++;
            if(str2[j] != str2[k]){
                array[j] = k;
            }
            else{
                //如果相等则需要向前进行递归
                array[j] = array[k];
            }
        }
        else{
            k = array[k];
        }
    }

    int i = 0;
    int lenstr1 = str1.size();
    j = 0;
    while(i < lenstr1 && j < lenstr2){
        if(j == -1 || str1[i] == str2[j]){
            ++i;
            ++j;
        }
        else{
            j = array[j];
        }
    }
    if(j == lenstr2){
        return i -j;
    }
    return -1;
}

int main()
{
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    cout << KMP_search(str1, str2) << endl;
    return 0;
}

