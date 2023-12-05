#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cardNumber = 0;
    int finalans = 0;
    vector<int> cardcopy(208, 1);
    ifstream inputFile("input.txt");
    string line;
    if (inputFile.is_open())
    {
        string winningNumbers;
        while (getline(inputFile, line))
        {
            cardNumber++;
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
            int matches = 0;
            for (auto num : mynums)
            {
                if (wns.find(num) != wns.end())
                {
                    matches++;
                }
            }
            for (int tmp = cardNumber + 1; tmp <= cardNumber + matches; tmp++)
            {
                cardcopy[tmp] += cardcopy[cardNumber];
            }
        }
        finalans = accumulate(cardcopy.begin(), cardcopy.end(), 0);
        cout << finalans << "\n";
    }

    return 0;
}