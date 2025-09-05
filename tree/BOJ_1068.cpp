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

// BOJ 1068 (tree) (S1)
// 삭제 노드가 나오면 탐색을 중지, 자식 노드가 0인 노드는 리프 노드

int main(){
	int N;
	cin >> N;
	// 그래프 저장 이차원 벡터
	vector<vector<int>> arr;
	// 방문 여부 벡터
	vector<bool> visited(N + 1, false);

	int temp;
	// 삭제 노드
	int bomb;
	int root = 0;
	arr.resize(N + 1);

	// -1 이라면 root에 저장
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == -1) {
			root = i;
		}
		else {
			// 트리는 양방향 저장
			arr[temp].push_back(i);
			arr[i].push_back(temp);
		}
	}
	//삭제 노드
	cin >> bomb;

	//삭제 노드가 root와 같다면, 0 출력 후 종료
	if (bomb == root) {
		cout << 0;
		return 0;
	}

	stack<int> S;
	S.push(root);
	int now;
	visited[root] = true;

	int cNode;
	int answer = 0;

	// DFS -> stack 사용
	while (!S.empty()) {
		// now 는 stack의 top
		now = S.top(); S.pop();
		cNode = 0;
		// now의 모든 자식 노드에 대해서 탐색
		for (int node : arr[now]) {
			// 삭제 노드가 아니고
			if (node != bomb) {
				// 미방문 노드라면
				if (!visited[node]) {
					// 방문 처리 후 스택에 넣고, 부모 노드를 저장
					visited[node] = true;
					S.push(node);
					cNode++;
				}
			}
		}
		//자식 노드가 0이라면 answer 1 증가
		if (cNode == 0) answer++;
	}
	cout << answer;
}