class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> un(n);
        un[0] = 1;
        // our target is to find the min of x*2, y*3, z*5
        // we need to determine the x, y, z each time.
        
        
        // initially un[0]=1 and x=y=z=1
        
        // 1. un[1]=min(1*2,1*3,1*5)=2 and 
        // now next smallest after x would give the next smallest
        // possible value thus go to the next in sequence, thus x=2, y=z=1
        
        // 2. un[2]=min(2*2,1*3,1*5)=3 and x=2, y=2, z=1
        // 3. un[3]=min(2*2,2*3,1*5)=4 and x=3, y=2, z=1
        // 4. un[4]=min(3*2,2*3,1*5)=5 and x=3, y=2, z=2
        // 5. un[5]=min(3*2,2*3,2*5)=6 and x=4, y=3, z=2 (notice both x and y updated)
        // 6. un[6]=min(4*2,3*3,2*5)=8 and x=5, y=3, z=2
        // 7. un[7]=min(5*2,3*3,2*5)=9 and x=5, y=4, z=2
        // 8. un[8]=min(5*2,4*3,2*5)=10 and x=6, y=4, z=3 (notice both x and z updated)
        // 9. un[9]=min(6*2,4*3,3*5)=12 and x=8, y=5, z=3 (notice both x and y updated)
        // 10. un[10]=min(8*2,5*3,3*5)=9 and x=5, y=5, z=4 (notice both y and z updated)
        // And so on...........
        
        // i,j,k indicates the indices which would give the next smallest
        // ugly # after the last one found, for the first all are at index 0
        int i = 0, j = 0, k = 0;
        for(int l=1;l<n;l++){
            un[l] = min(un[i]*2,min(un[j]*3,un[k]*5));
            if(un[l]==un[i]*2) i++;
            if(un[l]==un[j]*3) j++;
            if(un[l]==un[k]*5) k++;
        }
        return un[n-1];
    }
};