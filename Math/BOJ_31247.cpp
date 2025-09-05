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

// BOJ 31247 2024는 무엇이 특별할까? (math) (S1)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int test = 0; test < T; test++) {
        long long N, K; cin >> N >> K;

        // 2^K 가 범위를 초과하는 경우, 0 출력
        if (K > 60) {
            cout << 0 <<"\n";
            continue;
        }

        // long long 형의 1을 K만큼 shift = 2^K
        long long pow2K = 1LL << K;

        // 2^K+1 을 조건부 설정
        // 너무 커지는 경우 4e18이라는 큰 숫자로 대체
        long long pow2K1 = (K + 1 > 60) ? (long long)4e18 : (1LL << (K + 1));

        //N/2^K - N/2^K+1 을 계산하면, 2^K * (홀수) 의 개수
        long long res = N / pow2K - N / pow2K1;
        cout << res << "\n";
    }
}

// 문제에서 규칙을 찾고. 제한 시간에 맞춰 구현하는 것이 중요