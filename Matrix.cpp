#include <iostream>
#include <cmath>
#include <istream>
#include <ostream>
#include "Matrix.h"

#define EPSILON 0.1

using std::cout;
using std::cin;
using std::ostream;
using std::istream;

Matrix::Matrix (int num_row, int num_col)
{
  if (num_row <= 0 || num_col <= 0)
    {
      throw std::length_error ("size of matrix is invalid");
    }
  rows = num_row;
  cols = num_col;
  data = new float[rows * cols] ();
  for (int i = 0; i < rows * cols; i++)
    {
      data[i] = 0;
    }
}

Matrix::Matrix () : Matrix (1, 1)
{}

Matrix::Matrix (const Matrix &matrix) : rows (matrix.rows), cols (matrix.cols)
{

  data = new float[rows * cols] ();
  for (int i = 0; i < rows * cols; i++)
    {
      data[i] = matrix.data[i];
    }
}

Matrix::~Matrix ()
{
  delete[] data;
}

int Matrix::get_rows () const
{
  return rows;
}

int Matrix::get_cols () const
{
  return cols;
}

float Matrix::sum () const
{
  float sum = 0;
  for (int i = 0; i < rows * cols; i++)
    {
      sum += data[i];
    }
  return sum;
}

Matrix &Matrix::transpose ()
{
  Matrix transposed (cols, rows);
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          transposed.data[j * rows + i] = (*this)[i * cols + j];
        }
    }
  *this = transposed;
  return *this;
}

Matrix &Matrix::vectorize ()
{
  rows = rows * cols;
  cols = 1;
  return *this;
}

void Matrix::plain_print () const
{
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          std::cout << data[i * cols + j] << " ";
        }
      std::cout << std::endl;
    }
}

Matrix Matrix::dot (const Matrix m) const
{
  if (rows != m.rows || cols != m.cols)
    {
      throw std::length_error (
          "Error: Matrix dimensions must match for element-wise"
          " multiplication!");
    }

  Matrix result (rows, cols);

  for (int i = 0; i < rows * cols; i++)
    {
      result.data[i] = data[i] * m.data[i];
    }

  return result;
}

float Matrix::norm () const
{
  float sum = 0.0;
  for (int i = 0; i < rows * cols; i++)
    {
      sum += pow (data[i], 2);
    }
  return sqrt (sum);
}

int Matrix::argmax () const
{
  int max_index = 0;
  int max_val = data[0];

  for (int i = 0; i < rows * cols; i++)
    {
      if (data[i] > max_val)
        {
          max_val = data[i];
          max_index = i;
        }
    }

  return max_index;
}

Matrix &Matrix::operator= (const Matrix &matrix)
{
  if (this != &matrix)
    {
      if (rows != matrix.rows || cols != matrix.cols)
        {
          delete[] data;

          rows = matrix.rows;
          cols = matrix.cols;

          data = new float[rows * cols] ();
        }

      for (int i = 0; i < rows * cols; i++)
        {
          data[i] = matrix.data[i];
        }
    }

  return *this;
}

Matrix Matrix::operator+ (const Matrix &matrix) const
{
  if (rows != matrix.rows || cols != matrix.cols)
    {
      throw std::length_error (
          "Error: Matrix dimensions must match for element-wise"
          " +!");
    }

  Matrix result (rows, cols);

  for (int i = 0; i < rows * cols; i++)
    {
      result.data[i] = data[i] + matrix.data[i];
    }

  return result;
}

Matrix Matrix::operator* (const Matrix &matrix) const
{
  if (cols != matrix.rows)
    {
      throw std::length_error (
          "Error: Matrix dimensions must match for element-wise"
          " multiplication!");
    }

  Matrix result (rows, matrix.cols);

  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < matrix.cols; j++)
        {
          for (int k = 0; k < cols; k++)
            {
              result.data[i * result.cols + j] +=
                  data[i * cols + k] * matrix.data[k * matrix.cols + j];
            }
        }
    }

  return result;
}

