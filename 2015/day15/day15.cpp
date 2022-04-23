#include <iostream>
#include <fstream>
#include <string>

#define lli long long int
int const num_Ing = 4;

using namespace std;


struct ingredient {
	string name;		  
	lli capacity, durability, flavor, texture, calories, tablespoon = 0;
} comb[num_Ing];


// Algorithm Section: ----------------------------------------------------------------------
void check(int& prop)
{
	if (prop < 0)
		prop = 0;
}

void algorithm(int ele, int& maxScore)
{
	if (ele > (num_Ing - 1))
	{
		int total_Tbps = 0;
		int cap = 0, dura = 0, flav = 0, text = 0, calo = 0;
		lli score = 0;
		
		for (int i = 0; i < num_Ing; i++)
		{
			total_Tbps += comb[i].tablespoon;
		}

		if (total_Tbps != 100) return;

		for (int i = 0; i < num_Ing; i++)
		{
			cap += comb[i].capacity * comb[i].tablespoon;
			dura += comb[i].durability * comb[i].tablespoon;
			flav += comb[i].flavor * comb[i].tablespoon;
			text += comb[i].texture * comb[i].tablespoon;
			calo += comb[i].calories * comb[i].tablespoon;
		}

		check(cap); check(dura); check(flav); check(text);
		// This line is for part 2: if (calo != 500) return;
		score = cap * dura * flav * text;

		if (score > maxScore) maxScore = score;	

		return;
	}
	
	ele++;
	int remainingSp = 100;

	for (int i = 0; i < num_Ing; i++)
		remainingSp -= comb[i].tablespoon;

	for (int i = 1; i <= remainingSp; i++)
	{
		comb[ele - 1].tablespoon = i;
		algorithm(ele, maxScore);
		comb[ele - 1].tablespoon = 0;
	}
}


int main()
{
	// Initialization And Declaration: ----------------------------------------------------
	ifstream inData; inData.open("input.txt");

	string tempStr;
	char tempCh;
	int maxScore = -1;

	// Input Section: --------------------------------------------------------------------
	for (int i = 0; i < num_Ing; i++)
	{
		inData >> comb[i].name >> tempStr >> comb[i].capacity >> tempCh >> tempStr >> comb[i].durability
			   >> tempCh >> tempStr >> comb[i].flavor >> tempCh >> tempStr >> comb[i].texture >> tempCh
			   >> tempStr >> comb[i].calories;
	}

	// Output Section: -------------------------------------------------------------------
	algorithm(0, maxScore);
	cout << maxScore;

}