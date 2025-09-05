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

// BOJ 1932 정수 삼각형 (DP) (S1)

using namespace std;

int main() {
	int N; cin >> N;
	vector<vector<int>> arr(N);
	int temp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> temp;
			arr[i].push_back(temp);
		}
	}

	//아래 두 값 중, 큰 값을 더하기를 반복
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			arr[i - 1][j] += max(arr[i][j], arr[i][j + 1]);
		}
	}
	cout << arr[0][0];
}

