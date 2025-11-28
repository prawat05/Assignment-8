/*Write a program to determine whether a given binary tree is a BST or not*/
#include<iostream>
#include<climits>
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
bool BSTcheck(node *root , long minval , long maxval)
{
    if(root==NULL) return true;
    if(root->data<=minval || root->data>=maxval) return false;
    return BSTcheck(root->left,minval,root->data) && BSTcheck(root->right,root->data,maxval);
}
int main()
{
    node *root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(5);
    root1->right->left = new node(3);

    node *root2 = new node(7);
    root2->left = new node(5);
    root2->right = new node(9);
    root2->right->left = new node(8);
    root2->right->right = new node(6);

    if(BSTcheck(root1,INT_MIN,INT_MAX)) 
    {
        cout<<"First tree is BST"<<endl;
    }
    else 
    {
        cout<<"First tree is not BST"<<endl;
    }
    if(BSTcheck(root2,INT_MIN,INT_MAX)) 
    {
        cout<<"Second tree is BST"<<endl;
    }
    else 
    {
        cout<<"Second tree is not BST"<<endl;
    }
}
