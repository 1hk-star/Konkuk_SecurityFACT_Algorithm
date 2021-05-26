#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int count = clothes.capacity();
    unordered_map<string, int> hashMap;
    vector<int> counting;
    int i = 0;
    int j = 0;
    for(i=0;i<clothes.size();i++){
        if(hashMap.end() == hashMap.find(clothes[i][1])){
            hashMap[clothes[i][1]] = 1;
        } else{
            hashMap[clothes[i][1]]++;
        }      
    }
    //hashMap.size() : 옷 종류(상의 하의만 있으면 2로 나옴)
    //hashMap
    int answer_temp=1;
    unordered_map<string,int>::iterator iter;
    for(iter = hashMap.begin(); iter!= hashMap.end(); iter++){
        answer_temp = (iter->second+1) * answer_temp;   
    }
    answer = answer_temp - 1;
    
    return answer;
}