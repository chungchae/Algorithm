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

// BOJ 1806 부분합 (2Pointer) (G4)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 변수선언, 입력
	int N; int S; cin >> N >> S;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int ans = 1e9;
	// 구현
	int left = 0; int right = 0;
	int sum = arr[0];

	while (right < N) {
		// S보다 작은 경우, right를 오른쪽으로 한 칸 이동
		if (sum < S) {
			right++;
			if (right < N) {
				sum += arr[right];
			}
		}
		// 조건 충족 시 ans 갱신 후 left를 오른쪽으로 한 칸 이동
		else {
			ans = min(ans, right - left + 1);
			sum -= arr[left];
			left++;
		}
	}
	if (ans == 1e9)cout << 0;
	else cout << ans;
}