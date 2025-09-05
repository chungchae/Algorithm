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

// BOJ_1614

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int fin;
	long long count;
	cin >> fin;
	cin >> count;

	switch (fin) {
	case 1:
		cout << count * 8;
		break;
	case 2:
		if (count % 2 == 0) {
			cout << count * 4 + 1;
		}
		else {
			cout << count * 4 + 3;
		}
		break;
	case 3:
		cout << count * 4 + 2;
		break;
	case 4:
		if (count % 2 == 0) {
			cout << count * 4 + 3;
		}
		else {
			cout << count * 4 + 1;
		}
		break;
	case 5:
		cout << count * 8 + 4;
		break;
	}
}