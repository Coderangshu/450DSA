#include <bits/stdc++.h>
using namespace std;

// A structure to contain the element and its
// count while the Moore Voting Algorithm is in action.
struct EC{
	int e;
	int c;
};

void moreThanNdK(int arr[],int n,int k){
	// k should be 2 or more as for one this conditions are not valid
	if(k < 2) return;
	// k-1 is the atmost number of different values that can be
	// present in the array as (n/k)*k = n and it is told that more
	// than n/k number of times so k-1.

	// Initialization of the k-1 elements in the struct array
	// wherein e(lements) holds -1 and c(ount) holds 0.
	// cout<<"Hello"<<endl;
	struct EC temp[k-1];
	for(int i=0;i<k-1;i++){
		temp[i].e = -1;
		temp[i].c = 0;
	}

	// Iterating through the complete array only once.
	for(int i=0;i<n;i++){
		// If arr[i] is in temp increase its count by 1.
		int j;
		for(j=0;j<k-1;j++){
			if(temp[j].e == arr[i]){
			// cout<<i<<" "<<j<<endl;
				temp[j].c += 1;
				break;
			}
		}
		// If there is no element matching arr[i] in temp
		// then two things can be done, either create a new
		// position for the element(if k-1 slots are not
		// filled) else decreement all the counts for the
		// k-1 elements in the temp by 1.

		// Applying the first option
		if(j == k-1){
			int l;
			for(l=0;l<k-1;l++){
				if(temp[l].c == 0){
					temp[l].e = arr[i];
					temp[l].c = 1;
					break;
				}
			}
			if(l == k-1) for(int m=0;m<k-1;m++) temp[m].c -= 1;
		}
	}
	// Till now maximum total time spend is O(n)*O(k) == O(nk).
	// Now we have got our candidates that might be fulfilling the given
	// criteria. So, lastly we check all this elements and their counts
	// the array to make sure the count of each element.
	for(int i=0;i<k-1;i++){
		int f=0;
		for(int j=0;j<n;j++) if(temp[i].e == arr[j]) f++;
		if(f>n/k) cout<<"Number: "<<temp[i].e<<endl<<"Frequency: "<<f<<endl;
	}
}

int main()
{
		// int size,k;
    cout << "First Test\n";
    int arr1[] = { 4, 5, 6, 7, 8, 4, 4 };
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int k = 3;
    moreThanNdK(arr1, size, k);

    cout << "\nSecond Test\n";
    int arr2[] = { 4, 2, 2, 7 };
    size = sizeof(arr2) / sizeof(arr2[0]);
    k = 3;
    moreThanNdK(arr2, size, k);

    cout << "\nThird Test\n";
    int arr3[] = { 2, 7, 2 };
    size = sizeof(arr3) / sizeof(arr3[0]);
    k = 2;
    moreThanNdK(arr3, size, k);

    cout << "\nFourth Test\n";
    int arr4[] = { 2, 3, 3, 2 };
    size = sizeof(arr4) / sizeof(arr4[0]);
    k = 3;
    moreThanNdK(arr4, size, k);

    return 0;
}
