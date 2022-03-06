#include <iostream>
#include <string>
using namespace std;

int main()
{
    int rep=1;
    string input, output = "";
    cin >> input;
    for (int k = 0; k < 50; k++)
    {
        for(int i = 0; i < input.length();)
        {
            for (int j = i+1; j < input.length(); j++)
            {
                if ( input[j] == input[i])
                {
                    rep++;
                }
                else if ( input[j] != input[i] )
                {
                    break;
                }
            }
            output += to_string(rep) + input[i];
            i += rep;
            rep = 1;
        }
        input = output;
        output = "";
    }
    cout << input.length();
}