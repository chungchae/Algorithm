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

// BOJ_2579 (DP)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int DP[301] = { 0 };
	vector<int> arr(N + 1, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i + 1];
	}
	if (N == 1) {
		cout << arr[1];
		return 0;
	}
	if (N == 2) {
		cout << arr[1] + arr[2];
		return 0;
	}

	DP[1] = arr[1]; DP[2] = DP[1] + arr[2];
	DP[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	for (int i = 4; i <= N; i++) {
		DP[i] = max(DP[i - 2], DP[i - 3] + arr[i - 1]) + arr[i];
	}
	cout << DP[N];
}