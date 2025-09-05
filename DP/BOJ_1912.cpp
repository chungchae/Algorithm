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

// BOJ_1912 (DP)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> dp(N);
	dp[0] = arr[0];
	int maxSum = dp[0];

	for (int i = 1; i < N; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		maxSum = max(maxSum, dp[i]);
	}

	cout << maxSum << "\n";
	return 0;
}