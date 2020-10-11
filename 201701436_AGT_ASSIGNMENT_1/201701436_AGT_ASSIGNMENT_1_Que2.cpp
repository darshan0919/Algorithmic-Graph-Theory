#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,n,m,edge=0;
    cin>>n>>m;
    vector<vector<int>> adj_mat(n,vector<int>(n,0)),inc_mat(n,vector<int>(m));

    /// Reading the input
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>inc_mat[i][j];
        }
    }

    ///Traversing each column of incidence matrix
    for(int i=0;i<m;i++){
        x = -1;
        y = -1;
        for(int j=0;j<n;j++){
            /// If inc_mat[i][j] > 0 we take it into account
            if(inc_mat[j][i]>0){
                if(x<0) x = j;
                else y = j;
            }
        }
        ///If y < 0 then there is only one node meaning its a loop
        if(y<0)
            adj_mat[x][x]+=2;
        else{
            adj_mat[x][y]++;
            adj_mat[y][x]++;
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) cout<<adj_mat[i][j]<<((j==n-1)?'\n':' ');
    return 0;
}
/*
8 13
1 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 1 0 0 2 2 1 1 0 0 0 0
0 0 0 1 0 0 0 0 0 2 1 0 0
0 0 0 0 1 0 0 1 1 0 0 1 1
0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 1 0 1
*/
