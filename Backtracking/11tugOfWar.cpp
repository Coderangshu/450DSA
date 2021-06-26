#include<bits/stdc++.h>
using namespace std;


// Method: We traverse the given array from start to end
// for every element we got 2 choices either put into part 1
// or part 2
// We do the same for every element and send it for the next element
// insertion

// We need to find the pair of vectors with lowest difference of sum
// we do the same procedure as when to find the minimum of something

// minDiff to keep track of the min difference of the sums
int minDiff = INT_MAX;
// a1 and a2 to store the final answers
vector<int> a1, a2;


// recursive function to go through every possibilities in compliance with the given condition
// that the 2 subsets musn't be of lengths difference greater than 1(for off) and for even length
// provided array the difference in length must be 0
void partitioner(int index, vector<int> v, vector<int> p1, vector<int> p2){
    // if all elements processed
	if(index==v.size()){
        // if this diff is the minimum we update else reject
// 		int tdiff = abs(sumOf1-sumOf2); 
        int tdiff = abs(accumulate(p1.begin(),p1.end(),0)-accumulate(p2.begin(),p2.end(),0));
		if(tdiff<minDiff){
			minDiff = tdiff;
			a1 = p1;
			a2 = p2;
		}
		return;
	}
	
	// putting current element at part 1 subset 
	// if the size of part 1 is less than (length of
	// given array+1)/2 (this will handle both the cases
	// of odd and even) and also we know that in case of
	// odd length array is provided, if one will
	// be of length len/2 then other will be len/2+1
	// that case is also managed
	if(p1.size()<(v.size()+1)/2){
		p1.push_back(v[index]);
        // sending for next element insertions
		partitioner(index+1,v,p1,p2);
        // poping the element to try the next possibility of
        // pushing the element into the part 2 subset(below) 
		p1.pop_back();
	}
	
	// same steps followed for inseting the element to the 
	// part 2 subset
	if(p2.size()<(v.size()+1)/2){
		p2.push_back(v[index]);
		partitioner(index+1,v,p1,p2);
		p2.pop_back();
	}
}

int main(){
	vector<int> v = {3,4,5,100,1,89,-3,54,23,20};
	vector<int> p1,p2;
    // index initialized to 0
	partitioner(0,v,p1,p2);

	cout<<"{ ";
	for(auto e:a1) cout<<e<<" ";
	cout<<"}"<<endl<<"{ ";
	for(auto e:a2) cout<<e<<" ";
	cout<<"}"<<endl;

	return 0;
}
