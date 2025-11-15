//depth first search 
// it means keep going to first unvisited nodes its not neccesary it is immediate node
//after we moving we marked it as visited
//stacks are used in this
//time complexity is O(v+e)
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
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
void printadjlist(){
    for(int i =0;i<v;i++){
        cout<<i<<": ";
        for(int neighbour : l[i]){
            cout<<neighbour<<",";
        }
        cout<<endl;
    }
}
void bfs(){
    queue<int> a;
    vector<bool> visited(v,false);
    a.push(0);
    visited[0]= true;
    while(a.size() >0){
        int u = a.front();
        a.pop();
        cout<<u<<" ";
        for(int v: l[u]){
            if(!visited[v]){
                visited[v] = true;
                a.push(v);

            }
        }
    }
cout<<endl;
}
void dfshelper(int u, vector<bool> &visited){
    cout<<u<<" ";
    visited[u] = true;
    for(int v:l[u]){
        if(!visited[v]){
            dfshelper(v,visited);
        }
    }

}
void dfs(){
    int source =0;
    vector<bool> visited(v,false);
    dfshelper(source, visited);
}
};

int main(){
    graph g(5);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);
    g.printadjlist();
    g.bfs();
    g.dfs();
    return 0;
}


