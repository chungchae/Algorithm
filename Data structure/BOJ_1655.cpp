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

// BOJ 1655 가운데를 말해요 (Data structure) (G2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//큰 값이 우선인 큐1, 작은 값이 우선인 큐2 선언
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;

	pq1.push(-1e9); pq2.push(1e9);

	int N; cin >> N;

	for (int total = 0; total < N; total++) {
		//삽입
		int now; cin >> now;
		int top1 = pq1.top(); int top2 = pq2.top();

		//큐2의 최솟값보다 크다면 큐2에 삽입
		if (now > top2)pq2.push(now);
		//나머지는 큐1에 삽입
		else pq1.push(now);

		//정리1: 두 큐가 오름차순 정렬되도록 교환
		while (pq1.top() > pq2.top()) {
			if (pq1.top() > pq2.top()) {
				int temp1 = pq1.top();
				int temp2 = pq2.top();

				pq1.pop(); pq2.pop();

				pq1.push(temp2); pq2.push(temp1);
			}
		}
		//정리2: 두 큐의 사이즈가 같아지도록 각 큐의 top들을 이동
		while (pq1.size() != pq2.size() && pq1.size() - 1 != pq2.size()) {
			if (pq1.size() < pq2.size()) {
				int temp2 = pq2.top();
				pq1.push(temp2);
				pq2.pop();
			}
			else if (pq1.size() > pq2.size()) {
				int temp1 = pq1.top();
				pq2.push(temp1);
				pq1.pop();
			}
		}

		//출력은 큐1의 top (짝수라면 작은값이 우선이므로)
		cout << pq1.top() << "\n";
	}
}


