#define _CRT_SECURE_NO_WARNINGS
#include "book.h"
#include <stdio.h>
#include <string.h>

void showBook() {
    FILE* f = fopen("book.txt", "r");
    if (!f) {
        printf("Khong the mo book.txt\n");
        return;
    }

    char line[4096];

    // Đọc dòng đầu tiên và loại bỏ BOM nếu có
    if (fgets(line, sizeof(line), f)) {
        // Kiểm tra BOM UTF-8 của book.txt
        if (strncmp(line, "\xEF\xBB\xBF", 3) == 0) {
            size_t len = strlen(line + 3);  // Độ dài phần data
            memmove(line, line + 3, len + 1); // +1 để copy cả '\0'
        }

        /*Book b;
        int result = sscanf(line, " %d|%[^|]|%[^|]|%d|%d", &b.id, b.title, b.author, &b.year, &b.quantity);
        if (result == 5) {
            printf("%d|%s|%s|%d|%d\n", b.id, b.title, b.author, b.year, b.quantity);
        }
        else {
            printf("Loi dinh dang dong dau tien: [%s]", line);
        }*/
    }
    //Đặt con trỏ về vị trí đầu tiên trong file
    rewind(f);
    // Đọc các dòng còn lại
    while (fgets(line, sizeof(line), f)) {
        Book b;
        int result = sscanf(line, " %d|%[^|]|%[^|]|%d|%d", &b.id, b.title, b.author, &b.year, &b.quantity);
        if (result == 5) {
            printf("%d|%s|%s|%d|%d\n", b.id, b.title, b.author, b.year, b.quantity);
        }
        else {
            printf("Loi dinh dang dong: [%s]", line);
        }
    }

    fclose(f);
}

void addBook(){
    FILE* f = fopen("book.txt", "a");
    if (!f) {
        printf("Loi khong the mo file\n");
        return;
    }
    char line[256];
    Book b;
    printf("Nhap id: "); scanf("%d%*c", &b.id);
    printf("Nhap ten sach: "); fgets(b.title, sizeof(b.title), stdin);b.title[strcspn(b.title, "\n")] = '\0';
    printf("Nhap tac gia: "); fgets(b.author, sizeof(b.author), stdin);b.author[strcspn(b.author, "\n")] = '\0';
    printf("Nhap nam: "); scanf("%d", &b.year);
    printf("Nhap so luong: "); scanf("%d", &b.quantity);
    fprintf(f, "%d|%s|%s|%d|%d\n", b.id, b.title, b.author, b.year, b.quantity);
    printf("Da them sach vao file: %d|%s|%s|%d|%d\n", b.id, b.title, b.author, b.year, b.quantity);
    fclose(f);
}

