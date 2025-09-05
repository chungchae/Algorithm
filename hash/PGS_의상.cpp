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

// PGS 의상 (hash) (L2)

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    // 정렬되지 않는 맵, 중복 비허용
    unordered_map<string, int> M;

    // 두번째 값 (옷 종류)의 해시 value를 1 증가
    for (int i = 0; i < clothes.size(); i++) {
        M[clothes[i][1]]++;
    }
    // M의 key, value에 대해서
    for (const auto& [key, value] : M) {
        // 입지 않는 경우까지, +1
        answer *= (value + 1);
    }
    // 아무것도 안입은 경우 제외 (-1)
    return answer - 1;
}