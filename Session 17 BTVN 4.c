#include <stdio.h>

void arrangeItema_z(int *ptr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, *(ptr + i));
    }
}


void arrangeItemz_a(int *ptr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(ptr + j) < *(ptr + j + 1)) {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, *(ptr + i));
    }
}
void reverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
int linearSearch(int *arr, int size, int valueItem, int *flag) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == valueItem) {
            *flag = 1;
            printf("Phan tu %d nam o vi tri %d\n", valueItem, i);
            return 0;
        }
    }
    if (*flag == -1){
        printf("Phan tu %d khong ton tai trong mang\n", valueItem);
    }
    return -1;
}

int main() {
    int *arr;
    int size = 0;
    int choice;
    int option;
    int valueItem;
    int flag = -1;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang tang dan\n");
        printf("6. Nhap vao mot phan tu va tim kiem\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                printf("Nhap tung phan tu:\n");
                for (int i = 0; i < size; i++) {
                    printf("Phan tu %d: ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                printf("Cac phan tu la so chan: ");
                for (int i = 0; i < size; i++) {
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;

            case 3:
                break; 
            case 4:
                reverseArray(arr, size);
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 5:
                printf("\n1. Tang dan\n2. Giam dan\n");
			    printf("Moi ban chon yeu cau 1 hoac yeu cau 2: ");
			    scanf("%d", &option);
			    switch (option) {
			    case 1:
			        arrangeItema_z(arr, size);
			        break;
			    case 2:
			        arrangeItemz_a(arr, size);
			        break;
			    default:
			        printf("Lua chon khong hop le\n");
			        break;
    }
				break; 
            case 6:
                printf("Moi ban nhap vao gia tri can tim o trong mang:\n");
			    scanf("%d", &valueItem);
			    linearSearch(arr, size, valueItem, &flag);
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}

