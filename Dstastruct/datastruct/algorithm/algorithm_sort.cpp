/*
 * 排序算法
 */

#include <iostream>
#include <vector>
using namespace std;

class algorithm_sort{
public:
    //冒泡排序  平均时间复杂度：o(n^2) 最好时间复杂度o(n)   稳定
    void Bubble_sort(vector<int>& array, int begin, int end){
        if(array.empty())
            return;
        //flag用来标记是否进行了交换，如果没有，直接退出即可
        int flag = 1;
        for(int i = begin; i < end && (flag == 1); ++i){
            flag = 0;
            for(int j = begin + 1; j < end; ++j){
                if(array[j-1] > array[j]){
                    flag = 1;
                    int temp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp;
                }
            }
        }
    }
    //选择排序 平均时间复杂度o(n^2) 最好时间复杂度o(n) 不稳定
    void Select_sort(vector<int>& array, int begin, int end){
        if(array.empty())
            return;
        for(int i = begin; i < end; ++i){
            int min_num = array[i];
            int index = i;
            for(int j = i + 1; j < end; ++j){
                if(array[j] < min_num){
                    min_num = array[j];
                    index = j;
                }
            }
            if(i != index && index < end){
                int temp = array[i];
                array[i] = array[index];
                array[index] = temp;
            }
        }
    }
    //插入排序 平均时间复杂度 o(n^2)   稳定
    void Insert_sort(vector<int>& array, int begin, int end){
        if(array.empty())
            return;
        for(int i = begin + 1; i < end; ++i){
            int temp = array[i];
            int j = i - 1;
            for(; j >= 0; --j){
                if(temp < array[j]){
                    array[j + 1] = array[j];
                }
                else{
                    break;
                }
            }
            array[j + 1] = temp;
        }
    }
    //快速排序  平均时间复杂度 o( nlog(n) )    不稳定
    void Quick_sort(vector<int>& arr, int bgn, int end){
        if (bgn >= end - 1)
            return;
        int lindex = bgn;
        int rindex = end - 1;
        int temp = arr[lindex];
        while (lindex < rindex)
        {
            //从后往前找一个比temp小的放到基准值的位置
            while (lindex < rindex)
            {
                if (arr[rindex] < temp)
                {
                    arr[lindex++] = arr[rindex];
                    break;
                }
                --rindex;
            }

            //从前往后找一个比基准值大的放到适合的位置
            while (lindex < rindex)
            {
                if (arr[lindex] >= temp)
                {
                    arr[rindex--] = arr[lindex];
                    break;
                }
                ++lindex;
            } 
        }
        //将基准值放到适合的位置
        arr[lindex] = temp;
        Quick_sort(arr, bgn, lindex);
        Quick_sort(arr, rindex + 1, end);//数组arr空or仅有一个元素则退出
    }

    //左闭右开区间
    int partion(vector<int>& array, int begin, int end){
        int left = begin;
        int right = end - 1;
        int temp = array[end - 1];
        while(left < right){
            while(left < right && array[left] < temp){
                left++;
            }
            while(left < right && array[right] > temp){
                right--;
            }
            int t = array[left];
            array[left] = array[right];
            array[right] = t;
        }
        array[left] = temp;
        return left;
    }
    void Quick_sort_2(vector<int>& array, int begin, int end){
        if(begin >= end)
            return;
        int index  = partion(array, begin, end);
        Quick_sort_2(array, begin, index);
        //此处必须是index+1,因为index的位置已经是正确的，如果传入index会出错
        Quick_sort_2(array, index + 1, end);
    }
    //堆排序
    
    //归并排序
    vector<int> merge(vector<int> front, vector<int> back){
        vector<int> res;
        size_t first = 0;
        size_t second = 0;
        while(first < front.size() && second < back.size()){
            if(front[first] < back[second]){
                res.push_back(front[first++]);
            }
            else if(front[first] == back[second]){
                res.push_back(front[first++]);
                res.push_back(back[second++]);
            }
            else{
                res.push_back(back[second++]);
            }
        }
        while(first < front.size()){
            res.push_back(front[first++]);
        }
        while(second < back.size()){
            res.push_back(back[second++]);
        }
        return res;
    }
    vector<int> Merge_sort(vector<int>& array){
        int s = array.size();
        if(s < 2){
            return array;
        }
        int mid = s/2;
        vector<int> front(array.begin(), array.begin() + mid);
        vector<int> back(array.begin() + mid, array.end());
        return merge(Merge_sort(front), Merge_sort(back));
    }
    
    //希尔排序
    void shell(vector<int>& array, int beg, int gap){
        for(int i = beg + gap; i < array.size(); i+=gap ){
            int temp = array[i];
            int j = i - gap;
            while(j >= 0 && array[j] > temp){
                array[j + gap] = array[j];
                j -= gap;
            }
            array[j + gap] = temp;
        }
    }
    void shell_sort(vector<int>& array){
        if(array.empty())
            return;
        int gap = array.size()/2;
        while(gap > 0){
            int beg = gap - 1;
            while(beg >= 0){
                shell(array, beg, gap);
                beg--;
            }
            gap /= 2;
        }
    }
    //计数排序
    
    //桶排序
    
    //基数排序
};
int main()
{
    vector<int> array = { 2, 3, 5, 1, 6, 9, 0 , 4, 8 , 7 };
    algorithm_sort al;
    //al.Quick_sort_2(array, 0, array.size());
    vector<int> result;
    al.shell_sort(array);
    for(size_t i = 0; i < array.size(); ++i){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}

