#include <iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        stack<int> s;
        int num = 0;
        for(size_t i = 0; i < flowerbed.size(); ++i){
            if(flowerbed[i] == 1){
                while(!s.empty()){
                    s.pop();
                }
            }
            while(i < flowerbed.size() && flowerbed[i] == 0){
                s.push(flowerbed[i]);
                i++;
            }
            if(s.size() >= 3){
                if(s.size() % 2 == 0){
                    num += s.size()/2 - 1;
                }
                else
                    num += s.size()/2;
            }
        }
        cout << "num " << num << endl;
        if(num == n){
            return true;
        }
        return false;
    }
};

class Solution2{
public:
    bool canPlaceFlowers(vector<int>& flowered, int n){
        if(flowered.empty() || flowered.size() < n){
            return false;
        }
        for(size_t i = 0; i < flowered.size(); ++i){
            vector<int> array = {-1, -1, -1};
            array[0] = flowered[i];
            if(i + 1 < flowered.size())
                array[1] = flowered[i+1];
            if(i + 2 < flowered.size())
                array[2] = flowered[i+2];
        }
    }
};
int main()
{
    Solution s;
    vector<int> array;
    int input;
    cin >> input;
    for(size_t i = 0; i < input; ++i){
        int temp ;
        cin >> temp;
        array.push_back(temp);
    }
    int K;
    cin >> K;
    cout << s.canPlaceFlowers(array, K) << endl;
    return 0;
}

