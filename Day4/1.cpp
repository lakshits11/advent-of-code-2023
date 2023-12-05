#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l = 0;
    int finalans = 0;
    ifstream inputFile("input.txt");
    string line;
    if (inputFile.is_open())
    {
        string winningNumbers;
        while (getline(inputFile, line))
        {
            // if (l > 0) break;
            // l++;
            line = line.substr(10);
            istringstream iss(line);
            string part;
            getline(iss, part, '|');
            istringstream numbersStream(part);
            unordered_set<int> wns;
            int num;
            while (numbersStream >> num)
            {
                wns.insert(num);
            }
            unordered_set<int> mynums;
            while (iss >> num)
            {
                mynums.insert(num);
            }
            double points = 0.5;
            for (auto num : mynums)
            {
                if (wns.find(num) != wns.end())
                    points *= 2;
            }
            if (points == 0.5) points = 0;
            finalans += (int)points;
        }
        cout << finalans << "\n";
    }

    return 0;
}