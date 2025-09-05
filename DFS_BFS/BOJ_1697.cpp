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

// BOJ 1697 숨바꼭질 (BFS) (S1)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M; cin >> N >> M;

	// 현재 위치, 현재 카운트 pair로 선언
	queue<pair<int, int>> Q;
	bool visited[100001] = { false, };

	int count = 0;
	// 큐에 시작점 넣기
	Q.push({ N, 0 });

	int a, b;
	while (1) {
		// a: 현재 위치 b: 현재 카운트
		a = Q.front().first;
		b = Q.front().second;

		// 맨 앞 노드를 방문처리 후
		visited[a] = true;

		// 큐에서 제거
		Q.pop();

		// 도착했다면 break
		if (a == M) {
			break;
		}

		// -1, +1, *2 에 대해 BFS 수행
		if (a - 1 >= 0 && a - 1 < 100001 && !visited[a - 1]) Q.push({ a - 1, b + 1 });
		if (a + 1 >= 0 && a + 1 < 100001 && !visited[a + 1]) Q.push({ a + 1, b + 1 });
		if (a * 2 >= 0 && a * 2 < 100001 && !visited[a * 2]) Q.push({ a * 2, b + 1 });
	}
	cout << b;
}

