#include<bits/stdc++.h>
using namespace std;

int findpar(int p,vector<int> par)
{
  return par[p] == p ? p : (par[p] = findpar(par[p],par));
}

int optimizewaterdist(vector<vector<int>> &pipes, int n , vector<int> &wellprices)
{
            for(int i=0;i<n;i++)
            {
                pipes.push_back({0,i+1,wellprices[i]});
            }

          sort(pipes.begin(),pipes.end(),[](vector<int> &a , vector<int> &b)
          {
              return a[2] < b[2];
          });
          int cost = 0;
          vector<int> par(n);
          for(int i=0;i<n;i++)
          {
              par[i] = i;
          }

          for(vector<int> vec : pipes)
          {
              int u = vec[0];
              int v = vec[1];
              int cost = vec[2];
         
             int p1 = findpar(u,par);
             int p2 = findpar(v,par);

             if(p1 != p2)
             {
                 par[p1] = p2;
                 cost++;
             }

          }


}


int main()
{

}