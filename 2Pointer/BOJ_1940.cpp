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

using namespace std;

// BOJ_1940 (2-pointer)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> arr(N, 0);
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int count = 0;
	int s = 0; int e = N -1 ;

	while (s < e) {
		if ((arr[s] + arr[e]) == M) {
			s++;
			e--;
			count++;
		}
		else if ((arr[s] + arr[e]) < M) {
			s++;
		}
		else {
			e--;
		}
	}

	cout << count;
}