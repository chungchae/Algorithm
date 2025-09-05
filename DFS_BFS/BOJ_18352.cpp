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

// BOJ_18352 (BFS)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector <int>> arr;
	vector<int> distance(N + 1, 0);
	vector<bool> visited(N + 1, false);
	vector<int> ans;

	arr.resize(N + 1);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
	}

	queue<int> Q;
	Q.push(X);
	int front;

	while (!Q.empty()) {
		front = Q.front();
		visited[front] = true;
		for (int i : arr[front]) {
			if (!visited[i])
			{
				visited[i] = true;
				Q.push(i);
				distance[i] = distance[front] + 1;
			}
		}
		Q.pop();
	}

	int answer = 0;

	for (int i = 1; i <= N; i++) {
		if (distance[i] == K)
			ans.push_back(i);
	}
	if (!ans.empty()) {
		for (int k = 0; k < ans.size(); k++) {
			cout << ans[k] << "\n";
		}
	}
	else
		cout << "-1";
}