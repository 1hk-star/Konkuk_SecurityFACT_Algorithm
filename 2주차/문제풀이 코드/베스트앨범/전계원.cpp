// C++ 베스트앨범
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, pair<int, int>> m; // map 만들기, pair은 각각 1등, 2등 이다.
    unordered_map<string, int> m_sum; // map 만들기, 각각 장르, 총 play 수 이다.
    
    // 장르 공간 만들기
    for(int i=0; i<genres.size(); i++){
        m_sum.insert(make_pair(genres[i], 0)); // play의 합계를 구해줄 것이기에 0으로 초기화
        m.insert(make_pair(genres[i], make_pair(-1, -1))); // -1은 입력되지 않았다는 뜻
    }
    
    // 장르쪽에 1등, 2등 맞게 넣어주기
    for(int i=0; i<genres.size(); i++){
        m_sum[genres[i]] += plays[i]; // m_sum 에 play의 합 계속 누적        
        if(m[genres[i]].first == -1){
            // 1등, 2등 칸 모두 비어있음
            m[genres[i]].first = i;
        }
        else if(plays[m[genres[i]].first] < plays[i]){
            // 1등 칸이 있는데, 현재 값이 1등보다 큼
            m[genres[i]].second = m[genres[i]].first;
            m[genres[i]].first = i;
        }
        else if(m[genres[i]].second == -1){
            // 현재 값이 1등보다 작은데, 2등이 비어있음
            m[genres[i]].second = i;
        }
        else if(plays[m[genres[i]].second] < plays[i]){
            // 현재 값이 1등보다 작은데, 2등 보다는 큼
            m[genres[i]].second = i;
        }
    }
    
    // 장르 순서 정렬하기
    vector<pair<int, string>> tmp; // sort 쓰기 위해 만들어주었다.
    for(auto it=m_sum.begin(); it!=m_sum.end(); it++){
        tmp.push_back(make_pair(it->second, it->first)); // (play총합, 장르) 넣어주기
    }
    sort(tmp.begin(), tmp.end(), greater<>()); // 내림차순으로 sort
        
    // 앨범에 넣어주기
    for(int i=0; i<tmp.size(); i++){
        string genre = tmp[i].second;
        answer.push_back(m[genre].first);
        if(m[genre].second != -1){
            // 2등 값이 존재하면 이 친구도 answer에 넣어주기
            answer.push_back(m[genre].second);
        }
    }
    
    return answer;
}