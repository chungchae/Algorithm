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

// BOJ 18870 좌표 압축 (sort) (S2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<pair<int, int>> arr;
	
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		// <인덱스, 값> pair로 저장
		arr.push_back({ i, temp });
	}

	sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		// 값(second)을 기준으로 오름차순 정렬
		return a.second < b.second;
		});

	vector<int> ans(N);

	// 가장 작은 노드는 ans에 0으로 저장
	ans[arr[0].first] = 0;
	// 이전 값을 prev에 저장
	int prev = arr[0].second;
	int now = 0;
	for (int i = 1; i < N; i++) {
		// 이전 값과 동일하다면, 같은 인덱스를 저장
		if (arr[i].second != prev) now++;
		ans[arr[i].first] = now;
		prev = arr[i].second;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
}

