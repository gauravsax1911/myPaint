
#include <bits/stdc++.h>
using namespace std;

int findpar(int p, vector<int> &par)
{
    return par[p] == p ? p : (par[p] = findpar(par[p], par));
}

int findminroadconv(vector<vector<int>> &roads, int n, int k)
{
    vector<int> par(n+1);

    for (int i = 0; i < n+1; i++)
    {
        par[i] = i;
    }
    sort(roads.begin(), roads.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });
    int totalmaintancecost = 0;
    int components = n;
    vector<int> costofroad;
    for (vector<int> x : roads)
    {
        int u = x[0];
        int v = x[1];
        int w = x[2];

        int p1 = findpar(u, par);
        int p2 = findpar(v, par);
        
        if (p1 != p2)
        {
            par[p1] = p2;
            totalmaintancecost += w;
            costofroad.push_back(w);
            components-- ;
            
        }
    }
    if(components > 1)
    {return -1 ; }
    int count = 0;
    if(totalmaintancecost <= k)
    {return 0;}

    for(int i=costofroad.size()-1;i>=0;i--)
    {   
        
         totalmaintancecost -= costofroad[i] + 1;
          if(totalmaintancecost <= k)
         {return count +1  ;}
          count++;
    }
    if(totalmaintancecost > k)
    {return -1;}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> roads;

    for (int i = 0; i < m; i++)
    {
        int c1, c2, w;
        cin >> c1 >> c2 >> w;
        roads.push_back({c1, c2, w});
    }

    int maintancecost = findminroadconv(roads, n, k);
    cout<<maintancecost<< endl;
}
