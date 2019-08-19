/*
 *求字符串的全排列，对于重复的，换需要进行去重set
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    
    void Permutation_str(string& str,string& temp, int index, vector<string>& result,vector<int> flag){
        if(index >= str.size()){
            result.push_back(temp);
            return;
        }
        for(size_t i = 0; i < str.size(); ++i){
            if(flag[i] == 0){
                string t = temp;
                flag[i] = 1;
                temp += str[i];
                Permutation_str(str, temp, index + 1, result, flag);
                flag[i] = 0;
                temp = t;
            }
        }
    }
    
    vector<string> Permutation(string str) {
        vector<int> flag(str.size(), 0);
        vector<string> result;
        if(str.empty())
            return result;
        string temp = "";
        Permutation_str(str, temp, 0, result, flag);
        set<string> s(result.begin(), result.end());
        result.clear();
        for(auto e : s){
            result.push_back(e);
        }
        return result;
    }
};
int main()
{
    return 0;
}

