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

// BOJ_1012 (DFS, BFS)

static int G[51][51] = { 0 };
static bool visited[51][51] = { false };
static int N, M;
static int dx[] = { 0,1,0,-1 };
static int dy[] = { 1,0,-1,0 };
static int anw;


void BFS(int a, int b) {
	deque<pair<int, int>> Q;
	Q.push_back(make_pair(a, b));
	visited[a][b] = true;

	while (!Q.empty()) {
		int now_x, now_y;
		now_x = Q.front().first;
		now_y = Q.front().second;
		Q.pop_front();

		for (int k = 0; k < 4; k++) {
			int x = now_x + dx[k];
			int y = now_y + dy[k];

			if (x >= 0 && y >= 0 && x < N && y < M) {
				if (G[x][y] != 0 && !visited[x][y]) {
					visited[x][y] = true;
					Q.push_back(make_pair(x, y));
				}
			}
		}
	}
}

int main() {
	int c;
	cin >> c;
	for (int temp = 0; temp < c; temp++) {
		int T;
		anw = 0;
		cin >> N >> M >> T;
		for (int i = 0; i < 51; i++) {
			for (int k = 0; k < 51; k++) {
				G[i][k] = 0;
			}
		}
		for (int i = 0; i < 51; i++) {
			for (int k = 0; k < 51; k++) {
				visited[i][k] = false;
			}
		}
		for (int i = 0; i < T; i++) {
			int a, b;
			cin >> a >> b;
			G[a][b] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				if (G[i][k] == 1 && !visited[i][k])
				{
					BFS(i, k); anw++;
				}
			}
		}
		cout << anw << "\n";
	}
}