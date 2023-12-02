/****************************

Author: LAKSHIT SOMANI

****************************/

#include <bits/stdc++.h>
using namespace std;

int ans = 0;
void countBalls(string line)
{
    line = line.substr(line.find(':') + 2);
    istringstream iss(line);
    string gameData;
    int maxBlue = INT_MIN, maxGreen = INT_MIN, maxRed = INT_MIN;
    while (getline(iss, gameData, ';'))
    {
        istringstream gameStream(gameData);
        string colorData;
        // int blue = 0, green = 0, red = 0;
        while (getline(gameStream, colorData, ','))
        {
            istringstream colorStream(colorData);
            int count;
            string color;
            colorStream >> count >> color;
            if (color == "blue")
                maxBlue = max(maxBlue, count);
            else if (color == "green")
                maxGreen = max(maxGreen, count);
            else if (color == "red")
                maxRed = max(maxRed, count);
        }
    }
    // cout << maxBlue << ", " << maxGreen << ", " << maxRed << "\n";
    int mul = maxBlue * maxGreen * maxRed;
    ans += mul;
}

int main()
{
    ifstream inputFile("./input.txt");
    string line;
    // int lc = 0;
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            // if (lc > 1) break;
            // lc++;
            // cout << lc << ": ";
            countBalls(line);
        }
    }
    cout << ans << "\n";
    return 0;
}