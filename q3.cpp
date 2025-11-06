#include <iostream>
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
    Node *minNode(Node *cur)
    {
        while (cur && cur->l)
            cur = cur->l;
        return cur;
    }
    Node *del(Node *cur, int x)
    {
        if (!cur)
            return nullptr;
        if (x < cur->v)
            cur->l = del(cur->l, x);
        else if (x > cur->v)
            cur->r = del(cur->r, x);
        else
        {
            if (!cur->l)
            {
                Node *t = cur->r;
                delete cur;
                return t;
            }
            if (!cur->r)
            {
                Node *t = cur->l;
                delete cur;
                return t;
            }
            Node *s = minNode(cur->r);
            cur->v = s->v;
            cur->r = del(cur->r, s->v);
        }
        return cur;
    }
    void remove(int x) { root = del(root, x); }
    int maxDepth(Node *cur)
    {
        if (!cur)
            return 0;
        return 1 + max(maxDepth(cur->l), maxDepth(cur->r));
    }
    int minDepth(Node *cur)
    {
        if (!cur)
            return cur ? ((!cur->l) ? 1 + minDepth(cur->r) : (!cur->r) ? 1 + minDepth(cur->l)
                                                                       : 1 + min(minDepth(cur->l), minDepth(cur->r)))
                       : 0;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    if (!(cin >> m))
        return 0;
    BST b;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.insert(x);
    }
    int ops;
    cin >> ops;
    while (ops--)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            int v;
            cin >> v;
            b.insert(v);
            cout << "ok\n";
        }
        else if (s == "delete")
        {
            int v;
            cin >> v;
            b.remove(v);
            cout << "ok\n";
        }
        else if (s == "maxDepth")
            cout << b.maxDepth(b.root) << "\n";
        else if (s == "minDepth")
            cout << b.minDepth(b.root) << "\n";
    }
    return 0;
}
