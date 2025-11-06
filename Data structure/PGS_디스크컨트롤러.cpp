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

// PGS 디스크 컨트롤러 (Data structure) (L3)

// jobs: 요청시점/소요시간
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<int> ans;

    //기본 큐(요청 시점 기준 less 정렬) 요청 시점, 소요 시간
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
    //대기 큐(소요 시간 기준 less 정렬) 소요 시간, 요청 시점
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

    for (vector<int> j : jobs) {
        pq1.push({ j[0], j[1] });
    }

    int now = 0;
    while (!pq1.empty() || !pq2.empty()) {
        //기본 큐에서 요청 시간이 지난 작업을 대기 큐로 보내기
        while (!pq1.empty()) {
            if (pq1.top().first <= now) {
                auto [b, a] = pq1.top();
                pq2.push({ a,b });
                pq1.pop();
            }
            else break;
        }

        //대기 큐에서 작업 꺼내기
        if (!pq2.empty()) {
            now += pq2.top().first;
            ans.push_back(now - pq2.top().second);
            pq2.pop();
        }
        else now++;

    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        sum += ans[i];
    }
    answer = (int)sum / ans.size();

    return answer;
}