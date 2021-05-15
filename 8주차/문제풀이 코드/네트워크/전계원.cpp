#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    // 데이터 저장
    int check[200];  // computers 의 그룹이 지어졌는지 체크하는 배열
    for(int i=0; i<200; i++){
        check[i] = 0;
    }
    
    // BFS 돌면서 group의 개수를 셈
    queue<int> q;
    for(int i=0; i<n; i++){
        if(check[i]==0){
            // i번째 값이 group이 지정 안되어있음
            q.push(i);
            check[i] = ++answer;
        }
        while(!q.empty()){
            // i번째 값과 연결된 group BFS 탐색 후 같은 group으로 묶기
            int tmp = q.front();
            q.pop();
            for(int j=0; j<n; j++){
                if(computers[tmp][j]==1 && check[j]==0){
                    check[j] = answer;
                    q.push(j);
                }
            }
        }
    }
    return answer;
}