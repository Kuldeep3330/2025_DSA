int maxProfit(vector<int> &prices)
{
    // //TLE at 201
    // int n=prices.size();
    // int profit=0;
    // for( int i=0; i<n-1; i++){
    //     for( int j=i+1; j<n; j++){
    //         int diff=prices[j]-prices[i];
    //         if(diff>0)
    //         profit=max(profit, diff);
    //     }
    // }
    // return profit;

    // using kadane algorithm
    int n = prices.size();
    for (int i = 0; i < n - 1; i++)
    {
        prices[i] = prices[i + 1] - prices[i];
    }
    prices.resize(n - 1);

    for (int i = 1; i < n - 1; i++)
    {
        prices[i] = max(prices[i], prices[i - 1] + prices[i]);
    }
    int profit = 0;
    for (int i = 0; i < n - 1; i++)
    {
        profit = max(profit, prices[i]);
    }
    return profit;
}