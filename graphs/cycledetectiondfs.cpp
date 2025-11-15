//in undirected graph
#include<iostream>
#include<vector>
#include<list>
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
bool iscycleundirected(int source,int parent,vector<bool>&visited){
    visited[source] = true;
    list<int> neighbours = l[source];
    for(int v: neighbours){
        if(!visited[v]){
            if(iscycleundirected(v,source,visited)){
                return true;
            }
        } else if(v != parent){
            return true;
        }
    }
    return false;
}
bool iscycle(){
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(iscycleundirected(i,-1,visited)){
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
   // g.addedge(0,2);
    g.addedge(0,3);
    g.addedge(1,2);
    g.addedge(3,4);
    cout<<g.iscycle()<<endl;
    return 0;

}