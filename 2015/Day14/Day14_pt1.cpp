#include <iostream>
#include <fstream>
#include <string>

#define numR 9
#define elapsedT 2503

using namespace std;

struct reindeer{
    string name;
    int speed, maxDist = 0, timeRun, timeRest;
};

int main()
{
    // Declaration and Initialization Section -----------------------------------------------------------
    reindeer reinDeer[numR]; 
    string temp; 
    int i = 0;
    
    ifstream inData; 
    inData.open("Day14_Input.txt");
    
    // Input Section ------------------------------------------------------------------------------------
    while(inData.eof() == 0)
    {
        inData >> reinDeer[i].name >> temp >> temp >> reinDeer[i].speed >> temp >> temp >> reinDeer[i].timeRun 
               >> temp >> temp >> temp >> temp >> temp >> temp >> reinDeer[i].timeRest >> temp;
        i++;
    }

    // Algorithm Section --------------------------------------------------------------------------------
    for (int i = 0; i < numR; i++)
    {
        for (int j = 1; j <= elapsedT; j++)
        {
            reinDeer[i].maxDist += reinDeer[i].speed;
            if (reinDeer[i].maxDist % (reinDeer[i].speed * reinDeer[i].timeRun) == 0)
                j += reinDeer[i].timeRest;
        }
    }

    // Output Section ----------------------------------------------------------------------------------
    int winner = 0;
    for (int i = 0; i < numR; i++)
        if (reinDeer[i].maxDist > winner)
            winner = reinDeer[i].maxDist;
    cout << winner;
}
