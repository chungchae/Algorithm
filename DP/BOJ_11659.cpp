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

using namespace std;

// BOJ_11659
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int S[100001] = {};

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << S[b] - S[a - 1] << "\n";
	}

	return 0;
}