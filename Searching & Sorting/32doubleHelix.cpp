#include<bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int na;
        cin>>na;
        if(na==0) break;
        vector<int> fa;
        for(int i=0;i<na;i++){
            int e;
            cin>>e;
            fa.push_back(e);
        }
        int nb;
        cin>>nb;
        vector<int> sa;
        for(int i=0;i<nb;i++){
            int e;
            cin>>e;
            sa.push_back(e);
        }

        // we use 2 pointer to traverse thorugh the 2 vectors
        // keep calculating sum upto a bridge number is reached
        // then we keep the max of both sum in the result and then
        // reset the sums of both  to 0
        // i and j are the 2 pointers
        int suma = 0, sumb = 0, maxSum = 0, i = 0, j = 0;
        while(i<na and j<nb){
            // we increment the pointer which has lesser value in
            // both of the array and add them to their respective sum
            // (we add then increment the point)
            if(fa[i]<sa[j]) suma += fa[i++];
            else if(sa[j]<fa[i]) sumb += sa[j++];
            // else we reach a bridge element
            else{
                // store max sum of suma and sumb in maxSum
                // and add the bridge element
                maxSum += max(suma,sumb)+fa[i];
                // reset suma and sumb
                suma = sumb = 0;
                // increment both pointers
                i++;
                j++;
            }
        }
        // going upto the end of both the arrays
        while(i<na) suma += fa[i++];
        while(j<nb) sumb += sa[j++];

        // adding the max of both to maxSum
        maxSum += max(suma,sumb);
        
        cout<<maxSum<<endl;
    }
	return 0;
}
