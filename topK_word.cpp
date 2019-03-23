#include <iostream>
#include<set>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;



class Solution{
public:
    struct compare{
        bool operator()(const pair<string, int>& left, const pair<string, int>& right){
            return left.second > right.second;
        }
    };
    vector<string> TopKwords(vector<string> array, int k){
        map<string,int> m;
        vector<string> v;
        for(size_t i = 0; i < array.size(); ++i){
            //统计字符出现的次数
            ++m["array[i]"];
        }
        //将出现次数一样的单词放到一起，通过multimap进行排序
        multimap<string, string , compare> mu(m.begin(), m.end());

        //将相同次数的单词存放到set中
        set<string> s;
        int count = 0;
        size_t lifeCount = k;
        vector<string> ret;
        for(auto it = mu.begin(); it != mu.end(); ++it){
            if(!s.empty()){
                if(count != it->second){
                    if(s.size()!=lifeCount){
                        ret.insert(ret.end(),s.begin(),s.end());
                        lifeCount -= s.size();
                        s.clear();
                    }
                    else{
                        break;
                    }
                }
            }
            count = it->second;
            s.insert(it->first);
        }
        for(auto& e : s){
            if(0 == lifeCount){
                break;
            }
            ret.push_back(e);
            lifeCount--;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> array ={"a", "a", "aa", "a", "aa", "aaa"};
    vector<string> result;
    result = s.TopKwords(array, 1);
    for(auto e : result){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}

