#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;  
};

// Function to compare two items based on their value-to-weight ratio
int compare( void *a,  void *b) {
    struct Item *item1 = (struct Item*)a;
    struct Item *item2 = (struct Item*)b;
    if (item1->ratio < item2->ratio)
        return 1;
    else
        return -1;
}

float fractionalKnapsack(int weights[], int values[], int W, int n) {
    struct Item items[n];
    int i;
    for ( i = 0; i < n; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].ratio = (float)values[i] / weights[i];
    }
    qsort(items, n, sizeof(struct Item), compare);
    float totalValue = 0.0;
    for ( i = 0; i < n; i++) {
        if (W == 0)
		{
            break;
        }
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((float)W / items[i].weight);
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);
    
    float max_value = fractionalKnapsack(weights, values, capacity, n);
    printf("Maximum value in Knapsack = %.2f\n", max_value);
    
    return 0;
}
