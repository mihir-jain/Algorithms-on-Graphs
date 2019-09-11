#include <iostream>
using namespace std;

struct Maze
{
    long long val;
    Maze* right;
};

void DFS(Maze ar[], long long node, bool visited[])
{
    if(visited[node]==false)
    {
        visited[node] = true;
        Maze* trace = new Maze();
        trace = ar[node-1].right;
        while(trace!=NULL)
        {
            DFS(ar, trace->val, visited);
            trace = trace->right;
        }
    }
        
}

int main(void)
{
    long long v, e;
    cin>>v>>e;
    Maze ar[v];
    long long i, first, second;
    for(i=0;i<v;i++)
    {
        ar[i].val = i+1;
        ar[i].right = NULL;
    }
    for(i=0;i<e;i++)
    {
        cin>>first>>second;
        Maze* x = new Maze();
        x->val = second;
        x->right = ar[first-1].right;
        ar[first-1].right = x;

        Maze* y = new Maze();
        y->val = first;
        y->right = ar[second-1].right;
        ar[second-1].right = y;
    }
    
    long long path_b, path_e;
    cin>>path_b>>path_e;

    bool visited[v+1];
    for(i=1;i<=v;i++)
    visited[i] = false;

    DFS(ar, path_b, visited);
    if(visited[path_e]==true)
    cout<<1;
    else
    cout<<0;    
    
    return 0;
}
