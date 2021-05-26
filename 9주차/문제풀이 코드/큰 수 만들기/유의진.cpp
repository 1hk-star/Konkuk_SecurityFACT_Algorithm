#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int t=0; //현재 제거한 개수
    int ptr=0;
    while(t<k){
        if(number[ptr]<number[ptr+1]){
            number.erase(ptr, 1);
            t++;
            ptr=0;
        }
        else{
            ptr++;
            if(ptr+1==number.length()){ //포인터가 끝에 도달할 경우
                number.erase(number.length()-1, 1);
                t++;
                ptr=0;
            }
        }
    }
    return number;
}


