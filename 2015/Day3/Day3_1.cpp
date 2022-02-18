#include <iostream>
#include <string>
#include <set>
#include <fstream>
using namespace std;

int main()
{
    int x,y;

    set<string> positions;
    string position = "00";
    positions.insert(position);
    
    ifstream INPUT;
    INPUT.open("Day3_Input.txt");
    char ch;
    while (INPUT)
    {
        INPUT >> ch;
        if (ch == '>')
            x++;
        else if (ch == '<')
            x--;
        else if (ch == '^')
            y++;
        else if (ch == 'v')
            y--;
        
        position[0] = x;
        position[1] = y;
        
        positions.insert(position);
    }
    INPUT.close();
    cout << positions.size();
}