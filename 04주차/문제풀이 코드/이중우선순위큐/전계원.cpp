#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    map<int, int> rb_tree; // 값, 개수
    vector<int> answer;
    // operation 적용
    for(int i=0; i<operations.size(); i++){
        if(operations[i].substr(0, 1)=="I"){
            // Insert
            int val = stoi((operations[i].substr(2, operations[i].length()-2)));
            if(rb_tree.find(val) == rb_tree.end()){
                // tree에 없음
                rb_tree.insert(make_pair(val, 1));
            } else {
                // tree에 있음
                rb_tree[val]++;
            }
        } else {
            // Delete            
            int val = stoi((operations[i].substr(2, operations[i].length()-2)));
            if(!rb_tree.empty()){
                if(val == 1){
                    // 최대값 삭제
                    int max_val = (--rb_tree.end())->first;
                    if(rb_tree[max_val] > 1){
                        rb_tree[max_val]--;
                    } else {
                        rb_tree.erase(max_val);
                    }                
                } else {
                    // 최소값 삭제
                    int min_val = (rb_tree.begin())->first;
                    if(rb_tree[min_val] > 1){
                        rb_tree[min_val]--;
                    } else {
                        rb_tree.erase(min_val);
                    }
                }
            }
        }
    }
    // 결과 출력
    if(!rb_tree.empty()){
        int max_value = (--rb_tree.end())->first;
        int min_value = (rb_tree.begin())->first;
        answer.push_back(max_value);
        answer.push_back(min_value);
    } else {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}