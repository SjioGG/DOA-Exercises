template <typename Object>
void Matrix<Object>::add(Matrix& mat) {
	int rows = numrows();
	int cols = numcols();

	if (rows != mat.numrows() || cols != mat.numcols()) {
		throw invalid_argument{"Matrix has incompatible dimensions"};
	}

	for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            array[i][j] = array[i][j] + mat[i][j];
		}
	}
}

template <typename Object>
void Matrix<Object>::transpose() {
    int numRows = numrows();
    int numCols = numcols();

    // Create a new matrix to store the transposed data.
    Matrix<Object> transposed(numCols, numRows);

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            transposed[j][i] = array[i][j]; // Transpose by copying elements
        }
    }

    // Replace the original matrix with the transposed matrix.
    array = transposed.array;
}


template <typename Object>
Matrix<Object>& multiply(Matrix<Object>& a, Matrix<Object>& b) {
	if (a.numcols() != b.numrows()) {
		throw invalid_argument{"Matrix has incompatible dimensions"};
	}

	Matrix<Object> *mult = new Matrix<Object>(a.numrows(), b.numcols());

	for(int i = 0; i < a.numrows(); ++i) {
        for(int j = 0; j < b.numcols(); ++j) {
			(*mult)[i][j] = 0;
		}
	}

	for(int i = 0; i < a.numrows(); ++i) {
        for(int j = 0; j < b.numcols(); ++j) {
			for (int k = 0; k < b.numrows(); k++) {
				(*mult)[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return *mult;
}
