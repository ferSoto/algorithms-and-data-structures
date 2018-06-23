#include <iostream>
#include <vector>

using namespace std;

// f(x) = 2 * x + 3
int pos2num(int i) {
    if (i == -1) return 2;
    return 2 * i + 3;
}

vector<int> primesum(int n) {
    if (n == 4) return {2, 2};

    // Create vector of odd numbers to search for primes numbers
    // The 0 elements represents the position of a prime number
    // f(x) = 2 * x + 3 is the function to convert a position in the vector to its prime value.
    vector<bool> numbers(n / 2 + 1, 0);

    // Get the position of all of the primes numbers between 0 and n
    int num, last;
    for (int i = 0; (num = pos2num(i)) <= n; i++) {
        last = i;
        // Skip not primes numbers
        if (numbers[i]) continue;

        for (int j = i + num; pos2num(j) <= n; j+= num) {
            // When found a prime number, mark all of its multiples as not primes
            numbers[j] = 1;
        }
    }

    // Get the pair of numbers which sum is n
    for (int i = -1; i < last; i++) {
        if (i > 0 && numbers[i]) continue;

        int a = pos2num(i);
        int b;
        for (int j = last; j >= 0 && ((b = pos2num(j)) + a >= n); j--) {
            if (numbers[j]) continue;
            if (a + b == n) return {a, b};
        }
    }

    // Return a dummy vector just for the sake of avoid warnings
    return {-1, -1};
}

int main () {
    int n;
    cin >> n;
    auto primes = primesum(n);
    cout << primes[0] << " " << primes[1] << endl;
}