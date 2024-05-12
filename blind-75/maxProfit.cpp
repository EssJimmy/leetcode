#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices){
    int ans = 0;
    
    int l = 0;

    for(int i = 1; i < (int) prices.size(); i++){
        if(prices[l] < prices[i]) ans = max(ans, prices[i] - prices[l]);
        else l = i;
    }

    return ans;
}

int main(void){
    int n;
    
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxProfit(arr) << endl;
    
    return 0;
}