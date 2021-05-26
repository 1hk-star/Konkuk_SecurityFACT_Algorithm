#include <string>
#include <vector>
#include <queue>

using namespace std;

bool is_one_word_diff(string a, string b){
    // a와 b가 1글자만 다른지 체크
    int cnt=0;
    for(int i=0; i<a.length(); i++){
        if(a[i]!=b[i])
            cnt++;
    }
    return cnt==1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = -1;
    int cnt=0;
    int check[50];
    for(int i=0; i<50; i++){
        check[i] = 0;
    }
    
    // BFS 로 돌면서 target이 있는지 찾기
    queue<string> q;
    q.push(begin);
    while(!q.empty() && answer==-1){
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            string cur_str = q.front();
            q.pop();
            if(cur_str==target)
                answer = cnt; // target 찾았음. answer 설정하기
            for(int j=0; j<words.size(); j++){
                if(check[j]==0 && is_one_word_diff(cur_str, words[j])){
                    check[j]=cnt+1;
                    q.push(words[j]);
                }
            }
        }
        cnt++;
    }
    if(answer==-1)
        answer=0; // 변환할 수 없을 때 answer = 0 으로 설정
    return answer;
}