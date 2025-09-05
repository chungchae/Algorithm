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

// BOJ_2023 (DFS)

static int N; 

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
void DFS(int num, int index) {
	if (index == N) {
		if (isPrime(num)) {
			cout << num << "\n";
		}
		return;
	}
	for(int i = 1; i < 10; i++) {
		if (i % 2 == 0) {
			continue;
		}
		if (isPrime(num * 10 + i)) {
			DFS(num * 10 + i, index + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
}