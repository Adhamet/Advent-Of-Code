#include <iostream>
using namespace std;

bool ruleOne(string password);
bool ruleTwo(string password);
bool ruleThree(string password);
void incrementing(string& password, int i);

int main()
{
    int i = 7;
    string pass;
    while(true)
    {
        cout << "Write the password: ";
        cin >> pass;
        if (pass.length() == 8)
        {
            break;
        }
    }
    while(true)
    {
        incrementing(pass, i);
        if (ruleOne(pass) && ruleTwo(pass) && ruleThree(pass))
        {
            cout << pass;
            break;
        }
    }
}

bool ruleOne(string password)
{
    for (int i = 0; i < password.length()-2; i++)
    {
        if (password[i] == password[i+1]-1 && password[i] == password[i+2]-2)
        {
            return true;
        }
    }
    return false;
}

bool ruleTwo(string password)
{
    int count = 0;
    char ch = ' ';
    for (int i = 0; i < password.length()-1; i++)
    {
        if (password[i] == password[i+1] && password[i] != ch)
        {
            count++;
            ch = password[i];
            i++;
        }
    }
    if (count >= 2) 
    { 
        return true; 
    }
    else { return false; }
}

bool ruleThree(string password)
{
    for (int i = 0; i < password.length(); i++)
    {
        if(password[i] == 'l' || password[i] == 'i' || password[i] == 'o')
        {
            return false;
        }
    }
    return true;
}

void incrementing(string& password, int i)
{
    if (password[i] == 'z')
    {
        password[i] = 'a';
        incrementing (password, i-1);
    }
    else
    {
        password[i]++;
    }
}