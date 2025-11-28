//searching a number in BST
#include<iostream>
#include<vector>
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
node* insert_BST(node *root,int val)
{
    if(!root) return new node(val);
    if(root->data<val)
    {
        root->right=insert_BST(root->right,val);
    }
    else
    {
        root->left=insert_BST(root->left,val);
    }
    return root;
}
node* BST(vector<int> &v)
{
    if(!v.size()) return nullptr;
    node *root = new node(v[0]);
    for(int i=1;i<v.size();i++)
    {
        insert_BST(root,v[i]);
    }
    return root;
}
void search(node *root , int num)
{
    while(root!=NULL && root->data!=num)
    {
        if(num<root->data) root = root->left;
        if(num>root->data) root = root->right;
    }
    if(root==NULL) 
    {
        cout<<"The given number is not present in the tree"<<endl;
    }
    else
    {
        cout<<num<<" is present in the tree"<<endl;
    }
}
int main()
{
    vector <int> v = {8,3,10,6,14,4,7,13};
    node *root = BST(v);
    search(root,15);
}
