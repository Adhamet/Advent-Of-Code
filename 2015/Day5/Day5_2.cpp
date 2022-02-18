#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream INPUT;
    INPUT.open("Day5_Input.txt");
    int prop1=0,prop2=0,nice=0, row, col, col1;
    char input[1000][16];
    for ( row = 0; row < 1000; row++ )
    {
        for ( col = 0; col < 16; col++ )
        {
            INPUT >> input[row][col];
            input[row][col1] == input[row][col];
            col1++;
        }
        for ( col = 0; col < 16; col++ )
        {
            for ( col1 = 0; col1 < 16; col1++ )
            {
                    if ( input[row][col1+2] == input[row][col] && input[row][col1+3] == input[row][col+1] && input[row][col1+2] != input[row][col])
                    {
                        if (col1+1 < 16 && col1+2 < 16 && col1+3 < 16)
                        {
                            prop1++;
                        }
                    }
            }
        }
        
        for ( col = 0; col < 16; col++ )
        {
            if ( input[row][col] == input[row][col+2] )
            {
                if (input[row][col+2] < 16)
                {
                    prop2++;
                }
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