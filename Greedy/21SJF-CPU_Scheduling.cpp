#include<bits/stdc++.h>
using namespace std;

// compare arrival time if same compare PID
bool comparator(vector<int> a, vector<int> b){
	if(a[1]==b[1]) return (a[0]<b[0]);
	return (a[1]<b[1]);
}

vector<int> getSJF(vector<vector<int>> &jobs){
	// convert job queue to the ready queue
	sort(jobs.begin(),jobs.end(),comparator);

	// min heap to maintain the shortest job on top
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
	// jobs are executed according to least burst time, if same burst time
	// then least arrival time, if same then least PID
	// pushing first job from ready queue
	minHeap.push({jobs[0][2],jobs[0][1],jobs[0][0]});

	vector<int> ans;
	int i = 1, currentTime = jobs[0][1];
	while(!minHeap.empty()){
		auto currentJob = minHeap.top();
		int bt = currentJob[0], at = currentJob[1], pid = currentJob[2];
		minHeap.pop();
		ans.push_back(pid);
		currentTime += bt;
		// taking all jobs whose arrival time less or equal
		// to currentTime
		while(i<jobs.size() and jobs[i][1]<=currentTime){
			minHeap.push({jobs[i][2],jobs[i][1],jobs[i][0]});
			i++;
		}
	}
	return ans;
}

int main(){
	vector<vector<int>> jobs = {{1,2,3},
								{2,0,4},
								{3,4,2},
								{4,5,4}};

	vector<int> ans = getSJF(jobs);
	for(auto e:ans) cout<<e<<" ";
	cout<<endl;

	return 0;
}
