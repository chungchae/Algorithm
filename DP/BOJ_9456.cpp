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
#include <limits.h>

using namespace std;

// BOJ 9465 스티커 (DP) (S1)


int main() {
	int total; cin >> total;

	for (int t = 0; t < total; t++) {
		int N; cin >> N;

		vector<vector<int>> arr(N+1, vector<int>(2));

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[j][i];
			}
		}

		if (N == 1) {
			cout << max(arr[0][0], arr[0][1]) << "\n";
			continue;
		}

		vector<vector<int>> dp(N, vector<int>(2, 0));

		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[1][0] = arr[1][0] + dp[0][1];
		dp[1][1] = arr[1][1] + dp[0][0];

		for (int i = 2; i < N; i++) {
			//대각선 스티커 or 2칸전 대각선
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + arr[i][0];
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + arr[i][1];
		}
		cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;
	}
}