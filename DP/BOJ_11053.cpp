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

// BOJ 11053 가장 긴 증가하는 부분 수열 (DP) (S2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> arr(N, 0);
	// DP[n] = n번째 원소 기준, 가장 긴 증가하는 부분 수열의 길이
	vector<int> DP(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	DP[0] = 1;
	// n 이전의 원소 중 길이가 최대이고, 배열의 값이 작은 값을 찾아 +1
	for (int i = 1; i < N; i++) {
		int max = 0; int maxi = 0;
		for (int j = 0; j < i; j++) {
			if (DP[j] > max && arr[j] < arr[i]) {
				max = DP[j];
			}
			DP[i] = max + 1;
		}
	}
	// DP배열 중 가장 긴 값을 출력
	int answer = *max_element(DP.begin(), DP.end());
	cout << answer;
}

