#include<bits/stdc++.h>
using namespace std;

// Space --> O(n+m)
// Time ---> O(m)

vector<vector<int>> createGraph(int node, int edge){

    vector<vector<int>> adjL(node+1);

    for(int i=0;i<edge;i++){

        int u, v;
        cout<<"Enter first node value of "<<i+1<<" edge : ";
        cin>>u;
        cout<<"Enter second node value of "<<i+1<<" edge : ";
        cin>>v;

        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    return adjL;
}

int main(){

    int node, edge;

    cout<<"Enter total number of nodes : ";
    cin>>node;

    cout<<"Enter total number of edges : ";
    cin>>edge;

    vector<vector<int>> adjL = createGraph(node, edge);

    for(int i=1;i<=node;i++){

        cout<<i<<" --> ";

        for(int j=0;j<adjL[i].size();j++){
            cout<<adjL[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}