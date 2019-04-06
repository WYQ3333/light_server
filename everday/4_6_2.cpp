#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
        /**
         *   *  正数数组中的最小不可组成和
         *   *  输入：正数数组arr
         *   *  返回：正数数组中的最小不可组成和
         * */
    int getFirstUnFormedNum(vector<int> arr, int len) {
        sort(arr.begin(), arr.end());
        int min_num =  0, max_num = 0; 
        min_num = arr[0];
        for(int i = 0; i < len; ++i){
            max_num += arr[i];
        }
        int result = 0;
        int i = 0;
        for(i = min_num; i <= max_num; ++i){
            size_t a = 0;
            size_t b = a + 1;
            int sum = 0;
            sum += arr[0];
            while(b < arr.size()){
                if(sum == i){
                    break;
                }
                else if(sum < i){
                    sum += arr[b];
                    b++;
                }
                else if(sum > i){
                    sum -= arr[a];
                    a++;
                }
            }
            if(sum != i){
                result = i;
                break;
            }
            else if(sum == i){
                continue;
            }
        }
        if(result != i){
            result += max_num + 1;
        }
        return result;
    }
};

int main()
{
    vector<int> array1 = {3, 2, 5};
    int len = 3;
    Solution s;
    vector<int> array2 = {3, 2, 4};
    vector<int> array3 = {3, 1, 2};
    cout << "answer is 4:" << s.getFirstUnFormedNum(array1, len) << endl;
    cout << "answer is 8:" << s.getFirstUnFormedNum(array2, len) << endl;
    cout << "answer is 7:" << s.getFirstUnFormedNum(array3, len) << endl;
    return 0;
}

