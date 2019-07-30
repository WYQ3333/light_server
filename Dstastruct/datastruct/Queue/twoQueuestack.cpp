#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> temp1;
    queue<int> temp2;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
       temp2.push(x); 
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(temp1.size() == 0 && temp2.size() == 0){
            return -1;
        }
        while(temp2.size() != 1){
            int result;
            result = temp2.front();
            temp1.push(result);
            temp2.pop();
        }
        int result = temp2.front();
        temp2.pop();
        while(temp1.size()){
            temp2.push(temp1.front());
            temp1.pop();
        }
        return result;
    }

    /** Get the top element. */
    int top() {
        //int result;
        //while(temp2.size() != 1){
        //    temp1.push(temp2.front());
        //    temp2.pop();
        //}
        //result = temp2.front();
        //temp2.pop();
        //temp1.push(result);
        //while(temp1.size()){
        //    temp2.push(temp1.front());
        //    temp1.pop();
        //}
        int result = temp2.back();
        return result;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        if(temp1.size() == 0 && temp2.size() == 0){
            return true;
        }
        return false;
    }
};
int main()
{
    MyStack ms;
    cout << ms.empty() << endl;
    cout << "-----------------------" << endl;
    for(int i = 0; i < 5; i++){
        int input;
        cin >> input;
        ms.push(input);
    }
    while(!ms.empty()){
        cout << ms.pop() << " ";
    }
    cout << endl;
    return 0;
}

