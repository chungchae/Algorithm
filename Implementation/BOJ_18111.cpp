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

// BOJ 18111 마인크래프트 (Implementation) (S2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> arr(N, vector<int>(M));

	int minH = 1e9; int maxH = -1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			minH = min(arr[i][j], minH);
			maxH = max(arr[i][j], maxH);
		}
	}

	// 정답 시간과 높이
	int ans_T = 1e9; int ans_H = 0;
	// 최소 높이 ~ 최대 높이 탐색
	for (int key = minH; key <= maxH; key++) {
		int remain = B;
		int sum = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				// 파내는 경우
				if (arr[x][y] >= key) {
					sum += 2 * (arr[x][y] - key);
					remain += arr[x][y] - key;
				}
				// 채우는 경우
				else {
					sum += key - arr[x][y];
					remain -= key - arr[x][y];
				}
			}
		}
		// 남은 블럭이 음수가 아닌 경우
		if (remain >= 0) {
			// 시간이 덜 걸리거나, 시간은 같고 높이가 더 높은 경우
			if (sum < ans_T || (sum == ans_T && key > ans_H)) {
				// 갱신
				ans_T = sum;
				ans_H = key;
			}
		}
	}
	cout << ans_T << " " << ans_H;

}


