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

// BOJ 치킨 배달 (Implementation) (G5)

vector<vector<int>> ck_combination;

// 조합 함수
void make_combination(vector<int> now, int n, int size, int start) {
	if (now.size() == size) {
		ck_combination.push_back(now);
		return;
	}
	for (int i = start; i < n; i++) {
		now.push_back(i);
		make_combination(now, n, size, i+1);
		now.pop_back();
	}
}

int main() {
	int N, M; cin >> N >> M;

	//배열 저장
	vector<vector<int>> arr(N, vector<int>(N, 0));

	vector<pair<int, int>> ck;
	vector<pair<int, int>> pp;

	int a;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			if (a == 2) {
				ck.push_back({ i,j });
			}
			if (a == 1) {
				pp.push_back({ i,j });
			}
			arr[i][j] = a;
		}
	}
	// 전체 치킨집 수 C M 조합을 ck_combination에 저장
	make_combination({}, ck.size(), M, 0);

	int min_totaldis = 1e9;

	// 모든 조합에 대해서 최단거리 구하기
	for (vector<int> vv : ck_combination) {
		int now_sum = 0;
		for (auto p : pp) {
			int min_dis = 1e9;
			int px = p.first; int py = p.second;
			
			for (int index : vv) {
				int cx = ck[index].first;
				int cy = ck[index].second;

				min_dis = min(min_dis, abs(px - cx) + abs(py - cy));
			}
			now_sum += min_dis;
		}
		min_totaldis = min(min_totaldis, now_sum);
	}
	cout << min_totaldis;
}