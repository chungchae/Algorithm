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

// BOJ_10986
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, temp;
	cin >> N >> M;
	vector<long> S(N, 0);
	vector<long> R(M, 0);
	long answer = 0;
	int remainder;

	cin >> S[0];

	for (int i = 1; i < N; i++) {
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}

	for (int i = 0; i < N; i++) {
		remainder = S[i] % M;
		if (remainder == 0)
			answer++;
		R[remainder]++;
	}

	for (int i = 0; i < M; i++) {
		if (R[i] > 1) {
			answer += R[i] * (R[i] - 1) / 2;
		}
	}

	cout << answer;

}