Matrix Matrix::operator* (const float scalar) const
{
  Matrix result (rows, cols);

  for (int i = 0; i < rows * cols; i++)
    {
      result.data[i] = data[i] * scalar;
    }

  return result;
}

Matrix &Matrix::operator+= (const Matrix &matrix)
{
  if (rows != matrix.rows || cols != matrix.cols)
    {
      throw std::length_error (
          "Error: Matrix dimensions must match for element-wise"
          " add !");
    }

  for (int i = 0; i < rows * cols; i++)
    {
      data[i] += matrix.data[i];
    }

  return *this;
}

Matrix operator* (const float scalar, const Matrix &matrix)
{

  return matrix * scalar;
}

float &Matrix::operator() (int i, int j)
{
  if (i < 0 || i >= rows || j < 0 || j >= cols)
    {
      throw std::out_of_range ("Invalid matrix index!");
    }
  return data[i * cols + j];
}

const float &Matrix::operator() (int i, int j) const
{
  if (i < 0 || i >= rows || j < 0 || j >= cols)
    {
      throw std::out_of_range ("Invalid matrix index!");
    }
  return data[i * cols + j];
}

float &Matrix::operator[] (const int k)
{
  if (k < 0 || k >= rows * cols)
    {
      throw std::out_of_range ("Invalid matrix index!");
    }
  return data[k];
}

const float &Matrix::operator[] (const int k) const
{
  if (k < 0 || k >= rows * cols)
    {
      throw std::out_of_range ("Invalid matrix index!");
    }
  return data[k];
}

std::ostream &operator<< (std::ostream &os, const Matrix &matrix)
{
  for (int i = 0; i < matrix.rows; i++)
    {
      for (int j = 0; j < matrix.cols; j++)
        {
          if (matrix.data[i * matrix.cols + j] > EPSILON)
            {
              os << "**";
            }
          else
            {
              os << " ";
            }
        }
      os << std::endl;
    }
  return os;
}

std::istream &operator>> (std::istream &is, Matrix &matrix)
{
  is.seekg (0, std::istream::end);
  if (is.tellg () < long (matrix.cols * matrix.rows * sizeof (float)))
    {
      throw std::runtime_error ("Error reading matrix elements!");
    }
  else
    {
      is.seekg (0, std::istream::beg);
    }
  for (int i = 0; i < matrix.cols * matrix.rows; i++)
    {
      is.read ((char *) &matrix[i], sizeof (float));
      if (!is)
        {
          throw std::runtime_error ("Error reading matrix elements!");
        }
    }
  return is;
}

Matrix Matrix::rref () const
{
  Matrix result (*this);  // Create a copy of the matrix
  int lead = 0;
  for (int r = 0; r < result.rows; ++r)
    {
      if (result.cols <= lead)
        {
          return result;
        }
      int i = r;
      while (result.data[i * result.cols + lead] == 0)
        {
          ++i;
          if (result.rows == i)
            {
              i = r;
              ++lead;
              if (result.cols == lead)
                {
                  return result;
                }
            }
        }
      for (int j = 0; j < result.cols; ++j)
        {
          double temp = result.data[i * result.cols + j];
          result.data[i * result.cols + j] = result.data[r * result.cols + j];
          result.data[r * result.cols + j] = temp;
        }
      double pivot = result.data[r * result.cols + lead];
      for (int j = 0; j < result.cols; ++j)
        {
          result.data[r * result.cols + j] /= pivot;
        }
      for (int i = 0; i < result.rows; ++i)
        {
          if (i != r)
            {
              double factor = result.data[i * result.cols + lead];
              for (int j = 0; j < result.cols; ++j)
                {
                  result.data[i * result.cols + j] -=
                      factor * result.data[r * result.cols + j];
                }
            }
        }
      ++lead;
    }
  return result;
}
