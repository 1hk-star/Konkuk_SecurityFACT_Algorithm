#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, t=edge.size(), che=1;
    vector<vector<int>> list(n+1);
    vector<vector<int>> ans(n+1);
    bool check[20001]={false, true, };
    for(int i=0; i<t; i++){
        list[edge[i][0]].push_back(edge[i][1]);
        list[edge[i][1]].push_back(edge[i][0]);
    }
    ans[0].push_back(1);
    while(n>che){
        for(int i=0; i<ans[answer].size(); i++){
            for(int j=0; j<list[ans[answer][i]].size(); j++){
                if(check[list[ans[answer][i]][j]]==false){
                    check[list[ans[answer][i]][j]]=true;
                    ans[answer+1].push_back(list[ans[answer][i]][j]);
                    che++;
                }
            }
        }
        answer++;
    }
    return ans[answer].size();
}
