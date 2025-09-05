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

// PGS 타겟 넘버 (BFS) (L3)

using namespace std;

//BFS
void BFS(vector<vector<int>> edge, vector<bool>& visited, int start) {
    queue<int> Q;
    Q.push(start);

    while (!Q.empty()) {
        int now = Q.front();
        for (int node : edge[now]) {
            if (!visited[node]) {
                visited[node] = true;
                Q.push(node);
            }
        }
        Q.pop();
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    // 방문 여부 벡터
    vector<bool> visited(n, false);
    vector<vector<int>> edge(n);

    // edge 배열로 바꿔 저장
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (computers[i][k] == 1) {
                edge[i].push_back(k);
            }
        }
    }

    // 방문 안한 노드가 있다면, BFS
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            BFS(edge, visited, i);
            answer++;
        }
    }

    return answer;
}