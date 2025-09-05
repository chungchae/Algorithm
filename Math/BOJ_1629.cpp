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

// BOJ 1629 곱셉 (math) (S1)

long long halfPow(long long A, long long B, long long C) {
    if (B == 0)return 1;
    long long half = halfPow(A, B / 2, C);
    long long result = (half * half) % C;
    if (B % 2 == 1) {
        result = (result * A) % C;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C; cin >> A >> B >> C;

    cout << halfPow(A, B, C);
}
