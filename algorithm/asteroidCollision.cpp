#include <iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int num_ans(int num1, int num2){
        int result = 0;
        if(num1 < 0){
            if(0 - num1 < num2){
                result = num2;
            }
            else if( 0 - num1 == num2 ){
                result = 0;
            }
            else{
                result = num1;
            }
        }
        else{
            if(0 - num2 < num1){
                result = num1;
            }
            else if(0 - num2 == num1){
                result = 0;
            }
            else{
                result = num2;
            }
        }
        return result;
    }
    vector<int> asteroidCollision(vector<int>& asteroids){
        vector<int> result;
        if(asteroids.empty())
            return result;
        if(asteroids.size() == 1){
            return asteroids;
        }
        int i = 0;
        int j = 1;
        while(j < asteroids.size()){
            if(asteroids[i] * asteroids[j] < 0){
                int temp = num_ans(asteroids[i], asteroids[j]);
                if(temp != 0)
                    result.push_back(temp);
                i++; 
                j++;
            }
            else{
                result.push_back(asteroids[i]);
            }
            j++;
            i++;
        }
        return result;
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
    vector<int> result;
    result = s.asteroidCollision(array);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

