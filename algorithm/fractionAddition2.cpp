#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string fractionAddition(string expression) {
		int index = 0, expressionSize = expression.size();
		long resNumerator, resDenominator;//结果的分子、分母
		//获取第一个分数
		if (expression[0] == '-') {
			index += 1;
		}
		//获取分子
		resNumerator = expression[index++] - '0';
		if (expression[index] != '/') {//可能分子含有两位数
			resNumerator = resNumerator * 10 + expression[index++] - '0';
		}
		index += 1;//跳过分数线
		//获取分母
		resDenominator = expression[index++] - '0';
		if (index < expressionSize && expression[index] >= '0' && expression[index] <= '9') {//可能分母含有两位数
			resDenominator = resDenominator * 10 + expression[index++] - '0';
		}
		if (expression[0] == '-') {//第一个符号是负号，注意只需要添加到分子即可，不能添加到分母
			resNumerator = -resNumerator;
		}
        //以上是对第一个分数的操作
		while (index < expressionSize) {
			char operatorCh = expression[index++];//操作符
			//获取下一个分子
			int tempNumerator = expression[index++] - '0';
			if (expression[index] != '/') {//可能分子含有两位数
				tempNumerator = tempNumerator * 10 + expression[index++] - '0';
			}
			index += 1;//跳过分数线
			//获取下一个分母
			int tempDenominator = expression[index++] - '0';
			if (index < expressionSize && expression[index] >= '0' && expression[index] <= '9') {//可能分母含有两位数
				tempDenominator = tempDenominator * 10 + expression[index++] - '0';
			}
			if (operatorCh == '-') {//符号是负号，注意只需要添加到分子即可，不能添加到分母
				tempNumerator = -tempNumerator;
			}
			//计算
			resNumerator = resNumerator * tempDenominator + resDenominator * tempNumerator;
			resDenominator *= tempDenominator;
			if (resNumerator == 0) {//如果分子为0，则分母需要变成1
				resDenominator = 1;
			}
			else {
				int factor = maxCommonFactor(resNumerator, resDenominator);//寻找最大公因数
				resNumerator /= factor;//化简约分
				resDenominator /= factor;
			}
		}
		return to_string(resNumerator) + "/" + to_string(resDenominator);
	}
	//辗转向除法
	int maxCommonFactor(long numOne, long numTwo) {
		if (numOne < 0) {
			return maxCommonFactor(-numOne, numTwo);
		}
		if (numOne < numTwo) {
			return maxCommonFactor(numTwo, numOne);
		}
		long tempRes;
		while (numOne % numTwo != 0) {
			tempRes = numOne % numTwo;
			numOne = numTwo;
			numTwo = tempRes;
		}
		return numTwo;
	}
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

