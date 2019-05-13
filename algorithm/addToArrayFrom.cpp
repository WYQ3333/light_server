#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    vector<int> addToArrayFrom(vector<int>& A, int K){
        vector<int> array;
        string temp = "";
        while(K){
            temp += K%10 + '0';
            K /= 10;
        }
        string cur = "";
        /* cout << "temp " << temp << endl; */
        for(size_t i = 0; i < A.size(); ++i){
            cur += A[i] + '0';
        }
        reverse(cur.begin(), cur.end());
        /* cout << "cur " << cur << endl; */
        if(cur.size() < temp.size()){
            swap(cur, temp);
        }
        string result = "";
        int i = 0;
        for(i = 0; i < temp.size(); ++i){
            result += (temp[i] - '0' + cur[i] - '0') + '0';
        }
        if(i < cur.size())
            result += cur.substr(i);
        //cout << result << endl;
        for(size_t j = 0; j < result.size(); ++j){
            if(j < result.size() - 1 && result[j] - '0' > 9){
                result[j+1] = result[j+1] + 1;
                result[j] -= 10;
            }
        }
        if(result[result.size() - 1] - '0' > 9){
            result[result.size() - 1] -= 10;
            result += '1';
        }
        array.clear();
        reverse(result.begin(), result.end());
        for(size_t k = 0; k < result.size(); ++k){
            array.push_back(result[k] - '0');
        }
        return array;
    }
};

int main()
{
    vector<int> array = { 1, 2, 0, 0 };
    int K = 10;
    cin >> K;
    Solution s;
    vector<int> result = s.addToArrayFrom(array, K);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

