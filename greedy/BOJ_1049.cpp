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

// BOJ 1049 기타줄 (greedy) (S4)

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int a, b;
	int min1 = 1e9;
	int min2 = 1e9;
	int ans = 0;

	//기타줄 세트와 낱개 목록 중 최솟값 구하기
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (a < min1) min1 = a;
		if (b < min2) min2 = b;
	}
	// 세트를 최대, 나머지는 낱개 or 전부 세트 or 전부 낱개 중 최솟값을 선택
	ans = min(min(N / 6 * min1 + N % 6 * min2, (N / 6 + 1) * min1), N * min2);
	cout << ans;
}

