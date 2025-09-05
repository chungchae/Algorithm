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
#include <unordered_map>

using namespace std;

// BOJ_10828 (stack)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	string now;
	int temp;

	stack<int> S;

	for (int i = 0; i < N; i++) {
		cin >> now;
		if (now == "push") {
			cin >> temp;
			S.push(temp);
		}
		else if (now == "top") {
			if (S.size() != 0) {
				cout << S.top() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if (now == "size") {
			cout << S.size() << "\n";
		}
		else if (now == "pop") {
			if (S.size() != 0) {
				cout << S.top() << "\n";
				S.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (now == "empty") {
			if (S.size() == 0) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
	}
	return 0;
}