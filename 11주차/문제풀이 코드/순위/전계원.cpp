#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int count_front_node(vector<vector<int>> graph, int n){
    // graph의 n번 이후로 연결된 node의 개수 반환
    vector<int> check(graph.size()+1, 0);
    queue<int> q;
    q.push(n);
    for(int j=0; j<graph.size(); j++){
        for(int i=0; i<graph[j].size(); i++){
            if(check[graph[j][i]]==0){
                check[graph[j][i]]=1;
                q.push(graph[j][i]);
            }
        }        
    }
    
    int count = 0;
    for(int i=0; i<check.size(); i++){
        if(check[i]==1)
            count++;
    }
    return count;
}

int solution(int n, vector<vector<int>> results) {
    // 그래프 구성
    int answer = 0;
    vector<vector<int>> graph(n+1, vector<int>());
    vector<vector<int>> back_graph(n+1, vector<int>());
    for(int i=0; i<results.size(); i++){
        graph[results[i][1]].push_back(results[i][0]);
        back_graph[results[i][0]].push_back(results[i][1]);
    }

    // 본인 앞쪽에 연결된 Node의 수와 뒤쪽의 연결된 Node의 수 합이 n-1 이면 순위를 매길 수 있음!!
    for(int i=1; i<=n; i++){
        if(count_front_node(graph, i) + count_front_node(back_graph, i) == n-1)
            answer++;
    }
    return answer; 
}