#include<bits/stdc++.h>

using namespace std;

int ch[123];

char inp[501];

int main()
{

    // to save the calculated length of the input string
    int length;

    // to skip the first odd number
    bool first;

    // talking input inside while loop
    while(cin>>inp)
    {

        // checking if # in pressed. if then break and exit.
        if(inp[0] == '#')
        {
            break;
        }

        // default value of first is setting true;
        first = true;

        // calculating and storing the value of the string to length
        length = strlen(inp);

        // calculating the occurrence of characters in the string
        for(int i=0; i<length; i++)
        {
            ch[inp[i]]++;
        }


        // checking and printing the result.
        for(int j = 122; j>=97; j--)
        {
            if(ch[j] % 2 !=0  )
            {
                if(first)
                {
                    first = false;
                } else
                {
                    cout<<char(j);
                }


            }
            // reset the count value to zero.
            ch[j] = 0;

        }

        cout<<endl;

    }

    return 0;
}
