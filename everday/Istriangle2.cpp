#include <iostream>
#include <string>
#define ADD(x, y) ((x) + (y))
#define CMP(x, y) ((x) > (y))
int main()
{
	long a, b, c;
	while (std::cin >> a >> b >> c)
	{
		//对两边进行求和与第三遍进行比较
		if (CMP(ADD(a, b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b)) {
			std::cout << "Yes" << std::endl;
		}else {
			std::cout << "No" << std::endl;
		}
	}
	return 0;
}

