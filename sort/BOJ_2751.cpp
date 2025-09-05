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

// BOJ_2751 (sort) (S5)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    // 우선순위 큐 (내림차순)
    // 자료형, 컨테이너, 비교함수
    priority_queue<int, vector<int>, greater<int>> min_pq;

    int temp;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        min_pq.push(temp);
    }

    for (int i = 0; i < N; i++) {
        cout << min_pq.top() <<"\n";
        min_pq.pop();
    }
}