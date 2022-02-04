// PART 1;

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int FLOOR=0, i = 0; char ch;
    ifstream input;
    input.open("Day1 Input.txt");
    while (input)
    {
        input >> ch;
        if ( ch == '(' )
        {
            FLOOR++; 
        }
        else if ( ch == ')' )
        {
            FLOOR--;
        }
        else break;
        i++;
    }
    input.close();
    cout << FLOOR-1;
}



// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------


// PART 2;

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ALPHA;
    int FLOOR=0;
    getline (cin , ALPHA);
    for ( int i = 0; i < ALPHA.length() ; i++ )
    {
        if ( ch == '(' )
        {
            FLOOR++; 
        }
        else if ( ch == ')' )
        {
            FLOOR--;
        }
        if (FLOOR == -1)
        {
            cout << i+1;
            break;
        }
    }
}
