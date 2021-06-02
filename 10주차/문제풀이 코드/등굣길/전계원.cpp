#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int map[102][102];
    for(int i=0; i<102; i++){
        for(int j=0; j<102; j++){
            map[i][j]=-1;
        }
    }
    
    // map 만들어주기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            map[i][j]=0;
        }
    }

    // 웅덩이
    for(int i=0; i<puddles.size(); i++){
        map[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    // BFS로 탐색하면서 DP map에 작성하기
    int _x[2] = {1, 0};  // 우측으로 가거나
    int _y[2] = {0, 1};  // 아래로 가는 방법만 존재
    queue<pair<int, int>> q;
    map[1][1] = 1;
    q.push(make_pair(1,1));
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i=0; i<2; i++){
            if(map[cur_y+_y[i]][cur_x+_x[i]]==0){
                // 첫 방문
                map[cur_y+_y[i]][cur_x+_x[i]] = map[cur_y][cur_x];
                q.push(make_pair(cur_x+_x[i], cur_y+_y[i]));
            } else if(map[cur_y+_y[i]][cur_x+_x[i]]>0){
                // 이미 방문함
                map[cur_y+_y[i]][cur_x+_x[i]] += map[cur_y][cur_x];
                map[cur_y+_y[i]][cur_x+_x[i]] %= 1000000007;
            }
        }
    }
    answer = map[n][m];
    return answer;
}