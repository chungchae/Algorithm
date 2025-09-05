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

// BOJ_1448 (greedy)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	while (arr.size() >= 3) {
		sort(arr.begin(), arr.end());
		if (arr[N - 1] < arr[N - 2] + arr[N - 3]) {
			cout << arr[N - 1] + arr[N - 2] + arr[N - 3];
			return 0;
		}
		arr.pop_back();
		N--;
	}
	cout << "-1";
}