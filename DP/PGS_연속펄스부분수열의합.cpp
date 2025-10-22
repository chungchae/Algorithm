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

// PGS 연속 펄스 부분 수열의 합 (DP) (L3)

long long solution(vector<int> sequence) {
    long long answer = 0;

    int n = sequence.size();

    // {1, -1, 1, ..} -> dp1
    // {-1, 1, -1, ..} -> dp2
    vector<long long> dp1(n); dp1[0] = sequence[0];
    vector<long long> dp2(n); dp2[0] = (-1 * sequence[0]);


    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            dp1[i] = max(dp1[i - 1] + sequence[i], (long long)sequence[i]);
            dp2[i] = max(dp2[i - 1] + (-1 * sequence[i]), (long long)(-1 * sequence[i]));
        }
        else {
            dp1[i] = max(dp1[i - 1] + (-1 * sequence[i]), (long long)(-1 * sequence[i]));
            dp2[i] = max(dp2[i - 1] + sequence[i], (long long)sequence[i]);
        }
    }
    // 두 dp 최댓값 중 큰 값 반환
    answer = max(*max_element(dp1.begin(), dp1.end()), *max_element(dp2.begin(), dp2.end()));
    return answer;
}