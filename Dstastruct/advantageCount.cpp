#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> result;
        sort(A.begin(), A.end());
        for(size_t i = 0; i < B.size(); ++i){
            for(size_t j = 0; j < A.size(); ++j){
                if(A[j] > B[i]){
                    result.push_back(A[i]);
                    A.erase(A.begin() + j);
                    break;
                }
            }
        }
        return result;
    }

    vector<int> advantageCount1(vector<int>& A, vector<int>& B) {
        vector<int> temp;
        sort(A.begin(), A.end());
        for (size_t i = 0; i < B.size(); ++i) {
            size_t j = 0;
            bool flag = false;
            while (j < A.size()) {
                if (A[j] > B[i]) {
                    temp.push_back(A[j]);
                    A.erase(A.begin() + j);
                    flag = true;
                    break;
                }
                ++j;
            }
            if (!flag) {
                temp.push_back(A[0]);
                A.erase(A.begin());
            }
        }
        return temp;
    }
};

int main()
{
    int input;
    cin >> input;
    vector<int> array1;
    vector<int> array2;
    for(int i = 0; i < input; ++i){
        int temp;
        cin >> temp;
        array1.push_back(temp);
    }
    for(int i = 0; i < input; ++i){
        int temp;
        cin >> temp;
        array2.push_back(temp);
    }
    vector<int> result;
    Solution s;
    result = s.advantageCount(array1, array2);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    result.clear();
    result = s.advantageCount1(array1, array2);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

