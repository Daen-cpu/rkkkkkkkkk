#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string binary_and(const string& a, const string& b) {
    string result = "";
    for (size_t i = 0; i < a.size(); ++i) {
        result += (a[i] == '1' && b[i] == '1') ? '1' : '0';
    }
    return result;
}

string binary_add(const string& a, const string& b) {
    int carry = 0;
    string result = "";
    for (int i = a.size() - 1; i >= 0; --i) {
        int bit_a = a[i] - '0';
        int bit_b = b[i] - '0';
        int sum = bit_a + bit_b + carry;
        result += (sum % 2) + '0';
        carry = sum / 2;
    }
    if (carry) {
        result += '1';
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string A = "101101";
    string B = "110011";

    string and_result = binary_and(A, B);
    string sum_result = binary_add(A, B);


    cout << "A AND B = " << and_result << endl;
    cout << "A + B = " << sum_result << endl;

    return 0;
}
