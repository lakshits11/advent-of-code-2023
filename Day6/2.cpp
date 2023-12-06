#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

void part2(ull &t, ull &c)
{
    ull ans = 1;
    ull x = 1;
    while (true)
    {
        ull dis = (t - x) * x;
        if (dis < c)
            x++;
        else
        {
            ans *= (t - (2 * x) + 1);
            break;
        }
    }
    cout << ans << "\n";

}

int main()
{
    ifstream file("input.txt");
    string line;
    int count = 0;
    getline(file, line);
    line = line.substr(12);
    istringstream iss(line);
    string tm;
    string word;
    while (iss >> word)
    {
        tm.append(word);
    }
    getline(file, line);
    line = line.substr(12);
    istringstream iss2(line);
    string cr;
    while (iss2 >> word)
    {
        cr.append(word);
    }
    ull t = 0;
    ull c = 0;
    t = stoull(tm);
    c = stoull(cr);
    part2(t, c);

    return 0;
}