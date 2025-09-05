#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

// BOJ 1003 피보나치 함수 (DP) (S3)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	for (int test = 0; test < T; test++) {
		int N; cin >> N;

		if (N == 0) {
			cout << "1 0\n";
		}
		else {
			int DP[41];

			DP[0] = 0;
			DP[1] = 1; DP[2] = 1;

			// N = 0 인 경우 제외
			for (int i = 3; i <= N; i++) {
				DP[i] = DP[i - 1] + DP[i - 2];
			}
			cout << DP[N - 1] << " " << DP[N] << "\n";
		}
	}
	
}


