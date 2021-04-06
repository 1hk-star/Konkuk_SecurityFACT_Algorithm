#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    //사람 이름 , 순서
    map<string, int> persons;
    
    int len = participant.size();
    for (int i=0 ; i<len ; i++) {
        string person = participant[i];
        
        if(persons.find(person)->first != person) {
            //null
            persons[person] = 1;
        }
        else {
            int size = persons.find(person)->second;
            size++;
            persons.erase(person);
            persons[person] = size;
        }
    } 


    for(int i=0 ; i<len-1 ; i++) {
        string person = completion[i];

        if(persons.find(person)->second >1) {
            persons.find(person)->second -=1;
        }
        else {
            persons.erase(person);
        }
        
    }
    

    answer = persons.begin()->first;

    return answer;
}

int main(void) {
    vector<string> p;
    p.push_back("leo");
    p.push_back("kiki");
    p.push_back("eden");
    p.push_back("kiki");

    vector<string> c;
    c.push_back("eden");
    c.push_back("kiki");
    c.push_back("leo");

    cout << solution(p, c)<< endl;
}

