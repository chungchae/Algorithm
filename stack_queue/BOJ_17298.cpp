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

// BOJ_17298 (stack)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	stack<int> s;
	vector<int> arr(N, 0);
	vector<int> anwser(N, -1);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	s.push(0);
	for (int i = 1; i < N; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			anwser[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < N; i++) {
		cout << anwser[i] << " ";
	}
}