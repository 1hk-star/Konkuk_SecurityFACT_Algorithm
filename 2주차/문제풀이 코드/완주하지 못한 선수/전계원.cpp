// c++, programmers 완주하지 못한 선수
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m; // 참가자 목록이 있는 map 만들어주기

    for(int i=0; i<participant.size(); i++){
        // {[이름], 0} 으로 map에 모든 참가자 초기화
        m.insert(make_pair(participant[i], 0));
    }

    for(int i=0; i<participant.size(); i++){
        // participant의 이름들 map에서 +1
        m[participant[i]]+=1;
    }

    for(int i=0; i<completion.size(); i++){
        // completion의 이름들 map에서 -1
        m[completion[i]] -= 1;
    }
    
    for(int i=0; i<participant.size(); i++){
        // 참가자 목록에서 int값이 1이상인 string 값 찾기
        if(m[participant[i]] > 0){
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}