// verdict  : Accepted
// Run Time : 0.012
#include<bits/stdc++.h>

using namespace std;

int main()
{
    char ch;

    bool first = true;

    //freopen("out.txt", "w" , stdout);

    while(scanf("%c", &ch) ==1)
    {
        if(ch != '"')
        {
            printf("%c", ch);
        } else {
            if(first)
            {
                printf("``");
                first = false;
            } else {
                printf("''");
                first = true;
            }
        }
    }

    //fclose(stdout);

    return 0;
}
