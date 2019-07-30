#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

/*
 * 这是一个棒球比赛的分数记录规则
 *
 */


class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        stack<pair<int, int>> s;//保存每一轮的得分
        for(size_t i = 0; i < ops.size(); ++i){
            int cur = 0;
            if(ops[i] == "C"){
                if(s.empty())
                    continue;
                else{
                    s.pop();
                    if(s.empty())
                        sum = 0;
                    else
                        sum = s.top().second;
                }

            }
            else{
                if(ops[i] == "D"){
                    if(s.empty())
                        cur = 0;
                    else{
                        cur = 2*s.top().first;
                    }
                        
                }
                else if(ops[i] == "+"){
                    if(s.empty())
                        cur = 0;
                    else{
                        int first = s.top().first;
                        pair<int, int> t = s.top();
                        s.pop();
                        int second = s.top().first;
                        cur = first + second;
                        s.push(t);
                    }
                }
                else{
                    //输入的是数字
                    cur = atoi(ops[i].c_str());
                }
                sum += cur;
                pair<int, int> temp = make_pair(cur, sum);
                s.push(temp);
            }
        }
        return s.top().second;
    }
};
int main()
{
    Solution s;
    vector<string> input ={"1","C","-62","-45","-68"};
    // {"5","-2","4","C","D","9","+","+"};
    cout << s.calPoints(input) << endl;;
    return 0;
}

