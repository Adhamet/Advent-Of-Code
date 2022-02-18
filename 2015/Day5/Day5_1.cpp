#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream INPUT;
    INPUT.open("Day5_Input.txt");
    int prop1=0,prop2=0,prop3=0,nice=0;
    char input[1000][16];
    for ( int row = 0; row < 1000; row++ )
    {
        for ( int col = 0; col < 16; col++ )
        {
            INPUT >> input[row][col];
        }
        for ( int col = 0; col < 16; col++ )
        {
            if (input[row][col] == 'a' || input[row][col] == 'e' || input[row][col] == 'i' || input[row][col] == 'o' || input[row][col] == 'u')
            {
                prop1++;
            }
        }
        for ( int col = 0 ; col < 15 ; col++ )
        {
            if ( input[row][col] == input[row][col+1] )
            {
                prop2++;
            }
            if ( input[row][col] == 'a' && input[row][col+1] == 'b' || input[row][col] == 'c' && input[row][col+1] == 'd' || input[row][col] == 'p' && input[row][col+1] == 'q' || input[row][col] == 'x' && input[row][col+1] == 'y')
            {
                prop3++;
            }
        }
        if ( prop1 > 2 && prop2 > 0 && prop3 == 0)
            {
                nice++;
            }
        prop1=0,prop2=0,prop3=0;
    }
    INPUT.close();
    cout << nice;
}