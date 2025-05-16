#define _CRT_SECURE_NO_WARNINGS
#include "auth.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>

void inputPassword(char* password){
	printf("Nhap mat khau: ");
	int i = 0;
	char ch;
	while ( ( ch = _getch() ) != '\r' && i < 19 ) {
		if (ch == 8 && i > 0) {
			i--;
			printf("\b \b");
		}
		else if (ch != 8) {
			password[i++] = ch;
			printf("*");
		}
	}
	password[i] = '\0';
}

int login(char* username, char* role){
	char inputUser[50], inputPass[50];
	//nhap ten dang nhap
	printf("Ten dang nhap: ");
	fgets(inputUser, sizeof(inputUser), stdin);
	inputUser[strcspn(inputUser, "\n")] = '\0';
	//nhap mat khau
	inputPassword(inputPass);
	
	//mo file auth.txt de kiem tra tai khoan
	FILE* f = fopen("auth.txt", "r");
	if (!f) {
		printf("Khong mo duoc file auth.txt\n");
		return 0;
	}

	char user[50], pass[50], roleAc[10];
	char line[100];

	if (fgets(line, sizeof(line), f)) {
		if (strncmp(line, "\xEF\xBB\xBF", 3)) {
			size_t len = strlen(line + 3);
			memmove(line, line + 3, len + 1);
		}
	}
	rewind(f);

	while (fgets(line, sizeof(line), f)) {
		sscanf(line, "%[^|]|%[^|]|%s", user, pass, roleAc);
		if (strcmp(inputUser, user) == 0 && strcmp(inputPass, pass) == 0) {
			strcpy(username, user);
			strcpy(role, roleAc);
			fclose(f);
			return 1;
		}
	}

	
	fclose(f);
	return 0;
}

void signup() {
	char user[50], pass[50];
	printf("Dang ki\n");
	//nhap tai khoan dang ky
	printf("Ten dang nhap cua ban: ");
	/*scanf("%s%*c", user);*/
	fgets(user, sizeof(user), stdin);
	user[strcspn(user, "\n")] = '\0';
	
	printf("Mat khau cua ban: ");
	//scanf("%s%*c", pass);
	fgets(pass, sizeof(pass), stdin);
	pass[strcspn(pass, "\n")] = '\0';

	printf("Vui long nho tai khoan cua ban\n");

	FILE* f = fopen("auth.txt", "a");
	if (!f) {
		printf("Khong the mo file auth.txt\n");
		return;
	}
	fprintf(f, "%s|%s|%s\n", user, pass, "user");
	printf("Chuc mung ban tao tai khoan thanh cong!\n");
	printf("=======================================\n");

	fclose(f);

}
