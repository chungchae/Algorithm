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

// BOJ_1920 (binary_search)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end()); //O(nlogn)

	cin >> M;

	for (int i = 0; i < M; i++) {
		bool find = false;
		int target;
		cin >> target;

		int start = 0; int end = arr.size() - 1;

		while (start <= end) {
			int midi = (start + end) / 2;
			int midV = arr[midi];
			if (midV > target) {
				end = midi - 1;
			}
			else if (midV < target) {
				start = midi + 1;
			}
			else {
				find = true;
				break; //escape while loop
			}
		}
		if (find)
			cout << "1\n";
		else
			cout << "0\n";
	}
}