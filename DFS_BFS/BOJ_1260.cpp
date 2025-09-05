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

// BOJ_1260 (DFS, BFS)
vector <vector<int>> G;
vector<bool> visited;

void DFS(int v) {
	cout << v << " ";
	visited[v] = true;
	for (int i : G[v]) {
		if (!visited[i])
			DFS(i);			
	}
}

void BFS(int v) {
	deque<int> Q;
	Q.push_back(v);
	visited[v] = true;

	while (!Q.empty()) {
		int now = Q.front();
		cout << now << " ";
		Q.pop_front();
		for (int i : G[now]) {
			if (!visited[i])
			{
				visited[i] = true;
				Q.push_back(i);
			}
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	int a, b;

	G.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(G[i].begin(), G[i].end());
	}
	visited = vector<bool>(N + 1, false);

	DFS(V);
	cout << "\n";

	fill(visited.begin(), visited.end(), false);
	BFS(V);
}