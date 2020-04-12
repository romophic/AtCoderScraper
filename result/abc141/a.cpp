#include<iostream>
#include<string>
#include<vector>
using namespace std;
int input_int(void)
{
	int i;
	cin >> i;
	return i;
}
int main()
{
	
	string word;
	cin >> word;
	if (word.substr(0, 1) == "S")
	{
		cout << "Cloudy" << endl;
	}
	if (word.substr(0, 1) == "C")
	{
		cout << "Rainy" << endl;
	}
	if (word.substr(0, 1) == "R")
	{
		cout << "Sunny" << endl;
	}


	return 0;
}
