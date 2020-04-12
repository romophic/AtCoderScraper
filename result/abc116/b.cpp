#include<iostream>
#include<algorithm>
using namespace std;
int main() {

	int a[10000], ax[10000], ans = 0,kouho=0;
	cin >> a[0];
	bool tr = false;

	for (int i = 0;; i++) {

		if (a[i] % 2 == 0) {//偶数
			a[i + 1] = a[i] / 2;
		}
		else {//奇数
			a[i + 1] = (a[i] * 3) + 1;
		}

		for (int q = 0; q != i; q++)ax[q] = a[q];

		sort(ax, ax + i);

		for (int w = 0; w != i; w++) {
			if (ax[w] == ax[w + 1]) {
				tr = true;
				ans = ax[w];
				w = i - 1;
			}
		}

		if (tr) {
			for (int e = 0; e != i; e++) {
				if (a[e] == ans) {
					if (kouho < e) {
						kouho = e;
					}
				}
			}
			cout << kouho+1 << endl;
			return 0;
		}
		
	}

	return 0;
}
