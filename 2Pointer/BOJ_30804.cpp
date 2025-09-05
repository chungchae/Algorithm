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

// BOJ 30804 과일 탕후루 (2-pointer) (S2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<int> arr(N, 0);
	set<int> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int a = 0; int b = 0;
	unordered_map<int, int> M;

	int maxLen = 0;

	while (b < N) {
		M[arr[b]]++;

		while (M.size() > 2) {
			M[arr[a]]--;
			if (M[arr[a]] == 0) {
				M.erase(arr[a]);
			}
			a++;
		}

		maxLen = max(maxLen, b - a + 1);
		b++;
	}

	cout << maxLen;
}


