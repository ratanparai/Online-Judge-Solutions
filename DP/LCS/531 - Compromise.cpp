// Verdict: Accepted
// Runtime: 0.032
#include<bits/stdc++.h>

using namespace std;

string word1[110];
string word2[110];

int lcsTable[110][110];
int trackLcs[110][110];
int n1, n2;

int countPrint;

void LCS()
{
    for(int i = 1; i<= n1; i++)
    {
        for (int j = 1; j<= n2; j++)
        {
            if(word1[i] == word2[j])
            {

                lcsTable[i][j] = lcsTable[i-1][j-1] + 1;
                trackLcs[i][j] = 1;
            } else
                if(lcsTable[i-1][j] >= lcsTable[i][j-1])
                {
                    lcsTable[i][j]= lcsTable[i-1][j];
                    trackLcs[i][j] = 2;
                } else {

                    lcsTable[i][j] = lcsTable[i][j-1];
                    trackLcs[i][j] = 3;
                }

        }
    }
}

void printLCS(int x, int y)
{
    if(x<1 || y<1 )
        return;

    if(trackLcs[x][y] == 1)
    {
        printLCS(x-1, y-1);
        cout<<word1[x];
        countPrint++;
        if(countPrint<lcsTable[n1][n2])
            cout<<" ";
        else {
            cout<<endl;
        }
    } else if(trackLcs[x][y] == 2)
    {
        printLCS(x-1,y);
    } else {
        printLCS(x, y-1);
    }
}

int main()
{
    while(cin>>word1[1])
    {
        n1 = n2 = 1;

        while(true)
        {
            if(word1[n1] == "#")
            {
                n1--;
                break;
            }

            n1++;
            cin>>word1[n1];
        }

        cin>>word2[1];
        while(true)
        {
            if(word2[n2] == "#")
            {
                n2--;
                break;
            }

            n2++;
            cin>>word2[n2];
        }

        LCS();
        countPrint = 0;
        printLCS(n1, n2);



    }

    return 0;
}
