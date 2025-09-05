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

// BOJ 20920 영단어 암기는 괴로워 (Data structure) (S3)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	map<string, int> m;

	// map에 입력
	for (int i = 0; i < N; i++) {
		string now; cin >> now;
		if (now.length() < M) continue;
		if (m.find(now) == m.end()) {
			m.insert({ now, 1 });
		}
		else {
			m[now]++;
		}
	}

	vector<pair<string, int>> arr(m.begin(), m.end());

	// 조건대로 정렬
	sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
		if (a.second == b.second) {
			if (a.first.length() == b.first.length()) {
				return a.first < b.first;
			}
			else {
				return a.first.length() > b.first.length();
			}
		}
		else {
			return a.second > b.second;
		}
		});

	for (auto node : arr) {
		cout << node.first << "\n";
	}

	return 0;
}