#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool inRange(char num);

int main()
{
    ifstream inData;
    string posNumber="", negNumber="", redCheck;
    char number;
    int sum=0;
    inData.open("Day12_Input.txt");

    while(inData.eof() == 0)
    {
        inData >> number;
        if (number == '-')
        {
            inData >> number;
            while(inRange(number))
            {
                negNumber += number;
                inData >> number;
            }
            sum -= stoi(negNumber);
        }
        else if (inRange(number))
        {
            while(inRange(number))
            {
                posNumber += number;
                inData >> number;
            }
            sum += stoi(posNumber);
        }
        negNumber = "";
        posNumber = "";
    }
    cout << sum;
}

bool inRange(char num)
{
    if (num >= '0' && num <= '9')
    {
        return true;
    }
    else { return false; }
}