//
#include<iostream>
#include<queue>

using namespace std;

void printQueue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

void printAllNum(vector<int> &v, int k){
    queue<int> q;
    for(int i=0; i<v.size(); i++){
        q.push(v[i]);
        if(q.size()==k){
            printQueue(q);
            cout<<endl;
            q.pop();
        }
    }
}

int main(){
    vector<int> v={3,6,2,7,8,11};
    printAllNum(v, 3);
    return 0;
}