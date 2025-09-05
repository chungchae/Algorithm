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

// PG 큰 수 만들기 (greedy) (L2)

string solution(string number, int k) {
    string answer = "";

    // number 배열의 각 숫자에 대해서
    for (char digit : number) {
        while (!answer.empty() && answer.back() < digit && k > 0) {
            answer.pop_back();
            k--;
        }
        answer.push_back(digit);
    }

    if (k > 0) answer = answer.substr(0, answer.size() - k);

    return answer;
}