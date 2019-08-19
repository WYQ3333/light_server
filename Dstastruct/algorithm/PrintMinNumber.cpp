#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    
    void MinNumber(vector<int>& numbers,vector<int> flag, int index, string& temp, vector<string>& result){
        if(index >= numbers.size()){
            result.push_back(temp);
            return;
        }
        for(size_t i = 0; i < numbers.size(); ++i){
            if(flag[i] == 0){
                string t = temp;
                temp += to_string(numbers[i]);
                flag[i] = 1;
                MinNumber(numbers, flag, index + 1,temp, result);
                temp = t;
                flag[i] = 0;
            }
        }
    }
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty())
            return "";
        vector<int> flag(numbers.size(), 0);
        vector<string> result;
        string temp = "";
        MinNumber(numbers, flag, 0, temp, result);
        sort(result.begin(), result.end());
        return result[0];
    }
};
int main()
{
    Solution s;
    vector<int> num = {3, 32, 321};
    cout << s.PrintMinNumber(num) << endl;
    return 0;
}

