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

// PG 모음 사전 (Brute_force) (L2)

string change(string cur, int length) {
    if (cur[length - 1] == 'A') {
        cur[length - 1] = 'E';
    }
    else if (cur[length - 1] == 'E') {
        cur[length - 1] = 'I';
    }
    else if (cur[length - 1] == 'I') {
        cur[length - 1] = 'O';
    }
    else if (cur[length - 1] == 'O') {
        cur[length - 1] = 'U';
    }
    return cur;
}

int solution(string word) {
    int answer = 1;
    string cur = "A";

    while (cur != "UUUUU") {
        if (cur == word)
            break;
        int length = cur.length();

        if (length < 5) {
            cur.push_back('A');
        }
        else {
            while (!cur.empty() && cur.back() == 'U') {
                cur.pop_back();
            }
            cur = change(cur, cur.length());
        }
        answer++;
    }

    return answer;
}