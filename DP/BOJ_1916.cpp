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

// BOJ 1916 최소비용 구하기 (dp) (G5)

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<vector<pair<int, int>>> g(N+1);
	for (int i = 0; i < M; i++) {
		int s, e, w;
		cin >> s >> e >> w;

		g[s].push_back({ e, w });
		/*g[e].push_back({ s, w });*/
	}

	int start, end;
	cin >> start >> end;

	vector<int> dist(N + 1, 1e9);
	vector<bool> visited(N + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		auto [d, now] = pq.top();
		pq.pop();
		if (visited[now])continue;
		visited[now] = true;

		for (auto [next, cost] : g[now]) {
			int nd = d + cost;
			if (nd < dist[next]) {
				dist[next] = nd;
				pq.push({ nd, next });
			}
		}
	}
	cout << dist[end];
}