#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
void UpperString(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

int main() {
    char arr[100];
    char *ptr = arr;
    char input[100];
    int choice;
    int count = 1;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap vao chuoi: ");
                fgets(arr, sizeof(arr), stdin);
                break;
            case 2:
                reverseString(ptr);
                printf("Chuoi dao nguoc: %s\n", ptr);
                reverseString(ptr);
                break;
            case 3:
                for (int i = 0; arr[i] != '\0'; i++) {
        			if (arr[i] == ' ') { 
            		count++; 
        	}
    	}

			    printf("Chuoi: %s\n", arr);
			    printf("So tu trong chuoi: %d\n", count);
                break;
            case 4:
                printf("Nhap vao chuoi khac: ");
                fgets(input, sizeof(input), stdin);
                if (strlen(input) < strlen(ptr)) {
                    printf("Chuoi khac ngan hon chuoi ban dau.\n");
                } else if (strlen(input) > strlen(ptr)) {
                    printf("Chuoi khac dai hon chuoi ban dau.\n");
                } else {
                    printf("Hai chuoi co do dai bang nhau.\n");
                }
                break;
            case 5:
                UpperString(ptr);
                printf("Chuoi in hoa: %s\n", ptr);
                break;
            case 6:
                printf("Nhap vao chuoi khac de them: ");
                fgets(input, sizeof(input), stdin);
                strcat(ptr, input);
                printf("Chuoi sau khi them: %s\n", ptr);
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

