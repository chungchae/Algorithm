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

// BOJ 1927 최소 힙 (DP) (Data structure) (S2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	priority_queue<int, vector<int>, greater<int>> pq;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() <<"\n";
				pq.pop();
			}
		}
		else {
			pq.push(temp);
		}
	}

}

