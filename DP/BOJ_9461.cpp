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

using namespace std;

// BOJ_9461 (DP)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	int N;
	cin >> T;

	long long DP[101] = { 0 };
	DP[1] = 1; DP[2] = 1; DP[3] = 1;

	for (int i = 0; i < T; i++) {
		cin >> N;

		if (DP[N] == 0) {
			for (int j = 4; j <= N; j++) {
				DP[j] = DP[j - 2] + DP[j - 3];
			}
		}
		cout << DP[N] << "\n";
	}
}