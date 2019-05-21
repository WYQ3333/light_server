#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution{
public:
    static bool cmp(string a, string b){
        int i = 0;
        for(i = 0; i < a.size() && i < b.size(); ++i){
            if(a[i] > b[i]){
                return true;
            }
            else if(a[i] == b[i]){
                i++;
            }
            else{
                return false;
            }
        }
        if(i < a.size()){
            return true;
        }
        return false;
    }
    static bool compare(pair<string, int> a, pair<string, int> b){
        return a.second < b.second;
    }

    vector<string> topKFrequent(vector<string>& nums, int k){
        if(nums.empty())
            return {};
        vector<pair<string, int>> array;
        sort(nums.begin(), nums.end(),cmp);
        /* for(size_t i = 0; i < nums.size(); ++i){ */
        /*     cout << nums[i] << " "; */
        /* } */
        //cout << endl;
        for(size_t i = 0; i < nums.size(); ++i){
            pair<string, int> temp = make_pair(nums[i], 1);
            if(array.empty())
                array.push_back(temp);
            else if(!array.empty() && array.back().first != temp.first){
                array.push_back(temp);
            }
            else{
                array.back().second++;
            }
        }
        cout << "-------------" << endl;
        stable_sort(array.begin(), array.end(), compare);
        for(size_t i = 0; i < array.size(); ++i){
            cout << array[i].first << "--> "<< array[i].second << endl;
        }
        vector<string> result;
        for(int i = array.size() -1 ; i >= 0; --i){
            if(result.size() <= k){
                result.push_back(array[i].first);
            }
        }
        return result;
    }
};
int main()
{
    vector<string> array = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"
   };
    int k = 2;
    Solution s;
    vector<string> result = s.topKFrequent(array, 4);
    cout << "---------------" << endl;
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

