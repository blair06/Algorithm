#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int n, k, s;
vector<pair<int, int>> leftSide;
vector<pair<int, int>> rightSide;
int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    
    cin >> n >> k >> s;
    
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        if(a < s){
            leftSide.push_back(make_pair(a,b));
        }else{
            rightSide.push_back(make_pair(a, b));
        }
        
    }
 
  
    int distance = 0;
    if(leftSide.size()!=0){
        sort(leftSide.begin(), leftSide.end());
        int idx = 0;
        int start = leftSide[0].first;
        int seat = k;
        while(idx < leftSide.size()){
            int students =leftSide[idx].second;
            if(students < seat){
                leftSide[idx].second = 0;
                seat -= students;
                idx++;
            } else if(students > seat){
                leftSide[idx].second = students-seat;
                seat = 0;
            } else if(students == seat){
                leftSide[idx].second = 0;
                seat = 0;
                idx++;
            }
            if(seat == 0 || idx == leftSide.size()){
                distance += (s-start) * 2;
                seat = k;
                start = leftSide[idx].first;
            }
        }
    }
    
    if(rightSide.size()){
        sort(rightSide.begin(), rightSide.end());
        long idx = rightSide.size() -1;
        int start = rightSide[idx].first;
        int seat = k;
        while(idx >-1){
            int students =rightSide[idx].second;
            if(students < seat){
                rightSide[idx].second = 0;
                seat -= students;
                idx--;
            } else if(students > seat){
                rightSide[idx].second = students-seat;
                seat = 0;
            } else if(students == seat){
                rightSide[idx].second = 0;
                seat = 0;
                idx--;
            }
            if(seat == 0 || idx == -1){
                distance += (start - s) * 2;
                seat = k;
                start = rightSide[idx].first;
            }
        }
    }
    
    
    cout << distance;
    return 0;

}

