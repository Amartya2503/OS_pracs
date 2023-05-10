#include<iostream>
#include<bits\stdc++.h>

using namespace std;

int faultcount(int pages[],int pn, int fn){
    unordered_set<int> s;
    queue<int> indexes; // queue is maintained to keep a track of my pages which are in frames 
    int framemiss;
    for(int i =0; i<pn; i++){

        if(s.size() < fn){
            if(s.find(pages[i]) == s.end()){
                framemiss +=1;
                s.insert(pages[i]);
                indexes.push(pages[i]);
            }
        }
        else{
            if(s.find(pages[i]) == s.end()){
                framemiss +=1;
                int val = indexes.front();
                indexes.pop();
                indexes.push(pages[i]);

                s.erase(val);
                s.insert(pages[i]);

            }
        }
    }
    return framemiss;
}

int main(){
    
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4,2, 3, 0, 3, 2};
    int pn = sizeof(pages);
    int fn = 4;
    int i = faultcount(pages, pn, fn);
    cout<<"number of miss : "<<i;
    cout<<"\n no of hits : "<<pn - i;
    return 0;
}
