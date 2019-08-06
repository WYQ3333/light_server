/*
 * 排序算法
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Linklist{
    int val;
    struct Linklist* next;
};

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
    //堆排序    o(nlong(n))  不稳定
    void heap(vector<int>& array, int start, int end){
        int father = start;
        int son = 2*father + 1;
        while(son < end){
            //先在左右子树中找到一个较小值
            if(son + 1 < end && array[son] < array[son + 1])
                son++;
            if(array[father] > array[son]){
                return;
            }
            else{
                int temp = array[son];
                array[son] = array[father];
                array[father] = temp;
                father = son;
                son = 2*father + 1;
            }
        }
    }
    void Heap_sort(vector<int>& array){
        if(array.empty())
            return;
        int len = array.size()/2 - 1;
        //首先进行调整，使数组成为大堆
        for(int i = len; i >= 0; --i){
            heap(array, i, array.size());
        }
        //将【0】处的元素与最后一个元素交换，在进行调整
        for(int i = array.size() - 1; i > 0; --i){
            swap(array[i], array[0]);
            heap(array, 0, i);
        }
    }

    //归并排序 o(nlog(n)) 稳定
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
    
    //希尔排序 o(nlog^2n) 不稳定
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
    //计数排序 顾名思义统计待排序数列中每个数字出现的次数。
    //填入数据结构的过程其实就是排序的过程。最后再按照统计结果覆盖原序列就行了
    //前提是知道数组的范围
    //o(n)   稳定
    void count_sort(vector<int>& array, int range){
        //range表示数组中的最大值
        vector<int> result(range + 1, 0);
        for(size_t i = 0; i < array.size(); ++i){
            result[array[i]]++;
        }
        int index = 0;
        for(size_t i = 0; i < result.size(); ++i){
            while(result[i]){
                array[index++] = i;
                result[i]--;
            }
        }
    }
    //桶排序 哈希排序,  o(n) 稳定
    //基于vector实现
    void Bucket_sort(vector<int>& array){
        if(array.empty())
            return;
        vector<vector<int>> result;
        result.resize(10);
        for(size_t i = 0; i < array.size(); ++i){
            //求桶号
            int index = array[i]%10;
            //将元素入桶
            result[index].push_back(array[i]);
        }

        //进行桶内排序
        for(size_t i = 0; i < result.size(); ++i){
            if(!result[i].empty())
                sort(result[i].begin(), result[i].end());
        }

        int index = 0;
        for(size_t i = 0; i < result.size(); ++i){
            for(size_t j = 0; j < result[i].size(); ++j){
                array[index++] = result[i][j];
            }
        }
    }
    //基数排序  o(n*k)   稳定
    //基数排序也是非比较的排序算法，对每一位进行排序，从最低位开始排序，复杂度为O(kn),
    //n为数组长度，k为数组中的数的最大的位数；
    //基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；
    //依次类推，直到最高位。有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。
    //最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。
    //基数排序基于分别排序，分别收集，所以是稳定的。
    int max_bit(vector<int>& array){
        if(array.empty())
            return 0;
        int count = 0;
        for(size_t i = 0; i < array.size(); ++i){
            int temp = array[i];
            int size = 0;
            while(temp){
                temp /= 10;
                size++;
            }
            if(size > count){
                count = size;
            }
        }
        return count;
    }
    void radix_sort(vector<int>& array){
        if(array.empty())
            return;
        int len_bit = max_bit(array);
        int num = 1;
        for(int i = 0; i < len_bit; ++i){
            vector<vector<int>> result;
            result.resize(10);
            for(size_t j = 0; j < array.size(); ++j){
                int fg = array[j]/num;
                int index = fg%10;
                result[index].push_back(array[j]);
            }

            int index = 0;
            for(size_t j = 0; j < result.size(); ++j){
                for(size_t k = 0; k < result[j].size(); ++k){
                    array[index++] = result[j][k];
                }
            }
            num *= 10;
        }
    }
};
int main()
{
    vector<int> array = { 222, 3, 5, 1, 6, 9, 0 , 4, 8 , 7 };
    algorithm_sort al;
    //al.Quick_sort_2(array, 0, array.size());
    al.radix_sort(array);
    for(size_t i = 0; i < array.size(); ++i){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}

