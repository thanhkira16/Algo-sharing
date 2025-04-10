#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Hàm đệ quy backtracking để sinh các chuỗi dấu ngoặc hợp lệ
    void backtrack(int openN, int closedN, int n, vector<string>& res, string& stack) {
        // Nếu đã thêm đủ n dấu '(' và n dấu ')', tức là chuỗi hợp lệ hoàn chỉnh
        if (openN == closedN && openN == n) {
            res.push_back(stack);  // Thêm chuỗi vào kết quả
            return;
        }

        // Nếu số dấu '(' hiện tại < n, ta có thể thêm một '('
        if (openN < n) {
            stack += '(';  // Thêm '(' vào chuỗi hiện tại
            backtrack(openN + 1, closedN, n, res, stack);  // Gọi đệ quy
            stack.pop_back();  // Quay lui (backtrack) để thử nhánh khác
        }

        // Nếu số dấu ')' < số dấu '(', ta có thể thêm một ')'
        if (closedN < openN) {
            stack += ')';  // Thêm ')' vào chuỗi hiện tại
            backtrack(openN, closedN + 1, n, res, stack);  // Gọi đệ quy
            stack.pop_back();  // Quay lui (backtrack)
        }
    }

    // Hàm chính để sinh tất cả chuỗi dấu ngoặc hợp lệ với n cặp
    vector<string> generateParenthesis(int n) {
        vector<string> res;  // Lưu các kết quả chuỗi hợp lệ
        string stack;        // Chuỗi tạm thời đang xây dựng
        backtrack(0, 0, n, res, stack);  // Bắt đầu từ 0 dấu '(' và 0 dấu ')'
        return res;  // Trả kết quả cuối cùng
    }
};

int main() {
    Solution solution;
    
    // Ví dụ đầu vào
    int n = 3;
    
    // Gọi hàm generateParenthesis để sinh các chuỗi dấu ngoặc hợp lệ
    vector<string> result = solution.generateParenthesis(n);
    
    // In kết quả
    cout << "Tat ca cac chuoi dau ngoac hop le voi " << n << " cap la:\n";
    for (const string& s : result) {
        cout << s << "\n";
    }
    
    return 0;
}