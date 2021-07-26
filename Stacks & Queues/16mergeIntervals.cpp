#include<bits/stdc++.h>
using namespace std;

void insertBottom(stack<pair<int,int>> &s, pair<int,int> e){
	if(s.empty()) s.push(e);
	else{
		auto f = s.top();
		s.pop();
		insertBottom(s,e);
		s.push(f);
	}
}

void reverseStack(stack<pair<int,int>> &s){
	if(!s.empty()){
		auto e = s.top();
		s.pop();
		reverseStack(s);
		insertBottom(s,e);
	}
}

stack<pair<int,int>>  mergeIntervals(vector<pair<int,int>> intervals){
	// first merge intervals according to the
	// starting time
	sort(intervals.begin(),intervals.end());

	// store merged intervals in stack
	stack<pair<int,int>> s;
	for(int i=0;i<intervals.size();i++){
		if(s.empty()) s.push(intervals[i]);
		else{
			// if merges
			if(intervals[i].first<s.top().second){
				auto i1 = s.top();
				s.pop();
				i1.second = max(i1.second,intervals[i].second);
				s.push(i1);
			}
			else s.push(intervals[i]);
		}
	}
	reverseStack(s);
	return s;
}

int main(){
	vector<pair<int,int>> intervals = {{22,28},{ 1, 8},{25,27},{14,19},{27,30},{5,12}};
	stack<pair<int,int>> mergedIntervals = mergeIntervals(intervals);
	cout<<"Merged Intervals: ";
	while(!mergedIntervals.empty()){
		cout<<mergedIntervals.top().first<<"-"<<mergedIntervals.top().second<<" ";
		mergedIntervals.pop();
	}

	return 0;
}
