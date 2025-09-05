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

// BOJ 10026 적록색약 (BFS) (G5)

vector<vector<char>> arr;
vector<vector<char>> arr2;

vector<vector<bool>> visited;
int N;

void bfs(int x, int y, char color) {
	queue<pair<int, int>> Q;

	Q.push({ x, y });

	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	while (!Q.empty()) {
		int now_x = Q.front().first;
		int now_y = Q.front().second;

		visited[now_x][now_y] = true;

		// 상하좌우 탐색
		for (int d = 0; d < 4; d++) {
			int nx = now_x + dx[d];
			int ny = now_y + dy[d];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] || arr[nx][ny] != color) continue;

			visited[nx][ny] = true;
			Q.push({ nx,ny });
		}
		Q.pop();
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	arr = vector<vector<char>>(N);
	arr2 = vector<vector<char>>(N);

	visited = vector<vector<bool>>(N, vector<bool>(N, false));

	

	for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		for (char c : temp) {
			arr[i].push_back(c);
			if (c == 'R') {
				arr2[i].push_back('G');
			}
			else {
				arr2[i].push_back(c);
			}
		}
	}
	int A = 0; int B = 0;

	// 일반 bfs
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j])
			{
				bfs(i, j, arr[i][j]);
				A++;
			}
		}
	}
	// 방문 배열 초기화
	visited = vector<vector<bool>>(N, vector<bool>(N, false));
	arr = arr2;

	// 적록색약 bfs
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j])
			{
				bfs(i, j, arr[i][j]);
				B++;
			}
		}
	}

	cout << A << " " << B;
}


