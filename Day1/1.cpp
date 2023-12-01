/****************************

Author: LAKSHIT SOMANI

****************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int ans = 0;
    for (int ccc = 0; ccc < 1000; ++ccc)
    {
        int f = -1, l = -1;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                l = s[i] - '0';
                if (f == -1)
                    f = s[i] - '0';
            }
        }
        cout << ccc + 1 << " f:" << f << ", l: " << l << "\n";
        int num = f * 10 + l;
        ans += num;
    }
    cout << ans;

    return 0;
}