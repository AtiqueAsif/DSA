/*You are in charge of compiling a list of students who have submitted their project reports from
two different labs: Lab-A and Lab-B. Each lab has provided their submission scores, where a
higher score indicates an earlier submission time. Your task is to combine both lab score lists,
sort the merged list in descending order, and help the admin check whether a specific score exists
in the final list using binary search.*/


#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, maxIdx, temp;
    for (i = 0; i < n - 1; i++) {
        maxIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == x)
            return 1;
        else if (arr[mid] < x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main() {
    int n1, n2, x;
    int labA[100], labB[100], merged[200], i, total;

    printf("Enter the lab A scores: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &labA[i]);
    }

    printf("Enter the lab B scores: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &labB[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &x);

    total = n1 + n2;
    for (i = 0; i < n1; i++) {
        merged[i] = labA[i];
    }
    for (i = 0; i < n2; i++) {
        merged[n1 + i] = labB[i];
    }

    selectionSort(merged, total);

    printf("Sorted list: \n");
    for (i = 0; i < total; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    if (binarySearch(merged, total, x))
        printf("\n%d is present in the list.\n", x);
    else
        printf("\n%d is not present in the list.\n", x);

    return 0;
}
