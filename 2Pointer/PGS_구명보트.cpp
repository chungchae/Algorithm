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

// PGS 구명보트 (2Pointer) (L2)

int solution(vector<int> people, int limit) {
    int answer = 0;
    // 1. 오름차순 정렬
    sort(people.begin(), people.end());

    // 2. 왼쪽 가벼운 사람 포인터, 오른쪽 무거운 사람 포인터
    int left = 0;
    int right = people.size() - 1;

    while (left <= right) {
        // 3. 둘 다 태울 수 있다면, left, right 둘다 한 칸씩 이동
        if (people[left] + people[right] <= limit) {
            left++;
        }
        // 4. 둘 다 못 탄다면, 무거운 사람만 태우기
        right--;
        // 5. 매 반복마다 answer + 1
        answer++;
    }
    return answer;
}