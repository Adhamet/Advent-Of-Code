#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main()
{
    int santaX=0,santaY=0,roboX=0,roboY=0, i=0; char ch;

    set<string> positions;
    string position="00";
    positions.insert(position);

    ifstream input;
    input.open("Day3_Input.txt");

    while ( input )
    {
        input >> ch;
        if ( i % 2 == 0 )
        {
            if ( ch == '>' )
                santaX++;
            else if ( ch == '<' )
                santaX--;
            else if ( ch == '^' )
                santaY++;
            else if ( ch == 'v' )
                santaY--;
            else break;

            position[0] = santaX;
            position[1] = santaY;

            positions.insert(position);
        }

        if ( i % 2 != 0 )
        {
            if ( ch == '>' )
                roboX++;
            else if ( ch == '<' )
                roboX--;
            else if ( ch == '^' )
                roboY++;
            else if ( ch == 'v' )
                roboY--;
            else break;

            position[0] = roboX;
            position[1] = roboY;

            positions.insert(position);
        }
        i++;
    }
    input.close();
    cout << positions.size()-1;
}