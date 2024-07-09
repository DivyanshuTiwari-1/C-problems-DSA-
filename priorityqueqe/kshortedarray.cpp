#include <iostream>
using namespace std;
#include <queue>

int *KShortedArray(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    int j = 0;
    for (int i = k; i < n; i++)
    {
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while (!pq.empty())
    {
        arr[j] = pq.top();
        pq.pop();
        j++;
    }

    return arr;
}

vector<int> ksmallestelement(int arr[], int n, int k)
{
    int *arr1 = KShortedArray(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i];
    }
    vector<int> output;

    for (int i = n - k; i < n; i++)
    {
        output.push_back(arr1[i]);
    }
    return output;
}

bool cheackmaxheap(int arr[], int n)
{
    int pI = 0;
    while (pI < n)
    {
        int cI1 = 2 * pI + 1;
        int cI2 = 2 * pI + 2;
        if (arr[pI] > arr[cI1] && arr[pI] > arr[cI2] || cI2 > n)
        {
            pI++;
        }
        else
        {
            return false;
            break;
        }
    }
    return true;
}
int klargestelement(int arr[], int n, int k)
{
    int *arr1 = KShortedArray(arr, n, k);
    return arr1[k - 1];
}

vector<int> kshortedarrays(vector<vector<int>> &karays, int k)
{
    vector<int> result;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push({karays[i][0], {i, 0}});
    }
    while (!pq.empty())
    {
        pair<int, pair<int, int>> current = pq.top();
        result.push_back(current.first);
        int i = current.second.first; // i is the arrindex and j the element index in the ith element
        int j = current.second.second;

        if ((j + 1) < karays[i].size())
        {
            pq.push({karays[i][j + 1], {i, j + 1}});
        }
        pq.pop();
    }
    return result;
}

vector<int> runningmedian(int arr[], int n)
{

    vector<int> result;
    for (int i = 0; i < n; i++)
    { // not working
        int *arr = KShortedArray(arr, i, n);
        if (i % 2 == 0)
        {
            result.push_back(arr[i / 2]);
        }
        else
        {
            int median = (arr[i / 2] + arr[(i + 1) / 2]) / 2;
            result.push_back(median);
        }
    }
    return result;
}

#include <queue>
#include <vector>
#include <algorithm>

int buyticket(int arr[], int n, int i)
{
    std::queue<int> q;
    std::priority_queue<int> pq;

    for (int j = 0; j < n; j++)
    {
        q.push(j);
        pq.push(arr[j]);
    }

    int time = 0;
    while (pq.top() != arr[i])
    {
        if (pq.top() == arr[q.front()])
        {
            time++;
            pq.pop();
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }

    return ++time;
}


int main()
{
    // vector<vector<int>> karays = {{1, 5, 9}, {45, 90}, {2, 6, 78, 100}, {0}};

    // vector<int> result = kshortedarrays(karays, 4);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }
    int arr[] = {3, 9, 4};
    //   int *arr1=KShortedArray(arr,6,5);
    //   for(int i=0;i<6;i++){
    //     cout<<arr1[i]<<" ";
    //   }
    // vector<int>result=runningmedian(arr,6);
    // for(int i=0;i<result.size();i++){
    //     cout<<result[i]<<" ";
    // }
    cout << buyticket(arr, 3, 2);
}