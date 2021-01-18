#include<iostream>
using namespace std;
void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i] = arr[l+i];
    for(int i=0;i<n2;i++) R[i] = arr[l+m+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[k] = L[i];
            i++;
        }
        if(R[j]<L[i]){
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l>=r) return;
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n1,n2;
	    int a1[n1],a2[n2];
	    cin>>n1>>n2;
	    for(int i=0;i<n1;i++){
	        int j;
	        cin>>j;
	        a1[i] = j;
	    }
	    for(int i=0;i<n2;i++){
	        int j;
	        cin>>j;
	        a2[i] = j;
	    }
	}
	return 0;
}
