#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    unordered_map<int, int> hash; // priority, count
    queue<pair<int, int>> waiting; // priority, idx
    vector<int> priority_list; // priority 리스트
    
    // hash에 중요도별로 문서 몇개있나 넣기
    for(int i=0; i<priorities.size(); i++){
        waiting.push(make_pair(priorities[i], i));
        if(hash.find(priorities[i]) == hash.end()){
            // 없으면 만들기
            hash.insert(make_pair(priorities[i], 1));
            priority_list.push_back(priorities[i]);
        } else {
            // 있으면 1추가
            hash[priorities[i]]++;
        }
    }

    sort(priority_list.begin(), priority_list.end(), greater<>()); // 정렬

    int cur_idx = 0, rank = 1;
    while(!waiting.empty()){
        pair<int, int> cur_doc = waiting.front();
        waiting.pop();
        if(priority_list[cur_idx] > cur_doc.first){
            //나보다 우선순위 높은 문서 존재, 뒷 순위로 넣기
            waiting.push(cur_doc);
        } else {
            // 내가 우선순위가 제일 높음, 출력
            if(location == cur_doc.second){
                // 내가 인쇄 요청한 문서 일때
                answer = rank;
                break;
            }
            hash[priority_list[cur_idx]]-=1;
            if(hash[priority_list[cur_idx]]==0)
                cur_idx++;
            rank++;
        }
    }
    
    return answer;
}