#include <stdio.h>
struct Item {
    int weight;
    int value;
};
float valuePerWeight(struct Item item) {
    return (float)item.value / item.weight;
}
float containerLoader(struct Item items[], int n, int maxWeight) {
    float totalValue = 0.0; 
    int currentWeight = 0; 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (valuePerWeight(items[j]) < valuePerWeight(items[j + 1])) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= maxWeight) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = maxWeight - currentWeight;
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, maxWeight;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    printf("Enter the maximum weight of the container: ");
    scanf("%d", &maxWeight);

    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    float maxValue = containerLoader(items, n, maxWeight);
    printf("Maximum value loaded into the container: %.2f\n", maxValue);

    return 0;
}
