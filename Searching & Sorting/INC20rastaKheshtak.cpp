// Check with following to see that its incomplete (providing wrong output)
// 5 8
// 1 2 3 4 5 6 7 8
// 2 3 4 5 6 7 8 9
// 3 4 5 6 7 8 9 10
// 4 5 6 7 8 9 10 11
// 5 6 7 8 9 10 11 12
// 2 2
// 9 10
// 10 11



#include<bits/stdc++.h>
#define d 10
#define ll long long int
// prime number for hashing
#define pn 11587
using namespace std;

vector<vector<int>> mat1, mat2;
int maxBCS = INT_MAX;
int comparison = 0;
// max Pow of d in col and row (as pattern
// is always square) thus the highest power
// will be same for both row and col
ll h = 1;

bool isSame(int i, int j, int k, int l, int size){
	comparison++;
    for(int a=0;a<size;a++){
        for(int b=0;b<size;b++){
            if(mat1[i+a][j+b]!=mat2[k+a][l+b]) return false;
        }
    }
    return true;
}




// Either use 1 or 2 from below:
// Both are O(n^4)
// But average time complexity of 1 is also n^4
// But average time complexity of 2 is far lesser
// due to hashing in Rabin Karp


// this function checks all the sub squares of the 
// size given as input, the starting index is taken
// from both matrices in n^4 time complexity
bool isThereCommonSubsquareNPow4(int size){
    int n = mat1.size(), m = mat1[0].size();
    int x = mat2.size(), y = mat2[0].size();
    // we take all the possible starting coordinates for the
    // given size in both the matrices and check if there's a common
    // subsquare of given size or not
    for(int i=0;i<n-size+1;i++){
        for(int j=0;j<m-size+1;j++){
            for(int k=0;k<x-size+1;k++){
                for(int l=0;l<y-size+1;l++)
                    if(isSame(i,j,k,l,size)) return true;
            }
        }
    }
    return false;
}


// for checking of the subsquares using rabin karp
// rolling hash function, its O(n^4) but average
// time complexity is far far better as it checks
// only for those whose pattern and the subsquare
// in the other matrix's hash value matches

// recursive function to calculate power in (log n) time
// calculates power of d (i.e. 256)
ll powCal(int exp){
    if(exp<=0) return 1;
    if(exp==1) return d;
    
    ll ans = 1;
    ll powNxt = powCal(exp/2);
    
    // if exp is odd
    if(exp&1) return powNxt*powNxt*d;
    // else if even
    else return powNxt*powNxt;
}

// We have 2 matrices one is the matrix and the other is the pattern
// matrix, in this question we take each subsquare from the 1st matrix
// of all possible size and check with each of this subsquare in the
// second matrix if hash value matches then we proceed with checking
// each of the elements in both the subsquare.

// Calculation of hash values for all the columns of given matrix
// are done for the first n rows, where n is number of rows in
// pattern matrix. Each is stored seperately in a array of size of
// number of columns in given matrix, then with the help of the hash
// value of the pattern matrix we check for the window in given matrix
// which includes the no. of columns same as the pattern matrix, if not
// found then calculate the hash (roll hash in column ) until the last 
// window is reached, then the array of hash values of the columns is
// rolled along the row (roll hash in row) this way its done until the
// last row is reached

// finding the first hash values for all the columns for the first n rows,
// here n rows will be the size of common subsquare for which we are checking
// as squares have same length and height
// here x is the starting row for the matrix and matrixNum tells
vector<ll> find1stHashCol(int size, int matrixNum){
    vector<vector<int>> temp;
    // if rolling in mat1
    if(matrixNum==1) temp = mat1;
    // else rolling in mat2
    else temp = mat2;
    
    int col = temp[0].size();
    vector<ll> hashes(col,0);
    
    // calculating all col's hash value each consisting of n rows summation of hashes
    for(int i=0;i<col;i++){
        // traversing vertically in each row for the n elements
        for(int j=0;j<size;j++) hashes[i] = ((hashes[i]*d%pn)%pn+temp[j][i]%pn)%pn;
    }
    return hashes;
}

// finding the hash sum of the first window across column
// (of previously calculated sum of hashes of rows for 
// (each column) of size = size
ll find1stHashRow(vector<ll> &hashes, int size){
    ll hashSum = 0;
    // traversing across the col hashes of the size 
    for(int i=0;i<size;i++)
        hashSum = ((hashSum*d%pn)%pn+hashes[i])%pn;
    return hashSum;
}

// function to roll in column, i.e. shift the col hashes one row
// down (exclude top row of current window and include the next row
// below the bottom row)
void rollHashCol(vector<ll> &hashes, int size, int prevX, int matrixNum){
    vector<vector<int>> temp;
    // if rolling in mat1
    if(matrixNum==1) temp = mat1;
    // else rolling in mat2
    else temp = mat2;
//     cout<<matrixNum<<" Prior: ";
//     for(auto e:hashes) cout<<e<<" ";
//     cout<<endl;
    // changing each value in hashes for each col
    for(int i=0;i<hashes.size();i++){
        hashes[i] = (((hashes[i]-(temp[prevX][i]%pn*h%pn)%pn)*d%pn)%pn+temp[prevX+size][i]%pn)%pn;
        if(hashes[i]<0) hashes[i] += pn;
    }
//     cout<<"After: ";
//     for(auto e:hashes) cout<<e<<" ";
//     cout<<endl;
}

