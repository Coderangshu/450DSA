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

    void pointUpdate(int i, int num)
    {
        // incrementing i to maintain 1 based indexing for BIT array
        for (i++; i < n + 1; i += i & -i)
            bit[i] += num;
        return;
    }

    int getRangeSum(int l, int r)
    {
        return getSumUptoI(r) - getSumUptoI(l - 1);
    }

    void updateArr()
    {
        for (int i = 0; i < n; i++)
            arr[i] = getRangeSum(i, i);
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
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    BinaryIndexedTree obj = BinaryIndexedTree(n, arr);

    while (true)
    {
        // 0 -> pointUpdate
        // 1 -> getRangeSum
        int queryType;
        cin >> queryType;
        if (queryType == 0)
        {
            int i, num;
            cin >> i >> num;
            obj.pointUpdate(i, num);
            printArr(obj, arr, n);
        }
        else if (queryType == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << obj.getRangeSum(l, r) << endl;
        }
        else
            break;
    }
    return 0;
}
