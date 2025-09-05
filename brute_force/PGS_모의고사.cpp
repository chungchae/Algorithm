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

// PGS 모의고사 (brute_force) (L1)

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    // 각 배열 저장
    vector<int> A = { 1, 2, 3, 4, 5 };
    vector<int> B = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> C = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int a = 0; int b = 0; int c = 0;

    // 맞춘 문제의 수를 저장
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == A[i % 5]) a++;
        if (answers[i] == B[i % 8]) b++;
        if (answers[i] == C[i % 10]) c++;
    }
    // 가장 많이 맞춘 문제 수를 maxScore에 저장
    int maxScore = max({ a, b, c });

    if (a == maxScore) answer.push_back(1);
    if (b == maxScore) answer.push_back(2);
    if (c == maxScore) answer.push_back(3);

    return answer;
}