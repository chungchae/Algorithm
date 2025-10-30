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

// BOJ 15654 N과 M(5) (DFS) (S3)

vector<int> arr;
vector<vector<int>> ans;
vector<bool> check;

//순열은 visited를 사용
//조합은 start 인덱스를 넘긴다
void dfs(vector<int> now, int target) {
	if (now.size() == target) {
		ans.push_back(now);
		return;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (!check[i]) {
			now.push_back(arr[i]);
			check[i] = true;
			dfs(now, target);
			check[i] = false;
			now.pop_back();
		}
		
	}
}


int main() {
	int N, M; cin >> N >> M;

	arr = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	check = vector<bool>(N, false);

	dfs({}, M);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}