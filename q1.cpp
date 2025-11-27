/*Write program using functions for binary tree traversals: Pre-order, In-order and Post
order using recursive approach.*/
#include <iostream>
using namespace std;
class node //class to make a leaf node
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
void preorder(node *root)
{
    if (root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if (root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node *root)
{
    if (root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<"Tree after preorder"<<endl;
    preorder(root);
    cout<<endl<<"Tree after Inorder"<<endl;
    inorder(root);
    cout<<endl<<"Tree after postorder"<<endl;
    postorder(root);
}



