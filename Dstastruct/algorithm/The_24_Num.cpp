#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	void answer(vector<int>& array, int index, vector<char>& opt, int& sum){
		if (sum == 24){
			return;
		}
		if (index >= 4){
			return;
		}
		for (size_t j = 0; j < 4 && index < 4; ++j){
			switch (opt[j]){
			case '+':
				if (array[index]){
					sum += array[index];
					if (sum == 24){
						break;
					}
					answer(array, index + 1, opt, sum);
					if (sum == 24){
						break;
					}
					sum -= array[index];
				}
				break;
			case '-':
				if (array[index]){
					if (sum == 24){
						break;
					}
					sum -= array[index];
					answer(array, index + 1, opt, sum);
					if (sum == 24){
						break;
					}
					sum += array[index];
				}
				break;
			case '*':
				if (array[index]){
					int temp = sum;
					if (sum == 24){
						break;
					}
					sum *= array[index];
					answer(array, index + 1, opt, sum);
					if (sum == 24){
						break;
					}
					sum = temp;
				}
				break;
			case '/':
				if (array[index]){
					if (sum == 24){
						break;
					}
					int temp = sum;
					sum /= array[index];
					answer(array, index + 1, opt, sum);
					if (sum == 24){
						break;
					}
					sum = temp;
				}
				break;
			}
			if (sum == 24){
				return;
			}
		}
		return;
	}
	bool The24num(vector<int>& array, vector<char>& opt){
		int sum = 0;
		answer(array, 0, opt, sum);
		if (sum == 24){
			return true;
		}
		return false;
	}

};
int main(){
	vector<int> array;
	int input;
	for (int i = 0; i < 4; ++i){
		cin >> input;
		array.push_back(input);
	}
	vector<char> opt = { '+', '-', '*', '/' };
	Solution s;
	int result = s.The24num(array, opt);
	if (result == 1){
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

