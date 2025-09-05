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

// BOJ_1874 (stack)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	stack<int> s;
	int temp;
	int now = 0;

	vector<string> result;
	bool r = true;

	cin >> temp;
	for (int i = 1; i <= temp; i++)
	{
		s.push(i);
		now++;
		result.push_back("+");
	}
	s.pop();
	result.push_back("-");

	for (int i = 1; i < N; i++) {
		cin >> temp;
		if (s.empty() || temp > s.top()) {
			for (int j = now; j < temp; j++)
			{
				s.push(j + 1);
				now++;
				result.push_back("+");
			}
			s.pop();
			result.push_back("-");
		}
		else {
			if (s.top() > temp)
			{
				cout << "NO\n";
				r = false;
				break;
			}
			else {
				s.pop();
				result.push_back("-");
			}
		}
	}

	if (r) {
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "\n";
		}
	}
}