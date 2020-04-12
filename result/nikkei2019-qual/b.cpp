#include<iostream>
#include<string>
using namespace std;
int main() {

	int n, ans = 0;
	string a, b, c;
	cin >> n >> a >> b >> c;

	for (int i = 0; i != n; i++) {
		if (a.substr(i, 1) == b.substr(i, 1) && b.substr(i, 1) == c.substr(i, 1)) {
			//全てi番目が同じ
		}
		else {
			if (a.substr(i, 1) != b.substr(i, 1) && b.substr(i, 1) == c.substr(i, 1)) {
				ans++;
			}
			else {
				if (a.substr(i, 1) == b.substr(i, 1) && b.substr(i, 1) != c.substr(i, 1)) {
					ans++;
				}
				else {
					if (a.substr(i, 1) != b.substr(i, 1) && a.substr(i, 1) == c.substr(i, 1)) {
						ans++;
					}
					else {
						ans += 2;
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
