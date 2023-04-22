#include <iostream>
#include <vector>

using namespace std;

const string NATO[26] = { "ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO", "FOXTROT", "GOLF", "HOTEL", "INDIA", "JULIETT", "KILO", "LIMA", "MIKE", "NOVEMBER", "OSCAR", "PAPA", "QUEBEC", "ROMEO", "SIERRA", "TANGO", "UNIFORM", "VICTOR", "WHISKEY", "XRAY", "YANKEE", "ZULU" };

char solve_1(string s, int k, long long index) {
	string orgin = s;
	string NatoString = "";
	for (int j = 0; j < k; j++){
		for (int i = 0; orgin[i] && NatoString.length() < index; i++) {
			NatoString = NatoString + NATO[orgin[i]-65];
		}
		orgin = NatoString;
		cout << orgin << endl;
		NatoString = "";
	}
	char result = orgin[index-1];
	return result;
}

char solve(string s, int k, long long index) {
	string orgin = s;
	string character;
	string NatoString = "";
	for (int i = 0; i < s.length(); i++) {
		character = orgin[i];
		for (int j = 0; j < k; j++) {
			NatoString = NatoString + NATO[character[j]-65];
			if (NatoString.length() > index) {
				character = NatoString;
				NatoString = "";
				
			}
		}

	}
}

int main() {
	string orgin;
	string current;
	string result;

	cout << solve("HCPC", 217, 987654);

	// int num;

	// cin >> orgin >> num;
	// current = orgin;

	// for(int i = 0; i < num; i++) {
	// 	int j, k;
	// 	cin >> j >> k;
	// 	int times;
	// 	if (j == 1) {
	// 		for(int x = 0; x < k; x++) {
	// 			current = solve(current, 1);
	// 		}
	// 	}
	// }

	// cout << result << endl;

	return 0;
}