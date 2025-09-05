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

// PGS 야근 지수 (Data structure) (L3)

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pq;
    // 우선순위 큐에 다 넣기
    for (int now : works) pq.push(now);

    // 맨 위(최댓값) 꺼내서 -1 후 다시 넣기 반복
    while (n > 0) {
        int top = pq.top();
        pq.pop();
        if (top > 0)top--;
        pq.push(top);
        n--;
    }

    // 전부 꺼내서 제곱 연산
    for (int i = 0; i < works.size(); i++) {
        int top = pq.top();
        pq.pop();
        answer += top * top;
    }

    return answer;
}