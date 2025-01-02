//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

int n;
int a[MAX];
set <int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    s.insert(a[0]);
    cout << 0 << endl;
    for (int i = 1; i < n; i++)
    {
        int tmp = s.size();
        s.insert(a[i]);
        if (s.size() != tmp)
            cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}
