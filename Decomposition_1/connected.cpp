#include <iostream>
using namespace std;

struct Maze
{
    long long val;
    Maze* right;
};

void DFS(Maze ar[], long long node, bool visited[], long long comp_val[], long long c)
{
    if(visited[node]==false)
    {
        comp_val[node] = c; 
        visited[node] = true;
        Maze* trace = new Maze();
        trace = ar[node-1].right;
        while(trace!=NULL)
        {
            DFS(ar, trace->val, visited, comp_val, c);
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
    
    
    bool visited[v+1];
    for(i=1;i<=v;i++)
    visited[i] = false;

    long long comp_val[v+1];
    for(i=1;i<=v;i++)
    comp_val[i] = 1;
    long long c = 0;
    for(i=0;i<v;i++)
    {
        if(visited[i+1]==false)
        {
            c+=1;
            DFS(ar, ar[i].val, visited, comp_val,c);
        }
    }
    
    long long max = comp_val[1];
    for(i=2;i<=v;i++)
    {
        if(comp_val[i]>max)
        max = comp_val[i];
    }
    cout<<max;
    
    return 0;
}