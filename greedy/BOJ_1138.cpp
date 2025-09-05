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

// BOJ_1138 (greedy)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> memory(N);
	vector<int> answer(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> memory[i];
	}

	for (int i = 0; i < N; i++) {
		int count = memory[i];
		for (int j = 0; j < N; j++) {
			if (answer[j] == 0) {
				if (count == 0) {
					answer[j] = i + 1;
					break;
				}
				count--;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << " ";
	}
}