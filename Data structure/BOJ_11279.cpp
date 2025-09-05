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
#include <map>
#include <set>

using namespace std;

// BOJ 11279  최대 힙 (data structure) (S2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	priority_queue<int> Q;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			if (Q.empty())
				cout << 0 << "\n";
			else {
				cout << Q.top() <<"\n";
				Q.pop();
			}
		}
		else {
			Q.push(temp);
		}
	}
}


