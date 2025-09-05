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

// BOJ 2512 예산 (binary search) (S2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> arr(N);

	int max_N = INT_MIN;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		max_N = max(arr[i], max_N);
	}
	int b; cin >> b;

	// 현재 예산이 충분하다면, 최댓값을 출력
	if (N * max_N < b) {
		cout << max_N;
		return 0;
	}

	// left는 예산을 N분의 1 한 값
	// right는 배열 중 최댓값
	int left = b / N; int right = max_N;
	int mid = (left + right) / 2;

	// 이분 탐색
	while (left <= right) {
		mid = (left + right) / 2;

		int remain = b;
		for (auto a : arr) {
			remain -= min(a, mid);
		}

		if (remain == 0) {
			cout << mid;
			return 0;
		}
		else if (remain > 0) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << (left + right) / 2;
}