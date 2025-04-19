

typedef vector<vector<int>> Matrix;

// to add two matrices
Matrix add(Matrix arr, Matrix brr, int n) {
    Matrix res(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res[i][j] = arr[i][j] + brr[i][j];
        }
    }
    return res;
}

// to multiply two matrices
Matrix mult(Matrix &arr, Matrix &brr) {
    int n = arr.size();

    Matrix res(n, vector<int>(n, 0));

    if(n == 1) {
        res[0][0] = arr[0][0] * brr[0][0];
        return res;
    }


    vector<Matrix> subMat(8, Matrix(n/2, vector<int>(n/2, 0)));

    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < n / 2; j++) {
            subMat[0][i][j] = arr[i][j];
            subMat[1][i][j] = arr[i][j + n / 2];
            subMat[2][i][j] = arr[i + n / 2][j];
            subMat[3][i][j] = arr[i + n / 2][j + n / 2];
            subMat[4][i][j] = brr[i][j];
            subMat[5][i][j] = brr[i][j + n / 2];
            subMat[6][i][j] = brr[i + n / 2][j];
            subMat[7][i][j] = brr[i + n / 2][j + n / 2];
        }
    }

    vector<Matrix> resMat(4, Matrix(n/2, vector<int>(n/2, 0)));

    resMat[0] = add(mult(subMat[0], subMat[4]), mult(subMat[1], subMat[6]), n/2);
    resMat[1] = add(mult(subMat[0], subMat[5]), mult(subMat[1], subMat[7]), n/2);
    resMat[2] = add(mult(subMat[2], subMat[4]), mult(subMat[3], subMat[6]), n/2);
    resMat[3] = add(mult(subMat[2], subMat[5]), mult(subMat[3], subMat[7]), n/2);

    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < n / 2; j++) {
            res[i][j] = resMat[0][i][j];
            res[i][j + n / 2] = resMat[1][i][j];
            res[i + n / 2][j] = resMat[2][i][j];
            res[i + n / 2][j + n / 2] = resMat[3][i][j];
        }
    }

    return res;
}

int main() {
    Matrix arr = {{7, 8}, {2, 9}};
    Matrix brr = {{14, 5}, {5, 18}};
    Matrix res = mult(arr, brr);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
