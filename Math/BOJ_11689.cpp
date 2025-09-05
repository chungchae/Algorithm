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

// BOJ_11689 (math)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long N;
	cin >> N;

	long result = N;

	for (long p = 2; p <= sqrt(N); p++) {
		if (N % p == 0) {
			result = result - result / p;
			while (N % p == 0)
				N /= p;
		}
	}
	if (N > 1) {
		result = result - result / N;
	}
	cout << result;
}