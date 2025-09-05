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

// BOJ_2193 (math)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<long long> DP(N + 1);

	DP[1] = 1; DP[2] = 1;
	for(int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[N];
}