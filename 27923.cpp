// imos를 기억하세용

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <math.h>

// using namespace std;

// int solve(int N, int K, int L, vector<long long> mass, vector<long long> coke) {
    
//     int ret = 0;
//     vector<long long> cokeNum(N);

//     for (int i = 0; i < K; i++) {
        
//         if(coke[i] != 0){
//             cokeNum[coke[i]-1]++;
//             if (coke[i] + L <= N) cokeNum[coke[i]+L-1]--;
//         }

//     }

//     for (int j = 1; j < N; j++) {
//         cokeNum[j] = cokeNum[j-1] + cokeNum[j];
//     }
    
//     sort(mass.begin(), mass.end(), greater<long long>());
//     sort(cokeNum.begin(), cokeNum.end(), greater<long long>());

//     for (int i = 0; i < N; i++) {
        
//         int cokeEffect = pow(2, cokeNum[i]);
//         ret = ret + (mass[i]/cokeEffect);

//     }
    
//     return ret;
// }

// int main(void) {

//     int N, K, L;
//     cin >> N >> K >> L;
//     vector<long long> mass(N);
//     vector<long long> coke(K);
//     for (int i = 0; i < N; i++) cin >> mass[i];
//     for (int i = 0; i < K; i++) cin >> coke[i];

//     cout << solve(N, K, L, mass, coke) << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int N, K, L;
std::vector<long long> H;
std::vector<long long> C;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N >> K >> L;
	H.resize(N + 1);
	C.resize(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> H[i];
	}

	for (int i = 0; i < K; ++i)
	{
		int k;
		std::cin >> k;

		if (k <= N)
		{
			C[k]++;
		}	
		
		if (k + L <= N)
		{
			C[k + L]--;
		}
	}

	for (int i = 2; i <= N; ++i)
	{
		C[i] = C[i] + C[i - 1];
	}

	std::sort(H.begin() + 1, H.end(), std::greater<long long>());
	std::sort(C.begin() + 1, C.end(), std::greater<long long>());

	long long ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		ans += (H[i] / pow(2, C[i]));
	}
	
	std::cout << ans;
	return 0;
}