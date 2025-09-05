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

// PGS 프로세스 (queue) (L2)

int solution(vector<int> priorities, int location) {

	queue<pair<int, int>> Q;
	priority_queue<int> PQ; // 오름차순 정렬

	// 큐에는 인덱스, 우선순위를 pair로 저장
	// 우선순위 큐에는 우선순위를 오름차순 저장
	for (int i = 0; i < priorities.size(); i++) {
		Q.push({ i, priorities[i] });
		PQ.push(priorities[i]);
	}
	int answer = 0;

	while (!Q.empty()) {
		int idx = Q.front().first;
		int priority = Q.front().second;
		Q.pop();

		// 우선순위 낮으면 맨 뒤로
		if (priority < PQ.top()) {
			Q.push({ idx, priority });
		}
		// 우선순위 높으면 실행, location과 idx 비교하여 answer 리턴
		else {
			PQ.pop();
			answer++;
			if (idx == location) return answer;
		}
	}

	return answer;
}