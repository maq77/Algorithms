#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;
    double valuePerWeight; // Value per unit weight
};

// Function to compare items based on value per unit weight
bool compareItems(const Item &a, const Item &b) {
    return a.valuePerWeight > b.valuePerWeight;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(Item items[], int n, int capacity) {
    // Calculate value per unit weight for each item
    for (int i = 0; i < n; ++i) {
        items[i].valuePerWeight = static_cast<double>(items[i].value) / items[i].weight;
    }

    // Sort items based on value per unit weight
    sort(items, items + n, compareItems);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    // Iterate through the sorted items
    for (int i = 0; i < n; ++i) {
        if (remainingCapacity >= items[i].weight) {
            // Take the whole item
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            totalValue += items[i].valuePerWeight * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    const int n = 3; // Number of items
    Item items[n] = {{60, 10}, {100, 20}, {120, 30}}; // Example items: {value, weight}
    int capacity = 50; // Example knapsack capacity

    double maxValue = fractionalKnapsack(items, n, capacity);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
