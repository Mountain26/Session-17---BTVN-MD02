#include <stdio.h>
void printfIndex(int *arr, int size);
int sum(int *arr, int size);
int findMax(int *arr, int size);

int main() { 
    int *arr;
    int n = 0, choose;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu co trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Nhap vao so phan tu: ");
                scanf("%d", &n);
                arr = (int *)malloc(n * sizeof(int));
                printf("Nhap vao tung phan tu:\n");
                for (int i = 0; i < n; i++) {
                    printf("Phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                printf("Cac phan tu trong mang la:\n");
                printfIndex(arr, n);
                break; 
            case 3:
                printf("Do dai cua mang: %d\n", n);
                break;
            case 4: {
                int total = sum(arr, n);
                printf("Tong cac phan tu co trong mang la: %d\n", total);
                break;
            }
            case 5: {
                if (n > 0) {
                    int max = findMax(arr, n);
                    printf("Phan tu lon nhat: %d\n", max);
                }
                break;
            }
            case 6:
                printf("Thoat chuong trinh.\n");
                free(arr);
                break;
            default:
                printf("Lua chon khong hop le! vui long chon lai.\n");
                break;
        }
    } while (choose != 6);

    return 0;
}

void printfIndex(int *arr, int size) {
    for (int i = 0; i < size; i++){
        printf("Gia tri cua cac phan tu co trong mang la %d \n", *(arr + i));
    }
}

int sum(int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}
int findMax(int *arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}
