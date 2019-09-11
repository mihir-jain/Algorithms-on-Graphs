#include <iostream>
using namespace std;

struct Maze
{
    long long val;
    Maze* right;
};

bool DFS(long long source, Maze ar[], long long node, bool visited[])
{
    for(int j=1;j<=4;j++)
    cout<<visited[j]<<" ";
    cout<<"\n";
    if(node == source && visited[source]==true)
    return false;
    else if(visited[node]==false)
    {
        visited[node] = true;
        Maze* trace = new Maze();
        trace = ar[node-1].right;
        
        while(trace!=NULL)
        {
            bool x = DFS(source, ar, trace->val, visited);
            if(x==false)
            return false;
            trace = trace->right;
        }
        return true;
    }
    else
    return true;
    

}

int main(void)
{
    long long v, e;
    cin>>v>>e;
    if(e==0)
    {
        cout<<0;
        return 0;
    }
    
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
  
    }

    bool visited[v+1];
    long long var = 0;;
    long long source, j;
    for(i=0;i<v;i++)
    {
        source = ar[i].val;
        for(j=1;j<=v;j++)
        visited[j] = false;     
        bool y = DFS(source, ar, source, visited);
        if(y==false)
        {
            var = 1;
            break;
        }
    }

    cout<<var;
    return 0;
}
