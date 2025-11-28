#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
int heightTree(node *root) //Height of a tree = 1 + max(height of left subtree, height of right subtree)
{
    int height = 0;
    if(root!=NULL)
    {
        height = 1 + max(heightTree(root->left),heightTree(root->right));
    }
    return height;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(7);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->left->left = new node(8);
    int h = heightTree(root);
    cout<<"Height of Tree "<<h<<endl;
}
