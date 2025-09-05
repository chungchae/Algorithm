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

using namespace std;

// BOJ_1072 (math)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long X, Y;
    cin >> X >> Y;

    int Z = (Y * 100) / X;

    if (Z >= 99) {
        cout << -1 << "\n";
        return 0;
    }

    long long left = 1;
    long long right = 1e9;
    long long result = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long newZ = (Y + mid) * 100 / (X + mid);

        if (newZ > Z) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << result << "\n";
}