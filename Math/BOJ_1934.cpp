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

// BOJ_1934 (Math)

int gcd(int a, int b) {
	int temp;
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	int a, b; int result;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		result = a * b / gcd(a, b);
		cout << result << "\n";
	}
}