// Verdict: Accepted
// Runtime: 0.009

#include<iostream>

using namespace std;

int main()
{

    int testCase;

    int number1;
    int number2;

    int sum;

    cin>>testCase;
    for(int i = 1; i<= testCase; i++)
    {
        cin>>number1>>number2;
        sum = 0;

        for(int j = number1; j<=number2; j++)
        {
            if(j&1)
                sum +=j;
        }

        cout<<"Case "<<i<<": "<<sum<<endl;
    }

    return 0;
}
