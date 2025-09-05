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

// BOJ_9095 (DP)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int DP[12] = {};
	int now;
	DP[1] = 1; DP[2] = 2; DP[3] = 4;

	for (int j = 0; j < N; j++) {
		cin >> now;
		if (DP[now] == 0)
		{
			for (int i = 4; i <= now; i++) {
				DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
			}
		}
		cout << DP[now]<<"\n";
	}
}