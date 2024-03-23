// Arrays and Structs Program 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void file_reading(string runners[5], int daily_miles[][7]);
void calculations(int miles_tot[5], double miles_avg[5], int daily_miles[][7]);
void output_table(string runners[5], int daily_miles[][7], int miles_tot[5], double miles_avg[5]);

int main()
{
    string runners[5];
    int daily_miles[5][7]{ 0 };
    int miles_tot[5]{ 0 };
    double miles_avg[5]{ 0 };
    file_reading(runners, daily_miles);
    calculations(miles_tot, miles_avg, daily_miles);
    output_table(runners, daily_miles, miles_tot, miles_avg);
}

//Reads the information from the file into arrays
void file_reading(string runners[5], int daily_miles[][7])
{
    ifstream input_file;
    string k;
    input_file.open("runners.txt");
    for (int i = 0; i <= 4; ++i)
    {
        input_file >> runners[i];
        for (int j = 0; j <= 6; ++j)
        {
            input_file >> daily_miles[i][j];
        }
        input_file.ignore(2, '\n');
    }
}

//Calculates the total miles and average miles of each athlete
void calculations(int miles_tot[5], double miles_avg[5], int daily_miles[][7])
{
    for (int i = 0; i <= 4; ++i)
    {
        for (int j = 0; j <= 6; ++j)
        {
            miles_tot[i] = daily_miles[i][j] + miles_tot[i];
        }
        miles_avg[i] = miles_tot[i] / 7;
    }
}

//Prints out all the information
void output_table(string runners[5], int daily_miles[][7], int miles_tot[5], double miles_avg[5])
{
    string day_names[9]{ "Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Total", "Avg"};
    cout << setw(15);
    for (int k = 0; k <= 8; ++k)
    {
        cout << day_names[k] << setw(5);
    }
    for (int i = 0; i <= 4; ++i)
    {
        cout << endl << runners[i];
        cout << setw((15 - (runners[i].length())));
        for (int j = 0; j <= 6; ++j)
        {
            cout << daily_miles[i][j] << setw(5);
        }
        cout << setw(5) << miles_tot[i] << setw(5) << miles_avg[i] << endl;
    }
}
