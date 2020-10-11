#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define S string

template<class T>
class Graph{
    map<T,map<T,ll>> Adj;
    map<T,T> Label;
    map<T,ll> Size;
    map<T,bool> vis;
    public:
    void add_node(T x){
        if (Adj.find(x) != Adj.end()){
            cout<<"Node with the given label is already in the graph\n";
            return;
        }

        /// Initial values
        Adj[x] = map<T,ll>();
        Label[x] = x;
        Size[x] = 1;

        cout<<"Node added successfully\n";
    }
    void remove_node(T x){
        if (Adj.find(x) == Adj.end()){
            cout<<"Node with the given label does not exist in the graph\n";
            return;
        }

        /// Store the neighbors in adj
        set<T> adj;

        for (auto c:Adj[x])
            if (c.first != x)
                adj.insert(c.first);

        /// Complete necessary removals from graph
        Adj.erase(x);
        Size.erase(Label[x]);
        Label.erase(x);

        for (auto c:adj)
            Adj[c].erase(x);

        /// Relabel all the disconnected components because of removal
        vis.clear();
        while (adj.size()){
            T next = *adj.begin();
            adj = dfs(next, next, adj);
        }
        cout<<"Node removed successfully\n";
    }

    set<T> dfs(T x, T p, set<T> adj = set<T>()){
        Label[x] = p;
        Size[p]++;
        vis[x] = 1;
        /// Remove x from adj so that does not get repeated
        adj.erase(x);
        for(auto c:Adj[x])
            if (!vis[c.first])
                adj = dfs(c.first, p, adj);
        return adj;
    }

    void add_edge(T u,T v){
        if (Adj.find(u) == Adj.end()){
            cout<<"Node "<<u<<" not present in the graph\n";
            return ;
        }
        if (Adj.find(v) == Adj.end()){
            cout<<"Node "<<v<<" not present in the graph\n";
            return ;
        }

        /// Add the edge
        Adj[u][v]++;
        Adj[v][u]++;

        /// Check whether nodes were from different Components or not
        if (Label[u] != Label[v]){
            if (Size[Label[u]] > Size[Label[v]])
                swap(u,v);

            /// Relabel the smaller component
            Size.erase(Label[u]);
            Label.erase(u);
            dfs(u,Label[v]);
        }

        cout<<"Edge added successfully\n";
    }


    void remove_edge(T u,T v){
        if (Adj.find(u) == Adj.end()){
            cout<<"Node "<<u<<" not present in the graph\n";
            return ;
        }
        if (Adj.find(v) == Adj.end()){
            cout<<"Node "<<v<<" not present in the graph\n";
            return ;
        }
        if (Adj[u][v] == 0){
            cout<<"Edge not found!\n";
            return ;
        }

        /// Remove the edge
        Adj[u][v]--;
        Adj[v][u]--;

        if (Adj[u][v] == 0){

            Adj[u].erase(v);
            Adj[v].erase(u);

            /// Remove the label since graph might get disconnected
            Size.erase(Label[u]);

            set<T> adj;

            adj.insert(u);
            adj.insert(v);

            /// Relabel the graphs again
            vis.clear();
            while (adj.size()){
                T next = *adj.begin();
                adj = dfs(next, next, adj);
            }
        }

        cout<<"Edge removed successfully\n";
    }

    ll Connected_Components(){
        return Size.size();
    }
};

int main(){
    Graph<S> G = Graph<S>();
    S u,v;
    ll id;
    while(1){
        cout<<"Enter the id of operation you want to perform:\n\n";
        cout<<"0. Exit\n";
        cout<<"1. Add an Edge\n";
        cout<<"2. Remove an Edge\n";
        cout<<"3. Add a Node\n";
        cout<<"4. Remove a Node\n";
        cout<<"5. Get count of Connected components in graph\n\n";
        cin>>id;
        switch(id){
            case 0:
                return 0;
            case 1:
                cin >> u >> v;
                G.add_edge(u,v);
                break;
            case 2:
                cin >> u >> v;
                G.remove_edge(u,v);
                break;
            case 3:
                cin >> u;
                G.add_node(u);
                break;
            case 4:
                cin >> u;
                G.remove_node(u);
                break;
            case 5:
                G.Connected_Components();
                break;
            default:
                cout<<"Please enter valid operation id!!!\n";
        }
  }
}
