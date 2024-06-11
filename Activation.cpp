#include "Activation.h"


// Relu activation function
Matrix activation::relu (const Matrix &a)
{
  int rows = a.get_rows ();
  int cols = a.get_cols ();

  Matrix result (rows, cols);

  for (int i = 0; i < rows * cols; i++)
    {
      if (a[i] >= 0)
        {
          result[i] = a[i];
        }
      else
        {
          result[i] = 0;
        }
    }

  return result;
}

// Softmax activation function
Matrix activation::softmax (const Matrix &a)
{
  int rows = a.get_rows ();
  int cols = a.get_cols ();
  Matrix help (a);
  float sum = 0;

  for (int j = 0; j < cols * rows; j++)
    {
      help[j] = std::exp(help[j]);
      sum += help[j];
      }
  return (1/sum) * help;
}

