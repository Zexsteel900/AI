#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, [](Job a, Job b)
         { return a.profit > b.profit; });
    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << arr[result[i]].id << " ";
            totalProfit += arr[result[i]].profit;
        }
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main()
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Job " << i << "'s[id, deadline,profit]\n";
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }
    cout << "ID\tDeadline\tProfit";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << arr[i].id << "\t\t" << arr[i].deadline << "\t" << arr[i].profit;
    }

    cout << "\nScheduled jobs: ";
    printJobScheduling(arr, n);

    return 0;
}
