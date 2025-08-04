#include<iostream>
#include<queue>
using namespace std;
int firstNeg(queue<int> q){
    int res=0;
    while(!q.empty()){
        if(q.front()<0){
            res=q.front();
            break;
        }
        q.pop();
    }
    return res;
}
void negInt(vector<int> &v, int k){
    queue<int> q;
    for(int i=0; i<v.size(); i++){
        q.push(v[i]);
        if(q.size()==k){
            int res=firstNeg(q);
            cout<<res<<" ";
            q.pop();
        }
    }
}

//efficient

void firstNegInt(vector<int> &v, int k){
    queue<int> q;
    for(int i =0; i<k-1; i++){
        if(v[i]<0) q.push(i);
    }
    for(int i=k-1; i<v.size(); i++){
        if(v[i]<0) q.push(i);

        if(q.empty()) cout<<0<<" ";
        else {
            if(i-q.front()>=k){
            q.pop();
            }
            if(q.empty()){
                cout<<0<<" ";
            }
            else{
                cout<<v[q.front()]<<" ";
            }
        }        
    }
}

int main()
{
    vector<int> v={2, -3, -4, -2, 7, 8, 9, -10};
    firstNegInt(v, 3);
    return 0;
}