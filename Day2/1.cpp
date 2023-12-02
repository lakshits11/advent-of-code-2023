/****************************

Author: LAKSHIT SOMANI

****************************/

#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void countBalls(string line)
{
    istringstream iss(line);
    string gameData;
    string gameId;
    getline(iss, gameId, ':');
    string id = gameId.substr(gameId.find(" ") + 1);
    // cout << "Game ID: " << gameId << endl;
    while (getline(iss, gameData, ';'))
    {
        istringstream gameStream(gameData);
        string colorData;
        int blue = 0, green = 0, red = 0;
        while (getline(gameStream, colorData, ','))
        {
            istringstream colorStream(colorData);
            int count;
            string color;
            colorStream >> count >> color;
            if (color == "blue")
                blue += count;
            else if (color == "green")
                green += count;
            else if (color == "red")
                red += count;
        }
        if (blue > 14 || green > 13 || red > 12)
            return;
    }
    ans += stoi(id);
}

int main()
{
    ifstream inputFile("input.txt");
    string line;
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            countBalls(line);
        }
    }
    cout << ans << "\n";
    return 0;
}