#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string, int> si;

bool compare(string a, string b) {
    return a.length() < b.length();
}

bool compare1(si a, si b) {
    return a.second > b. second;
}

bool solution(vector<string> phone_book) {
    bool result=true;

    // map<string, int> temps;
    vector<si> temps;
    map<string, int> mids;
    sort(phone_book.begin(), phone_book.end(), compare);

    for (auto i : phone_book) {
        // cout << i << endl;
        temps.push_back(si(i, i.length()));
    }

    int len = temps[0].second;
    // cout << len << endl;
    for (auto i: temps) {
        for(int j = len ; j<=i.second ; j++) {
            // cout << j << " , ";
            // cout << mids[i.first.substr(0, j)] << endl;
            mids[i.first.substr(0, j)]+=1;
            // cout << j << " , "<< i.first.substr(0, j) << " . " <<  mids[i.first.substr(0, j)]<< endl;
        }
        // cout << endl;
    }

    for(auto i:temps) {
        // cout <<  mids[i.first] << " . " << i.first << endl;
        if(mids[i.first]>1) {
            result = false;
            // break;
        }
    }

    return result;
}

int main(void) {
    cout << "전화번호 목록" << endl;

    vector<string> t1; //["119", "97674223", "1195524421"]
    t1.push_back("119");
    t1.push_back("97674223");
    t1.push_back("1195524421");
    cout << "test1" << endl << solution(t1) << endl;

    vector<string> t2; //["123","456","789"]
    t2.push_back("123");
    t2.push_back("456");
    t2.push_back("789");
    cout << "test2" << endl << solution(t2) << endl;

    vector<string> t3; //["12","123","1235","567","88"]
    t3.push_back("12");
    t3.push_back("123");
    t3.push_back("1235");
    t3.push_back("567");
    t3.push_back("88");
    cout << "test3" << endl <<  solution(t3) << endl;
    return 0;
} 
