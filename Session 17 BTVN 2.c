#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countLetters(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) count++;
    }
    return count;
}

int countDigits(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) count++;
    }
    return count;
}
int main() {
    char arr[100];
    char *ptr = arr;
    int choice;
    int countText=0;
	int countNum=0;
	int countSpecial=0;
	int length = strlen(arr);
	
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai\n");
        printf("4. Dem so luong chu so\n");
        printf("5. Dem so luong ky tu dac biet\n");
        printf("6. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap vao chuoi: ");
                fgets(arr, sizeof(arr), stdin);
                break;
            case 2:
                printf("Chuoi da nhap: %s\n", ptr);
                break;
            case 3:
                printf("%d ky tu chu cai\n", countLetters(ptr));
                break;
            case 4:
                printf("%d ky tu chu so\n", countDigits(ptr));
                break;
            case 5:
                for (int i = 0; i < length; i++){
					if(isalpha(arr[i])){
						countText++; 
					}else if(isdigit(arr[i])){
						countNum++; 
					}else{
						countSpecial++; 
					}
	}
				printf("%d ki tu dac diet\n", countSpecial++);
				break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);

    return 0;
}

