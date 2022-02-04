#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream INPUT;
    INPUT.open("Day5_Input.txt");
    int prop1=0,prop2=0,nice=0;
    char input[1000][16];
    for ( int row = 0; row < 1000; row++ )
    {
        for ( int col = 0; col < 16; col++ )
        {
            INPUT >> input[row][col];
        }
        for ( int col = 0; col < 16; col++ )
        {
            if ( input[row][col] == input[row][col+2] && input[row][col+1] == input[row][col+3] && input[row][col] != input[row][col+1] && input[row][col+2] != input[row][col+1])
            {
                prop1++;
            }
        }
        for ( int col = 0; col < 16; col++ )
        {
            if ( input[row][col] == input[row][col+2] )
            {
                prop2++;
            }
        }
        if ( prop1 > 1 && prop2 != 0 )
            {
                nice++;
            }
        prop1=0,prop2=0;
    }
    INPUT.close();
    cout << nice;
}