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

using namespace std;

// BOJ 2805 나무 자르기 (binary_search) (S2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    int maxH = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        // 최댓값 찾기
        maxH = max(maxH, arr[i]);
    }

    int left = 0, right = maxH;
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] > mid) sum += arr[i] - mid;
        }

        if (sum >= M) {
            ans = mid;    
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;
}


