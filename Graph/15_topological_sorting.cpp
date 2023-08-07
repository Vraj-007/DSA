#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>> &adjL, vector<int> &visited, stack<int> &st){

    visited[node] = 1;

    for(auto neighbour : adjL[node]){
        if(visited[neighbour] == 0){
            DFS(neighbour, adjL, visited, st);
        }
    }

    st.push(node);
}


vector<int> topological_sort(vector<vector<int>> &adjL){

    int n = adjL.size();

    vector<int> visited(n, 0);

    stack<int> st;

    for(int node=0 ; node<n ; node++){
        if(visited[node] == 0){
            DFS(node, adjL, visited, st);
        }
    }

    vector<int> List;

    while(!st.empty()){
        int node = st.top();
        List.push_back(node);
        st.pop();
    }

    return List;
}


int main(){

    vector<vector<int>> adjL{
        {},
        {},
        {3},
        {1},
        {0,1},
        {0,2}
    };

    vector<int> List = topological_sort(adjL);

    for(auto node : List){
        cout<<node<<" ";
    }

    return 0;
}