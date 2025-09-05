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

// BOJ 1904 01타일 (DP) (S3)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int DP[1000001] = { 0, };

	int N; cin >> N;

	DP[1] = 1; DP[2] = 2;

	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2])% 15746;
	}

	cout << DP[N];
}


