#include <iostream>
#include <stack>
using std::stack;

//两个栈实现一个队列
class Solution
{
public:
    void push(int node) {
        stack2.push(node);
    }

    int pop() {
        if(stack1.empty()){
            if(stack2.empty()){
                perror("queue is empty!!");
                return -1;
            }
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        int result = stack1.top();
        stack1.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
int main()
{
    return 0;
}

