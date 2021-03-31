#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
    return p1.first>p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string,int> hashMap;
    
    for(int i=0;i<genres.size();i++){
        hashMap[genres[i]]+=plays[i]; 
    }
    //classic = 500+150+800

    
    //map<string,int, greater<int>> gmap; //내림차순, value는 이렇게 정렬 오류뜨네
    map<int,string, greater<int>> gmap; //키값가지고 정렬하기위해 string-int에서 int-string으로 바꿈
    for(unordered_map<string, int>::iterator i=hashMap.begin();i!=hashMap.end();i++){
        gmap.insert(make_pair(i->second,i->first)); //int-string 페어, 내림차순 하기위함.
    }
    //pop(3100)-classic(1450)-... 

    for(map<int, string>::iterator i=gmap.begin();i!=gmap.end();i++){ //pop부터
        vector<pair<int,int>> temp;
        for(int j=0;j<genres.size();j++){
            if(genres[j] == i->second){ //pop = pop
                temp.push_back(make_pair(plays[j],j)); //600,1
            }
        } //(600,1) (2500,4)
        sort(temp.begin(),temp.end(),comp); //큰 순서대로
        //(2500,4)(600,1)
        answer.push_back(temp[0].second); //첫번째 고유번호 넣음
        if(temp.size()>1) {
            answer.push_back(temp[1].second); //사이즈 1이상이면 두번째 고유번호도 넣음 
        }   
    }
    return answer;
}