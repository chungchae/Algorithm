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

// PGS 전력망을 둘로 나누기 (BFS) (L2)

// 노드 개수를 리턴
int BFS(vector<vector<int>> edge, int start, int n) {
    vector<bool> visited(n + 1, false);
    int count = 0;

    queue<int> Q;
    Q.push(start);

    visited[start] = true;

    while (!Q.empty()) {
        count++;
        int now = Q.front();
        for (int node : edge[now]) {
            if (!visited[node]) {
                visited[node] = true;
                Q.push(node);
            }
        }
        Q.pop();
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;

    for (int i = 0; i < wires.size(); i++) {
        // 간선 그래프로 변경
        vector<vector<int>> graph(n + 1);
        for (int j = 0; j < wires.size(); j++) {
            // 간선 하나를 끊기
            if (i == j) continue;
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int A = BFS(graph, wires[i][0], n);
        int B = n - A;

        answer = min(answer, abs(A - B));
    }


    return answer;
}