//searching the maximum element in BST
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
void searchMAX(node *root)
{
    int max;
    while(root!=NULL)
    {
        max = root->data;
        root = root->right;
    }
    cout<<"The maximum element is "<<max<<endl;
}
int main()
{
    vector <int> v = {8,3,10,6,14,4,7,13};
    node *root = BST(v);
    searchMAX(root);
}