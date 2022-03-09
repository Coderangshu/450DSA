// Question link : https://codeforces.com/problemset/problem/296/C

#include <bits/stdc++.h>
using namespace std;

class BinaryIndexedTree
{
private:
    // bit => BINARY INDEXED TREE
    // ops => each row stores left, right, to be incremented by #
    int *bit, *arr, n;

    void createBIT()
    {
        for (int i = 0; i < n; i++)
            pointUpdate(i, arr[i]);
        return;
    }

    void printBIT()
    {
        cout << "BIT array : ";
        for (int i = 1; i < n + 1; i++)
            cout << bit[i] << " ";
        cout << endl;
    }

    int getSumUptoI(int i)
    {
        int ans = 0;
        for (i++; i > 0; i -= i & -i)
            ans += bit[i];
        return ans;
    }

    void pointUpdate(int i, int num)
    {
        // incrementing i to maintain 1 based indexing for BIT array
        for (i++; i < n + 1; i += i & -i)
            bit[i] += num;
        return;
    }

public:
    BinaryIndexedTree(int n, int *arr)
    {
        this->n = n;
        this->arr = arr;
        // Initialize BIT array with all zeroes
        // taking extra space to maintain 1 based indexing
        bit = new int[n + 1];
        for (int i = 0; i < n + 1; i++)
            bit[i] = 0;
        createBIT();
        printBIT();
    }

    void rangeUpdate(int l, int r, int val)
    {
        pointUpdate(l, val);
        pointUpdate(r + 1, -val);
        return;
    }

    int getPointVal(int i)
    {
        // after range update the effect on each element is determined
        // by all those elements that support this element
        return getSumUptoI(i);
    }

    void updateArr()
    {
        for (int i = 0; i < n; i++)
            arr[i] = getPointVal(i);
        return;
    }
};

void printArr(BinaryIndexedTree obj, int *arr, int n)
{
    cout << "Array : ";
    obj.updateArr();
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return;
}

int main()
{
    int n;
    // First row input : array size followed by the array elements
    // CONSTRAINT : need to start with all elements as 0
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    BinaryIndexedTree obj = BinaryIndexedTree(n, arr);

    while (true)
    {
        // 0 -> rangeUpdate
        // 1 -> pointQuery
        // 9 -> quit
        int queryType;
        cin >> queryType;
        if (queryType == 0)
        {
            int l, r, val;
            cin >> l >> r >> val;
            obj.rangeUpdate(l, r, val);
            obj.updateArr();
            printArr(obj, arr, n);
        }
        else if (queryType == 1)
        {
            int i;
            cin >> i;
            cout << obj.getPointVal(i) << endl;
        }
        else
            break;
    }
    return 0;
}
