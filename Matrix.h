// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <istream>

/**
 * @struct matrix_dims
 * @Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims
{
    int rows, cols;
} matrix_dims;

class Matrix {
 private:
  int rows;    // Number of rows in the matrix
  int cols;    // Number of columns in the matrix
  float *data; // Pointer to the matrix data

 public:
  /**
   * @Parameterized constructor.
   * @param rows Number of rows in the matrix.
   * @param cols Number of columns in the matrix.
   */
  Matrix(int rows, int cols);

  /**
   * @Default constructor.
   */
  Matrix();

  /**
   * @Copy constructor.
   * @param matrix Matrix object to be copied.
   */
  Matrix(const Matrix &matrix);

  /**
   * @Destructor.
   */
  ~Matrix();

  /**
   * @Get the number of rows in the matrix.
   * @return Number of rows.
   */
  int get_rows() const;

  /**
   * @Get the number of columns in the matrix.
   * @return Number of columns.
   */
  int get_cols() const;

  /**
   * @Calculate the sum of all elements in the matrix.
   * @return Sum of elements.
   */
  float sum() const;

  /**
   * @Transpose the matrix.
   * @return Reference to the transposed matrix.
   */
  Matrix& transpose();

  /**
   * @Vectorize the matrix (flatten into a column vector).
   * @return Reference to the vectorized matrix.
   */
  Matrix& vectorize();

  /**
   * @Print the matrix in plain format (row by row).
   */
  void plain_print() const;

  /**
   * @Perform matrix multiplication with another matrix.
   * @param m Matrix to multiply with.
   * @return Resulting matrix after multiplication.
   */
  Matrix dot(Matrix m) const;

  /**
   * @Calculate the Frobenius norm of the matrix.
   * @return Frobenius norm of the matrix.
   */
  float norm() const;

  /**
   * @Find the index of the maximum element in the matrix.
   * @return Index of the maximum element.
   */
  int argmax() const;

  /**
   * @Copy assignment operator.
   * @param matrix Matrix object to be assigned.
   * @return Reference to the assigned matrix.
   */
  Matrix &operator=(const Matrix &matrix);

  /**
   * @Add two matrices element-wise.
   * @param matrix Matrix to add.
   * @return Resulting matrix after addition.
   */
  Matrix operator+(const Matrix &matrix) const;

  /**
   * @Multiply two matrices element-wise or multiply matrix with scalar.
   * @param matrix Matrix or scalar to multiply with.
   * @return Resulting matrix after multiplication.
   */
  Matrix operator*(const Matrix &matrix) const;
  Matrix operator*(float scalar) const;

  /**
   * @Add another matrix to the current matrix element-wise.
   * @param matrix Matrix to add.
   * @return Reference to the updated matrix.
   */
  Matrix &operator+=(const Matrix &matrix);

  /**
   * @Multiply matrix with scalar.
   * @param scalar Scalar value to multiply with.
   * @param matrix Matrix to multiply with scalar.
   * @return Resulting matrix after scalar multiplication.
   */
  friend Matrix operator*(float scalar, const Matrix &matrix);

  /**
   * @Access the element at the specified row and column indices
   * for modification.
   * @param i Row index.
   * @param j Column index.
   * @return Reference to the element at (i, j).
   */
  float &operator()(int i, int j);

  /**
   * @Access the element at the specified row and column indices for reading.
   * @param i Row index.
   * @param j Column index.
   * @return Constant reference to the element at (i, j).
   */
  const float &operator()(int i, int j) const;

  /**
   * @Access the element at the specified index for modification.
   * @param k Index.
   * @return Reference to the element at index k.
   */
  float &operator[](int k);

  /**
   * @Access the element at the specified index for reading.
   * @param k Index.
   * @return Constant reference to the element at index k.
   */
  const float &operator[](int k) const;

  /**
   * @Output stream operator overload for printing the matrix.
   * @param os Output stream.
   * @param matrix Matrix to be printed.
   * @return Reference to the output stream.
   */
  friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

  /**
   * @Input stream operator overload for reading the matrix.
   * @param is Input stream.
   * @param matrix Matrix to be read into.
   * @return Reference to the input stream.
   */
  friend std::istream &operator>>(std::istream &is, Matrix &matrix);

  /**
     * @Perform row echelon form (REF) on the matrix and return a
     * new matrix.
     * @return The matrix in reduced row echelon form (RREF).
     */
  Matrix rref() const;
};

#endif //MATRIX_H