// function to roll in row, i.e. shift the 2d matrix hash sum by 
// one unit right in the hashes(exclude leftmost col of current
// window and include the next right col of current window)
void rollHashRow(ll &hashSum, vector<ll> &hashes, int size, int prevY){
    // rolling across the hashes vector
    hashSum = (((hashSum-(hashes[prevY]*h%pn)%pn)*d%pn)%pn+hashes[prevY+size])%pn;
    if(hashSum<0) hashSum += pn;
}

// here we take the pattern matrix as all the subsquares of length size
// from mat1 and for each pattern we check it in mat2
bool isThereCommonSubsquareRabinKarp(int size){
    int n = mat1.size(), m = mat1[0].size();
    int x = mat2.size(), y = mat2[0].size();
    
    // get first row hash sum for all columns of both matrices
    vector<ll> hashes1 = find1stHashCol(size,1), hashes2 = find1stHashCol(size,2);
    
    // get first 2d window hash value of both matrices
    ll hashSum1 = find1stHashRow(hashes1,size), hashSum2 = find1stHashRow(hashes2,size);
    
    // we roll the hashes and check for all the combinations of windows
    for(int i=0;i<n-size+1;i++){
        for(int j=0;j<m-size+1;j++){
            for(int k=0;k<x-size+1;k++){
                for(int l=0;l<y-size+1;l++){
                    // if both hashSum are equal check each of the elements
                    if(hashSum1==hashSum2) if(isSame(i,j,k,l,size)) return true;
                    // else roll window one column right and recalculate
                    // hashSum of the mat2
                    if(l<y-size) rollHashRow(hashSum2,hashes2,size,l);
                }
                // complete row traversed now roll window one row below and recalculate
                // the hashes vector of the mat2
                if(k<x-size) rollHashCol(hashes2,size,k,2);
            }
            // with current window of mat1 all window in mat2 checked now roll window
            // in mat1 to recalculate the next window's hashSum
            if(j<m-size) rollHashRow(hashSum1,hashes1,size,j);
        }
        // checked with all window in current row of mat1 thus roll to next row
        if(i<n-size) rollHashCol(hashes1,size,i,1);
    }
    // if none window matches then reached here
    return false;
}

// we know that if certain size common subsquare
// is possible then all the smaller length common
// subsquare would be possible thus we go on with
// searching for the next greater length of common
// subsquare, if found we return that else we return
// the last obtained length of common subsquare

// we search for the lengths in the search space 
// ranging from lowest possible length (0) to the
// highest possible length (maxBCS)
int getMaxBCS(int lowLen, int highLen){
    // if search space for lengths becomes 
    // from 0 to 0 then no possible subsquare
    // of any length
    if(lowLen==0 and highLen==0) return 0;
    
    // calculate the middle length and see if there's
    // any common subsquare of this length
    int mid = (lowLen+highLen)/2;
    
    // if mid is permissible (i.e. <=maxBCS) and mid
    // length's found we check for next ones use either
    // of the 2 above function (1 faster than other)
    
    // IF USING N^4
    //isThereCommonSubsquareNPow4(size)
    
    // IF USING RABIN KARP
    // first calculate highest power of d, that is d^(mid-1)
    // using poCal then check for the size using 
    // isThereCommonSubsquareRabinKarp(size)
    
    h = powCal(mid-1);
    if(mid<=maxBCS and isThereCommonSubsquareRabinKarp(mid)){
        // if there's common subsquare of length=mid
        // then we check for the more bigger lengths
        // but before proceeding we check for the next
        // bigger length if thats possible than we send
        // for searching in the bigger lengths (including
        // the one that we just checked for), this is done
        // because we cannot set a base condition at the upper
        // limit as for the extreme case, i.e. maxBCS if theres
        // no possible common subsquare then we have nothing to
        // return thus we need to check from small and move to
        // larger lengths if not found we return that smaller on
        // the first hand before calling for the next bigger ones
                
        // this is a kind of base condition as we are restricted
        // to not be able to put a base condition as we need to
        // check from lower to higher, thus we check if mid+1 is
        // < or == to maxBCS, only then we send for next call else
        // we return the current value
        
        h = powCal((mid+1)-1);
        if(mid+1<=maxBCS and isThereCommonSubsquareRabinKarp(mid+1))
            return getMaxBCS(mid+1,highLen);
        // else this is the max possbile side length of common
        // subsquare
        else return mid;
    }
    // else we return a smaller length's search space
    else return getMaxBCS(lowLen,mid-1);
}

int main(){
    int m,n,x,y;
    
    // getting matrix 1
    cin>>n>>m;
    mat1.assign(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int e;
            cin>>e;
            mat1[i][j] = e;
        }
    }
    
    // getting matrix 2
    cin>>x>>y;
    mat2.assign(x,vector<int>(y));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            int e;
            cin>>e;
            mat2[i][j] = e;
        }
    }
    
    // stores the max possible size of the BCS
    // max possible BCS size would be min of n,m,x,y
    maxBCS = min(n,min(m,min(x,y)));
    
    // searching for the max length of common subsquare
    // (binary search)
    int ans = getMaxBCS(0,maxBCS);
//     h = powCal(2-1);
//     cout<<isThereCommonSubsquareRabinKarp(2);
    cout<<ans<<endl;
    
    return 0;
}
