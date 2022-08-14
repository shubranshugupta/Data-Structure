#include<bits/stdc++.h>

using namespace std;

class Graph{
    int vertex;
    vector<vector<int>> *adj;

    public:

        Graph(int v){
            vertex = v;
            adj = new vector<vector<int>>(v, vector<int>(v, 0));
        }

        void addEdge(int u, int v){
            if(u >= vertex || v >= vertex){
                cout << "Invalid vertex" << endl;
                return;
            }

            if(u == v){
                cout << "Self loop not allowed" << endl;
                return;
            }

            adj->at(u).at(v) = 1;
            adj->at(v).at(u) = 1;
        }

        void printGraph(){
            for(int i = 0; i < vertex; i++){
                for(int j = 0; j < vertex; j++){
                    cout<<adj->at(i).at(j)<<" ";
                }
                cout<<endl;
            }
        }

        ~Graph(){
            delete adj;
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.printGraph();

    return 0;
}