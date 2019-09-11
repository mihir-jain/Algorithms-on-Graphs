#include <iostream>
using namespace std;

struct Curriculum
{
    long long val;
    Curriculum* right;
};

long long DFS(bool visited[], Curriculum ar[], long long node, long long post[], long long pre[], long long clock)
{
   
    if(visited[node]==false )
    {
        visited[node] = true;
        //cout<<node<<" "<< clock<< "\n";
        pre[node-1] = clock;
        clock = clock + 1; 
        Curriculum* trace = new Curriculum;
        trace = ar[node-1].right;
        while(trace!=NULL)
        {
            clock = DFS(visited, ar, trace->val, post, pre, clock);
            trace = trace->right;
        }
        //cout<<node<<" "<< clock<< "\n";
        post[node-1] = clock;
        clock+=1;
        return clock;
    }
    else
    return clock;
    
}

int main(void)
{
    long long v, e, i;
    cin>>v>>e;
    Curriculum ar[v];
    for(i=0;i<v;i++)
    {
        ar[i].val = i+1;
        ar[i].right = NULL;
    }

    long long first, second;
    for(i=0;i<e;i++)
    {
        cin>>first>>second;
        Curriculum* x = new Curriculum();
        x->val = second;
        x->right = ar[first-1].right;
        ar[first-1].right = x;
    }
    long long post[v];
    
    long long pre[v];
    
    for(i=0;i<v;i++)
    {
        pre[i] = INT16_MAX;
        post[i] = INT16_MAX;
    }
    bool visited[v+1];
    for(i=1;i<=v;i++)
    visited[i] = false;

    long long clock = 0;long long j;
    for(i=0;i<v;i++)
    {
       if(ar[i].right!=NULL)
       clock =  DFS(visited, ar, ar[i].val, post, pre, clock);
       //cout<<clock<<" \n";
       
    }
    
    long long min;
    long long index;


    for(i=0;i<v-1;i++)
    {
        //cout<<"jello1";
        min = post[i];
        //cout<<min<<"\n";
        index = i;
        for(j=i+1;j<v;j++)
        {
            if(post[j]<min)
            {
                min = post[j];
                index = j;
            }
            
        }
        //cout<<"jello2";
        //cout<<ar[i].val<<" "<<ar[index].val<<"\n";
        long long temp = ar[i].val;
        ar[i].val = ar[index].val;
        ar[index].val = temp;
        //cout<<ar[i].val<<" \n";
        temp = post[i];
        post[i] = post[index];
        post[index] = temp;
    }

    for(i=v-1;i>=0;i--)
    cout<<ar[i].val<<" ";
    return 0;

}