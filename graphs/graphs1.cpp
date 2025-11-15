// graphs have nodes connected to it but there are no hierarchy present in the nodes they are basically a network of nodes.
// graphs are coonected through edges.
// and the nodes are known as vertices.
//they are the most versatile data srtructure among all.
//Types of graph: 1-on bases of edges:direction and undirected graphs(there is no direction in it)
//2- on bases of weighted and unweighted graphs
//types-1-undirected unweighted graph
//2-undirecterd weigjhted graph
//3-directedd unweighted graph
//4-directed weighted graph
#include<iostream>
#include<vector>
#include<list>
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
};

int main(){
    graph g(4);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);
    g.printadjlist();
    return 0;
}


