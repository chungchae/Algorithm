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

// BOJ 2470 두 용액 (2Pointer) (G5)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 변수선언, 입력
	int N; cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 구현
	sort(arr.begin(), arr.end());
	int left = 0, right = N - 1;

	long long bestAbs = llabs((long long)arr[left] + arr[right]);
	int bestL = arr[left], bestR = arr[right];

	while (left < right) {
		long long now = (long long)arr[left] + arr[right];
		long long a = llabs(now);

		// 최솟값 갱신
		if (a < bestAbs) {
			bestAbs = a; bestL = arr[left]; bestR = arr[right];
		}
		if (now < 0) left++;
		else if (now > 0) right--;
		else break;
	}
	cout << bestL << ' ' << bestR << '\n';
}