// Verdict: Accepted
// Runtime: 0.016
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int b;

    char ch[1000];

    while(gets(ch))
    {
        int len = strlen(ch);
        b = -1;

        for(int i= 0; i<len; i++)
        {

            if(ch[i] == ' ')
            {
                for(int j = i-1; j>b; j--)
                {
                    printf("%c", ch[j]);

                }
                printf(" ");
                b = i;
            }
        }

        for (int k = len -1; k>b; k--)
        {
            printf("%c", ch[k]);
        }
        printf("\n");
    }

    return 0;
}
