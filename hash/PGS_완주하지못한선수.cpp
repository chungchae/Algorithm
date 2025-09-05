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

// PGS 완주하지 못한 선수 (hash) (L1)

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    // 두 벡터 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // 처음 불일치가 생기면 반환
    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) {
            return participant[i];
            break;
        }
    }
    //마지막까지 불일치가 없다면, 마지막 요소 반환
    return participant.back();
}