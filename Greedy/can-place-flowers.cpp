#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Hàm kiểm tra xem có thể trồng thêm n bông hoa vào luống hoa không
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Tạo mảng mới với kích thước lớn hơn 2 đơn vị, thêm 0 ở hai đầu
        // Điều này giúp đơn giản hóa việc kiểm tra biên
        vector<int> f(flowerbed.size() + 2, 0);
        
        // Sao chép dữ liệu từ flowerbed vào mảng mới, bắt đầu từ vị trí 1
        for (int i = 0; i < flowerbed.size(); i++) {
            f[i + 1] = flowerbed[i];
        }
        
        // Duyệt qua mảng từ vị trí 1 đến size-2 (bỏ qua hai đầu 0)
        for (int i = 1; i < f.size() - 1; i++) {
            // Nếu vị trí hiện tại và hai vị trí lân cận đều trống (0)
            if (f[i - 1] == 0 && f[i] == 0 && f[i + 1] == 0) {
                f[i] = 1;  // Trồng hoa tại vị trí này
                n--;       // Giảm số hoa cần trồng đi 1
            }
        }
        
        // Trả về true nếu đã trồng đủ hoặc thừa số hoa cần thiết (n <= 0)
        return n <= 0;
    }
};

int main() {
    Solution solution;
    
    // Ví dụ đầu vào
    vector<int> flowerbed = {1, 0, 0, 0, 1};  // Luống hoa ban đầu
    int n = 1;                                 // Số hoa cần trồng thêm
    
    // Gọi hàm canPlaceFlowers để kiểm tra
    bool result = solution.canPlaceFlowers(flowerbed, n);
    
    // In kết quả
    cout << "Co the trong them " << n << " bong hoa khong? ";
    cout << (result ? "Co" : "Khong") << "\n";
    
    return 0;
}