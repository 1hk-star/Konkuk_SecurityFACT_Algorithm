#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int t=0; //���� ������ ����
    int ptr=0;
    while(t<k){
        if(number[ptr]<number[ptr+1]){
            number.erase(ptr, 1);
            t++;
            ptr=0;
        }
        else{
            ptr++;
            if(ptr+1==number.length()){ //�����Ͱ� ���� ������ ���
                number.erase(number.length()-1, 1);
                t++;
                ptr=0;
            }
        }
    }
    return number;
}


