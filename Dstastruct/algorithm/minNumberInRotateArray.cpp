
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        int left = 0;
        int right = rotateArray.size() - 1;
        //log(n)时间复杂度
        //因为是旋转数组，因此可以利用二分法进行查找，
        //定义两个指针left 和 right
        //如果right 小于 mid, 则说明最小值肯定在mid的后面或者是mid本身 left = mid
        //如果right 大于mid，则说明最小值在mid的前面或者是mid本身 right = mid;
        //如果right == mid, 另right--,因为非递减中值有可能相等
        while(rotateArray[left] >= rotateArray[right]){
            int mid = left + (right - left)/2;
            if(rotateArray[right] < rotateArray[mid]){
                left = mid;
            }
            else if(rotateArray[right] == rotateArray[mid]){
                right = right - 1;
            }
            else{
                right = mid;
            }
        }
        return rotateArray[left];
    }


    int minNumberInRotateArray2(vector<int> array) {
        //O(n)时间复杂度
        sort(array.begin(), array.end());
        return array[0];

    }
};

int main()
{
    return 0;
}

