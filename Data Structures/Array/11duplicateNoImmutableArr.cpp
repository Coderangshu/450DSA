 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];
        int tortoise = nums[0];
        do{
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }while(hare!=tortoise);
        tortoise = nums[0];
        while(hare!=tortoise){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        return hare;
    }
};

int main(){
	vector<int> V;
	int t,N;
	cin>>t;
	while(t--){
		cin>>N;
		for(int i=0;i<N;i++){
			int e;
			cin>>e;
			V.push_back(e);
		}
		Solution obj;
		cout<<obj.findDuplicate(V)<<endl;
	}
}
