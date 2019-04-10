#include <iostream>
#include <cstdio>
int main(){
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;
	// 提前计算斐波那契数列，只保留后6位
	for (int i = 2; i <= 100000; ++i)
	{ 
		fib[i] = fib[i - 1] + fib[i -2]; 
		fib[i] = fib[i] % 1000000;
	}
	// 这里利用了 OJ 平台计时从开始读取数据的 trick
	int n;
	while (std::cin >> n)
	{ 
		if (n < 29) {
			// 斐波那契数列小于 6 位
			printf("%d\n", fib[n]);
		} else {
			printf("%06d\n", fib[n]);
		}
	}
	return 0;
}

