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

// PGS 크레인 인형뽑기 게임 (Implementation) (L1)

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int l = 10; int r = 12;
    int now;

    for (int nn : numbers) {
        if (nn == 0) {
            now = 11;
        }
        else now = nn;

        // 1, 4, 7 or 3, 6, 9 인 경우 처리
        if (now == 1 || now == 4 || now == 7) {
            l = now;
            answer += "L";
            continue;
        }
        if (now == 3 || now == 6 || now == 9) {
            r = now;
            answer += "R";
            continue;
        }

        // 이동 거리 계산
        int l_move = (abs(now - l)) / 3 + (abs(now - l)) % 3;
        int r_move = (abs(now - r)) / 3 + (abs(now - r)) % 3;

        if (l_move < r_move) {
            l = now;
            answer += "L";
        }
        else if (l_move > r_move) {
            r = now;
            answer += "R";
        }
        else { // 거리가 같은 경우
            if (hand == "right") {
                r = now;
                answer += "R";
            }
            else {
                l = now;
                answer += "L";
            }
        }
    }

    return answer;
}