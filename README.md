# 📚 Dự án hệ thống quản Lý Thư Viện - C Console App
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
- 🔍 Tìm kiếm sách theo id

### Chức năng cho User
- 📖 Xem danh sách sách
- 🔍 Tìm kiếm sách

## 📂 Cấu trúc tệp
```bash
├── main.c           # Chứa hàm main và menu chính
├── auth.c           # Xử lý đăng nhập, đăng ký
├── auth.h           # Khai báo hàm cho auth.c
├── book.c           # Quản lý sách (thêm, sửa, xóa, tìm kiếm)
├── book.h           # Khai báo hàm cho book.c
├── auth.txt         # Lưu thông tin tài khoản (username|password|role)
├── book.txt         # Lưu thông tin sách (id|tên|tác giả|năm|số lượng)
```
## 🚀 Hướng phát triển

🧾 **Thêm chức năng mượn/trả sách**  
Cho phép người dùng mượn sách và lưu thông tin mượn (tên sách, ngày mượn, ngày trả).

📁 **Lưu lịch sử mượn sách**  
Ghi lịch sử mượn/trả sách vào file `borrow_history.txt` để theo dõi.

🔍 **Tìm kiếm theo nhiều tiêu chí**  
Cho phép tìm sách theo tên, tác giả, hoặc năm xuất bản.

🧑‍💼 **Cập nhật thông tin tài khoản**  
Cho phép người dùng đổi mật khẩu hoặc sửa tên tài khoản.

🧹 **Cải thiện giao diện dòng lệnh**  
Thêm màu sắc, khung menu, hoặc làm sạch màn hình khi chuyển menu để dễ sử dụng hơn.
