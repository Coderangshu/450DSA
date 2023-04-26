// Using the fact that each # is atmost k diff with neighbour
// find the diff of target with current # and jump to diff/k
// index ahead to reduce the searh time.

int search(int arr[], int n, int x, int k){
    int i = 0;
    while(i<n){
        if(arr[i]==x) return i;
        // max of 1 or diff/k is used so that at
        // each step atleast 1 step is taken forward
        i += max(1,abs(arr[i]-x)/k);
    }
    return -1;
}   