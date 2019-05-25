#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        vector<int> array(33,-1);
        for(int i = m; i <= n; ++i){
            int temp = i;
            int index = 1;
            if(temp == 0){
                array[index] = 0;
            }
            while(temp){
                int t = temp&1;
                if(t == 0){
                    array[index] = 0;
                }
                else{
                    array[index] = 1&array[index];
                }
                temp = temp>>1;
                index++;
            }
        }
        for(size_t i = 0; i < array.size(); ++i){
            cout << array[i] << " ";
        }
        cout << endl;
        string result = "";
        for(size_t i = 1; i < array.size(); ++i){
            if(array[i] == 0){
                result += '0';
            }
            else if(array[i] == 1){
                result += '1';
            }
            else{
                continue;
            }
        }
        if(result.empty()){
            return 0;
        }
        long long answer = 0;
        cout << "result " << result << endl;
        answer += (result[0] - '0')*1;
        for(size_t i = 1; i < result.size(); ++i){
            answer += (result[i] - '0')*(1 << i);
        }
        return answer;
    }
};
int main()
{
    Solution s;
    cout << s.rangeBitwiseAnd(0, 1) << endl;
    return 0;
}

