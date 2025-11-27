#include <iostream>
#include <climits>
using namespace std;
struct Node
{
    int v;
    Node *l;
    Node *r;
    Node(int x) : v(x), l(nullptr), r(nullptr) {}
};
struct BST
{
    Node *root = nullptr;
    Node *ins(Node *cur, int x)
    {
        if (!cur)
            return new Node(x);
        if (x < cur->v)
            cur->l = ins(cur->l, x);
        else if (x > cur->v)
            cur->r = ins(cur->r, x);
        return cur;
    }
    void insert(int x) { root = ins(root, x); }
    Node *searchRec(Node *cur, int x)
    {
        if (!cur)
            return nullptr;
        if (cur->v == x)
            return cur;
        return x < cur->v ? searchRec(cur->l, x) : searchRec(cur->r, x);
    }
    bool searchIter(int x)
    {
        Node *cur = root;
        while (cur)
        {
            if (cur->v == x)
                return true;
            cur = x < cur->v ? cur->l : cur->r;
        }
        return false;
    }
    int maximum()
    {
        Node *cur = root;
        if (!cur)
            return INT_MIN;
        while (cur->r)
            cur = cur->r;
        return cur->v;
    }
    int minimum()
    {
        Node *cur = root;
        if (!cur)
            return INT_MAX;
        while (cur->l)
            cur = cur->l;
        return cur->v;
    }
    int successor(int x)
    {
        Node *cur = root;
        Node *succ = nullptr;
        while (cur && cur->v != x)
        {
            if (x < cur->v)
            {
                succ = cur;
                cur = cur->l;
            }
            else
                cur = cur->r;
        }
        if (!cur) return INT_MIN;
        if (cur->r)
        {
            cur = cur->r;
            while (cur->l)
                cur = cur->l;
            return cur->v;
        }
        return succ ? succ->v : INT_MIN;
    }
    int predecessor(int x)
    {
        Node *cur = root;
        Node *pre = nullptr;
        while (cur && cur->v != x)
        {
            if (x > cur->v)
            {
                pre = cur;
                cur = cur->r;
            }
            else
                cur = cur->l;
        }
        if (!cur) return INT_MIN;
        if (cur->l)
        {
            cur = cur->l;
            while (cur->r)
                cur = cur->r;
            return cur->v;
        }
        return pre ? pre->v : INT_MIN;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    if (!(cin >> m))
        return 0;
    BST t;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        t.insert(x);
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int v;
            cin >> v;
            cout << (t.searchRec(t.root, v) ? "Found" : "NotFound") << "\n";
        }
        else if (type == 2)
            cout << t.maximum() << "\n";
        else if (type == 3)
            cout << t.minimum() << "\n";
        else if (type == 4)
        {
            int v;
            cin >> v;
            int s = t.successor(v);
            if (s == INT_MIN)
                cout << "-1\n";
            else
                cout << s << "\n";
        }
        else if (type == 5)
        {
            int v;
            cin >> v;
            int p = t.predecessor(v);
            if (p == INT_MIN)
                cout << "-1\n";
            else
                cout << p << "\n";
        }
    }
    return 0;
}
