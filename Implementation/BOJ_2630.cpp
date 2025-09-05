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

// BOJ 2630 색종이 만들기 (Implementation) (S2)

// 규칙에 해당하는 파란색, 하얀색 색종이 수
int B; int W;
vector<vector<int>> arr;

void colorCheck(int x, int y, int size) {
	// x ~ x+size, y ~ y+size 까지 탐색
	// B, W 중 하나의 색만 있는지 확인
	int now_B = 0; int now_W = 0;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] == 0) now_W++;
			else now_B++;
		}
	}
	// 하나의 색만 있다면, B, W에 +1
	if (now_B == 0)W++;
	else if (now_W == 0)B++;
	else {
		// 색이 섞여 있다면, 4분할 재귀
		colorCheck(x, y, size / 2);
		colorCheck(x, y + size / 2, size / 2);
		colorCheck(x + size / 2, y, size / 2);
		colorCheck(x + size / 2, y + size / 2, size / 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	B = 0; W = 0;

	int N; cin >> N;
	arr = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	colorCheck(0, 0, N);

	cout << W << "\n" << B;
}


