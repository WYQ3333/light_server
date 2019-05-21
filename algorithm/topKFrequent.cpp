#include<iostream>
#include<utility>
#include<algorithm>
#include<vector
using namespace std; 
/* 只是简单的外部声明，也没有类的引用，在VS上运行时正确，但是在其它平台上出现报错： */

/* reference to non-static member function must be called sort(temp.begin(),temp.end(),compare); */

/* 意思是sort的调用必须是静态成员，之后声明为static后就正确了。 */

/* 但是官方文档的例子没有这样的说明 */
class Solution{
public:
    static bool compare(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k){
        if(nums.empty())
            return {};
        vector<pair<int, int>> array;
        sort(nums.begin(), nums.end());
        for(size_t i = 0; i < nums.size(); ++i){
            pair<int, int> temp = make_pair(nums[i], 1);
            if(array.empty())
                array.push_back(temp);
            else if(!array.empty() && array.back().first != temp.first){
                array.push_back(temp);
            }
            else{
                array.back().second++;
            }
        }
        sort(array.begin(), array.end(), compare);
        for(size_t i = 0; i < array.size(); ++i){
            cout << array[i].first <<"--->" << array[i].second << " ";
            cout << endl;
        }
        vector<int> result;
        for(size_t i = 0; i < k; ++i){
            result.push_back(array[i].first);
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> array = { 1, 1, 1, 2, 2 };
    int k = 2;
    vector<int> result = s.topKFrequent(array, k);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << "";
    }
    cout << endl;
    return 0;
}

