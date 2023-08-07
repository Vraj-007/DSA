#include<bits/stdc++.h>
using namespace std;

// Space --> O(n x n)
// Time --> O(m)

vector<vector<int>> createGraph(int node, int edge){

    vector<vector<int>> adjM(node+1, vector<int> (node+1, 0));

    for(int i=0;i<edge;i++){

        int u, v;
        cout<<"Enter first node value of "<<i+1<<" edge : ";
        cin>>u;
        cout<<"Enter second node value of "<<i+1<<" edge : ";
        cin>>v;

        adjM[u][v] = adjM[v][u] = 1;

    }

    return adjM;
}


int main(){

    int node, edge;

    cout<<"Enter total number of nodes : ";
    cin>>node;

    cout<<"Enter total number of edges : ";
    cin>>edge;

    vector<vector<int>> adjM = createGraph(node, edge);

    for(int i=0;i<=node;i++){
        for(int j=0;j<=node;j++){
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}