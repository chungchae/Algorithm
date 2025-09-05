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

// PGS 기능 개발 (queue) (L2)

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // 현재 날짜
    int days = 0;

    for (int i = 0; i < progresses.size(); i++) {
        // 남은 작업량을 계산
        int remain = 100 - progresses[i] - speeds[i] * days;
        // 현재 날짜 기준, 완료되었다면 answer의 마지막 요소 +1 , 같이 배포
        if (remain <= 0)
            answer[answer.size() - 1]++;
        // 현재 날짜 기준, 완료할 수 없다면 days를 필요한 만큼 추가, answer에 1을 push_back
        else {
            int take = (remain + speeds[i] - 1) / speeds[i];
            days += take;
            answer.push_back(1);
        }
    }

    return answer;
}