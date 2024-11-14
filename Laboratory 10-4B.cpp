/*
* Program: Laboratory 10-4B.cpp
* Author: Aanika Mishra
* Date: 11-13-2024
* Description: This program reads in a card number as 
* a string and then checks if the card is valid or not.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool isCardValid(int digits[], int size);
bool isNumeric(string s);
bool isCorrectLength(string s);

int main()
{
    string num;
    int numArr[17];
    bool done = false;

    while (!done)
    {
        cout << "Please Enter 16-Digit Credit Card # or Q to Quit: ";
        cin >> num;

        if (num == "Q")
        {
            break;
        }

        if (isNumeric(num) == true && isCorrectLength(num) == true)
        {
            for (int i = 0; i < num.length(); i++)
            {
                numArr[i] = num[i];
            }
            if (isCardValid(numArr, num.length()) == true)
            {
                cout << "Card is Valid." << endl;
            }
            else
            {
                cout << "Card is Invalid." << endl;
            }
        }
        else if (isNumeric(num) != true)
        {
            cout << "Error - Card Number Must Contain Only Digits" << endl;
        }
        else if (isCorrectLength(num) != true)
        {
            cout << "Error - Card Number Must Contain 16 Digits" << endl;
        }
    }
    


}

bool isCardValid(int digits[], int size)
{
    int sum1 = 0;
    int sum2 = 0;
    int dub;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 != 0)
        {
            sum1 += digits[size - i];
        }
        else
        {
            dub = digits[size - i] * 2;
            sum2 += (dub % 10) + (dub / 10);
        }
    }
    if ((sum1 + sum2) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isNumeric(string s)
{
    bool done = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] > 47 && s[i] < 58)
        {
            done = true;
        }
        else
        {
            done = false;
        }

    }
    return done;
}

bool isCorrectLength(string s)
{
    if (s.length() == 16)
    {
        return true;
    }
    else
    {
        return false;
    }

}