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

// BOJ_1406 (stack)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	stack<char> L;
	stack<char> R;
	char ch;
	while (1)
	{
		cin.get(ch);
		if (ch == '\n')
			break;
		else {
			L.push(ch);
		}
	}
	int N; char now; char pChar;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> now;
		switch (now) {
		case 'L':
			if (!L.empty()) {
				R.push(L.top());
				L.pop();
			}
			break;
		case 'D':
			if (!R.empty()) {
				L.push(R.top());
				R.pop();
			}
			break;
		case 'B':
			if (!L.empty())
				L.pop();
			break;
		case 'P':
			cin >> pChar;
			L.push(pChar);
			break;
		}
	}
	while (!L.empty()) {
		R.push(L.top());
		L.pop();
	}
	while (!R.empty()) {
		cout << R.top();
		R.pop();
	}
}