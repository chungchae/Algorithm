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

// PGS 멀리 뛰기 (DP) (L2)

using namespace std;

long long solution(int n) {
    long long answer = 0;

    long long DP[2001] = { 0, };
    // 초기화
    DP[1] = 1; DP[2] = 2;

    // DP
    for (int i = 3; i <= n; i++) {
        if (DP[i] == 0) {
            DP[i] = (DP[i - 1] + DP[i - 2]) % 1234567;
        }
    }
    answer = DP[n];

    return answer;
}

