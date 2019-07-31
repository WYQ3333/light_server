#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    int Height(Node* root){
        if(root == nullptr)
            return 0;
        int max_sum = 0;
        for(size_t i = 0; i < root->children.size(); ++i){
            int temp = Height(root->children[i]);
            if(temp > max_sum ){
                max_sum = temp;
            }
        }
        return max_sum + 1;
    }
    int maxDepth(Node* root) {
        if(root == nullptr)
            return 0;
        int result = Height(root);
        return result;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

