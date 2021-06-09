#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    // graph 제작
    int answer = 0;
    vector<int> node_check(n+1, 0);
    vector<vector<int>> graph(n+1, vector<int>());
    for(int i=0; i<edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    // BFS 로 1번 Node에서부터 그래프 탐색
    queue<int> q;
    q.push(1);
    node_check[1] =1;
    while(!q.empty()){
        int c_node = q.front();
        q.pop();
        for(int i=0; i<graph[c_node].size(); i++){
            if(node_check[graph[c_node][i]] == 0){
                node_check[graph[c_node][i]] = node_check[c_node]+1;
                q.push(graph[c_node][i]);
            }
        }
    }
    
    // 최대값 찾기
    int max=0;
    for(int i=0; i<node_check.size(); i++){
        max = max > node_check[i] ? max : node_check[i];
    }
    
    // 최대값의 개수 세기
    for(int i=0; i<node_check.size(); i++){
        if(max==node_check[i])
            answer++;
    }

    return answer;
}