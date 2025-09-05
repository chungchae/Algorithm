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

// BOJ 10431 줄세우기 (Implementation) (S5)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	for (int total = 0; total < N; total++) {
		int now; cin >> now;
		vector<int> arr(20);

		for (int i = 0; i < 20; i++) {
			cin >> arr[i];
		}
		int count = 0;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[j] > arr[i])
					count++;
			}
		}

		cout << total + 1 << " " << count << "\n";
	}
}