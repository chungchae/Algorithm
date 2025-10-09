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

// PGS 불량 사용자 (DFS) (L3)

vector<bool> visited;
vector<vector<int>> arr;
int n2;
set<vector<int>> S;

void DFS(int now, vector<int>& result) {
    //끝까지 탐색했다면, 정렬 후 set에 insert
    if (result.size() == n2) {
        //result를 그대로 넣으면 백트래킹 중 오류
        vector<int> temp = result;
        //임시 vector를 생성해 정렬 후 set에 insert
        sort(temp.begin(), temp.end());
        S.insert(temp);
        return;
    }

    for (int node : arr[now]) {
        if (!visited[node]) {
            //재귀, 백트래킹
            visited[node] = true;
            result.push_back(node);
            DFS(now + 1, result);
            visited[node] = false;
            result.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    int n1 = user_id.size();
    n2 = banned_id.size();

    arr = vector<vector<int>>(n2);

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n1; j++) {
            //각 문자 일치 확인
            bool isSame = true;
            string str1 = user_id[j]; string str2 = banned_id[i];
            if (str1.length() != str2.length()) {
                isSame = false;
                continue;
            }
            else {
                for (int k = 0; k < str1.length(); k++) {
                    if (str2[k] == '*') continue;
                    if (str1[k] != str2[k]) {
                        isSame = false; break;
                    }
                }
            }
            //일치한다면, arr에 push_back
            if (isSame) {
                arr[i].push_back(j);
            }
        }
    }

    //DFS
    visited = vector<bool>(n1, false);
    vector<int> result;

    DFS(0, result);
    answer = S.size();

    return answer;
}