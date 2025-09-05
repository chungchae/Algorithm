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

// BOJ_1325 (BFS)

int N, M;
vector<vector<int>> graph;
vector<int> result;

int bfs(int start) {
    vector<bool> visited(N + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                cnt++;
                q.push(next);
            }
        }
    }
    return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N + 1);
    result.resize(N + 1);

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int maxVal = 0;
    for (int i = 1; i <= N; ++i) {
        result[i] = bfs(i);
        maxVal = max(maxVal, result[i]);
    }

    for (int i = 1; i <= N; ++i) {
        if (result[i] == maxVal) {
            cout << i << " ";
        }
    }

    return 0;
}