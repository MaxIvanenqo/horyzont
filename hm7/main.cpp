#include <bits/stdc++.h>
using namespace std;
void printLCS( string s1, string s2, int m, int n, string s3 )
{
   int L[m+1][n+1];
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (s1[i-1] == s2[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   int index = L[m][n];
   char LCS[index+1];
   LCS[index] = '\0'; 
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      if (s1[i-1] == s2[j-1])
      {
          LCS[index-1] = s1[i-1];
          i--; j--; index--;
      }
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
   string a = LCS;
 	 if (s3.compare(a) == 0) {
 	 	cout<<"TAK"<<endl;
 	 }
 	 else cout<<"NIE"<<endl;
}
int main()
{
  string s1;
  string s2;
  string s3;
  cin>>s1>>s2>>s3;
  printLCS(s1, s2, s1.size(), s2.size(), s3);
  return 0;
}