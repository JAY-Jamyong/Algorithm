#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int c, H, W;
int shape[4][2][2] = {
	{
		{1, 1}, 
		{1, 0}
	},
	{
		{1, 0}, 
		{1, 1}
	},
	{
		{0, 1}, 
		{1, 1}
	},
	{
		{1, 1},
		{0, 1}
	}
};

pair<int, int> FindDot(vector<vector<char>> &board) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == '.') {
				return make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

pair<bool, vector<vector<char>>> CheckFit(int Ord, int x, int y, vector<vector<char>> board) {
	if (Ord == 2) {
		if (y-1 < 0 || x + 1 >= H) {
			return make_pair(false, board);
		}
		if (board[x][y] == '#' || board[x+1][y-1] == '#' || board[x+1][y] == '#') {
			
			return make_pair(false, board);
		}
		board[x][y] = '#';
		board[x+1][y-1] = '#';
		board[x+1][y] = '#';
		return make_pair(true, board);
	}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			if (shape[Ord][i][j] == 1) {
				int _x = x + i;
				int _y = y + j;
				if (_x >= H || _y >= W) return make_pair(false, board);
				if (board[_x][_y] == '#') return make_pair(false, board);
			}
		}
	}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			if (shape[Ord][i][j] == 1) {
				board[x + i][y + j] = '#';
			}
		}
	}
	return make_pair(true, board);
}

int solve(vector<vector<char>> board) {

	int ret = 0;
	int count = 0;
	pair<int, int> fd;

	fd = FindDot(board);
	if (fd.first == -1) return 1;
	
	int x = fd.first;
	int y = fd.second;

	for (int i = 0; i < 4; i++) {
		pair<bool, vector<vector<char>>> checkfit= CheckFit(i, x, y, board);
		if (checkfit.first) {
			ret += solve(checkfit.second);
		} else {
			count++;
		}
	}

	if (count == 4) {
		return 0;
	}

	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> H >> W;
		vector<vector<char>> board(H, vector<char>(W));


		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				cin >> board[j][k];
			}
		}

		cout << solve(board) << endl;
	}

	return 0;
}