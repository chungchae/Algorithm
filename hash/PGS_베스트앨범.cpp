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

// PGS 베스트앨범 (hash) (L3)

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, int> genre_total;
	unordered_map<string, vector<pair<int, int>>> genre_songs;

	// 1. 장르별 총 재생 수, 장르별 곡 정보 저장
	for (int i = 0; i < genres.size(); i++) {
		// 장르별 총 재생 수
		genre_total[genres[i]] += plays[i];
		// 장르별 각 곡의 재생 수, 인덱스 저장
		genre_songs[genres[i]].push_back({ plays[i], i });
	}

	// 2. 총 재생 수 대로 정렬한 뒤, sorted_genres에 저장
	vector<string> sorted_genres;
	for (auto& [genre, total] : genre_total)
		sorted_genres.push_back(genre);
	// 람다 [ ] 안 & -> 외부 변수를 가져다 쓰겠다
	sort(sorted_genres.begin(), sorted_genres.end(), [&](const string& a, const string& b) {
		return genre_total[a] > genre_total[b];
		});

	// 3. 장르별로 내림차순 정렬
	vector<int> answer;
	for (const auto& genre : sorted_genres) {
		auto& songs = genre_songs[genre]; // pair로 곡의 재생 수, 인덱스 조회
		sort(songs.begin(), songs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
			if (a.first == b.first) return a.second < b.second; // 우선순위 높은 게 왼쪽!
		return a.first > b.first;
			});
		// 4. answer 배열에 저장
		for (int i = 0; i < min(2, (int)songs.size()); i++) {
			answer.push_back(songs[i].second);
		}
	}
	return answer;
}