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

// PGS 같은 숫자는 싫어 (stack) (L1)

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	for (int i = 0; i < arr.size(); i++) {
		// answer 배열이 비어있다면, 삽입
		if (answer.empty()) {
			answer.push_back(arr[i]);
		}
		// answer 배열이 비어있지 않다면, back 값과 비교해 다른 경우에만 삽입
		else if (arr[i] != answer.back()) {
			answer.push_back(arr[i]);
		}
	}

	return answer;
}