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

// PGS 더 맵게 (queue) (L2)

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // 오름차순 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> pq;

    // 1. 스코빌 배열을 우선순위 큐에 넣기 (오름차순)
    for (auto i : scoville) {
        pq.push(i);
    }
    // 2. front가 K를 넘지 않으면, 두개를 꺼내 섞은 후 큐에 추가
    while (pq.size() > 1) {
        if (pq.top() < K) {
            int a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(a + 2 * b);
            answer++;
        }
        // 3. front가 K를 넘으면 break
        else
            return answer;
    }
    // 4. 큐에 요소 하나만 남은 경우, K와 크기 비교
    if (pq.top() < K)
        return -1;
    else
        return answer;
}