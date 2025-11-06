#include <iostream>
#include<vector>
#include<climits>
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
    vector<Node *> ns(n, nullptr);
    for (int i = 0; i < n; i++)
        if (a[i] != -1)
            ns[i] = new Node(a[i]);
    for (int i = 0; i < n; i++)
        if (ns[i])
        {
            int L = 2 * i + 1, R = 2 * i + 2;
            if (L < n)
                ns[i]->l = ns[L];
            if (R < n)
                ns[i]->r = ns[R];
        }
    return ns[0];
}
bool ok(Node *r, long long lo, long long hi)
{
    if (!r)
        return true;
    if (r->v <= lo || r->v >= hi)
        return false;
    return ok(r->l, lo, r->v) && ok(r->r, r->v, hi);
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
    cout << (ok(root, LLONG_MIN, LLONG_MAX) ? 1 : 0) << "\n";
    return 0;
}
