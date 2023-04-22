#include <iostream>

using namespace std;

int Solve(int n, int fence[]) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int height = fence[i];
		cout << height << endl;
		for (int k = height; k > 0; k--) {
			int xLength = 1;
			for (int j = i; j < n; j++) {
				
				if (j + 1 <= n && k <= fence[j + 1]) {
					xLength++;
				} else {
					cout << k << " " << xLength << endl;
					int square = k * xLength;
					if (square > ret) {
						ret = square;
					} 
					break;
				}
			}
		}
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		int fence[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> fence[i];
		}
		cout << Solve(n, fence) << endl;
	}
	return 0;
}