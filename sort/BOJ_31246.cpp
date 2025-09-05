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

// BOJ 31246 모바일 광고 입찰 (sort) (S5)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K; cin >> N >> K;

    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;

        arr.push_back(a - b);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    if (arr[K - 1] >= 0) {
        cout << 0;
        return 0;
    }
    else {
        cout << -arr[K - 1];
        return 0;
    }
}
