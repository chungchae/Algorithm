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

// BOJ 14940 쉬운 최단거리 (BFS) (S1)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	// 입력받을 그래프 배열
	vector<vector<int>> arr(N, vector<int>(M));

	// 방문 여부 배열
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	// 최단거리 저장할 정답 배열
	vector<vector<int>> ans(N, vector<int>(M, 0));

	// BFS에 사용할 큐
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				Q.push({ i,j });
				ans[i][j] = 0;
				visited[i][j] = true;
			}
		}
	}
	int now = 1;

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;

		Q.pop();

		int dx[4] = { -1,1,0,0 };
		int dy[4] = { 0,0,-1,1 };

		// 상, 하, 좌, 우
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 인덱스 범위 검사
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			// 방문 여부 검사
			if (visited[nx][ny]) continue;
			// 벽인지 검사
			if (arr[nx][ny] == 0) continue;

			// 다 통과하면, 방문 처리 후
			visited[nx][ny] = true;
			// 이전 노드 + 1 을 정답 배열에 저장
			ans[nx][ny] = ans[x][y] + 1;
			// 큐에 추가
			Q.push({ nx,ny });
		}
	}

	// 방문 못한 1 타일은 -1로 처리
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				ans[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

