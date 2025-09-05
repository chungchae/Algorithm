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

// BOJ_1182 (DFS)

int N, S; int cnt = 0;
vector<int> arr;

void dfs(int index, int sum) {
	if (index == N) {
		if (sum == S) cnt++;
		return;
	}
	dfs(index + 1, sum + arr[index]);
	dfs(index + 1, sum);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);
	if (S == 0)cnt--;

	cout << cnt;
}