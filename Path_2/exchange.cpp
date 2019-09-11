#include <iostream>
using namespace std;

struct money
{
    long long val;
    long long weight;
    money* right;
};

void neg_cyc_det(long long distance[], money ar[], long long v)
{
    long long i, j;
    for(j=1;j<=v;j++)
    {
        if(ar[j].right!=NULL)
        break;
    }

    distance[j] = 0;
    for(i=j;i<=v-1;i++)
    {
       for(long long k=1; k<=v;k++)
       {
           
           money* track = new money();
           track = ar[k].right;
           //cout<<track->val<<"\n";
           while(track!=NULL)
           {
               if(distance[track->val]> distance[k] + track->weight)
               distance[track->val] = distance[k] + track->weight;
               track = track->right;
           }           
        }
    }

    bool flag = false;
    for(long long k =1; k<=v;k++)
    {
           
        money* track = new money();
        track = ar[k].right;
        //cout<<track->val<<"\n";
        while(track!=NULL)
        {
            if(distance[track->val]> distance[k] + track->weight)
            flag = true;
            break;
            track = track->right;
        }
        if(flag==true)
        break;
    }
    if(flag==true)
    cout<<1;
    else
    cout<<0;
}
      
int main(void)
{
    long long i, v, e, w, first, second;
    cin>>v>>e;
    money ar[v+1];
    for(i=1;i<=v;i++)
    {
        ar[i].val = i;
        ar[i].right = NULL;
    }
    for(i=1;i<=e;i++)
    {
        cin>>first>>second>>w;
        money* x = new money();
        x->val = second;
        x->right = ar[first].right;
        x->weight = w;
        ar[first].right = x;
    }
    long long distance[v+1];
    for(i=1;i<=v;i++)
    distance[i] = INT16_MAX;
    neg_cyc_det(distance, ar, v);

    return 0;

}