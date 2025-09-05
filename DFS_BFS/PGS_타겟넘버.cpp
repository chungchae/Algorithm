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

// PGS 타겟 넘버 (DFS) (L2)

using namespace std;

void DFS(vector<int> numbers, int target, int now, int index, int& answer) {
    if (index == numbers.size()) {
        if (now == target)
            answer++;
        return;
    }
    DFS(numbers, target, now + numbers[index], index + 1, answer);
    DFS(numbers, target, now - numbers[index], index + 1, answer);

}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(numbers, target, 0, 0, answer);

    return answer;
}