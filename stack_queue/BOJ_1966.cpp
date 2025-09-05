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

// BOJ 1966 프린터 큐 (queue) (S3)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	for (int test = 0; test < T; test++) {
		// 큐의 길이, 타겟 인덱스
		int N, tg; cin >> N >> tg;
		vector<pair<int, int>> arr(N);

		for (int i = 0; i < N; i++) {
			int temp; cin >> temp;
			arr[i] = make_pair(i, temp);
		}

		int count = 0;
		while (!arr.empty()) {
			// 가장 앞의 문서의 중요도, 인덱스를 저장
			int now = arr[0].second;
			int now_index = arr[0].first;
			bool isOkay = true;
			// 남은 문서들 중에서
			for (int i = 0; i < arr.size(); i++) {
				// 중요도가 더 큰 문서가 있다면
				if (arr[i].second > now) {
					// 맨 뒤로 이동
					arr.erase(arr.begin());
					arr.push_back({ now_index, now });
					// okay를 false로 체크
					isOkay = false;
					break;
				}
			}
			// 중요도가 더 큰 문서가 없다면
			if (isOkay) {
				// 출력 카운트 + 1
				count++;
				// 만약 타겟 인덱스라면
				if (now_index == tg) {
					// 현재 출력 카운트를 출력하고, 반복 종료
					cout << count << "\n";
					break;
				}
				// 맨 앞 문서 출력
				arr.erase(arr.begin());
			}
		}
	}
}


