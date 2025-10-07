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

// PGS 보석 쇼핑 (2Pointer) (L3)

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    set<string> S;
    for (string str : gems) {
        S.insert(str);
    }
    //보석 종류 수 set으로 계산 후 저장
    int num = S.size();

    map<string, int> M;

    int l = 0; int r = 0;
    M[gems[l]]++;

    //구간 최소 계산
    int min_size = 1e9;
    // 투 포인터로 탐색
    while (l <= r && r < gems.size() && l < gems.size()) {
        if (M.size() == num) {
            //기존 최소 구간보다 짧다면 갱신
            if ((r - l) < min_size) {
                min_size = r - l;
                answer = { l + 1,r + 1 };
            }//옮길 기존 왼쪽 포인터의 보석이 1개였다면, map에서 제거
            M[gems[l]]--;
            if (M[gems[l]] == 0) M.erase(gems[l]);
            if (l + 1 == gems.size()) break;
            l++;
        }
        else {
            //보석 종류 수가 부족하다면 오른쪽 포인터를 한 칸 이동
            if (r + 1 == gems.size()) break;
            r++;
            M[gems[r]]++;
        }
    }

    return answer;
}