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

// PGS 완전범죄 (DP) (L2)

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<bool>> dp(n, vector<bool>(m, false));
    dp[0][0] = true;

    for (int i = 0; i < info.size(); i++) {
        int a_add = info[i][0];
        int b_add = info[i][1];

        vector<vector<bool>> next(n, vector<bool>(m, false));

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (!dp[a][b]) continue;
                if (a + a_add < n) next[a + a_add][b] = true;
                if (b + b_add < m) next[a][b + b_add] = true;
            }
        }

        dp = next;
    }
    int answer = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j]) {
                answer = min(answer, i);
            }
        }
    }
    if (answer == 1e9)return -1;
    else return answer;
}