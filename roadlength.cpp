#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

long double distance(long long x1, long long y1, long long x2, long long y2)
{
    long long a = (long long)(pow((x1-x2), 2) + 0.5);
    long long b = (long long)(pow(y1-y2, 2)+0.5);
    //long long c = a+b; 

    //double p = sqrt(c);
    //return p;
    
    return sqrt(a+b); 
}

void construction(long double sorted[][7], long long n, long long segments)
{
    long double parent[n+1];       
    long double length;
    long long k = 0, i;
    long long v = sorted[k][5]; 
    long long count = 1;   
    long long dest = sorted[k][6];

    //for(i=0;i<segments;i++)
    //cout<<sorted[i][4]<<" "<<sorted[i][5]<<" "<<sorted[i][6]<<"\n";
    for(i=1;i<=n;i++)
    parent[i] = i;     
    length = sorted[k][4];  
    parent[v] = parent[dest];
    k = k+1;
    while(count!=n-1 && k<segments)
    {
        //cout<<count<<" "<<k<<"\n";
        v = sorted[k][5];
        dest = sorted[k][6];
        if(parent[dest]!=parent[v])
        {
            long long l = parent[v];
            parent[v] = parent[dest];
            for(long long y=1;y<=n;y++)
            {
                if(parent[y]==l)
                parent[y] = parent[dest];
            }
            length = length + sorted[k][4];
            count = count + 1;
        }
        k = k+1;
    }
    cout << fixed << setprecision(9) << length;
  
}

int main(void)
{
    long long n, i, j;
    cin>>n;
    long long segments = n*(n-1)/2;
    long long ar[n][3];

    long double s[segments][7];
    long double d;
    for(i=0;i<n;i++)
    {
        cin>>ar[i][0]>>ar[i][1];
        ar[i][2] = i+1;
    }   

    long long k = 0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            d =  distance(ar[i][0], ar[i][1], ar[j][0], ar[j][1]);
            //cout<<d<<"\n";
            s[k][0] = (double)ar[i][0];
            s[k][1] = (double)ar[i][1];
            s[k][2] = (double)ar[j][0];
            s[k][3] = (double)ar[j][1];           
            s[k][4] = (double)d;
            s[k][5] = (double)ar[i][2];
            s[k][6] = (double)ar[j][2];
            k = k+1;
        }
    } 
    
    long long index;
    long double t;
    for(i=0;i<segments-1;i++)
    {
        index = i;
        for(j=i+1;j<segments;j++)
        {
            if(s[j][4]<s[index][4])
            index = j;
            
        }
        t = s[index][0];
        s[index][0] = s[i][0];
        s[i][0] = t;

        t = s[index][1];
        s[index][1] = s[i][1];
        s[i][1] = t;

        t = s[index][2];
        s[index][2] = s[i][2];
        s[i][2] = t;

        t = s[index][3];
        s[index][3] = s[i][3];
        s[i][3] = t;

        t = s[index][4];
        s[index][4] = s[i][4];
        s[i][4] = t;
        
        t = s[index][5];
        s[index][5] = s[i][5];
        s[i][5] = t;

        t = s[index][6];
        s[index][6] = s[i][6];
        s[i][6] = t;
    }    


    construction(s, n, segments);
    return 0;
}