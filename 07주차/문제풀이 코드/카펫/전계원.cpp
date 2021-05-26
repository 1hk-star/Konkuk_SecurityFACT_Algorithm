#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = yellow+brown;
    int width = total, height = 1;
    while(width >= height){
        // 정답 조건
        if(height >= 3 && width >= 3 && yellow == (height-2)*(width-2)){
            answer.push_back(width);
            answer.push_back(height);
            break;
        }            
        
        // 다음 width, height 쌍 update
        while(total%++height!=0);
        width = total/height;
    }
    return answer;
}