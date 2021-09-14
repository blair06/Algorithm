#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
map<string,int> rcount;
map<string,int> mcount;
string arr [200000][2];
    vector<int> answer;
    map<string, int>::iterator iter;
vector<string> id_list = {{"muzi"}, {"frodo"}, {"apeach"}, {"neo"}};
vector<string> report = {{"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}};
int k =2;
vector<int> solution() {
    //신고당한 횟수, 메일 횟수 저장 map 생성
    for(int i=0; i<id_list.size(); i++){
        rcount.insert(make_pair(id_list[i],0));
        mcount.insert(make_pair(id_list[i],0));
    }
    
    for(int i=0; i<report.size(); i++){
    string mapkey;
    string mapvalue;
    auto it = find(report.begin(), report.begin()+i, report[i]);
        if(it == report.begin()+i){
            istringstream ss(report[i]);
            
            for(int j=0; j<2; j++){
                if(j==0){
                    getline(ss, mapkey, ' ');
                }else{
                    getline(ss, mapvalue, ' ');
                    rcount[mapvalue] += 1;

                }
            }
                
            
        
        arr[i][0] = mapvalue;
        arr[i][1] = mapkey;
        }
        
      
    }
    for(iter = rcount.begin(); iter != rcount.end(); iter++){
        if(iter->second >= k){
            for(int i=0; i<report.size();i++){
                if(arr[i][0] == iter->first){
                    mcount[arr[i][1]] += 1;
                }
            }
        }
    }
    for(int i=0; i<id_list.size();i++){
        
            for(iter = mcount.begin(); iter != mcount.end(); iter++){
                if(id_list[i]==iter->first){
                answer.push_back(iter->second);
            }
        }
    }
    
    return answer;
}

int main(){
    solution();

    for(int i =0; i<answer.size();i++){
        cout << answer[i];
    }
        
    return 0;
}
