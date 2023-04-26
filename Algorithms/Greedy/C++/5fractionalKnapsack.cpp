class Solution
{
    public:
    
    // to sort by max value per unit weight
    static bool compare(Item a, Item b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        if(W==0) return 0;
        
        sort(arr,arr+n,compare);
        
        double ans = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i].weight<=W){
                ans += arr[i].value;
                W -= arr[i].weight;
            }
            else if(arr[i].weight>W){
                ans += (double)W/(double)arr[i].weight*arr[i].value;
                break;
            }
            if(W<=0) break;
        }
        return ans;
    }
        
};
