#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    queue<int> q;
    vector<int> answer;
    
    int t=0, a, day;
    for(int i=0; i<progresses.size(); i++){  
        day=ceil(float(100-progresses[i])/float(speeds[i]));
        q.push(day);
    }
    a=q.front();
    while(!q.empty()){
        if(q.front() > a){
            answer.push_back(t);
            t=0;
            a=q.front();
        }
        else{
            t++;
            q.pop();
        }
    }
    answer.push_back(t);
    return answer;
}
