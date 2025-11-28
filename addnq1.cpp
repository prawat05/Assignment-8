/*Given the root of a binary tree, return the sum of all left leaves. A leaf is a node with no
children. A left leaf is a leaf that is the left child of another node.*/

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
int sumOfLeftLeaves(node* root) 
{
    if (root == NULL) return 0;
    int sum = 0;

    if (root->left != NULL && root->left->left == NULL &&  root->left->right == NULL) // if left child exists AND that left child is a leaf
    {
        sum = sum + root->left->data;
    }
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);     // recurse left and right
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
