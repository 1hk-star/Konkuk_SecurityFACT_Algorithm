#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<string> path; // 경로 stack에 넣기
vector<bool> check;

bool DFS(vector<pair<string, string>> tickets, int total_depth, int cur_depth, string start_nation, int before_idx){
    if(total_depth==cur_depth){
        // 경로가 완성되었을 때
        return true;
    } else {
        // 경로 완성 중..
        for(int i=0; i<tickets.size(); i++){
            if(tickets[i].first==start_nation && check[i]){
                check[i] = false;
                path.push(tickets[i].second);
                if(DFS(tickets, total_depth, cur_depth+1, tickets[i].second, i)){
                    // 경로 찾았을 때
                    return true;
                } else {
                    // 여기가 경로가 아닌 것 같다.
                    check[i] = true;
                    path.pop();
                }
            }
        }
        check[before_idx] = true;
        return false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // data setting
    for(int i=0; i<tickets.size(); i++){
        check.push_back(true);
    }
    vector<string> answer;
    vector<pair<string, string>> m_tickets; // tickets를 vector<pair<string, string>> 으로 변환
    for(int i=0; i<tickets.size(); i++){
        m_tickets.push_back(make_pair(tickets[i][0], tickets[i][1]));
    }
    sort(m_tickets.begin(), m_tickets.end()); // 알파벳 순서가 앞서는 경로를 우선시 하기 위해 정렬
    
    // 재귀 이용 백트레킹
    string start_nation = "ICN";
    path.push(start_nation);
    bool res = DFS(m_tickets, m_tickets.size(), 0, start_nation, -1);

    // 정답 출력
    while(!path.empty()){
        answer.push_back(path.top());
        path.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}