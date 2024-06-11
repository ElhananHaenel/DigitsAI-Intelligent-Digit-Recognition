#include "Matrix.h"
#include "Activation.h"

#include "Dense.h"
#include <ostream>
#include <istream>
#include "MlpNetwork.h"

#define TEN 10

MlpNetwork::MlpNetwork (const Matrix weights[], const Matrix biases[]) :
    level1 (weights[0], biases[0], activation::relu),
    level2 (weights[1], biases[1], activation::relu),
    level3 (weights[2], biases[2], activation::relu),
    level4 (weights[3], biases[3], activation::softmax)
{
}

digit MlpNetwork::operator() (Matrix &input) const
{

  Matrix output = level4 (level3 (level2 (level1(input.vectorize()))));
  digit result;
  for (int i = 0; i < TEN; i++)
    {
      if (output[i] > result.probability)
        {
          result.value = i;
          result.probability = output[i];
        }
    }

  return result;
}

