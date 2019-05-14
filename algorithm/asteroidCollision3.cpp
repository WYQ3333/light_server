#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        if(asteroids.empty() || asteroids.size() == 1){
            return asteroids;
        }
        vector<int> result;
        int left = 0, right = asteroids.size() - 1;
        int left_pre = 0, right_pre = asteroids.size() - 1;
        while(true){
            while(asteroids[left] < 0){
                left_pre = left;
                left++;
                result.push_back(asteroids[left_pre]);
            }
            if(left != left_pre && left < asteroids.size() && 0 - asteroids[left_pre] < asteroids[left]){
                result[result.size() - 1] = asteroids[left];
                left++;
            }
            vector<int> temp;
            while(asteroids[right] > 0){
                right_pre = right;
                right--;
                temp.push_back(asteroids[right_pre]);
            }
            if(right != right_pre && right > 0 && 0 - asteroids[right] > asteroids[right_pre]){
                temp[temp.size() - 1] = asteroids[right];
                right--;
            }
            reverse(temp.begin(), temp.end());
            for(size_t i = 0; i < temp.size(); ++i){
                result.push_back(temp[i]);
            }
            //if(right <= left || right < 0 || left > asteroids.size() - 1){
                //cout << "跳出循环" << "left: " << left << "right " << right << endl;
                //break;
            //}
            left = 0; right = result.size() - 1;
            asteroids = result;
            result.clear();
        }
        result = asteroids;
        return result;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0) {
                res.push_back(asteroids[i]);
            } else if (res.empty() || res.back() < 0) {
                res.push_back(asteroids[i]);
            } else if (res.back() <= -asteroids[i]) {
                if (res.back() < -asteroids[i]) --i;
                res.pop_back();
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> array;
    int input;
    cin >> input;
    for(size_t i = 0; i < input; ++i){
        int temp;
        cin >> temp;
        array.push_back(temp);
    }
    vector<int> result = s.asteroidCollision(array);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

