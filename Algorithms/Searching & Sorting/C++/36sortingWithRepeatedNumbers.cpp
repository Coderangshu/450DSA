// see the post linked via the sheet excellent explanation

#include<bits/stdc++.h>
using namespace std;

int compare(int n1, int n2){
	if(n1>n2) return 1;
	else if(n1<n2) return -1;
	else return 0;
}

pair<int,int> partition(int arr[], int start, int end){
	// lessThan is filled left to right
	// greaterThan is filled right to left
	int lessThan, current, greaterThan;
	lessThan = current = start;
	greaterThan = end;

	// start element is taken as the partitioning value
	int partitioningValue = arr[start];

	// while there's unvisited element, i.e. the elements
	// in between current index and the greaterThan index
	// keep arranging elements w.r.t. partitioningValue and
	// place in respective section (lessThan/greaterThan)
	while(current<=greaterThan){
		int compareCur = compare(arr[current],partitioningValue);
		switch(compareCur){
			// if current greater than partitioningValue send
			// to greater section and decrement greaterThan
			case 1:
				swap(arr[current],arr[greaterThan--]);
				break;
			// if same increment current
			case 0:
				current++;
				break;
			// if less than send to lesser section and increment
			// both lessThan and current
			case -1:
				swap(arr[current++],arr[lessThan++]);
				break;
		}
	}
	// sending back the ending index of less section
	// and the starting index of greater section
	// so that these sections can be sorted recursively
	return {lessThan,greaterThan};
}

void quickSort3WayPartition(int arr[], int start, int end){
	if(start>end) return;
	auto getLTGT = partition(arr,start,end);

	// sending for sorting the lesser and the greater section
	quickSort3WayPartition(arr,start,getLTGT.first-1);
	quickSort3WayPartition(arr,getLTGT.second+1,end);
}

int main(){
	int arr[] = {1,4,2,6,2,5,3,1,5,3,4,2,6,1,3,2,4,5,3,4,6,5,2,3,4,1,3};
	int n = sizeof(arr)/sizeof(int);

	quickSort3WayPartition(arr,0,n-1);

	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}
