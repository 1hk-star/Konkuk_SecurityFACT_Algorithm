#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(string left, string right){
    //30, 3
    //303, 30
    int l = stoi(left+right), r = stoi(right+left);
    return l > r;
}

string solution(vector<int> numbers) {
    vector<string> str;
    string answer = "";
    int zero = false;
    
    for(int i = 0; i < numbers.size(); i++){
        str.push_back(to_string(numbers[i]));
        if(numbers[i]!= 0)
            zero = true;
    }
    sort(str.begin(), str.end(), Compare);
    
    for(int i =0; i < numbers.size(); i++)
        answer += str[i];
    if(!zero)
        return "0";
    else
        return answer;
}