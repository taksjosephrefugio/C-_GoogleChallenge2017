/*
This code takes a string and a number K from the user.
The output of the program is the all caps of the user's string
and there would be dashes between K letters

e.g.
Input: helloworld, 3
Output: HEL-LLO-WOR-LD

Code Written by: TAK'S JOSEPH REFUGIO
Code Written on: Summer 2017
Code Written for: Google Interview Challenge
*/
#include <iostream>
#include <string>
using namespace std;

// FUNCTION PROTOTYPES
string withoutDashes(string S);
string capsAll(string S);
string solution(string S, int K);

int main(void)
{
	// string teststring = "asofij-rghuwivefv-asdocijadvi";
	string teststring = "helloworld";
	string sol1 = withoutDashes(teststring);
	string sol2 = capsAll(sol1);
	string sol3 = solution(sol2, 3);
	cout << sol3 << endl;
	return 0;
}

string withoutDashes (string inputstring) {
	string returnString;

	int ctr=0;
	int numdash=0;
	while (inputstring[ctr])
	{
		if (inputstring[ctr] == '-')	{ numdash++; }
		ctr++;
	}
	ctr=0;

	returnString.resize(inputstring.size() - numdash);
	int dashcount=0;

	//FIXME
	
	while (inputstring[ctr])
	{
		if (inputstring[ctr] != '-')  	{ returnString[ctr - dashcount] = inputstring[ctr]; }
		else 							{ dashcount++; }
		ctr++;
	}
	returnString[ctr - dashcount] = '\0';
	ctr=0;

	// returnString[0] = 'H';
	// returnString[1] = 'E';
	// returnString[2] = 'L';
	// returnString[3] = 'L';
	// returnString[4] = 'O';
	return returnString;
}

string capsAll (string inputstring) {
	string returnString;
	returnString.resize(inputstring.size());

	int ctr=0;
	while (inputstring[ctr])
	{
		int intchar = inputstring[ctr];
		if ((intchar >= 97) && (intchar <= 122))	{ returnString[ctr] = intchar - 32; }
		else 										{ returnString[ctr] = intchar; }
		ctr++;
	}
	ctr=0;
	return returnString;
}

string solution (string inputstring, int K) {
	int dashputback = inputstring.size() / K;
	int firstcharslength = inputstring.size() % K;
	int putbackcount=0;
	int ctr=0;

	string returnString;
	returnString.resize(inputstring.size() + dashputback);

	for (ctr; ctr < firstcharslength; ctr++)
	{
		returnString[ctr] = inputstring[ctr];
	}
	returnString[ctr] = '-';
	putbackcount++;

	int charcount=0;
	while (inputstring[ctr])
	{
		charcount++;
		returnString[ctr + putbackcount] = inputstring[ctr];
		if (charcount == K)
		{
			putbackcount++;
			returnString[ctr + putbackcount] = '-';
			charcount = 0;
		}
		ctr++;
	}
	return returnString;
}