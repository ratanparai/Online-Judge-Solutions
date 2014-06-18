// Verdict: Accepted
// Runtime: 0.012
#include<bits/stdc++.h>

using namespace std;

int tower1[110];
int tower2[110];
int n1,n2;
int lcsTable[110][110];

int LCS()
{
    for(int i = 1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            if(tower1[i] == tower2[j])
            {
                lcsTable[i][j] = lcsTable[i-1][j-1]+1;
            } else {
                lcsTable[i][j] = max(lcsTable[i-1][j], lcsTable[i][j-1]);
            }
        }
    }

    return lcsTable[n1][n2];
}


int main()
{
    int testCase = 1;

    while(scanf("%d%d",&n1, &n2) && (n1 && n2))
    {
        for(int j = 1; j<= n1; j++)
        {
            cin>>tower1[j];
        }
        for(int k = 1; k<= n2; k++)
        {
            cin>>tower2[k];
        }

        cout<<"Twin Towers #"<<testCase<<endl;
        cout<<"Number of Tiles : "<<LCS()<<endl<<endl;
        testCase++;
    }

    return 0;
}
