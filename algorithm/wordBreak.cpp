/*
 *
是否可以根据词典中的词分成
   一个或多个单词。
   比如，给定
   s = "leetcode"
   dict = ["leet", "code"]
   返回true，因为"leetcode"可以被分成"leet code"
 方法：动态规划
 状态：
   子状态：前1，2，3，...*
    F[i] 表示前i个字符可以在字典中被分割成其他单词
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution{
public:
    bool workbreak(string s, unordered_set<string>& dict){
        if(s.empty())
            return false;
        if(dict.empty())
            return false;
        //找dict中的字符串的最大长度
        size_t max_len = 0;
        unordered_set<string>::iterator it = dict.begin();
        for(; it != dict.end(); ++it){
            if((*it).size() > max_len)
                max_len = (*it).size();
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); ++i){
            for(int j = i - 1; j >= 0; --j){
                if(i - j > max_len){
                    //此时可定无法由字典中的字符串组成
                    break;
                }
                if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}

