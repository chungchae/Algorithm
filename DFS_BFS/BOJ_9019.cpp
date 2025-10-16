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
#include <limits.h>

using namespace std;

// BOJ 9019 DSLR (bfs) (G4)

vector<bool> visited;

string bfs(int start, int target) {
	queue<pair<int, string>> q;

	q.push({ start, ""});
	visited[start] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string cmd = q.front().second;

		if (num == target)return cmd;

		q.pop();


		int D = (num * 2) % 10000;
		int S = (num == 0 ? 9999 : num - 1);
		int L = (num % 1000) * 10 + num / 1000;
		int R = (num / 10) + (num % 10) * 1000;

		if (!visited[D]) {
			visited[D] = true;
			q.push({ D, cmd + "D" });
		}
		if (!visited[S]) {
			visited[S] = true;
			q.push({ S, cmd + "S" });
		}
		if (!visited[L]) {
			visited[L] = true;
			q.push({ L, cmd + "L" });
		}
		if (!visited[R]) {
			visited[R] = true;
			q.push({ R, cmd + "R" });
		}
	}
	return "";
}

int main() {
	int test; cin >> test;

	for (int t = 0; t < test; t++) {
		int a, b; cin >> a >> b;
		visited = vector<bool>(10000, false);

		cout << bfs(a, b) << endl;
	}
}