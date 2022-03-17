#include <iostream>
#include <fstream>
#define sent 1000
using namespace std;

bool prop1(string sentence);
bool prop2(string sentence);


int main()
{
    ifstream inData;
    inData.open("Day5_Input.txt");

    int nice = 0, i = 0;
    string array[sent];

    while(inData.eof() == 0)
    {
        inData >> array[i];
        i++;
    }
    for (int i = 0; i < sent; i++)
        if (prop1(array[i]) && prop2(array[i]))
            nice++;
    cout << nice;
}


bool prop1 (string sentence)
{
    for (int i = 0; i < sentence.length()-3; i++)
        for (int j = i+2; j < sentence.length()-1; j++)
            if (sentence[i] == sentence[j])
                if (sentence[i+1] == sentence[j+1])
                    return true;
    return false;
}
bool prop2 (string sentence)
{
    for (int i = 0; i < sentence.length()-2; i++)
        if (sentence[i] == sentence[i+2])
            return true;
    return false;
}
