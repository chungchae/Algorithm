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

using namespace std;

// BOJ 11725(tree) (S2)
// DFS로 탐색하며, 이전 탐색 노드를 현재 노드의 정답(부모) 벡터에 저장

int main(){
	int N;
	cin >> N;
	// 그래프 저장 이차원 벡터
	vector<vector<int>> arr;
	// 방문 여부 벡터
	vector<bool> visited(N + 1, false);
	// 정답(부모) 저장 벡터
	vector<int> answer(N + 1, 0);
	int a, b;
	arr.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	stack<int> S;
	S.push(1);
	int now;
	visited[1] = true;

	// DFS -> stack 사용
	while (!S.empty()) {
		// now 는 stack의 top
		now = S.top(); S.pop();
		// now의 모든 자식 노드에 대해서 탐색
		for (int node : arr[now]) {
			// 미방문 노드라면
			if (!visited[node]) {
				// 방문 처리 후 스택에 넣고, 부모 노드를 저장
				visited[node] = true;
				S.push(node);
				answer[node] = now;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << answer[i] << "\n";
	}
}