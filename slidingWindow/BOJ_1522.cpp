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

using namespace std;

// BOJ_1522 (sliding_window)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string arr;
    cin >> arr;

    //a 개수
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 'a')
            count++;
    }
    //원형이므로, 배열 늘려줌
    arr = arr + arr;

    //반환할 최솟값
    int min_count = count;
    //윈도우 속 b 개수
    int b_count = 0;

    //슬라이딩 윈도우
    for (int i = 0; i < arr.size() - count; i++) {
        for (int j = 0; j < count; j++)
        {
            if (arr[i + j] == 'b')
                b_count++;
        }
        if (b_count < min_count)
            min_count = b_count;
        b_count = 0;
    }
    cout << min_count;

}