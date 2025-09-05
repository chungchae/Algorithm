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

// BOJ_1929 (Math)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N;
	cin >> M >> N;
	vector<bool> arr(N + 1, true);
	arr[1] = false;
	// Optimize with square root to reduce time complexity
	// Any factor larger than sqrt(N) must have a smaller pair already checked
	for (int i = 2; i <= sqrt(N); i++) {
		if (arr[i]) {
			for (int j = i + i; j <= N; j += i) {
				if (j % i == 0) {
					arr[j] = false;
				}
			}
		}
	}
	for (int i = M; i <= N; i++) {
		if (arr[i])
			cout << i << "\n";
	}
}