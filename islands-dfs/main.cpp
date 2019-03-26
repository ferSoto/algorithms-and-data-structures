/**********
*
* Fernando de Jesús Soto
*
***********/

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int mark_and_get_island_size(vector<string> &map, int n, int i, int j) {
    int acc = 0;
    if (map[i][j] == 'l') {
        map[i][j] = 'm';
        acc ++;
        for (int h = max(0, i - 1); h < min(n, i + 2); h++) {
            for (int k = max(0, j - 1); k < min(n, j + 2); k++) {
                if (h == i && k == j) continue;
                acc += mark_and_get_island_size(map, n, h, k);
            }
        }
    }
    return acc;
}

int main() {
    int n = 0;
    while (cin >> n) {
        if (!n) break;

        vector<string> map(n);
        for (int i = 0; i < n; i++) {
            cin >> map[i];
        }

        int n_islands = 0;
        int largest = INT_MIN;
        int smallest = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 'l') {
                    n_islands ++;

                    int size = mark_and_get_island_size(map, n, i, j);
                    largest = max(largest, size);
                    smallest = min(smallest, size);
                }
            }
        }
        cout << n_islands << " " << (smallest == INT_MAX ? 0 : smallest) << " " << (largest == INT_MIN ? 0 : largest) << endl;
    }
    return 0;
}