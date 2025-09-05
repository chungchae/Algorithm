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

using namespace std;

// BOJ_2606 (BFS) (S3)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N;
    cin >> M;

    // 연결 그래프 2차원 벡터로 선언
    vector<vector<int>> arr;
    // 방문 여부 bool 벡터
    vector<bool> visited(N + 1, false);

    arr.resize(N + 1);

    int a, b;

    // 양방향 그래프 이므로, 양쪽 입력
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    // BFS를 위해 큐 선언, 1기준 탐색이므로 큐에 넣고 방문 처리
    queue<int> Q;
    Q.push(1);
    int front;
    int count = 0;
    visited[1] = true;

    // 큐가 빌 때 까지 반복
    while (!Q.empty()){
        front = Q.front();
        for (int node : arr[front]) {
            if (!visited[node]) {
                Q.push(node);
                visited[node] = true;
            }
        }
        Q.pop();
        // 한 루프마다 count를 1씩 증가
        count++;
    }
    // 1을 제외하고 count를 출력
    cout << count - 1;
}