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
        rescalc += 2;
        for (int j = 0 ; j < list[i].length() ;)
        {
            if (list[i][j] == '\"')
            {
                j++; rescalc += 2;
            }
            else if (list[i][j] == '\\')
            {
                j++; rescalc += 2;
            }
            else
            {
                j++; rescalc++;
            }
        }
    }
    input.close();
    cout << rescalc - orgcalc;
}