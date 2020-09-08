#include "CNote2.h"

int main()
{
string fileLine;    //Used for loop through file

float floatValue;   //Used as a Joker, in every operation where we need a temporary float variable

float sum;      //Used to get the sum of the users input

float MAX;  //Max value for the user per month

START:

float amountUsed = 0;    //Amount Used by user during the month

float amountLeft = 0;   //What is left of money for the current month

string date;

fstream FMAX;   //Max value is stored there

FMAX.open("MAX.txt");   // get value of
FMAX >> MAX;            // MAX and put it
FMAX.close();           // in the vector

ofstream Output;    //The final result

vector<string> VMONTHS; //Vector months
vector<string> VDATES;  //Vector Dates
vector<float> VAMOUNTS; //Vector Amounts

//------------------------Get the value of amountUsed-----------------------------------------------
        Amount.open("Amount.txt", std::fstream::out | std::fstream::in | std::fstream::app);
        Amount >> floatValue;
        VAMOUNTS.push_back(floatValue);
        while(getline(Amount, fileLine))
        {
            amountUsed += floatValue;
            Amount >> floatValue;
            VAMOUNTS.push_back(floatValue);
        }
        Amount.close();
//----------------------------------------------------------------------------------------------------




//--------------------Put date on the vector and have value of  the counter ---------------------
        Dates.open("Dates.txt");

        int c = 0;      //Counter of current date

        while (getline(Dates, fileLine))
        {   VDATES.push_back(fileLine);
            c++;
        }//cout << c;
        Dates.close();
//----------------------------------------------------------------------------------------------------



//------------------------ Put months on the vector -----------------------------------------------
        Months.open("Months.txt");
        while(getline(Months, fileLine))
            VMONTHS.push_back(fileLine);
        Months.close();
//----------------------------------------------------------------------------------------------------

//Getting the time
time_t now = time(0);
tm *Ltm = localtime(&now);
int cYear = 1900 + Ltm->tm_year;
int cDay = Ltm->tm_mday;
int cMonth = 1 + Ltm->tm_mon;


cout << "==$== Welcolme to the K-Manager ==$=="
    << "\nHere are the options you can select from:\n"
    << "\n1-Add Info"
    << "\n2-Set the Max Amount for current month"
    << "\n3-Know the Average";
cout << "\n\nWhat is your choice? [-1 to exit]\n";

cin >> floatValue;
switch((int)floatValue)
{
    case 1:
    {   float add= 0;
        Amount.open("Amount.txt", std::fstream::out | std::fstream::in | std::fstream::app);
        Months.open("Months.txt", std::fstream::out | std::fstream::in | std::fstream::app);
        Dates.open("Dates.txt", std::fstream::out | std::fstream::in | std::fstream::app);

        while(floatValue == 1)  //Calculate the amount used that day.
        {
            sum = 0;
            cout << "+ ";
            cin >> amount;
            Verify(amount);
            while(amount != 0)
            {
                Verify(amount);
                sum += amount;
                cout << "+ ";
                cin >> amount;
                Verify(amount);
            }

            cout << "\nThe amount entered was: " << fixed << sum << " [if False press 1]\n";
            cin >> floatValue;
        }                       //End of calculation

        cout << "Today's date is:\nday: "<< cDay << "\nMonth: " << cMonth << "\nYear: " << cYear << endl;
        cout << "Do you want to work with this date or to input your own?\n[1/0] input/no\t\t\t";
        cin >> floatValue;
        if(floatValue == 1)
        {
//----------------------------Pick a month and initialize the date maximum----------------------------
        cout << "Pick the month [1-12]";
        cout << "\n1: January\n2: February\n3: March\n4: April\n5: May\n6: June"
        << "\n7: July\n8: August\n9: September\n10: October\n11: November\n12: December";
        cout << "\n\nMonth: ";
        cin >> floatValue;
        SwitchM(floatValue);
        int dateMax = CalcMonth(month);
        //cout << "dateMax = " << dateMax << endl;
//----------------------------------    Choose date      ---------------------------------------------
        cout << "Date: ";
        cin >> date;
        stringstream x(date);
        x >> floatValue;
        while(floatValue<1 || floatValue>dateMax)
            {
            cout << "Between 1 and " << dateMax <<" please: ";
            cin >> date;
            stringstream x(date);
            x >> floatValue;
            }
//----------------------------------------------------------------------------------------------------
        }
        else
        {
            date = to_string(cDay);
            SwitchM(cMonth);
        }


        if(c==0)    //Case: Never used program before
        {   RESETALL();
            Amount << sum << endl;
            Months << month << endl;
            Dates << date << endl;
            VDATES.push_back(date);
            VMONTHS.push_back(month);
            return 0;
        }

        else if(month == VMONTHS[c-1] && date == VDATES[c-1])   //Case: if date-month inputted are same
        {   Amount.close();
            Amount.open("Amount.txt", std::fstream::out | std::fstream::in);
            while(getline(Amount, fileLine))
            {   Amount >> add;  }

            sum += add;
            cout << "New sum = " << sum;
            Amount.close();
            Amount.open("Amount.txt", std::fstream::out | std::fstream::in);
            int i = 0;
            while(getline(Amount, fileLine))
            {
                if(i == c-1){
                    Amount.seekg(-1, ios_base::cur);
                    Amount << fixed << setprecision(2) << sum << endl;}
                i++;

            }
        }

        else        //Case: date/month different from before
        {
            RESETALL();
            Amount << sum << endl;
            Months << month << endl;
            Dates << date << endl;
            VDATES.push_back(date);
            VMONTHS.push_back(month);
            c++;    // New day
        }
        VAMOUNTS.push_back(sum);
        RESETALL();

//--------------------------------      Final Product       ----------------------------------
        Output.open("Output.txt");
        string lastMonth="";
        for(int i=0; i <= c-1; i++)
        {
            Amount >> fileLine;
            Output << setw(6) << fixed << setprecision(2) << fileLine;
            Dates >> fileLine;
            Output << setw(6) << fixed << setprecision(2) << fileLine;
            Months >> fileLine;
            if(lastMonth != fileLine)
            {   lastMonth = fileLine;
                Output<< setw(10) << fileLine << endl;
            }
            else
            {   Output<< " \t "<< endl;}
        }
        Output.close();
//--------------------------------------------------------------------------------------------

        cout << "\n\t\tMAIN MENU[1] --- QUIT[Any]\n";
        cin >> floatValue;
        if(floatValue == 1)
            goto START;
        else
            return 0;
    break;
    }

    case 2:
    {   if(MAX>0)
        {
            cout << "MAX value: " << MAX;
            cout << "\nNew Value: ";
            cin >> MAX;
            Verify(MAX);
            while(MAX<0)
            {
                cout << "MAX shouldn't be negative, RESET: ";
                cin >> MAX;
            }

            cout << "\nNew MAX value Updated: " << MAX;
            FMAX.open("MAX.txt");
            FMAX << MAX;
            FMAX.close();
            cout << "\n\t\tMAIN MENU[1] --- QUIT[Any]\n";
            cin >> floatValue;
            if(floatValue == 1)
                goto START;
            else
                return 0;
            break;
        }
        cout << "Value for MAX: ";
        cin >> MAX;
        Verify(MAX);
        while(MAX<0)
        {
            cout << "MAX shouldn't be negative, RESET: ";
            cin >> MAX;
            Verify(MAX);
        }
        cout << "\nMAX value Updated: " << MAX;
        FMAX.open("MAX.txt");
        FMAX << MAX;
        FMAX.close();

        cout << "\n\t\tMAIN MENU[1] --- QUIT[Any]\n";
        cin >> floatValue;
        if(floatValue == 1)
            goto START;
        else
            return 0;

        break;
    }

    case 3:
    {
        monthReset();
        string lastMonth="";
        amountUsed = 0;
        for(int i=1; i <= c; i++)
        {
            Months >> fileLine;
            if(i==0)
                lastMonth=fileLine;
            //cout << "Amount is " << fixed << setprecision(2) << VAMOUNTS[i-1]<< endl;
            if(lastMonth != fileLine && i != 0)
            {
                lastMonth = fileLine;
                amountUsed = 0;
                amountUsed += VAMOUNTS[i-1];
            }
            else
            {   amountUsed += VAMOUNTS[i-1];}
        }

        amountLeft = MAX - amountUsed;  //Calculate amount left to use

        cout << "\nMaximum amount: " << fixed << setprecision(2) <<  MAX;
        cout << "\nAmount spent so far: " << amountUsed;

        if(amountLeft < 0)
            cout << "\nYou already exceeded the maximum by " << (amountLeft*-1) << " yuan.";
        else
            cout << "\nYou can still use: " << amountLeft << " Yuan";

        stringstream x(VDATES[c-1]);
        int currentDate = 0;
        x >> currentDate;

        floatValue = CalcMonth(VMONTHS[c-1])- currentDate;  // Remaining days

        cout << "\n\n\nDays remaining:    " << setprecision(0) << floatValue;
        cout << "\nDate:              " << VDATES[c-1];
        cout << "\nMonth:             " << VMONTHS[c-1];
        cout << "\nDays in the month: " << CalcMonth(VMONTHS[c-1]);

        float average;
        average = amountLeft/floatValue;

        if(amountLeft < 0)
            cout << "\nYou should stop using money lowl.\n";
        else
        {
            cout << "\n\nYou should be spending " << setprecision(2) << average << " per day";
            if(average - amountUsed >= 0)
                cout << "\nYou can still use " << average - amountUsed << " yuan for today.\n\n";
        }


        cout << "\n\t\tMAIN MENU[1] --- QUIT[Any]\n";
        cin >> floatValue;
        if(floatValue == 1)
            goto START;
        else
            return 0;
        break;
}
    case 4:

    break;

    case -1:
    break;
}

return 0;
}


