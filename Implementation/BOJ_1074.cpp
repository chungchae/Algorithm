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

// BOJ 1074 Z (Implementation) (G5)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, x, y;
	cin >> N >> x >> y;
	x++; y++;
	int ans = 0;

	// 정사각형 구역을 축소해가며 구현
	for (int i = N - 1; i >= 0; i--) {
		// 1. 행 처리
		if (x > pow(2, i)) {
			ans += pow(2, i) * pow(2, i) * 2;
			x -= pow(2, i);
		}
		
		// 2. 열 처리
		if (y > pow(2, i)) {
			ans += pow(2, i) * pow(2, i);
			y -= pow(2, i);
		}
	}
	cout << ans;
}

