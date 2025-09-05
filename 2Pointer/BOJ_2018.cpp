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

// BOJ_2018 (2-pointer)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	int count = 1;	int s = 1; int e = 1; int sum = 1;
	
	cin >> N;

	while (e != N) {
		if (sum == N) {
			count++;
			e++;
			sum += e;
		}
		else if (sum > N) {
			sum -= s;
			s++;
		}
		else {
			e++;
			sum += e;
		}
	}
	cout << count << "\n";
}