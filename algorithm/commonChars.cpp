#include <iostream>
#include<limits.h>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        if(A.empty())
            return {};
        vector<vector<int>> array(A.size(), vector<int>(255,0));
        for(size_t i = 0; i < A.size(); ++i){
            for(size_t j = 0; j < A[i].size(); ++j){
                array[i][A[i][j]]++;
            }
        }
        vector<string> result;
        int min_num = INT_MAX;
        for(size_t j = 0; j < 255; ++j){
            min_num = INT_MAX;
            for(size_t i = 0; i < array.size(); ++i){
                if(array[i][j] < min_num){
                    min_num = array[i][j];
                }
            }
            if(min_num == 0){
                continue;
            }
            else if(min_num == 1){
                string temp = "";
                temp += (char)j;
                result.push_back(temp);
            }
            else if(min_num > 1){
                for(size_t k = 0; k < min_num; ++k){
                    string temp = "";
                    temp += (char)j;
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<string> array = {"bella","label","roller"};
    vector<string> result = s.commonChars(array);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
//python解法，只需取第一个字符串中的所有字符与其他字符进行比较即可
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        result = [];
        # 队列为空，或者队列长度小于2，返回空
        if not A or len(A) < 2:
            return result;

        # 获取队列中第一位的所有的字符
        setKey = set(A[0])

        # 遍历字符，并获取所有字符串中出现的次数的最小值
        for x in setKey:
            num = min(a.count(x) for a in A)
            for i in range(num):
                result.append(x)
        return result
