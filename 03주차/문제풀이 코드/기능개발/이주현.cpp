#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> vmax(progresses.size());
    float temp;
    int max = 0;
    int cnt=1;
 
    for (int i=0;i<progresses.size();i++) 
    {
        temp = speeds[i];
        temp = (100 - progresses[i])/temp;
        max = (int)ceil(temp);
        vmax[i] = max;
    }
 
    max = vmax[0];
    for (int i=1;i<vmax.size();i++) 
    {
        if(max>=vmax[i]) 
        {
            cnt++;
        } 
        else 
        {
            answer.push_back(cnt);
            cnt =1;
            max =vmax[i];
        }
    }
    answer.push_back(cnt);
    return answer;
}