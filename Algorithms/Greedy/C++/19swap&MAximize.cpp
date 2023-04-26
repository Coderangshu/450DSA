long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    
	// observe that while absolute diff sum
	// each small element is subtracted twice
	// each larger element is add twice
    long long int sum = 0;
    for (int i = 0; i < n/2; i++){
        sum -= (2 * arr[i]);
        sum += (2 * arr[n - i - 1]);
    }
    
    return sum;
}
