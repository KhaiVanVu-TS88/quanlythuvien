#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "book.h"
//chứa menu cho admin và menu cho người đọc
void menuAdmin() {
	int choice;
	do {
		printf("\n======Menu======\n");
		printf("= 1. Xem sach  =\n");
		printf("= 2. Them sach =\n");
		printf("= 3. Sua sach  =\n");
		printf("= 4. Xoa sach  =\n");
		printf("= 5. Tim sach  =\n");
		printf("= 0. Thoat!    =\n");
		printf("= Moi lua chon =\n");
		scanf("%d%*c", &choice);
		switch (choice) {
		case 0:
			//Thoat
			printf("Ban da thoat chuong trinh\n");
			choice = 0;
			break;
		case 1:
			//xem sach
			printf("Xem sach\n");
			showBook();
			break;
		case 2:
			//Them sach
			printf("Them sach\n");
			addBook();
			break;
		case 3:
			//Sửa sach
			printf("Sua sach\n");
			editBook();
			break;
		case 4:
			//Xóa sach
			printf("Xoa sach\n");
			deleteBook();
			break;
		case 5:
			//Tim sach
			printf("Tim sach\n");
			searchBook();
			break;
		default:
			printf("Moi ban nhap lai lua chon\n");
		}
	} while (choice != 0);
}

void menuUser() {
	int choice;
	do {
		printf("\n== Menu User ===\n");
		printf("= 1. Xem sach  =\n");
		printf("= 2. Tim sach  =\n");
		printf("= 0. Thoat!    =\n");
		printf("= Moi lua chon =\n");
		scanf("%d%*c", &choice);
		switch (choice) {
		case 0:
			//Thoát
			printf("Ban da thoat chuong trinh\n");
			choice = 0;
			break;
		case 1:
			//xem sách
			printf("Xem sach\n");
			showBook();
			break;
		case 2:
			//Tìm sách
			printf("Tim sach\n");
			searchBook();
			break;
		default:
			printf("Moi ban nhap lai lua chon\n");
		}
	} while (choice != 0);
}

int main() {
	char username[50], role[10];
	int choice;
	while (1) {
		printf("\n==== CHUONG TRINH QUAN LY THU VIEN ====\n");
		printf("1. Dang nhap\n");
		printf("2. Dang ky tai khoan\n");
		printf("0. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		int c;
		switch (choice) {
		case 1: 
			while ((c = getchar()) != '\n' && c != EOF);
			printf("== Dang nhap ==\n");
			if (login(username, role)) {
				printf("\nChao mung %s\n", username);
				if (strcmp(role, "admin") == 0)
					menuAdmin();
				else if (strcmp(role, "user") == 0)
					menuUser();
				else
					printf("\n== that bai ===\n");
			}
			else
				printf("\n== that bai ===\n");
			break;
		case 2:
			while ((c = getchar()) != '\n' && c != EOF);
			signup();
			break;
		case 0:
			printf("Ban da thoat\n");
			return 0;
		default:
			printf("Lua chon khong hop le!\n");
		}
	}

	return 0;
}