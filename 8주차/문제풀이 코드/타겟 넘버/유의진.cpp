#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int cnt, vector<int> numbers, int target, int now){
    if(cnt==numbers.size()){
        if(target==now) answer++;
        return;
    }
    dfs(cnt+1, numbers, target, now+numbers[cnt]);
    dfs(cnt+1, numbers, target, now-numbers[cnt]);
}

int solution(vector<int> numbers, int target) {
    dfs(0, numbers, target, 0);
    return answer;
}
