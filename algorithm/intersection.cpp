#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        if(nums1.empty() || nums2.empty())
            return {};
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int index1 = 0;
        int index2 = 0;
        while(index1 < nums1.size() && index2 < nums2.size()){
            if(nums1[index1] < nums2[index2]){
                index1++;
            }
            else if(nums1[index1] > nums2[index2]){
                index2++;
            }
            else if(nums1[index1] == nums2[index2]){
                if(result.empty()){
                    result.push_back(nums1[index1]);
                }
                else if(!result.empty() && nums1[index1] != result.back()){
                    result.push_back(nums1[index1]);
                }
                index1++;
                index2++;
            }
        }
        while(index1 < nums1.size()){
            if(nums1[index1] == nums2[nums2.size() - 1]){
                if(!result.empty() && nums1[index1] != result.back())  
                    result.push_back(nums1[index1]);
                else if(result.empty()){
                    result.push_back(nums1[index1]);
                }
            }
            index1++;
        }
        while(index2 < nums2.size()){
            if( nums2[index2] == nums1[nums1.size() - 1]){
                if(!result.empty() && nums2[index2] != result.back())  
                    result.push_back(nums2[index2]);
                else if(result.empty())
                    result.push_back(nums2[index2]);
            }
            index2++;
        }
        cout << result.size() << endl;
        return result;
    }
};

class Solution1{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        if(nums1.empty() || nums2.empty())
            return {};
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int index1 = 0;
        int index2 = 0;
        while(index1 < nums1.size() && index2 < nums2.size()){
            if(nums1[index1] < nums2[index2]){
                index1++;
            }
            else if(nums1[index1] > nums2[index2]){
                index2++;
            }
            else if(nums1[index1] == nums2[index2]){
                if(result.empty()){
                    result.push_back(nums1[index1]);
                }
                else if(!result.empty() && nums1[index1] != result.back()){
                    result.push_back(nums1[index1]);
                }
                index1++;
                index2++;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> array1 = {4, 5 , 9};
    vector<int> array2 = {6,7, 8};
    Solution s;
    vector<int> answer = s.intersection(array1, array2);
    for(size_t i = 0; i < answer.size(); ++i){
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}

