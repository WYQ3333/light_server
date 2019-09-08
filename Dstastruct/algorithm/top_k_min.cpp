#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void up_change(vector<int>& array, int begin, int end){
	int father = begin;
	int son = 2 * father + 1;
	while (son < end){
		if (son + 1 < end && array[son] > array[son + 1]){
			son++;
		}
		if (array[father] < array[son])
			return;
		else{
			swap(array[father], array[son]);
			father = son;
			son = 2 * father + 1;
		}
	}
}

int top_k(vector<int>& array, int k){
	if (array.size() < k){
		return -1;
	}
	int len = array.size() / 2 - 1;
	//建立小堆
	for (int i = len; i >= 0; --i){
		up_change(array, i, array.size());
	}
	int index = array.size() - 1;
	for (int i = 0; i < k - 1 && index >= 0; ++i){
		swap(array[0], array[index]);
		up_change(array, 0, index);
		index--;
	}
	return array[0];
}

int main(){
	int num;
	cin >> num;
    
	vector<int> array;
    unordered_set<int> s;
	for (int i = 0; i < num; ++i){
		int temp;
		cin >> temp;
		s.insert(temp);
	}
    for(auto e : s){
        array.push_back(e);
    }
	cout << top_k(array, 3) << endl;
	return 0;
}
