// C++ program to rearrange array in alternating
// C++ program to copy set bits in a given
// range [l, r] from y to x.
#include <bits/stdc++.h>
using namespace std;

// Copy set bits in range [l, r] from y to x.
// Note that x is passed by reference and modified
// by this function.
void copySetBits(unsigned &x, unsigned y,unsigned l, unsigned r){
    // l and r must be between 1 to 32 (assuming ints are stored using
    // 32 bits)
    if (l < 1 || r > 32)
        return ;

    // Travers in given range
    for (int i=l; i<=r; i++){
        // Find a mask (A number whose
        // only set bit is at i'th position)
        // 1<<(i-1) means 1 followed by i-1 0's
        // example: 1<<6 means 1000000
        int mask = 1 << (i-1);

        // If i'th bit is set in y, set i'th
        // bit in x also.
        if (y & mask)
            x = x | mask;
    }
}

// Copy set bits in range [l, r] from y to x.
// Note that x is passed by reference and modified
// by this function.
void copySetBits(unsigned &x, unsigned y,unsigned l, unsigned r){
    // l and r must be between 1 to 32
    if (l < 1 || r > 32)
        return ;
  
    // get the length of the mask
    // below gives us bit
    // example: (1<<5)-1 means 100000-1 = 11111
    int maskLength = (1<<(r-l+1)) - 1;
  
    // Shift the mask to the required position
    // "&" with y to get the set bits at between
    // l ad r in y
    // using above example maskLength is shifted by l-1
    // position to get the mask at the appropriate position
    // then bitwise and with y which gives us the bits of y
    // demarcated by the mask which is then used to bitwise or
    // with x to get the result
    int mask = ((maskLength)<<(l-1)) & y ;
    x = x | mask;
}

// Driver code
int main()
{
unsigned x = 10, y = 13, l = 2, r = 3;
copySetBits(x, y, l, r);
cout << "Modified x is " << x;
return 0;
}

