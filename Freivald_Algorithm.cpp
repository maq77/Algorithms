#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;
    double valuePerWeight; // Value per unit weight
};

// Function to compare items based on value per unit weight
bool compareItems(const Item& a, const Item& b) {
    return a.valuePerWeight > b.valuePerWeight;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(vector<Item> items, int capacity) {
    // Sort items based on value per unit weight
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    // Iterate through the sorted items
    for (const auto& item : items) {
        if (remainingCapacity >= item.weight) {
            // Take the whole item
            totalValue += item.value;
            remainingCapacity -= item.weight;
        }
        else {
            // Take a fraction of the item
            totalValue += item.valuePerWeight * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} }; // Example items: {value, weight}
    int capacity = 50; // Example knapsack capacity

    double maxValue = fractionalKnapsack(items, capacity);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
