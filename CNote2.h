#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>
#include <sstream>
#include <ctime>

using namespace std;

string month;
float amount;

fstream Amount;
fstream Months;
fstream Dates;

void amountReset()
{
    Amount.close();
    Amount.open("Amount.txt", std::fstream::out | std::fstream::in | std::fstream::app);
}

void dateReset()
{
    Dates.close();
    Dates.open("Dates.txt", std::fstream::out | std::fstream::in | std::fstream::app);
}

void monthReset()
{
    Months.close();
    Months.open("Months.txt", std::fstream::out | std::fstream::in | std::fstream::app);
}

void RESETALL()
{
    Amount.close();
    Months.close();
    Dates.close();
    Amount.open("Amount.txt", std::fstream::out | std::fstream::in | std::fstream::app);
    Months.open("Months.txt", std::fstream::out | std::fstream::in | std::fstream::app);
    Dates.open("Dates.txt", std::fstream::out | std::fstream::in | std::fstream::app);
}

template<class T>

void Verify(T x)
{
while(!cin.good())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "A number please: ";
        cin >> x;
    }
}

void SwitchM(int months)
{
    int loop = 0;
    nope:
        if(loop>0)
        {
            cout << "A month between 1-12, please: ";
            cin >> months;
        }
    switch(months)
    {
        case 1: month = "January";
            break;
        case 2: month = "February";
            break;
        case 3: month = "March";
            break;
        case 4: month = "April";
            break;
        case 5: month = "May";
            break;
        case 6: month = "June";
            break;
        case 7: month = "July";
            break;
        case 8: month = "August";
            break;
        case 9: month = "September";
            break;
        case 10: month = "October";
            break;
        case 11: month = "November";
            break;
        case 12: month = "December";
            break;
        default:
            loop++;
            goto nope;
    }
}

int CalcMonth(string month)
{
    if(month == "January") return 31;
    if(month == "February") return 28;
    if(month == "March") return 31;
    if(month == "April") return 30;
    if(month == "May") return 31;
    if(month == "June") return 30;
    if(month == "July") return 31;
    if(month == "August") return 31;
    if(month == "September") return 30;
    if(month == "October") return 31;
    if(month == "November") return 30;
    if(month == "December") return 31;
}
