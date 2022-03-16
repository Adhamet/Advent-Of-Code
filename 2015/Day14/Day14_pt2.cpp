#include <iostream>
#include <fstream>
#include <string>

#define numR 9
#define elapsedT 2503

using namespace std;
    
struct reindeer{
    string name;
    int speed, maxDist = 0, timeRun, timeRest, score = 0, restLast = 0;
};

int main()
{
    // Declaration and Initialization Section -----------------------------------------------------------
    ifstream inData; 
    inData.open("Day14_Input.txt");
    
    reindeer reinDeer[numR]; 
    string temp; 
    int i = 0;

    // Input Section ------------------------------------------------------------------------------------
    while(inData.eof() == 0)
    {
        inData >> reinDeer[i].name >> temp >> temp >> reinDeer[i].speed >> temp >> temp >> reinDeer[i].timeRun 
               >> temp >> temp >> temp >> temp >> temp >> temp >> reinDeer[i].timeRest >> temp;
        i++;
    }

    // Algorithm Section --------------------------------------------------------------------------------
    for (int i = 1; i < elapsedT; i++)
    {
        for(int j = 0; j < numR; j++)
        {
            if (reinDeer[j].restLast < i)
            {
                reinDeer[j].maxDist += reinDeer[j].speed;
                if (reinDeer[j].maxDist % (reinDeer[j].speed * reinDeer[j].timeRun) == 0)
                    reinDeer[j].restLast = i + reinDeer[j].timeRest;
            }
        }

        int winner = 0;
        for (int j = 0; j < numR; j++)
            if (winner < reinDeer[j].maxDist)
                winner = reinDeer[j].maxDist;

        for (int j = 0; j < numR; j++)
            if (reinDeer[j].maxDist == winner) 
                reinDeer[j].score++; 
    }

    // Output Section ----------------------------------------------------------------------------------
    int gold = 0;
    for (int i = 0; i < numR; i++)
    {
        if (reinDeer[i].score > gold)
        {
            gold = reinDeer[i].score;
        }
    }
    cout << gold;
}
