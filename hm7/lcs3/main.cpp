#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s1;
  string s2;
  string s3;
  cin>>s1>>s2>>s3;
    
    int d[s1.size()][s2.size()];
    d[0][0] = (s1[0] == s2[0]);
    for (int i = 0; i < s1.size(); ++i)
    {
        d[i][0] = (d[i-1][0] == 1 || s1[i] == s2[0]);
    }
    for (int j = 1; j < s2.size(); ++j)
    {
        d[0][j] = (d[0][j-1] == 1 || s1[0] == s2[j]);
    }
    for (int i = 1; i < s2.size(); ++i)
    {
        for (int j = 1; j < s1.size(); ++j)
        {
            if (s1[i] == s2[i]) 
            {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else
            {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    if (d[s1.size()-1][s2.size()-1] != s3.size()){
        cout<<"NIE"<<endl;
        return 0;
    }   
    for (int j = 0, p = 0; j < s3.size(); ++j)
    {
        while(j < s2.size() && s2[j] != s3[p]) j++;
        if (j == s2.size())
        {
            cout<<"NIE"<<endl;
            return 0;
        }
        else j--;
    }
    return 0;
}