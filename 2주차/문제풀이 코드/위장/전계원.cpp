// C++ 위장
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> m; // (의류 종류, 개수) map 생성
    
    // 의류 종류 초기화
    for(int i=0; i<clothes.size(); i++){
        m.insert(make_pair(clothes[i][1], 0)); 
    }
    
    // 의류 종류 개수 올리기
    for(int i=0; i<clothes.size(); i++){
        m[clothes[i][1]] += 1; 
    }
    
    // 조합 개수 구하기
    answer = 1; // 곱하기 연산할꺼라서 1로 설정
    for ( auto it = m.begin(); it != m.end(); ++it ){
        answer *= (it->second + 1); // 안입을 수 있기에 +1 한걸 곱함
    }
    answer -= 1; // 모두 안입었을 때의 경우 제외
    
    return answer;
}