// Getting runtime error?

#include<iostream>

typedef unsigned long int ll;

using namespace std;

// because 0 < A, B, C, P <= 100000000
ll NumOfWays;
ll Coins[4];
ll minValue;
ll tryCount;

ll minimum(ll first, ll second)
{
    return first<second?first:second;
}


void CountWays(ll first, ll Total)
{
    tryCount++;
    cout<<"Trying : "<<tryCount<<endl;
    if(first>3)
    {
        return;
    }

    if(Total == 0)
    {
        NumOfWays++;
        return;
    }

    if(Total < minValue)
    {
        return;
    }

    CountWays(first, Total - Coins[first]);
    CountWays(first+1, Total);

    return;
}


int main()
{
    ll giftTotal;
    ll testCase;

    cin>>testCase;
    for(int i=1; i<=testCase; i++ )
    {
        NumOfWays = 0;
        cin>>Coins[1]>>Coins[2]>>Coins[3]>>giftTotal;

        minValue = minimum((minimum(Coins[1], Coins[2])), Coins[3]);

        cout<<minValue<<endl;

        CountWays(1,giftTotal);

        cout<<"Case "<<i<<": "<<NumOfWays<<endl;



    }

    return 0;
}
