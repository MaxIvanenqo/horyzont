/*#include <iostream> 
#include <string>
#include <utility> 
using namespace std; 

int lcsFind(char *X, char *Y, int m, int n) 
{ 
	int lcs[m+1][n+1]; 
	int result = 0; 
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			if (i == 0 || j == 0) 
				lcs[i][j] = 0; 

			else if (X[i-1] == Y[j-1]) 
			{ 
				lcs[i][j] = lcs[i-1][j-1] + 1; 
				result = max(result, lcs[i][j]); 
			} 
			else lcs[i][j] = 0; 
		} 
	} 
	return result; 
} 

int main() 
{ 
	char X[100]; 
	char Y[100]; 
	int m = 0;
	do {
		cin>>X[m];
		m++;
	} while (cin.peek() != '\n');
	int n = 0;
	do {
		cin>>Y[n];
		n++;
	} while (cin.peek() != '\n');

	cout << lcsFind(X, Y, m, n) << endl; 
	return 0; 
} 
*/


#include<bits/stdc++.h>
#define N cout<<endl
#define MAX 100
#define inf 999999
using namespace std;

int lcs[MAX][MAX],n;
char dir[MAX][MAX];
string s1,s2;

void LCS(void)
{
    memset(dir,'A',sizeof(dir));
    n=0;
    for(int i=0;i<=s2.length();i++)
    {
        for(int j=0;j<=s1.length();j++)
        {
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(s1[j-1]==s2[i-1])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
                dir[i][j]='C';
                n=max(n,lcs[i][j]);
            }
            else
            {
                if(lcs[i-1][j]>lcs[i][j-1])
                {
                    lcs[i][j]=lcs[i-1][j];
                    dir[i][j]='U';
                }
                else if(lcs[i-1][j]<lcs[i][j-1])
                {
                    lcs[i][j]=lcs[i][j-1];
                    dir[i][j]='L';
                }
                else
                {
                    lcs[i][j]=lcs[i-1][j];
                    dir[i][j]='U';
                }
            }
        }
    }
}

void display(int j,int i)
{
    if(dir[i][j]=='A')
        return;
    else if(dir[i][j]=='L')
    {
        display(j-1,i);
    }
    else if(dir[i][j]=='U')
    {
        display(j,i-1);
    }
    else if(dir[i][j]=='C')
    {
        display(j-1,i-1);
        printf("%c",s1[j-1]);
    }
}

int main()
{
    //fo;

    cin>>s1;

    cin>>s2;


    LCS();
    cout<< n; N;


    return 0;
}