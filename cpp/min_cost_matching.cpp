#include <bits/stdc++.h>
using namespace std;
int maxWord, n, x[20], y[20];
double dist[20][20],dp[1<<16];
 
double rec(int word)
{
    if(word == maxWord)
        return 0;
    else if(dp[word]!=-1)
        return dp[word];
    else
    {
        int i,j;
        double d=1<<30;
        for(i = 0;i<2*n;i++)
        {   if(!(word&(1<<i)))  //check if player at position i is available
            {   for(j=i+1;j<2*n;j++)
                {   if(!(word&(1<<j)))  ////check if player at position j is available
                    {
                        d = min(d,dist[i][j]+rec(word|(1<<i)|(1<<j)));
                    }
                }
            }
        }
        return dp[word]=d;
    }
}
// sqrt((x2 - x1)^2 + (y2 - y1)^2)
double dis(int i, int j)
{   return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])); }
 
int main()
{
    char name[20];
    int i,j;
    scanf("%d",&n);
     maxWord = (1<<(2*n))-1; // 2^no._of_players - 1
        for(i=0;i<2*n;i++)
            scanf("%s %d %d",name,x+i,y+i); //input
        for(i=0;i<2*n;i++)
            for(j=i+1;j<2*n;j++)
                dist[i][j]=dist[j][i]=dis(i,j); //calculate distances of probable pairs
        for(i=0;i<=maxWord;i++)
            dp[i]=-1;   //initialize
        printf("%.2lf\n",rec(0));   //call function rec with initial word 0
      

    return 0;
}