void editBook(){
    FILE* f = fopen("book.txt", "r");
    if (!f) {
        printf("Loi khong mo duoc book.txt\n");
        return;
    }

    

    FILE* fTemp = fopen("temp.txt", "w");
    if (!fTemp) {
        printf("Khong mo duoc temp.txt\n");
        return;
    }
    int editId;
    printf("Nhap id muon sua: ");
    scanf("%d", &editId);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    int found = 0;
    char line[256];

    //xoa BOM UTF-8
    if (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "\xEF\xBB\xBF", 3) == 0) {
            size_t len = strlen(line + 3);
            memmove(line, line + 3, len + 1);
        }
        /*Book b;
        sscanf(line, "%d|%[^|]|%[^|]|%d|%d", &b.id, b.title, b.author, &b.year, &b.quantity);
        if (b.id == editId) {
            found = 1;
            printf("Nhap ten moi: "); fgets(b.title, sizeof(b.title), stdin); b.title[strcspn(b.title, "\n")] = '\0';
            printf("Nhap tac gia moi: "); fgets(b.author, sizeof(b.author), stdin); b.author[strcspn(b.author, "\n")] = '\0';
            printf("Nhap nam moi: "); scanf("%d", &b.year);
            printf("Nhap so luong moi: "); scanf("%d", &b.quantity);
        }
        fprintf(fTemp, "%d|%s|%s|%d|%d\n", b.id, b.title, b.author, b.year, b.quantity);*/
    }
    //Đưa con trỏ về vị trí đầu tiên sau khi xóa BOM
    rewind(f);
    while (fgets(line, sizeof(line), f)) {
        Book b;
        sscanf(line, "%d|%[^|]|%[^|]|%d|%d", &b.id, b.title, b.author, &b.year, &b.quantity);
        if (b.id == editId) {
            found = 1;
            printf("Nhap ten moi: "); fgets(b.title, sizeof(b.title), stdin); b.title[strcspn(b.title, "\n")] = '\0';
            printf("Nhap tac gia moi: "); fgets(b.author, sizeof(b.author), stdin); b.author[strcspn(b.author, "\n")] = '\0';
            printf("Nhap nam moi: "); scanf("%d", &b.year);
            printf("Nhap so luong moi: "); scanf("%d", &b.quantity);
        }
        fprintf(fTemp, "%d|%s|%s|%d|%d\n", b.id, b.title, b.author, b.year, b.quantity);
    }
    fclose(f);fclose(fTemp);
    //thuc hien xoa book.txt
    remove("book.txt");
    //thuc hien doi ten temp.txt thanh book.txt
    rename("temp.txt", "book.txt");
    if (found) printf("Cap nhat thanh con\n");
    else printf("Khong tim thay sach\n");


}

void deleteBook(){
    FILE* f = fopen("book.txt", "r");
    if (!f) {
        printf("Khong the mo book.txt\n");
        return;
    }
    FILE* fTemp = fopen("temp.txt", "w");
    if (!ftell) {
        printf("Khong the mo temp.txt\n");
        return;
    }

    int deleteId, found = 0;
    printf("Nhap id sach muon xoa: ");
    scanf("%d", &deleteId);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    char line[256];

    if (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "\xEF\xBB\xBF", 3) == 0) {
            size_t len = strlen(line + 3);
            memmove(line, line + 3, len + 1);
        }
    }
    // Đặt con trỏ về đầu file để đọc lại từ đầu
    rewind(f);
    while (fgets(line, sizeof(line), f)) {
        Book b;
        sscanf(line, "%d|%[^|]|%[^|]|%d|%d", &b.id, b.title, b.author, &b.year, &b.quantity);
        if (b.id == deleteId) 
        {
            found = 1;
            continue;
        }
        fprintf(fTemp,"%d|%s|%s|%d|%d\n", b.id, b.title, b.author, b.year, b.quantity);
    }

    fclose(f);
    fclose(fTemp);
    remove("book.txt");
    rename("temp.txt", "book.txt");
    if (found) printf("Xoa thanh cong\n");
    else printf("Khong tim thay id can xoa\n");
}

void searchBook(){
    FILE* f = fopen("Book.txt", "r");
    if (!f) {
        printf("Khong mo duoc book.txt\n");
        return;
    }
    int searchId, found = 0;
    printf("Tim sach voi id: ");
    scanf("%d", &searchId);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);//loai bo cac ky tu thua
    char line[256];
    if (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "\xEF\xBB\xBF", 3) == 0) {
            size_t len = strlen(line + 3);
            memmove(line, line + 3, len + 1);
        }
    }
    //Dat con tro ve vi tri dau file
    rewind(f);
    while (fgets(line, sizeof(line), f)) {
        Book b;
        sscanf(line, "%d|%[^|]|%[^|]|%d|%d", &b.id, b.title, b.author, &b.year, &b.quantity);
        if (searchId == b.id) {
            found = 1;
            printf("%d|%s|%s|%d|%d\n", b.id, b.title, b.author, b.year, b.quantity);
            break;
        }
    }
    fclose(f);
    if (!found) printf("Khong tim thay sach voi id: %d\n", searchId);
}
