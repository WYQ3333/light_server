#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int size = A.size();
        vector<int> result(size, 1);
        if(A.empty())
            return result;
        for(int i = 1; i < size; ++i){
            result[i] = result[i - 1] * A[i - 1];
            cout << result[i] << " ";
        }
        cout << endl;
        int temp = 1;
        for(int i = size - 2; i >= 0; --i){
            temp *= A[i + 1];
            result[i] *= temp;
            cout << result[i] << " ";
        }
        cout << endl;
        return result;
    }
};
int main()
{
    const vector<int> array = {2, 3, 4, 5, 6};
    Solution s;
    vector<int> result = s.multiply(array);
    return 0;
}

