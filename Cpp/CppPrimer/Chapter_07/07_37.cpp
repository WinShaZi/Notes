/*

Sales_data first_item(cin);   // 使用了 Sales_data(std::istream &is) ; 数据成员值依赖输入

int main() {
  Sales_data next;  // 使用了Sales_data(std::string s = ""); bookNo = "", cnt = 0, revenue = 0.0
  Sales_data last("9-999-99999-9"); // 使用了 Sales_data(std::string s = ""); bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}

*/