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

// BOJ_2839 (Math)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int count = 0;

	int k = N / 5;
	int j = N - 5 * k;
	count += k;

	while (j <= N) {
		if (j % 3 == 0) {
			count += j / 3;
			cout << count;
			return 0;
		}
		else
		{
			j += 5;
			count--;
		}
	}
	cout << "-1";

}