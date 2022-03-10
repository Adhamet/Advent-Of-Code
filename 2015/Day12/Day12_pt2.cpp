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
        breakpoint: if (number == '{')
        {
            while (number != '}')
            {
                inData >> number;
                redCheck += number;
            }
            for (int i = 0; i < redCheck.length()-2; i++)
            {
                if (redCheck[i] == 'r' && redCheck[i+1] == 'e' && redCheck[i+2] == 'd' )
                {
                    goto breakpoint;
                }
            }
            for (int i = 0; ;)
            {
                if (redCheck[i] == '-')
                {
                    while (inRange(redCheck[i+1]))
                    {
                        negNumber += redCheck[i+1];
                        i++;
                        if (i == redCheck.length())
                        {
                            break;
                        }
                    }
                    sum -= stoi(negNumber);
                }
                else if (inRange(redCheck[i]))
                {
                    while (inRange(redCheck[i]))
                    {
                        posNumber += redCheck[i];
                        i++;
                        if (i == redCheck.length())
                        {
                            break;
                        }
                    }
                    sum += stoi(posNumber);
                }
                else 
                { 
                    i++; 
                    if (i == redCheck.length())
                    {
                        break;
                    } 
                }
            }

        }
        else if (number == '-')
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