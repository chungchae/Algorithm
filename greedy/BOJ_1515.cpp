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

// BOJ_1515 (greedy)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string target;
	cin >> target;

	int i = 0; int num = 1;

	while (i < target.size()) {
		string cur = to_string(num);
		for (char c : cur) {
			if (c == target[i])
			{
				i++;
				if (i == target.size())
					break;
			}
		}
		num++;
	}
	cout << num - 1;

}