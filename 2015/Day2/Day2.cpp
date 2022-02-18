#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int L,W,H;
    int TotalOrderOfWP=0;
    int AreaOfRRP;
    int TRibbon = 0;

    for (int i = 0 ; i < 1000 ; i++)
    {
        cin >> L >> W >> H;
        AreaOfRRP= 2*L*W+2*W*H+2*H*L;
        
        int Sides[] = { L , W , H };
        sort(Sides, Sides+3);
        TotalOrderOfWP += Sides[0] * Sides[1] + AreaOfRRP;
        TRibbon += 2*(Sides[0] + Sides[1]) + (Sides[0]*Sides[1]*Sides[2]);
    }
    cout << TotalOrderOfWP << " " << TRibbon;
}