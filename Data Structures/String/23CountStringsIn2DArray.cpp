#include<bits/stdc++.h>
using namespace std;

int findString(string s,char a[6][6],int index, int i, int j){
	int size = s.length();
	int found = 0;
	if(i>=0 and j>=0 and i<6 and j<6 and s[index]==a[i][j]){
		int temp = s[index];
		// We set a[i][j] to 0 for each search so that
		// the same elements is not repeated in a single 
		// string search. Later we backtrack to restore 
		// the values. Hence stored in temp.
		a[i][j] = 0;
		index++;
		// Base condition
		if(index==size) found = 1;
		else{
			// Searching for the next character of the 
			// string in all four directions.
			found += findString(s,a,index,i+1,j);
			found += findString(s,a,index,i-1,j);
			found += findString(s,a,index,i,j+1);
			found += findString(s,a,index,i,j-1);
		}
		// Backtracking in action.
		a[i][j] = temp;
	}
	return found;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		s = "GEEKS";
		char a[6][6] = 	{
						{'D','D','D','G','D','D'},
						{'B','B','D','E','B','S'},
		                {'B','S','K','E','B','K'},
		                {'D','D','D','D','D','E'},
						{'D','D','D','D','D','E'},
		                {'D','D','D','D','D','G'}
			      		};
		int ans = 0;
		// Searching through matrix to find the first character
		// matching in string and array.
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				ans += findString(s,a,0,i,j);
		cout<<ans;
	}
}
