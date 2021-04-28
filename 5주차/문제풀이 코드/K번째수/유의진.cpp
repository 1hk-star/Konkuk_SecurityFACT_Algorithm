#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sub(array.size());
    int i, j, k;
    for(int a=0; a<commands.size(); a++){
        sub.clear();
        i=commands[a][0];
        j=commands[a][1];
        k=commands[a][2];
        for(int b=i-1; b<j; b++){
            sub.push_back(array[b]);
        }
        sort(sub.begin(), sub.end());
        answer.push_back(sub[k-1]);
    }
    return answer;
}
