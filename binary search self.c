#include <stdio.h>

void binary_search(int a[], int n, int search) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == search) {
            printf("%d is found at index %d.\n", search, mid);
            return;
        }
        if (a[mid] < search) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("NOT FOUND!!\n");
}

int main() {
    int n, i, search;

    printf("Enter the value of n (size): ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the sorted array: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &search);

    binary_search(a, n, search);

    return 0;
}
