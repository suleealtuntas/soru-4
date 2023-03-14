#include <stdio.h>

void quicksort(int arr[], int low, int high) {
    int i = low;
    int j = high;
    int temp;
    int pivot = arr[(low + high) / 2];

    while(i <= j) {
        while(arr[i] < pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if(low < j) {
        quicksort(arr, low, j);
    }
    if(i < high) {
        quicksort(arr, i, high);
    }
}

int main() {
    int arr[10000];
    int n = sizeof(arr) / sizeof(arr[0]);

    // Rastgele 10000 sayýlýk bir dizi oluþturma
    srand(time(0));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    // Veriyi sýralama
    clock_t start_time = clock();
    quicksort(arr, 0, n - 1);
    clock_t end_time = clock();

    // Sýralanmýþ veriyi yazdýrma
    printf("Sýralanmýþ dizi: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nÇalýþma süresi: %f saniye\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}


//brute force sýralama algoritmasý
#include <stdio.h>

void brute_force_sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {

