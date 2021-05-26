#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hashMap;
    int i=0;
    //setting
    for(i=0;i<completion.size();i++){
        if(hashMap.end() == hashMap.find(completion[i]))
            hashMap.insert(make_pair(completion[i],1));
        else
            hashMap[completion[i]]++;
    }
    
    //searching
    for(i=0;i<participant.size();i++) {
        if(hashMap.end() == hashMap.find(participant[i]))
            answer = participant[i];
        else 
            if (hashMap[participant[i]]==0)
                answer = participant[i];
            else
                hashMap[participant[i]]--;
    }
    return answer;
}