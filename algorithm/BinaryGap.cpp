#include <iostream>
using namespace std;
//& 和&& 的优先级
class Solution {
public:
	int binaryGap(int N) {
		int count = 0;
		int max_len = 0;
		while(N){
			int temp = N & 1;
			if(count == 0 && temp == 1){
				count++;
			}
			else if(count != 0 && temp == 1){
				count++;
				if(count > max_len){
					max_len = count;
				}
				count = 1;
			}
			else if(count != 0 && temp == 0){
				count++;
			}
			if(count > max_len){
				max_len = count;
			}
			N = N >> 1;
		}
		return max_len - 1;
	}
};
//优先级的问题，结合性
class Solution_false {
public:
    int binaryGap(int N) {
        int count = 0;
        int max_len = 0;
        while(N){
            cout << " N " << N  << endl;
            if(count == 0 && N&1 == 1){
                count++;
            }
            else if(count != 0 && N&1 == 1){
                count++;
                if(count > max_len){
                    max_len = count;
                }
                count = 1;
            }
            else if(count != 0){
                count++;
            }
            if(count > max_len){
                max_len = count;
            }
            cout << " count " << count << " max " << max_len << endl;
            N = N >> 1;
        }
        return max_len - 1;
    }
};

int main()
{
    Solution s;
    int input;
    cin >> input;
    cout << s.binaryGap(input) << endl;
    return 0;
}

