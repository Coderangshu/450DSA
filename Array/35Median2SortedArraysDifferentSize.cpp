#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &a1, vector<int> &a2){
	// As time complexity required is O(logn1 + logn2)
	// thus we implement a binary search.
	// We implement the search w.r.t the first array,
	int low = 0;
	int high = a1.size();
	int comLen = a1.size()+a2.size();
	// Beginning the binary search, we find the partitions
	// partX and partY for the two arrays respectively using
	// the low and high. Our target is two divide the complete
	// merged array into two parts and then find the median.
	// Thus,
	// (number of elements left of partX) + (number
	// of elements left of partY) == (number of elements 
	// right of partX) + (number of elements right of partY)
	// at all times. Now if element at immediate left of partX is bigger
	// than the one immediate right of partY then partX must decrease,
	// so the high is decreased and now the partition is searched from
	// low to previous position of partX. Else the vice versa is done.
	// When the above criteria is satiffied that brings us to the end 
	// of the search for the correct partition positions. Now if merged
	// array length is even then the median is as follows:
	// max(element at immediate left of partX,element at immediate left 
	// of partY) + min(element at immediate right of partX,element at 
	// immediate right of partY)/2
	// max of left gives us the nearest to median value and similarly
	// min of right gives us the nearest to median value.
	// And if length of merged array is odd than simply the 
	// max(element at immediate left of partX,element at immediate left 
    // of partY)
	while(low<=high){
		int partX = (high+low)/2;
		int partY = (comLen+1)/2-partX;
		int leftX = (partX==0)?INT_MIN:a1[partX-1];
		int leftY = (partY==0)?INT_MIN:a2[partY-1];
		int rightX = (partX==a1.size())?INT_MAX:a1[partX];
        int rightY = (partY==a2.size())?INT_MAX:a2[partY];
		if(leftX<=rightY and leftY<=rightX){
			if(comLen%2==0) return (max(leftX,leftY)+min(rightX,rightY))/2.0;
			return max(leftX,leftY);
		}else if(leftX>rightY) high = partX-1;
		else low = partX+1;
	}
	return -1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n1,n2;
		cin>>n1>>n2;
		vector<int> a1,a2;
		for(int i=0;i<n1;i++){
			int e;
			cin>>e;
			a1.push_back(e);
		}
		for(int i=0;i<n2;i++){
                        int e;
                        cin>>e;
                        a2.push_back(e);
                }
		cout<<median(a1,a2)<<endl;
	}
	return 0;
}
