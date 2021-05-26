#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

//가장 많이 재생된 노래를 찾고
//장르내 가장 많이 재생된 노래를 찾고
//고유 번호가 낮은 노래를 찾는다.
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,unordered_map<int,int>> um;
    vector<string> genre2;
    bool flag  = false;
    int size = genres.size();
    
  for(int i =0 ; i < size; i ++){
      if(um.find(genres[i]) == um.end()){
        //total
        um[genres[i]].insert(make_pair(-1, plays[i]));
        // max1 index
        um[genres[i]].insert(make_pair(-2, i));
        // max2 index
        um[genres[i]].insert(make_pair(-3, -1));
        // max1 value
        um[genres[i]].insert(make_pair(-4, plays[i]));
        // max2 vlaue
        um[genres[i]].insert(make_pair(-5, -1));
      }else{
        um[genres[i]].insert(make_pair(i, plays[i])); 
        um[genres[i]][-1] += plays[i]; 
          //만약 현재 곡의 재생횟수가 max 1보다 더 크다면
          if(um[genres[i]][-4] < plays[i]){
              //max1 -> max2 이동
              um[genres[i]][-3] = um[genres[i]][-2];
              um[genres[i]][-5] = um[genres[i]][-4];
              //max 1 변경
              um[genres[i]][-2] = i;
              um[genres[i]][-4] = plays[i];
          }
          else if(um[genres[i]][-5] < plays[i]){
              //max 2 변경
              um[genres[i]][-3] = i;
              um[genres[i]][-5] = plays[i];    
          }
      }
  }
    for(auto it : um){
        flag = false;
        if(genre2.empty()){
            genre2.emplace_back(it.first);
        }else{
            int genre_size = genre2.size();
            for(int i=0; i < genre_size; i ++){
                if(um[it.first][-1] > um[genre2[i]][-1]){
                    genre2.emplace(genre2.begin()+i,it.first);
                    flag = true;
                    break;
                }  
            }
            if(!flag){
                genre2.emplace_back(it.first);
                
            }
                
        }
    }
    
    for(auto str : genre2){
        answer.emplace_back(um[str][-2]);
        if(um[str][-3] != -1)
            answer.emplace_back(um[str][-3]);
    }
    return answer;
}