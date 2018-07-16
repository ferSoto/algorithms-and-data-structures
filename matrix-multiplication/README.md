# Matrix multiplication

The program reads two matrices, one of size nxm and the other of mxp, and prints the result of its multiplication.

Both matrices should be integers. If need to multiply matrices with float numbers, just change the type of

```cpp
typedef vector<vector<int>> Matrix;
```

to

```cpp
typedef vector<vector<float>> Matrix;
```

also change the type of `createZeroMatrix(int, int)` to return the correct type.

Input:

* 3 numbers (_n, m and p_), which are the size of both matrices.
* The next line contains _n * m_ numbers, the values of the first matrix.
* The third and last line, contains _m * p_ numbers, the values of the second matrix.

There are 3 input samples which can be found on [[1]](https://github.com/ferSoto/algorithms-and-data-structures/blob/master/matrix-multiplication/test_1.input), [[2]](https://github.com/ferSoto/algorithms-and-data-structures/blob/master/matrix-multiplication/test_2.input) and [[3]](https://github.com/ferSoto/algorithms-and-data-structures/blob/master/matrix-multiplication/test_3.input).
