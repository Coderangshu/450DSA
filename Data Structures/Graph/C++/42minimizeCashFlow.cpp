// C++ program to fin maximum cash flow among a set of persons
#include<iostream>
using namespace std;

// Number of persons (or vertices in the graph)
#define N 3



// Method: First calculate the amount each has to pay in total
// it may be negative or positive, positive means this person
// is to get that much amount and negative means this person is to
// pay that much amount.
// Using this array of total payments to be made by each, we find the
// max credit and max debit then pay the minimum of the two to the
// person who has credit from the person who has debit this way
// we recurse until all the debts and creds are settled.







// A utility function that returns index of minimum value in arr[]
int getMin(int arr[])
{
	int minInd = 0;
	for (int i=1; i<N; i++)
		if (arr[i] < arr[minInd])
			minInd = i;
	return minInd;
}

// A utility function that returns index of maximum value in arr[]
int getMax(int arr[])
{
	int maxInd = 0;
	for (int i=1; i<N; i++)
		if (arr[i] > arr[maxInd])
			maxInd = i;
	return maxInd;
}

// amount[p] indicates the net amount to be credited/debited
// to/from person 'p'
// If amount[p] is positive, then i'th person will amount[i]
// If amount[p] is negative, then i'th person will give -amount[i]
void minCashFlowRec(int amount[])
{
	// Find the indexes of minimum and maximum values in amount[]
	// amount[mxCredit] indicates the maximum amount to be given
	//				 (or credited) to any person .
	// And amount[mxDebit] indicates the maximum amount to be taken
	//				 (or debited) from any person.
	// So if there is a positive value in amount[], then there must
	// be a negative value
	int mxCredit = getMax(amount), mxDebit = getMin(amount);

	// If both amounts are 0, then all amounts are settled
	if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
		return;

	// Find the minimum of two amounts
	int min = min(-amount[mxDebit], amount[mxCredit]);
    // give min of both to the debited one from the credited one
	amount[mxCredit] -= min;
	amount[mxDebit] += min;

	// If minimum is the maximum amount to be
	cout << "Person " << mxDebit << " pays " << min
		<< " to " << "Person " << mxCredit << endl;

	// Recur for the amount array. Note that it is guaranteed that
	// the recursion would terminate as either amount[mxCredit]
	// or amount[mxDebit] becomes 0
	minCashFlowRec(amount);
}

// Given a set of persons as graph[] where graph[i][j] indicates
// the amount that person i needs to pay person j, this function
// finds and prints the minimum cash flow to settle all debts.
void minCashFlow(int graph[][N])
{
	// Create an array amount[], initialize all value in it as 0.
	int amount[N] = {0};

	// Calculate the net amount to be paid to person 'p', and
	// stores it in amount[p]. The value of amount[p] can be
	// calculated by subtracting debts of 'p' from credits of 'p'
	for (int p=0; p<N; p++)
        for (int i=0; i<N; i++)
            amount[p] += (graph[i][p] - graph[p][i]);

	minCashFlowRec(amount);
}

// Driver program to test above function
int main()
{
	// graph[i][j] indicates the amount that person i needs to
	// pay person j
    // p0 pays 1000 to p1 and 2000 to p2
    // p1 pays 5000 to p2
	int graph[N][N] = { {0, 1000, 2000},
						{0, 0, 5000},
						{0, 0, 0},};

	// Print the solution
	minCashFlow(graph);
	return 0;
}
