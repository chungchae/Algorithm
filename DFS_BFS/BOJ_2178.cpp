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

// BOJ_2178 (DFS, BFS)

static int G[101][101];
static bool visited[101][101] = { false };
static int N, M;
static int dx[] = { 0,1,0,-1 };
static int dy[] = { 1,0,-1,0 };


void BFS(int a, int b) {
	deque<pair<int, int>> Q;
	Q.push_back(make_pair(a, b));

	while (!Q.empty()) {
		int now_x, now_y;
		now_x = Q.front().first;
		now_y = Q.front().second;
		Q.pop_front();
		visited[a][b] = true;

		for (int k = 0; k < 4; k++) {
			int x = now_x + dx[k];
			int y = now_y + dy[k];

			if (x >= 0 && y >= 0 && x < N && y < M) {
				if (G[x][y] != 0 && !visited[x][y]) {
					visited[x][y] = true;
					G[x][y] = G[now_x][now_y] + 1;
					Q.push_back(make_pair(x, y));
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int k = 0; k < M; k++) {
			G[i][k] = s[k] - '0';
		}
	}

	BFS(0, 0);
	cout << G[N - 1][M - 1];
}