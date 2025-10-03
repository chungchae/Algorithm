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

// PGS 크레인 인형뽑기 게임 (Data Structure) (L1)

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int size = (int)board.size();

    vector<stack<int>> S(size);

    // 각 열마다 스택
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= 0; j--) {
            if (board[j][i] != 0) {
                S[i].push(board[j][i]);
            }
        }
    }

    stack<int> B;

    for (int mm : moves) {
        int m = mm - 1;
        if (!S[m].empty()) {
            int now = S[m].top();
            S[m].pop();

            if (!B.empty()) {
                if (now == B.top()) {
                    answer += 2;
                    B.pop();
                }
                else B.push(now);
            }
            else {
                B.push(now);
            }
        }
    }
    return answer;
}