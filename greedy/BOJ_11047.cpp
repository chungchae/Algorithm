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

// BOJ_11047 (greedy)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> amount(N);

	//store in reverse order
	for (int i = 1; i <= N; i++) {
		cin >> amount[N - i];
	}

	//save count
	int anwser = 0;

	for (int i = 0; i < N; i++) {
		int quotient = 0;
		quotient += K / amount[i];
		anwser += quotient;
		K -= quotient * amount[i];
	}

	cout << anwser;
}