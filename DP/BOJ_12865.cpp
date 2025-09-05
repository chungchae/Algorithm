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

// BOJ_12865 (DP)

int N, K;
vector<int> wt;
vector<int> val;
vector < vector<int>> DP;

// 남은 용량, 용량 배열, 가치 배열, 남은 개수
int func(int W, int* wt, int* val, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if (wt[i - 1] > j)
				DP[i][j] = DP[i - 1][j];
			else {
				int ValWith = val[i - 1] + DP[i - 1][j - wt[i - 1]]; // 넣는 경우
				int ValWithout = DP[i - 1][j]; // 안넣는 경우
				DP[i][j] = max(ValWith, ValWithout); // 더 큰 값 선택
			}
		}
	}
	return DP[n][W];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	cin >> N >> K;

	wt.resize(N);
	val.resize(N);
	//DP 배열 초기화
	DP = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));

	for (int i = 0; i < N; i++) {
		cin >> wt[i] >> val[i];
	}
	
	cout << func(K, wt.data(), val.data(), N) << "\n";
}