#include<bits/stdc++.h>
using namespace std;
class coordinates{
    public:
    int x;
    int y;
    coordinates(int x,int y)
    {
        this-> x = x;
        this-> y = y;
    }

};

int mincosttoconnectallpoints(vector<vector<int>> &points)
{     
      vector<vector<pair<coordinates,int>>> allpoints;
      int level = 0;
      for(int i=0;i<points.size();i++)
      {   allpoints.push_back({});
          for(int j=i+1;j<points.size();j++)
          {
              allpoints[level].push_back()
          }
      } 




}



int main()
{

}