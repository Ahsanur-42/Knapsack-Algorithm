#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int W, Item items[], int n)
{
    sort(items, items + n, compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {

        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }

        else
        {
            int remainingWeight = W - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main()
{
    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; i++)
        {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
        }

    double maxTotalValue = fractionalKnapsack(W, items, n);
    cout << "Maximum total value obtained = " << maxTotalValue << endl;

    return 0;
}
