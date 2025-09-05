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

// BOJ_9012

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	cin.ignore();

	vector<string> arr(N);
	bool isValid = true;

	for (int i = 0; i < N; i++) {
		getline(cin, arr[i]);
	}

	for (int i = 0; i < N; i++) {
		if (arr[i][0] != '(' || arr[i][arr[i].size() - 1] != ')') {
			cout << "NO\n";
		}
		else {
			int D = 0;
			isValid = true;
			for (int j = 0; j < arr[i].size(); j++) {
				if (arr[i][j] == '(')
					D++;
				else
					D--;
				if (D < 0)
				{
					isValid = false;
					break;
				}
			}
			if (isValid && D == 0) {
				cout << "YES\n";
			}
			else
				cout << "NO\n";
		}
	}
}