/****************************

Author: LAKSHIT SOMANI

****************************/

#include <bits/stdc++.h>

using namespace std;

int find_numbers(string line)
{
    const vector<string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    // index, value storing
    vector<vector<int>> found_numbers;

    // find all digit numbers and store
    for (int i = 0; i < line.size(); i++)
    {
        if (isdigit(line[i]))
        {
            found_numbers.push_back({i, line[i] - '0'});
        }
    }

    // find all word numbers and store
    for (int i = 0; i < numbers.size(); i++)
    {
        int occurence = line.find(numbers[i], 0);
        while (occurence != string::npos)
        {
            found_numbers.push_back({occurence, 1 + i});
            occurence = line.find(numbers[i], occurence + 1);
        }
    }

    // // sort the vector
    vector<int> sorted_numbers;
    for (int i = 0; i < line.size(); i++)
    {
        for (int j = 0; j < found_numbers.size(); j++)
        {
            if (found_numbers[j][0] == i)
            {
                sorted_numbers.push_back(found_numbers[j][1]);
                found_numbers.erase(found_numbers.begin() + j);
            }
        }
    }

    for (int i = 0; i < sorted_numbers.size(); i++)
    {
        cout << sorted_numbers[i];
    }
    cout << " --> ";

    // compose the final number and return
    if (sorted_numbers.size() == 1)
    {
        return stoi(to_string(sorted_numbers[0]) + to_string(sorted_numbers[0]));
    }
    else
    {
        return stoi(to_string(sorted_numbers[0]) + to_string(sorted_numbers[sorted_numbers.size() - 1]));
    }
}

int main()
{
    int result = 0;
    string line;
    ifstream file("input.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << " --> ";
            int number = find_numbers(line);
            cout << number << "\n";
            cout << "-------------------\n";
            result += number;
        }
        file.close();
    }
    cout << result << "\n";
    return 0;
}