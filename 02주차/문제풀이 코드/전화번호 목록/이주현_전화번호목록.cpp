#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int i = 0;
    int j = 0;
    unordered_map<string, int> hashMap;
    
    for(i=0;i<phone_book.size();i++){
        hashMap[phone_book[i]] = 1; //모든 전화번호 value 1로 다 넣기
    }
    
    for(i=0;i<phone_book.size();i++){ //하나 집어서
        for(j=0;j<phone_book[i].length();j++){ //걔를 1 11 119 1195 11955로 자르기위해서 한 글자씩
            if(hashMap[phone_book[i].substr(0,j)]==1){ //119일때 119가 1로 이미 넣어져있으면?
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}