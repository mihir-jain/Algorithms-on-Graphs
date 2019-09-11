#include <iostream>
#include <vector>

using namespace std;

struct flight
{
    long long val;
    flight* right;
};

void BFS( long long distance[], flight ar[], long long source, long long v)
{

    distance[source] = 0;
    vector<long long> queue;
    queue.insert(queue.begin(), source);
    /*long long l;
    l = queue.size();
    for(long long j = 0;j<l;j++)
    cout<<queue[j]<<" ";
    cout<<"\n";
    */
    //queue.push_back(source);

    while(!queue.empty())
    {
        /*l = queue.size();
        for(long long j = 0;j<l;j++)
        cout<<queue[j]<<" ";
        cout<<"\n";
        */
        long long x = queue.back();
        queue.pop_back();
        flight* track = new flight();
        flight* t = new flight();
        t = ar[x-1].right;
        track = ar[x-1].right;
        while(track!=NULL)
        {
            if(distance[track->val]== -1)
            {
                queue.insert(queue.begin(), track->val);
                distance[track->val] = distance[x] + 1;
            }
            track = t->right;
            t = t->right;
        }
    }

}

int main(void)
{
    long long n, i, v, e, source, dest;
    cin>>v>>e;
    flight ar[v];
    for(i=0;i<v;i++)
    {
        ar[i].val = i+1;
        ar[i].right = NULL;
    }

    for(i=0;i<e;i++)
    {
        cin>>source>>dest;
        flight* node = new flight();
        node->val = dest;
        node->right = ar[source-1].right;
        ar[source-1].right = node;

        flight* node_d = new flight();
        node_d->val = source;
        node_d->right = ar[dest-1].right;
        ar[dest-1].right = node_d;
    }

    cin>>source>>dest;
    long long distance[v+1];
    for(i=1;i<=v;i++)
    distance[i] = -1;
    BFS(distance, ar, source, v);

    /*for(i=1;i<=v;i++)
    cout<<distance[i]<<" ";
    cout<<"\n";
*/  
    cout<<distance[dest];



    return 0;
}
