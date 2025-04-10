#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Hàm chính để tìm tất cả tập con của mảng nums
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;  // Lưu trữ tất cả tập con tìm được
        vector<int> subset;       // Lưu trữ tập con hiện tại đang xây dựng
        dfs(nums, 0, subset, res); // Bắt đầu tìm kiếm từ chỉ số 0
        return res;               // Trả về kết quả
    }

private:
    // Hàm đệ quy DFS để sinh tất cả tập con
    // nums: mảng đầu vào
    // i: chỉ số hiện tại đang xét
    // subset: tập con đang xây dựng
    // res: danh sách các tập con đã tìm được
    void dfs(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res) {
        // Trường hợp cơ sở: nếu đã duyệt hết mảng
        if (i >= nums.size()) {
            res.push_back(subset); // Thêm tập con hiện tại vào kết quả
            return;
        }

        // Trường hợp 1: bao gồm phần tử nums[i] vào tập con
        subset.push_back(nums[i]);      // Thêm phần tử hiện tại vào tập con
        dfs(nums, i + 1, subset, res);  // Tiếp tục đệ quy với phần tử tiếp theo

        // Quay lui (backtrack)
        subset.pop_back();             // Loại bỏ phần tử vừa thêm để thử trường hợp khác
        
        // Trường hợp 2: không bao gồm phần tử nums[i]
        dfs(nums, i + 1, subset, res); // Tiếp tục đệ quy mà không thêm phần tử hiện tại
    }
};

int main() {
    Solution solution;
    
    // Ví dụ đầu vào
    vector<int> nums = {1, 2, 3};
    
    // Gọi hàm subsets để tìm tất cả tập con
    vector<vector<int>> result = solution.subsets(nums);
    
    // In kết quả
    cout << "Tat ca cac tap con la:\n";
    for (const vector<int>& subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    
    return 0;
}