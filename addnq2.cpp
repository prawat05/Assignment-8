
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
vector<vector<int>> levelorder(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    return ans;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            if (temp != NULL)
            {
                level.push_back(temp->data);
                q.push(temp->left);
                q.push(temp->right);
            }
            else
            {
                level.push_back(INT_MIN); //pushing NULL in absence of children
            }
        }
        int realNodes = 0;
        for (int i = 0; i < level.size(); i++)
        {
            if (level[i] != INT_MIN) realNodes++;
        }
        if (realNodes == 0) break;
        ans.push_back(level);
    }
    return ans;
}
void print(vector<vector<int>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            if (ans[i][j] == INT_MIN)
                cout << "null ";
            else
                cout << ans[i][j] << " ";
        }
    }
}
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

int main()
{
    node *root = new node(3);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);
    cout << "Original Tree order :- " << endl;
    vector<vector<int>> ans = levelorder(root);
    print(ans);
    cout <<endl<< "Sum of all left leaf nodes:- "<<endl;
    int x = sumOfLeftLeaves(root);
    cout<<x;
}
