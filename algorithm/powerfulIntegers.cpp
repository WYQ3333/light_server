#include <iostream>
#include<set>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> powerfulIntegers(int x, int y, int bound){
        //长整数
        vector<int> array1;
        int x1 = 1;
        array1.push_back(1);
        while(x1 <= bound){
            if(1 == x)
                break;
            x1 *= x;
            array1.push_back(x1);
        }
        vector<int> array2;
        int y1 = y;
        while(y1 <= bound){
            if(1 == y1)
                break;
            y1 *= y;
            array2.push_back(y1);
        }
        set<int> result;
        for(int i = 0; i < array1.size(); ++i){
            for(int j = 0; j < array2.size(); ++j){
                if(array1[i] + array2[j] <= bound){
                    result.insert(array1[i] + array2[j]);
                }
            }
        }
        vector<int> answer;
        for(auto e : result){
            answer.push_back(e);
        }
        return answer;
    }
};

int main()
{
    Solution s;
    int x = 2, y = 3, bound = 100;
    vector<int> result = s.powerfulIntegers(x, y, bound);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

