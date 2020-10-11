#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,n,edges=0,edge=0;
    cin>>n;
    vector<vector<int>> adj_mat(n,vector<int>(n));

    ///Taking the Input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj_mat[i][j];
            if(i<=j){
                /// Storing number of edges in the graph
                edges += (i==j) ? adj_mat[i][j]/2 : adj_mat[i][j];
            }
        }
    }

    ///Creating incidence matrix of appropriate size (#nodes * #edges)
    vector<vector<int>> inc_mat(n,vector<int>(edges,0));


    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            /// Whenever an edge is found we update the column in inc_mat and move the pointer to next column
            x = (i==j) ? adj_mat[i][j]/2 : adj_mat[i][j];
            while(x--){
                inc_mat[i][edge]++;
                inc_mat[j][edge]++;
                edge++;
            }
        }
    }
    cout<<n<<' '<<edges<<endl;
    for(int i=0;i<n;i++)for(int j=0;j<edges;j++) cout<<inc_mat[i][j]<<((j==edges-1)?'\n':' ');
    return 0;
}
/*
8
0 0 1 0 0 0 0 0
0 0 1 0 0 0 0 0
1 1 0 1 1 1 0 0
0 0 1 4 0 2 0 0
0 0 1 0 2 0 0 1
0 0 1 2 0 0 1 1
0 0 0 0 0 1 0 0
0 0 0 0 1 1 0 0
*/
