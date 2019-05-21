#include <iostream>
#include<set>
#include<vector>
using  namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        set<int> set1(nums1.begin(),nums1.end());
        set<int> set2(nums2.begin(),nums2.end());
        auto s1 = set1.begin();
        auto s2 = set2.begin();
        while(s1 != set1.end() && s2 != set2.end()){
            if(*s1 > *s2){
                s2++;
            }else if ( *s1 < *s2){
                s1++;
            }else{
                v.push_back(*s1);
                s1++;
                s2++;
            }
        }
        return v;
    }
};
int main()
{
    vector<int> array = {1, 2, 2, 1};
    vector<int> b = {2, 2};
    Solution s;
    vector<int> result = s.intersection(array, b);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] <<" ";
    }
    cout << endl;
    return 0;
}

