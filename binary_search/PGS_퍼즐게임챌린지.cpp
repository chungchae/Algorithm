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

using namespace std;

// PGS (binary_search) (L2)

// 걸리는 시간을 계산하는 함수
int time(int diff, int prev, int cur) {
	return (long long)(prev + cur) * diff + cur;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {

	long long cur;
	int start = 1;
	int end = *max_element(diffs.begin(), diffs.end());
	int mid;
	int answer = end;

	// 이진 탐색
	while (start <= end) {
		cur = times[0];
		mid = (start + end) / 2;

		for (int i = 1; i < diffs.size(); i++) {
			if (mid >= diffs[i])
				cur += times[i];
			else {
				cur += time(diffs[i] - mid, times[i - 1], times[i]);
			}
			if (cur > limit) break;
		}
		if (cur <= limit) {
			answer = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}


	return answer;
}