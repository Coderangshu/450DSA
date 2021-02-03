#include<iostream>
using namespace std;

// For searching in all 8 direction
// (x[i],y[i]) denotes direction, from current index
// we add the below pair to get the characters in the
// 8 direction.
int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 }; 
int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 }; 

bool search2D(char *grid, int row, int col, string word,int n, int m){
    if (*(grid+row*m+col) != word[0]) return false; 
    int len = word.length(); 
    for (int dir = 0; dir < 8; dir++){
        int k, rd = row + x[dir], cd = col + y[dir];
        for (k = 1; k < len; k++){
            if (rd >= n || rd < 0 || cd >= m || cd < 0) break;
	    // Debugger Line
            // cout<<"direction "<<dir<<" xy "<<row<<col<<" ValGrid "<<*(grid+rd*m+cd)<<endl;
            if (*(grid+rd*m+cd) != word[k]) break;
            rd += x[dir], cd += y[dir]; 
        }
        if (k == len) return true; 
    } 
    return false; 
} 

void patternSearch(char *grid,string s,int n,int m){
    int flag = 0;
    for (int row = 0; row < n; row++) 
        for (int col = 0; col < m; col++) 
            if (search2D((char *)grid, row, col, s,n,m)){
                cout<<row<<" "<<col<<", ";
                flag++;
            }
    if(flag==0)cout<< -1;
} 
// For printing the grid
// void prnt(char * a, int n, int m){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++)
//             cout<<*(a+i*m+j)<<" ";
//         cout<<endl;
//     }
// }

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    char arr[n][m];
	    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
	    string s;
	    cin>>s;
	   // prnt((char*)arr,n,m);
	    patternSearch((char *)arr,s,n,m);
	    cout<<endl;
	}
	return 0;
} 
