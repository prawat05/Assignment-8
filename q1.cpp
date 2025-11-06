/*Write program using functions for binary tree traversals: Pre-order, In-order and Post
order using recursive approach.*/
#include <iostream>
#include<vector>
using namespace std;
struct Node
{
    int v;
    Node *l;
    Node *r;
    Node(int x) : v(x), l(nullptr), r(nullptr) {}
};
Node *build(const vector<int> &a)
{
    if (a.empty() || a[0] == -1)
        return nullptr;
    int n = a.size();
    vector<Node *> nodes(n, nullptr);
    for (int i = 0; i < n; i++)
        if (a[i] != -1)
            nodes[i] = new Node(a[i]);
    for (int i = 0; i < n; i++)
        if (nodes[i])
        {
            int L = 2 * i + 1, R = 2 * i + 2;
            if (L < n)
                nodes[i]->l = nodes[L];
            if (R < n)
                nodes[i]->r = nodes[R];
        }
    return nodes[0];
}
void pre(Node *r, vector<int> &o)
{
    if (!r)
        return;
    o.push_back(r->v);
    pre(r->l, o);
    pre(r->r, o);
}
void ino(Node *r, vector<int> &o)
{
    if (!r)
        return;
    ino(r->l, o);
    o.push_back(r->v);
    ino(r->r, o);
}
void post(Node *r, vector<int> &o)
{
    if (!r)
        return;
    post(r->l, o);
    post(r->r, o);
    o.push_back(r->v);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Node *root = build(a);
    vector<int> p, i, o;
    pre(root, p);
    ino(root, i);
    post(root, o);
    for (int x : p)
        cout << x << " ";
    cout << "\n";
    for (int x : i)
        cout << x << " ";
    cout << "\n";
    for (int x : o)
        cout << x << " ";
    cout << "\n";
    return 0;
}
