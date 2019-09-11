#include <iostream>
#include <vector>
using namespace std;

struct cost
{
    long long val;
    long long weight;
    cost* right;
};

void Dijkstra(long long distance[], cost ar[], long long source, long long v)
{
    
    long long i; 
    bool visited[v+1];
    for(i=1;i<=v;i++)
    visited[i]= false;
    distance[source] = 0;    
       
    long long vertex = source;   
    while(visited[vertex]==false)
    {   
        visited[vertex] = true;     
        cost* x = new cost();
        x = ar[vertex].right;

        while(x!=NULL)
        {
            if(distance[x->val]> distance[vertex] + x->weight)
            distance[x->val] = distance[vertex] + x->weight;
            x = x->right; 
        }
            
        long long m = INT16_MAX;
        long long index = source;
        for(i =1;i<=v;i++)
        {
            if(distance[i]<m && visited[i]==false)
            {
                m = distance[i];
                index = i;
            }
        }

        vertex = ar[index].val;
        
    }

    for(i=1;i<=v;i++)
    {
        if(distance[i]==INT16_MAX)
        distance[i] = -1;
    }
}

int main(void)
{
    long long v, e, w, i, first, second;
    cin>>v>>e;
    if(e==0)
    {
        cout<<-1;
        return 0;
    }
    cost ar[v+1];
    for(i=1;i<=v;i++)
    {
        ar[i].val = i;
        ar[i].right = NULL;
    }

    for(i=1;i<=e;i++)
    {
        cin>>first>>second>>w;
        cost* x = new cost();
        x->val = second;    
        x->right = ar[first].right;
        ar[first].right = x;
        x->weight = w;      

    }
    
    cin>>first>>second;
    
    if(first>v || second>v)
    {
        cout<<-1;
        return 0;
    }
    long long distance[v+1];
    for(i=1;i<=v;i++)
    distance[i] = INT16_MAX;

    Dijkstra(distance, ar, first, v);

    cout<<distance[second];



    return 0;

}