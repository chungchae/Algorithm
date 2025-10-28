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

// BOJ 연구소 (BFS) (G4)

vector<vector<int>> comb_answer;
vector<vector<int>> arr;
vector<vector<bool>> visited;

//벽 조합
void combination(vector<int> now, int start, int total) {
	if (now.size() == 3) {
		comb_answer.push_back(now);
		return;
	}
	for (int i = start; i < total; i++) {
		now.push_back(i);
		combination(now, i+1, total);
		now.pop_back();
	}
}

//안전구역 개수 리턴하는 함수
int count() {
	int result = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] == 0)result++;
		}
	}
	return result;
}

//바이러스 bfs
void bfs() {
	queue<pair<int, int>> q;
	int n = arr.size(); int m = arr[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}

	int count = 0;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		visited[nx][ny] = true;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int sx = nx + dx[i];
			int sy = ny + dy[i];

			if (sx >= 0 && sx < n && sy >= 0 && sy < m) {
				if (!visited[sx][sy] && arr[sx][sy]!=1) {
					visited[sx][sy] = true;
					arr[sx][sy] = 2;
					q.push({ sx, sy });
				}
			}
		}
	}
}

int main() {
	int N, M; cin >> N >> M;

	vector<vector<int>> origin(N, vector<int>(M));

	vector<pair<int, int>> zero;

	//0인 칸 좌표 zero에 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp; cin >> temp;
			if (temp == 0) {
				zero.push_back({ i, j });
			}
			origin[i][j] = temp;
		}
	}

	//zero 개수 C 3 조합을 comb_answer에 저장
	combination({}, 0, zero.size());
	int ans = 0;
	
	//모든 조합에 대해서
	for (vector<int> v : comb_answer) {
		visited = vector<vector<bool>>(N, vector<bool>(M, false));
		arr = origin;

		//조합 벡터 기준으로 벽 세우기
		for (int a : v) {
			arr[zero[a].first][zero[a].second] = 1;
		}
		//벽 세우고 나서 bfs로 바이러스 전파
		//!!!바이러스가 여러 개 있는 경우, 바이러스들을 큐에 전부 넣고 bfs 하는 게 효율적!!!
		bfs();

		//안전구역 개수로 answer 갱신
		ans = max(ans,count());
	}
	cout << ans;
}