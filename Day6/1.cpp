#include <bits/stdc++.h>
using namespace std;
#define ll long long

void part1(vector<int> &tm, vector<int> &cr)
{
    ll ans = 1;
    for (int i = 0; i < 4; i++)
    {
        int x = 1;
        while (true)
        {
            int dis = (tm[i] - x) * x;
            if (dis < cr[i])
                x++;
            else
            {
                ans *= (tm[i] - (2 * x) + 1);
                break;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ifstream file("input.txt");
    string line;
    int count = 0;
    getline(file, line);
    line = line.substr(12);
    istringstream iss(line);
    vector<int> tm(4);
    string word;
    while (iss >> word)
    {
        tm[count] = stoi(word);
        count++;
    }
    getline(file, line);
    line = line.substr(12);
    istringstream iss2(line);
    vector<int> cr(4);
    count = 0;
    while (iss2 >> word)
    {
        cr[count] = stoi(word);
        count++;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << tm[i] << " " << cr[i] << endl;
    }

    part1(tm, cr);

    return 0;
}