#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

tuple<vector<int>, vector<int>> halfs(vector<int> xs) {
    if (xs.empty()) return {{}, {}};
    vector<int> ys, zs;
    int mid = xs.size() / 2;
    for (int i = 0; i < xs.size(); i++) {
        if (i < mid) {
            ys.push_back(xs[i]);
        } else {
            zs.push_back(xs[i]);
        }
    }
    return {ys, zs};
}

vector<int> merge(vector<int> xs, vector<int> ys) {
    vector<int> zs(xs.size() + ys.size());
    int ix = 0;
    int iy = 0;
    while (ix + iy < zs.size()) {
        if (ix == xs.size()) {
            while (iy < ys.size()) {
                zs[ix + iy] = ys[iy];
                iy ++;
            }
        } else if (iy == ys.size()) {
            while (ix < xs.size()) {
                zs[ix + iy] = xs[ix];
                ix ++;
            }
        } else if (xs[ix] < ys[iy]) {
            zs[ix + iy] = xs[ix];
            ix ++;
        } else {
            zs[ix + iy] = ys[iy];
            iy ++;
        }
    }
    return zs;
}

vector<int> mergesort(vector<int> xs) {
    if (xs.size() < 2) return xs;
    vector<int> ys, zs;
    tie(ys, zs) = halfs(xs);
    return merge(mergesort(ys), mergesort(zs));
}

void print(const vector<int> &xs) {
    for (int x : xs) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int n;
    vector<int> xs;

    while (cin >> n) {
        xs.push_back(n);
    }

    xs = mergesort(xs);
    print(xs);

    return 0;
}
