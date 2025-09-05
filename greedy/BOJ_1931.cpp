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

// BOJ_1931 (greedy)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	typedef pair<int, int> node;
	vector<node> arr(N);

	//store end time in first (for sort)
	for (int i = 0; i < N; i++) {
		cin >> arr[i].second >> arr[i].first;
	}

	sort(arr.begin(), arr.end());

	int count = 0; int end = -1;
	for (int i = 0; i < N; i++) {
		if (arr[i].second >= end) {
			count++;
			end = arr[i].first;
		}
	}

	cout << count;
}