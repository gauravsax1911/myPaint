#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int v, w;

    edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

void addedge(vector<vector<edge>> &edges, int u, int v, int w)
{
    edges[u].push_back(edge(v, w));
    edges[v].push_back(edge(u, w));
}

// Complexity : 2E
// O(2E)

void display(vector<vector<edge>> &edges, int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "--->";
        vector<edge> v1 = edges[i]; // for(edge e : edges[i])
                                    // { cout <<}
        for (int j = 0; j < v1.size(); j++)
        {
            cout << "(" << v1[j].v << "," << v1[j].w << ")"
                 << " ";
        }
        cout << endl;
    }
}

static std::vector<int> par;
static std::vector<int> size;

int findpar(int p)
{
    return par[p] == p ? p : (par[p] = findpar(par[p]));
}

void merge(int p1, int p2)
{
    if (size[p1] > size[p2])
    {
        par[p2] = p1;
        size[p1] += size[p2];
    }

    else
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
}

void unionfun(vector<vector<int>> edges, int n)
{
    vector<vector<edge>> graph;
    
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        size[i] = 1;
    }

    for (vector<int> vec : edges)
    {
        int u = vec[0];
        int v = vec[1];
        int w = vec[2];

        int p1 = findpar(u);
        int p2 = findpar(v);

        if (p1 != p2)
        {
            merge(p1,p2);
            addedge(graph,u,v,w);

        }
    }
}


//KRUSKAL'S ALGO

void kruskalalgo(vector<vector<int>> &edges, int n)
{
       sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });
       
       unionfun(edges,n);
}

int main()
{
    int n = 12;

    vector<vector<edge>>  edges(2*n, vector<edge>());

    //   EDGES WILL CONTAIN U V AND W
    // EDGES[0] = U EDGED[1] = V EDGES[2] = W;

    addedge(edges, 3, 4, 1);
    addedge(edges, 0, 1, 2);
    addedge(edges, 2, 1, 3);

    addedge(edges, 10, 11, 1);

    addedge(edges, 8, 9, 3);
    addedge(edges, 8, 7, 1);
    addedge(edges, 7, 6, 2);
    addedge(edges, 6,5, 1);
    
    vector<int> pricewell = {1,3,2,3,2,4,1,2,3,2,5,4};
    for(int i=0;i<pricewell.size();i++)
    {
        addedge(edges,i,n+1,pricewell[i]);
    }

    



  
    return 0;
}