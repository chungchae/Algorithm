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

// BOJ_1026 (greedy)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[N - i - 1];
	}
	cout << sum;
}