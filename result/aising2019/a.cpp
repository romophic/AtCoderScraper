#include <iostream>
#include<cstdlib>
	using namespace std;
	int main() {

		int n, h, w, ans = 0;
		int tate = 0, yoko = 0;
		cin >> n >> h >> w;
		tate = n - h + 1;
		yoko = n - w + 1;
		if (abs(tate*yoko) != tate * yoko) {
			cout << 0 << endl;
		}
		else {
			cout << tate * yoko << endl;
		}


		return 0;
	}

