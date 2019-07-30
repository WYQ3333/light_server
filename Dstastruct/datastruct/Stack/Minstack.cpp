#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

class MinStack {
public:
    stack<int> data;
    stack<int> minstack;
    /** initialize your data structure here. */
    MinStack() {


    }

    void push(int x) {
        data.push(x);
        if(minstack.empty() || x <= minstack.top()){
            minstack.push(x);

        }

    }

    void pop() {
        if(data.top() == minstack.top()){
            minstack.pop();

        }
        data.pop();

    }

    int top() {
        return data.top();

    }

    int getMin() {
        return minstack.top();

    }

};
class MinStack2 {
private:
    stack<int> min_stack;
    stack<int> num_stack;
    int min_num;
public:
    /** initialize your data structure here. */
    MinStack2() 
        :min_num(INT_MAX)
    {}
        
    void push(int x) {
        if(x <= min_num){
            min_num = x;
        }
        min_stack.push(min_num);
        num_stack.push(x);
    }
        
    void pop() {
        num_stack.pop();
        min_stack.pop();
    }
        
    int top() {
        return num_stack.top();
    }
        
    int getMin() {
        return min_stack.top();
    }
    int getSize(){
        return num_stack.size();
    }
};

int main()
{
    MinStack2 ms;
    int input;
    for(int i = 0; i < 5; ++i){
        cin >> input;
        ms.push(input);
    }
    //ms.push(1);
    //ms.push(2);
    //ms.push(-1);
    //ms.push(4);
    //ms.push(5);
    while(ms.getSize()){
        cout << ms.top() << " min num " << ms.getMin() << endl;
        ms.pop();
    }
    return 0;
}

