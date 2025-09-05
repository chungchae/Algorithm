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

// BOJ_1004 (Math)

bool isIn(int x, int y, int a, int b, int r) {
	float dis = sqrt((x - a) * (x - a) + (y - b) * (y - b));
	if (dis <= r)
		return true;
	else
		return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	int x1, y1, x2, y2;
	int N;
	int count;
	int a, b, r;
	for (int i = 0; i < T; i++) {
		count = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> N;
		for (int k = 0; k < N; k++) {
			cin >> a >> b >> r;
			if (isIn(x1, y1, a, b, r) != isIn(x2, y2, a, b, r)) {
				count++;
			}
		}
		cout << count << "\n";
	}
}