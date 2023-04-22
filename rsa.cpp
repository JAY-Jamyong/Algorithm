#include <iostream>
#include <cmath> 
#include <vector>
#include <numeric>

using namespace std;

int gcd(int a, int b);
int modInverse(int a, int b, int c);

class KeyGeneration {
public:
	unsigned p;
	unsigned q;
	unsigned n;
	unsigned phi_n;
	unsigned e;
	unsigned d;

	void prompter();
	void showValue();
	bool primality_check();
	void calculate_n();
	void calculate_pi();
	void calculate_e();
	void calculate_d();

};

void KeyGeneration::showValue() {
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "n: " << n << endl;
	cout << "Phi N: " << phi_n << endl;
	cout << "e: " << e << endl;
	cout << "d: " << d << endl;
}

void KeyGeneration::prompter()
{
	cout << "Prime P: " << endl;
	cin >> p;
	cout << "Prime Q: " << endl;
	cin >> q;
}

bool KeyGeneration::primality_check()
{
	vector<unsigned> p_factor;
	vector<unsigned> q_factor;

	for (unsigned i = 2; i <= static_cast<unsigned>(sqrt(p)); i++) {
		if (p % i == 0) {
			return false;
		}
	}

	for (unsigned i = 2; i <= static_cast<unsigned>(sqrt(q)); i++) {
		if (q % i == 0) {
			return false;
		}
	}

	return true;
}

void KeyGeneration::calculate_n() {
	this->n = p*q;
}

void KeyGeneration::calculate_pi() {
	this->phi_n = (p-1) * (q-1);
}

void KeyGeneration::calculate_e() {
	int result = 0;
	for (int x = 2; x < phi_n; x++) {
		if (phi_n % x !=0 && gcd(x, phi_n) > 1) {
			result = x;
			cout << result << endl;
			break;
		}
	}
	this->e = result;
}

void KeyGeneration::calculate_d() {
	this->d = modInverse(e, phi_n, 1);
}

int gcd(int a, int b) {
	int x = (a < b) ? b : a;
	int y = (a < b) ? a : b;

	if (x % y == 0) {
		return y;
	} else {
		gcd(x, x % y);
	}
}

int modInverse(int a, int b, int r) {
	int current = 0;
	int answer = 0;
	while (true) {
		if (a * current % b == r) {
			return current;
		}
		current++;
	}
}
		
int main(int argc, char **argv)
{
	KeyGeneration k;
	k.prompter();
	if(k.primality_check() == true) {
		k.calculate_n();
		k.calculate_pi();
		k.calculate_e();
		k.calculate_d();
		k.showValue();
	} else {
		cout << "ERROR" << endl;
	}
	return 0;
}
