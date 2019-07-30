#include <iostream>
#include <stack>
using namespace std;

/*
 *用两个栈实现一个队列
 */


class twostack_queue{
public:
    bool Push(int data){
        second.push(data);
        return true;
    }
    bool Pop(){
        if(first.empty()){
            if(second.empty()){
                perror("queue is emmpty!!!");
                return false;
            }
            while(second.size()){
                first.push(second.top());
                second.pop();
            }
        }
        first.pop();
        return true;
    }
    int Top(){
        if(first.empty()){
            if(second.empty()){
                perror("queue is empty!!");
                return -1;
            }
            while(second.size()){
                first.push(second.top());
                second.pop();
            }
        }
        return first.top();
    }
    bool Isempty(){
        if(first.empty() && second.empty()){
            return true;
        }
        return false;
    }
    int Size(){
        return first.size() + second.size();
    }
private:
    stack<int> first;
    stack<int> second;
};

int main()
{
    twostack_queue tq;
    cout << "isempty " << tq.Isempty() << endl;
    cout << "size " << tq.Size() << endl;
    tq.Push(1);
    tq.Push(2);
    tq.Push(4);
    tq.Push(3);
    tq.Push(5);
    cout << "isempty " << tq.Isempty() << endl;
    cout << "size " << tq.Size() << endl;
    while(tq.Size()){
        cout << tq.Top() << " ";
        tq.Pop();
    }
    cout << endl;
    return 0;
}

