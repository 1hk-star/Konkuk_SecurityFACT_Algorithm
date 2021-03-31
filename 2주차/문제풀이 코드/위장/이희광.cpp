#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string,int> um;
    vector<string> types;
    
    for(auto str : clothes){
        if (um.find(str[1]) == um.end()){
            um.insert(make_pair(str[1], 1));
            types.push_back(str[1]);
        }
        else{
            um[str[1]]++;
        }
    }
    for(auto str : types){
        answer *= (um[str]+1);
        //cout << str <<","<<um[str]<<endl;
    }
    
    return answer-1;
}