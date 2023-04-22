#include <iostream>
#include <vector>

using namespace std;

int n, m, temp;

void dsfSolution(int x, int y, vector<vector<int>> &board) {

	cout << "function called" << endl;

	if (x <= -1 || y <= -1 || y >= m || x >= n) {
		return;
	}

	if (!board[x][y]) {
		board[x][y] = 1;
		dsfSolution(x, y+1, board);
		dsfSolution(x, y-1, board);
		dsfSolution(x+1, y, board);
		dsfSolution(x-1, y, board);
	}
}



int main() {

	int ret = 0;

	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		char s[m];
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(!board[i][j]){
				dsfSolution(i, j, board);
				ret++;
			}
		}
	}

	cout << ret << endl;

	return 0;
}