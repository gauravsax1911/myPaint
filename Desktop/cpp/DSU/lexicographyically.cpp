#include <bits/stdc++.h>
using namespace std;

                                                 

string lexicographically_smallest_equivalent_string(string s1, string s2, string base)
{
    vector<char> parent(128);
    for (int i = 97; i < 123; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < s1.length(); i++)
    {
        char ch1 = s1[i];
        char ch2 = s2[i];

        char p1 = findpar(ch1, parent);
        char p2 = findpar(ch2, parent);

        if (p1 > p2)
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p2] = p1;
        }

    }

    
        string ans = "";

        for (int i = 0; i < base.length(); i++)
        {
            char ch = base[i];
            char x = findpar(ch, parent);
            ans += x;
        }

        return ans;
}

int main()
{
    string s = lexicographically_smallest_equivalent_string("parker", "morris", "parser");
    cout << s;

    return 0;
}