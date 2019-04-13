#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.empty()){
            return 0;
        }
        if(A.size() < 3){
            return 0;
        }
        if(A.size() == 3){
            return 1;
        }
        int a,b,c;
        a = A[0];
        b = A[1];
        c = A[2];
        int count = 0;
        int temp = b - a;
        if(temp == (c - b)){
            count++;
        }
        for(int i = 3; i < A.size(); ++i){
            a = b;
            b = c;
            c = A[i];
            if((b - a) == (c - b)){
                count++;
            }
        }
        if((count + 2) == A.size()){
            count++;
        }
        return count;
    }
};
class Solution2 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.empty()){
            return 0;
        }
        if(A.size() < 3){
            return 0;
        }
        if(A.size() == 3){
            return 1;
        }
        int count = 0;
        for(int i = 2; i < A.size(); ++i){
            int temp = i;
            int t = A[i-1] - A[i - 2];
            while(temp < A.size() && (A[temp] - A[temp - 1]) == t){
                count++;
                t = A[temp] - A[temp - 1];
                temp++;
            }
        }
        return count;
    }
};

int main()
{
    int input;
    cin >> input;
    vector<int> array;
    for(int i = 0; i < input; ++i){
        int temp;
        cin >> temp;
        array.push_back(temp);
    }
    Solution s;
    cout << s.numberOfArithmeticSlices(array) << endl;
    return 0;
}

