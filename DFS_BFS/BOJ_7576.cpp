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

// BOJ 7576 토마토 (BFS) (G5)

vector<vector<int>> arr;
vector<vector<int>> ans;
vector<vector<bool>> visited;

struct node {
	int x;
	int y;
	int day;
};

void bfs() {
	queue<node> Q;

	// 토마토가 있는 칸을 큐에 push
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] == 1) {
				Q.push({ i,j, 1 });
			}
		}
	}

	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	while (!Q.empty()) {
		int now_x = Q.front().x;
		int now_y = Q.front().y;
		int day = Q.front().day;

		visited[now_x][now_y] = true;

		// 정답 업데이트
		if (ans[now_x][now_y] == 0) ans[now_x][now_y] = day;
		else ans[now_x][now_y] = min(ans[now_x][now_y], day);

		// 상하좌우 탐색
		for (int d = 0; d < 4; d++) {
			int nx = now_x + dx[d];
			int ny = now_y + dy[d];

			if (nx < 0 || ny < 0 || nx >= arr.size() || ny >= arr[0].size()) continue;
			if (visited[nx][ny] || arr[nx][ny] == -1)continue;

			visited[nx][ny] = true;
			Q.push({ nx,ny,day + 1 });
		}
		Q.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> M >> N;

	arr = vector<vector<int>>(N, vector<int>(M));
	ans = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				ans[i][j] = -1;
			}
		}
	}
	visited = vector<vector<bool>>(N, vector<bool>(M, false));
	bfs();

	// 마지막 체크
	int max_time = 0;
	bool isOkay = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			max_time = max(max_time, ans[i][j]);
			if (ans[i][j] == 0)isOkay = false;
		}
	}
	if (isOkay) {
		cout << max_time - 1;
	}
	else {
		cout << -1;
	}
}


