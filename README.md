# 📚 Dự án Quản Lý Thư Viện - C Console App
Đây là dự án quản lý thư viện đơn giản được xây dựng bằng ngôn ngữ lập trình C. Ứng dụng hoạt động trên nền **giao diện dòng lệnh (console)** và hỗ trợ **phân quyền người dùng** gồm `admin` và `user`.
---
## ✅ Tính năng chính

### Đăng nhập / Đăng ký
- Đăng nhập bằng tên người dùng và mật khẩu
- Đăng ký tài khoản mới
- Phân quyền người dùng: `admin`, `user`

### Chức năng cho Admin
- 📖 Xem danh sách sách
- ➕ Thêm sách mới
- ✏️ Sửa thông tin sách
- ❌ Xóa sách
- 🔍 Tìm kiếm sách theo tiêu chí

### Chức năng cho User
- 📖 Xem danh sách sách
- 🔍 Tìm kiếm sách

## 📂 Cấu trúc tệp
---
```bash
├── main.c           # Chứa hàm main và menu chính
├── auth.c           # Xử lý đăng nhập, đăng ký
├── auth.h           # Khai báo hàm cho auth.c
├── book.c           # Quản lý sách (thêm, sửa, xóa, tìm kiếm)
├── book.h           # Khai báo hàm cho book.c
├── auth.txt         # Lưu thông tin tài khoản (username|password|role)
├── book.txt         # Lưu thông tin sách (id|tên|tác giả|năm|số lượng)
