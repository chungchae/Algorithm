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

// BOJ 14889 스타트와 링크 (Implementation) (S1)

vector<vector<int>> comb;

// 조합 만드는 함수
// 현재 벡터, 타깃 사이즈, 현재 인덱스, 전체 사이즈
void gen_comb(vector<int> c, int size, int now, int total) {
	if (c.size() == size) {
		comb.push_back(c);
		return;
	}
	for (int i = now; i < total; i++) {
		c.push_back(i);
		gen_comb(c, size, i+1, total);
		c.pop_back();
	}
}

int main() {
	int N; cin >> N;

	vector<vector<int>> arr(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	gen_comb({}, N / 2, 0, N);

	int min_result = 1e9;

	for (vector<int> v : comb) {
		vector<bool> isSelected(N, false);

		for (int i = 0; i < v.size(); i++) {
			isSelected[v[i]] = true;
		}

		int sum1 = 0; int sum2 = 0;
		//1번그룹 계산
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(isSelected[i] && isSelected[j])
					sum1 += arr[i][j];
			}
		}

		//2번그룹 계산
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!isSelected[i] && !isSelected[j])
					sum2 += arr[i][j];
			}
		}

		min_result = min(min_result, abs(sum1 - sum2));
	}
	cout << min_result;
}