#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvl vector<vll>

const ll INF = 1e12;


vvl Modified_Matrix_Multiplication(vvl &A,vvl &B){
  vvl C( A.size() , vll (B[0].size(), INF));
  for(int i=0;i<A.size();++i)
    for(int j=0;j<B[0].size();++j)
      for(int k=0;k<B.size();++k)
        //Modification area
        C[i][j] = min(C[i][j],A[i][k]+B[k][j]);
  return C;
}

vvl All_Pairs_Distance(vvl &a){
    vvl d = a;
    ll k = 1,n = a.size();
    while(k < n-1){
        d = Modified_Matrix_Multiplication(d,d);
        k = k + k;
    }
    return d;
}
int main(){

  cout<<"Enter total number of nodes"<<endl;
  ll i,j,n;
  cin>>n;
  vvl adj_mat( n , vll (n, 0)),dist;

  //Taking Adjacency matrix as Input
  for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        cin>>adj_mat[i][j];
        /// If there is not direct edge then initial distance will be INF
        if(adj_mat[i][j]==0 && i!=j)
            adj_mat[i][j] = INF;
        /// Distance of node to itself is ZERO
        if(i==j)
            adj_mat[i][j] = 0;
    }

  dist = All_Pairs_Distance(adj_mat);

  //Printing All Pair Minimum Distances
  for(auto &x:dist){
    for(auto &y:x)
        cout<<y<<' ';
    cout<<'\n';
  }
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
