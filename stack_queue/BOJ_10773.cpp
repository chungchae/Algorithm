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

// BOJ_10773 (stack)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K;
	cin >> K;

	stack<int> S;
	int temp;
	int sum = 0;

	for (int i = 0; i < K; i++) {
		cin >> temp;
		if (temp == 0)
			S.pop();
		else {
			S.push(temp);
		}
	}
	int k = S.size();
	for (int i = 0; i < k; i++) {
		sum += S.top();
		S.pop();
	}
	cout << sum;
}