#include <bits/stdc++.h>
using namespace std;

void moreThanNdK(int arr[],int n,int k){
	// k should be 2 or more as for one this conditions are not valid
	if(k < 2) return;
	// k-1 is the atmost number of different values that can be
	// present in the array as (n/k)*k = n and it is told that more
	// than n/k number of times so k-1.

	// Initialization of the k-1 elements in the pair array
	// wherein e(lements) holds INT_MAX and c(ount) holds 0.
	vector<pair<int,int>> kElems(k-1,{INT_MAX,0});

	// Iterating through the complete array only once.
	for(int i=0;i<n;i++){
		// If arr[i] is in temp increase its count by 1.
		int j;
		for(j=0;j<k-1;j++){
			if(kElems[j].first==arr[i]){
				kElems[j].second++;
                break;
            }
		}
		// If there is no element matching arr[i] in temp
		// then two things can be done, either create a new
		// position for the element(if k-1 slots are not
		// filled) else decreement all the counts for the
		// k-1 elements in the temp by 1.
		if(j == k-1){
			// Applying the first option
			for(j=0;j<k-1;j++){
				if(kElems[j].second==0){
					kElems[j] = {arr[i],1};
                    break;
                }
			}
			// Applying the second option
			if(j==k-1) for(auto &e:kElems) e.second--;
		}
	}
	// Till now maximum total time spend is O(n)*O(k) == O(nk).
	// Now we have got our candidates that might be fulfilling the given
	// criteria. So, lastly we check all this elements and their counts
	// the array to make sure the count of each element.
	for(int i=0;i<k-1;i++){
		int f=0;
		for(int j=0;j<n;j++) if(kElems[i].first==arr[j]) f++;
		if(f>n/k) cout<<"Number: "<<kElems[i].first<<endl<<"Frequency: "<<f<<endl;
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
