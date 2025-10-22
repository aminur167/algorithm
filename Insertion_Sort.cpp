#include <bits/stdc++.h>
using namespace std;

void Insertion_Sort(int arr[], int n, ofstream &outFile)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    // cout << "Sorted = ";
    for (int i = 0; i < n; i++)
    {
        outFile << arr[i] << " ";
    }
    outFile << endl;
}

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("out.txt");

    if (!inFile.is_open())
    {
        cerr << " Error: Could not open input.txt\n";
        return 1;
    }
    if (!outFile.is_open())
    {
        cerr << " Error: Could not open out.txt\n";
        return 1;
    }

    int n;
    // cout << "Enter array size = ";
    inFile >> n;

    int arr[n];

    // cout << "Enter " << n << " elements = ";
    for (int i = 0; i < n; i++)
    {
        // int x = rand();
        // arr[i] = x;
        inFile >> arr[i];
    }
    Insertion_Sort(arr, n, outFile);

    inFile.close();
    outFile.close();
}