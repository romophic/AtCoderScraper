#include<iostream>
using namespace std;
int main() {

	int n, h[100], ans = 0;
	cin >> n;
	for (int i = 0; i != n; i++)cin >> h[i];

	bool trg = false,trgend=false;

	for (;;) {
		
		trg = false;
		trgend = true;

		for (int i = 0; i != n; i++) {

			if (h[i] != 0) {
				trg = true;
				trgend = false;
			}

			if (trg == true) {
				if (h[i] == 0) {
				ans++;
				trg = false;
				}
				else {
					h[i]--;
				}
			}
		}

		if (trg == true) {
			trg = false;
			ans++;
		}

		if (trgend) {
			cout << ans << endl;
			break;
		}

	}

	return 0;
}
