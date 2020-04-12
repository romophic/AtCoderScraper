#include<iostream>
#include<string>
#include<vector>
#include<boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::cpp_int infinit;
using namespace std;
#define END return 0
int input(void)
{
	int i = 0;
	cin >> i;
	return i;
}
int main()
{

	int n,ans=0;
	vector<int> list;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		list.push_back(input());
	}

	for (int i = 0; i < list.size(); i++)
	{
		for (int w = i+1; w < list.size(); w++)
		{
			ans += list[i] * list[w];
		}
	}

	cout << ans << endl;

	END;
}
