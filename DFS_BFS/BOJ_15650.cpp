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

// BOJ 15650 N과 M(2) (DFS) (S3)

int N; int M;
vector<int> arr;
vector<bool> visited;

// DFS 백트래킹
void BT(int depth, int start) {
	if (depth == M) {
		for (int node : arr) {
			if (node != 0) {
				cout << node << " ";
			}
		}
		cout << "\n";
		return;
	}
	// 오름차순 구현을 위해 start 부터 시작
	for (int i = start; i <= N; i++) {
		// 미방문 노드를 방문 처리한 뒤, 계속 탐색
		if (!visited[i]) {
			visited[i] = true;
			arr[depth] = i;
			BT(depth + 1, i + 1);
			visited[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	arr = vector<int>(M, 0);
	visited = vector<bool>(N + 1, false);

	BT(0, 1);
}


