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

// PGS PCCP 모의1-1 (Implementation) (*)
string solution(string input_string) {
    string answer = "";

    int n = input_string.length();
    map<char, int> m;

    for (int i = 0; i < n; i++) {
        char c = input_string[i];
        while (input_string[i] == c)i++;
        i--;
        m[c]++;
    }
    for (auto a : m) {
        if (a.second > 1) {
            answer += a.first;
        }
    }
    if (answer == "") return "N";
    return answer;
}