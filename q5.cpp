#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
    string ord;
    cin >> ord;
    bool asc = (ord == "asc");
    if (asc)
    {
        make_heap(a.begin(), a.end());
        vector<int> out;
        while (!a.empty())
        {
            pop_heap(a.begin(), a.end());
            out.push_back(a.back());
            a.pop_back();
        }
        reverse(out.begin(), out.end()); // because default heap is max-heap
        for (int x : out)
            cout << x << " ";
        cout << "\n";
    }
    else
    {
        make_heap(a.begin(), a.end(), greater<int>());
        vector<int> out;
        while (!a.empty())
        {
            pop_heap(a.begin(), a.end(), greater<int>());
            out.push_back(a.back());
            a.pop_back();
        }
        for (int x : out)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}

