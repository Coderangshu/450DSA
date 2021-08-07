#include<bits/stdc++.h>
using namespace std;

// Understanding the concept behind sorted rotated array :

// 1 rotaton means the first element goes to last 

// PIVOT element is that element where the sorted
// array ends and the rotated elements begin, thus
// pivot element will always be the max of the array

// Also the index of the the NUMBER OF ROTATIONS can
// be obtained from the index of the pivot element,
// the formula is N-(index_of_pivot)-1

// NOR = Number of Rotations
// sorted rotated array example:
// Let sorted array is : 1 2 3 4 5 6 7 8 9 10
// Pivot element : 10, index : 9, NOR : 10-9-1 = 0

// After 1 rotation : 2 3 4 5 6 7 8 9 10 1
// Pivot element : 10, index : 8, NOR : 10-8-1 = 1
 
// After 2 rotation : 3 4 5 6 7 8 9 10 1 2
// Pivot element : 10, index : 7, NOR : 10-7-1 = 2

// After 3 rotation : 4 5 6 7 8 9 10 1 2 3
// Pivot element : 10, index : 6, NOR : 10-6-1 = 3

// After 4 rotation : 5 6 7 8 9 10 1 2 3 4
// Pivot element : 10, index : 5, NOR : 10-5-1 = 4


// To find the position of the pivot element we use modified
// binary search
// The max element has a special property both the previous and
// next of it are smaller always, thus for every mid obtained while
// binary search we check both the prev and next of it and return when
// condition gets satified
// Now observe that w.r.t. mid one side would be sorted(including it)
// and the other side would be unsorted(including it), and the pivot will
// always lie in the unsorted part thus we continue our search in the unsorted
// part

// function to binary search the index of the pivot element
// this function considers array is sorted ascendingly
int binarySearch(vector<int> a){
	int n = a.size();
	int low = 0, high = n-1, mid;
	while(low<=high){
		mid = low+(high-low)/2;

		// check prev and next of mid
		// prev we add n and put a modulo to keep check for
		// when mid = 0
		// next we put modulo to keep check for when mid = n-1
		int prev = (mid+n-1)%n, next = (mid+1)%n;
		// if condition satified then return mid
		if(a[prev]<=a[mid] and a[next]<=a[mid]) return mid;

		// else get the unsorted side of mid
		// observe that if pivot lies in right than right half is
		// unsorted and thus a[mid]>a[high] and we search right
		// if pivot lies in left than left half is unsorted and
		// a[low]>a[mid] and we search left
		if(a[mid]>a[high]) low = mid+1;
		else if(a[low]>a[mid]) high = mid-1;
		// else the sorted array has no rotation thus return the
		// side that has the higher sets of value
		else low = mid+1;
	}
	return mid;
}

int main(){
	// given sorted rotated array of different kind
	// the one to use make name as arr
	vector<int> arr1 = {3,4,5,6,7,8,9,10,1,2};
	vector<int> arr = {9,10,1,2,3,4,5,6,7,8};
	vector<int> arr2 = {1,2,3,4,5,6,7,8,9,10};
	vector<int> arr3 = {10,1,2,3,4,5,6,7,8,9};
	cout<<"Input array is: ";
	for(auto e:arr) cout<<e<<" ";
	cout<<endl;

	int n = arr.size();

	int pivotIndex = binarySearch(arr);
	int NOR = n-pivotIndex-1;

	cout<<"Pivot element : "<<arr[pivotIndex]<<endl;
	cout<<"Number of rotations : "<<NOR<<endl;
	return 0;
}
