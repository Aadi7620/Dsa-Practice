//in undirected graph
#include<iostream>
#include<vector>
#include<list>
#include<Stack>
#include<queue>
using namespace std;
class graph{
int v;
list<int> *l;
public:
graph(int v){
    this->v = v;
    l = new list<int>[v];
}
void addedge(int u,int v){
    l[u].push_back(v);
    l[v].push_back(u);
}
bool iscycleundirected(int source,vector<bool> &visited){
    queue<pair<int,int>> q;
    q.push({source,-1});
    visited[source] = true;
    while(q.size()>0){
        int u = q.front().first;
        int parentu = q.front().second;
        q.pop();
        list<int> neighbours = l[u];
        for(int v: l[u]){
            if(!visited[v]){
               q.push({v,u});
                visited[v] = true;
            }else if(v!= parentu){
                return true;
            }
        } 
    }
return false;
}
bool iscycle(){
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
    if(!visited[i]){
        if(iscycleundirected(i,visited)){
            return true;
        }

    }
    }
    return false;
}
};
int main(){
     graph g(5);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(0,3);
    g.addedge(1,2);
    g.addedge(3,4);
    cout<<g.iscycle()<<endl;
    return 0;
}