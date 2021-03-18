// c++, programmers 전화번호 목록
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> m; // 접두어 목록이 있는 hash 만들어주기

    // 접두어 목록 0으로 초기화
    for(int i=0; i<phone_book.size(); i++){
        for(int j=1; j<=phone_book[i].length(); j++){
            m.insert(make_pair(phone_book[i].substr(0, j), 0));
        }
    }

    // 접두어에 해당되는 hash에 +1
    for(int i=0; i<phone_book.size(); i++){
        for(int j=1; j<=phone_book[i].length(); j++){
            m[phone_book[i].substr(0, j)] += 1;
        }
    }
    
    // 한 번호가 다른 번호의 접두사인지 찾기
    for(int i=0; i<phone_book.size(); i++){
        if(m[phone_book[i]] > 1){
            answer = false;
            break;
        }
    }
    
    return answer;
}