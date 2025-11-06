#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cmds;
    if (!(cin >> cmds))
        return 0;
    vector<int> a;
    while (cmds--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int v;
            cin >> v;
            a.push_back(v);
            push_heap(a.begin(), a.end(), greater<int>());
            cout << "ok\n";
        }
        else if (s == "pop")
        {
            if (a.empty())
                cout << "empty\n";
            else
            {
                pop_heap(a.begin(), a.end(), greater<int>());
                cout << a.back() << "\n";
                a.pop_back();
            }
        }
        else if (s == "top")
        {
            if (a.empty())
                cout << "empty\n";
            else
                cout << a.front() << "\n";
        }
        else if (s == "size")
            cout << a.size() << "\n";
    }
    return 0;
}
