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

// PGS JadenCase 문자열 만들기 (Implementation) (L2)

using namespace std;

string solution(string s) {
    string answer = "";

    if (s[0] >= 'a') {
        s[0] -= 32;
    }
    // 이전 문자가 공백이고, 현재 문자가 공백이 아니라면
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != ' ' && s[i - 1] == ' ') {
            // 소문자 -> 대문자
            if (s[i] >= 'a') {
                s[i] -= 32;
            }
        }
        else {
            if (s[i] != ' ' && s[i] < 'a') {
                s[i] += 32;
            }
        }
    }
    answer = s;

    return answer;
}

