// C++ program to find winner of game
// if player can pick 1, x, y coins
#include <bits/stdc++.h>
using namespace std;


// Let us take few example values of n for x = 3, y = 4.
// n = 0 A can not pick any coin so he losses
// n = 1 A can pick 1 coin and win the game
// n = 2 A can pick only 1 coin. Now B will pick 1 coin and win the game
// n = 3 A will win the game by picking 3 (optimal choice) coins
// n = 4 A will win the game by picking 4 (optimal choice) coins
// n = 5 A chooses 4(optimal choice), now n=1 which is taken by B
// and thus B wins
// We see that this is occuring otherwise to what is happening when n=1.
// n=6 A chooses 4(optimal choice), now n=2 B picks 1 A picks last coin
// thus A wins
// We see that this is occuring otherwise to what is happening when n=2.


// Thus we conclude that A wins for n coins only when A wins for
// n-1 or n-x or n-y coins, i.e. B loses for n-1 or n-x or n-y coins.

// In simple words A wins for n coins when the reverse of the situation
// in case of n-1 or n-x or n-y coins is true.

// To find winner of game
bool findWinner(int x, int y, int n)
{
	// index i of dp stores whether A wins at current
    // index,
    // i.e. A wins when i coins are present => dp[i] is true
    // A loses when i coins are present => dp[i] is false
	int dp[n + 1];

    // keeping greater of x and y in x always
    if(x<y) swap(x,y);

	// Initial values
    // n=0 A loses
	dp[0] = false;
    // n=1 A wins
	dp[1] = true;

	// Computing other values.
	for (int i = 2; i <= n; i++) {

		// If A losses any of i-1 or i-x
		// or i-y game then he will
		// definitely win game i
		if (i-x>=0 and !dp[i-x])
			dp[i] = true;
		else if (i-y>=0 and !dp[i-y])
			dp[i] = true;
		else if (i-1>=0 and !dp[i-1])
			dp[i] = true;

		// Else A loses game.
		else
			dp[i] = false;
	}

	// If dp[n] is true then A will
	// game otherwise he losses
	return dp[n];
}

// Driver program to test findWinner();
int main()
{
	int x = 3, y = 4, n = 7;
	(findWinner(x, y, n))?cout<<'A':cout<<'B';

	return 0;
}
