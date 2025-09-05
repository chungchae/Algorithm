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

// BOJ 17626 Four Squares (DP) (S3)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	// 초기화
	int DP[50001]; DP[0] = 0;

	for (int i = 1; i <= N; i++) {
		// 최악의 경우 1^2 + 1^2 + ... (i번)
		DP[i] = i;
		// 제곱수가 가능한 경우 찾기
		for (int j = 1; j * j <= i; j++) {
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}
	cout << DP[N];
}


