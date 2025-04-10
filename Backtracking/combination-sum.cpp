#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Kết quả cuối cùng sẽ lưu trong biến toàn cục `res`
    vector<vector<int>> res;

    // Hàm chính để tìm tất cả các tổ hợp có tổng bằng target
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur; // Lưu tổ hợp hiện tại đang được xây dựng
        backtrack(nums, target, cur, 0); // Gọi hàm đệ quy bắt đầu từ chỉ số 0
        return res; // Trả về tất cả tổ hợp thỏa mãn
    }

    // Hàm đệ quy (backtracking)
    void backtrack(vector<int>& nums, int target, vector<int>& cur, int i) {
        // Trường hợp base case: nếu tổng hiện tại bằng target → lưu kết quả
        if (target == 0) {
            res.push_back(cur); // Thêm tổ hợp hiện tại vào kết quả
            return;
        }

        // Nếu target < 0 hoặc đã duyệt hết mảng → dừng lại
        if (target < 0 || i >= nums.size()) {
            return;
        }

        // Chọn phần tử tại vị trí i (có thể chọn lại nhiều lần)
        cur.push_back(nums[i]); // Thêm nums[i] vào tổ hợp hiện tại
        backtrack(nums, target - nums[i], cur, i); // Gọi lại đệ quy với target giảm đi, vẫn dùng chỉ số i (cho phép lặp lại)
        cur.pop_back(); // Bỏ phần tử vừa thêm để thử hướng khác (backtracking)

        // Bỏ qua phần tử nums[i], chuyển sang nums[i+1] (không lặp lại)
        backtrack(nums, target, cur, i + 1);
    }
};

int main() {
    Solution solution;
    
    // Ví dụ đầu vào
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;
    
    // Gọi hàm combinationSum
    vector<vector<int>> result = solution.combinationSum(nums, target);
    
    // In kết quả
    cout << "Cac to hop co tong bang " << target << " la:\n";
    for (const vector<int>& combination : result) {
        cout << "[";
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    
    return 0;
}