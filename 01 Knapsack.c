#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int w, int wt[], int val[], int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (wt[n - 1] > w)
        return knapSack(w, wt, val, n - 1);
    else
        return max(
            val[n - 1]
                + knapSack(w - wt[n - 1], wt, val, n - 1),
            knapSack(w, wt, val, n - 1));
}

int main()
{
    int profit[100],weight[100],w,i,m,n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d",&w);
    printf("Enter the number of items: ");
    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        printf("Enter the value of Weight and Profits - %d: ",i+1);
        scanf("%d%d", &weight[i], &profit[i]);
    }
        n=m;
        printf("Max Profit is: %d", knapSack(w, weight, profit, n));

    return 0;
}
