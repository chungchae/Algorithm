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

// BOJ 18110 solved.ac (math) (S4)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	// N = 0 인 경우
	if (N == 0) {
		cout << 0;
		return 0;
	}
	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 제외할 수를 계산 (round로 반올림)
	// 내림: floor(), 올림: ceil(), 소수점 이하 버리기: trunc()
	int exp = round(N * 0.15);

	// 오름차순 정렬
	sort(arr.begin(), arr.end());

	// 평균 계산을 위한 총점 변수
	double sum = 0;

	for (int i = exp; i < N - exp; i++) {
		sum += arr[i];
	}

	// "/" 연산자는 피연산자 중 하나라도 실수형이면 소수점 계산
	int ans = round(sum / (N - exp * 2));
	cout << ans;
}


