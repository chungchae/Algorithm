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

// PGS 다리를 지나는 트럭 (queue) (L2)

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 건너는 트럭: 무게/대기시간 pair, 대기 트럭
    vector<pair<int, int>> Q1; queue<int> Q2;
    // 대기 트럭에 삽입
    for (int i = 0; i < truck_weights.size(); i++) {
        Q2.push(truck_weights[i]);
    }

    // 경과 시간
    int answer = 0;
    // 현재 건너는 트럭의 총 무게
    int now_weight = 0;

    // 둘 다 빌 때까지
    while (!Q1.empty() || !Q2.empty()) {
        // 매 반복마다 1초씩 증가
        answer++;
        // 0. Q1의 front의 대기시간을 확인, 0이면 pop
        if (!Q1.empty() && Q1[0].second == 0) {
            now_weight -= Q1[0].first;
            Q1.erase(Q1.begin());
        }
        // 1. 건너는 트럭 + 다음 트럭이 무게를 초과하지 않는 경우
        if (!Q2.empty() && now_weight + Q2.front() <= weight) {
            now_weight += Q2.front();
            Q1.push_back({ Q2.front(), bridge_length });
            Q2.pop();
        }
        // 2. 건너는 트럭 + 다음 트럭이 무게를 초과하는 경우
        else {
            // 아무것도 안한다
        }
        // 매 반복마다, Q1의 요소들의 대기시간을 1씩 줄인다.
        for (int i = 0; i < Q1.size(); i++) {
            Q1[i].second--;
        }
    }

    return answer;
}