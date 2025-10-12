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

// PGS 숫자 문자열과 영단어 (Implementation) (L1)

int solution(string s) {
    int answer = 0;
    string ans = "";

    string sarr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    string temp = "";

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            ans += s[i];
        }
        else {
            temp += s[i];
        }

        if (temp.length() > 2) {
            for (int j = 0; j < 10; j++) {
                if (sarr[j] == temp) {
                    ans += to_string(j);
                    temp = "";
                    break;
                }
            }
        }
    }

    answer = stoi(ans);
    return answer;
}