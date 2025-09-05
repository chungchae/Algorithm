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

// BOJ_1183 (Math)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> diff(N);

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        diff[i] = B - A;
    }

    sort(diff.begin(), diff.end());

    if (N % 2 == 1) {
        cout << 1 << "\n";
    }
    else {
        int left = diff[N / 2 - 1];
        int right = diff[N / 2];
        cout << right - left + 1 << "\n";
    }

}