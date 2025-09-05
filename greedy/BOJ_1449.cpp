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

// BOJ_1449 (greedy)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, L;
	cin >> N >> L;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int index = 0;
	int count = 0;

	while (index < N) {
		count++;
		int limit = arr[index] + L - 1;

		while (index < N && arr[index] <= limit) {
			index++;
		}
	}
	cout << count;
}