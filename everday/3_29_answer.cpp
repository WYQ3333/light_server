#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		//超过一半的数排序之后必然排在中间
		int middle = gifts[n / 2];
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			//统计排在中间的数的个数
			if(gifts[i] == middle)
			{
				count++;
			}
		}
		//如果个数大于一半，则存在超过一半的数
		if(count > n / 2)
			return middle;
		else
			return 0;
	}
};


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

