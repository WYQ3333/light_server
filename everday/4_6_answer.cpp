#include <iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int getFirstUnFormedNum(vector<int> arr, int len) {
        int min_num = 0, max_num = 0;
        min_num = arr[0];
        for(int i = 0; i < len; ++i){
            max_num += arr[i];
            if(arr[i] < min_num){
                min_num = arr[i];
            }
        }

        vector<int> array(max_num + 1, 0);
        for(size_t i = 0; i < arr.size(); ++i){
            for(int j = max_num; j >= arr[i]; --j){
                if(array[j] < arr[i] + array[j - arr[i]]){
                    array[j] = arr[i] + array[j - arr[i]];
                }
                else{
                    array[j] = array[j];
                }
            }
        }
        int result  = 0;
        int i = 0;
        for(i = min_num; i < max_num; ++i){
            if(i != array[i]){
                result = i;
            }
        }
        if(result != i){
            result =  max_num + 1;
        }
        return result;
    }
};

class Solution2{
public:
    int getFirstUnFormedNum(vector<int> arr, int len) {
        int min_num = 0, max_num = 0;
        min_num = arr[0];
        for(int i = 0; i < len; ++i){
            max_num += arr[i];
            min_num = min_num > arr[i] ? arr[i] : min_num;
        }
        /* cout << "min_num is:" << min_num << endl; */

        vector<int> answer(max_num+1, 0);
        for(int i = 0; i < len; ++i){
            for(int j = max_num; j >= arr[i]; --j){
                if(answer[j] < arr[i] + answer[j - arr[i]])
                    answer[j] = arr[i] + answer[j- arr[i]];
                else
                    answer[j] = answer[j];
            }
        }
        int result = 0; 
        for(int i = min_num; i <= max_num; ++i){
            if(i != answer[i]){
                result = i;
                return result;
            }
        }
        result += max_num +1;
        return result;
    }

};
int main()
{
    vector<int> array1 = {3, 2, 5};
    vector<int> array2 = {3, 2, 4};
    vector<int> array3 = {3, 2, 1};

    Solution2 s;
    cout << s.getFirstUnFormedNum(array1, 3) << endl;
    cout << s.getFirstUnFormedNum(array2, 3) << endl;
    cout << s.getFirstUnFormedNum(array3, 3) << endl;
    return 0;
}

