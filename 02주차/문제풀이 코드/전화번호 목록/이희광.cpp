#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int> um;
    
    //n
    for(auto str : phone_book){
        um.insert(make_pair(str, str.length()));
    }
    
    //nlogn
    sort(phone_book.begin(), phone_book.end());
    
    reverse(phone_book.begin(), phone_book.end());     
    for(auto str : phone_book){
        for(int i =0; i < um[str]; i ++){
            if (um.find(str.substr(0, i)) != um.end()){
                answer = false;
                return answer;
            }
        }
    }
    
    
    return answer;
}
