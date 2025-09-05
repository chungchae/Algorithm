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

using namespace std;

// BOJ_1747 (Math)

bool isPalindrome(int num) {
	string str;
	str = to_string(num);
	int size = str.size();

	string str1 = str.substr(0, size / 2);
	string str2 = str.substr((size + 1) / 2, size / 2);

	reverse(str2.begin(), str2.end());

	return str1 == str2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<bool> arr(10000001, true);

	arr[1] = false;
	// Optimize with square root to reduce time complexity
	// Any factor larger than sqrt(N) must have a smaller pair already checked
	for (int i = 2; i <= sqrt(10000001); i++) {
		if (arr[i]) {
			for (int j = i + i; j <= 10000000; j += i) {
				if (j % i == 0) {
					arr[j] = false;
				}
			}
		}
	}

	for (int i = N; i <= 10000000; i++) {
		if (arr[i] && isPalindrome(i)) {
			cout << i;
			return 0;
		}
	}
}