#include<stdio.h>
#include<stdlib.h>

struct Item
{
    int weight;
    int value;
};

int compare(const void *a, const void *b)
{
    double ratio1 = (double)(((struct Item *)a)->value / (double)((struct Item *)a)->weight);
    double ratio2 = (double)(((struct Item *)b)->value / (double)((struct Item *)b)->weight);
    if (ratio1 > ratio2)
        return -1;
    else if (ratio1 < ratio2)
        return 1;
    else
        return 0;
}

double fractionalKnapsack(int capacity, struct Item items[], int n)
{
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++)
        {
        if (currentWeight + items[i].weight <= capacity)
        {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main()
{
    int capacity, numItems;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    struct Item items[numItems];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < numItems; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    double maxValue = fractionalKnapsack(capacity, items, numItems);
    printf("Maximum value obtained from the knapsack: %.2lf\n", maxValue);

    return 0;
}
