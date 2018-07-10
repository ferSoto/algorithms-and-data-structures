#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i <= 100; i++) {
        string ans = "";
        if (i % 3 == 0) ans += "Fizz";
        if (i % 5 == 0) ans += "Buzz";
        if (ans == "") ans = to_string(i);
        cout << ans << endl;
    }
    return 0;
}
