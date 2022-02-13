#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input;
    string list[300];

    input.open("Day8_Input.txt");
    int orgcalc=0, rescalc=0;
    for (int i = 0; i < 300; i++)
    {
        getline(input, list[i]);
    }
    for (int i = 0 ; i < 300 ; i++)
    {
        for (int j = 0 ; j < list[i].length() ; j++)
        {
            orgcalc++;
        }
    }
    for (int i = 0 ; i < 300 ; i++)
    {
        for (int j = 0 ; j < list[i].length() ;)
        {
            if (list[i][j] == '\"') { rescalc += 2; j++; }
            else if (list[i][j] == '\\')
            {
                if (list[i][j+1] == '\\')
                {
                    rescalc++;
                    j += 2;
                }
                else if (list[i][j+1] == '\"')
                {
                    rescalc++;
                    j += 2;
                }
                else if (list[i][j+1] == 'x')
                {
                    rescalc++;
                    j += 4;
                }
            }
            else
            {
                rescalc++;
                j++;
            }
        }
    }
    input.close();
    cout << orgcalc - rescalc;
}