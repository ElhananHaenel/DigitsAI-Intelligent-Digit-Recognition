// MlpNetwork.h
#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Dense.h"

#define MLP_SIZE 4

/**
 * @struct digit
 * @Identified (by Mlp network) digit with the associated probability.
 * @var value - Identified digit value.
 * @var probability - Identification probability.
 */
typedef struct digit
{
    unsigned int value; // Identified digit value
    float probability;  // Identification probability
} digit;

const matrix_dims img_dims = {28, 28};  // Dimensions of the input
const matrix_dims weights_dims[] = {
    {128, 784},  // Dimensions of weights for level 1
    {64, 128},   // Dimensions of weights for level 2
    {20, 64},    // Dimensions of weights for level 3
    {10, 20}     // Dimensions of weights for level 4
};
const matrix_dims bias_dims[] = {
    {128, 1}, // Dimensions of biases for level 1
    {64, 1},  // Dimensions of biases for level 2
    {20, 1},  // Dimensions of biases for level 3
    {10, 1}   // Dimensions of biases for level 4
};

class MlpNetwork
{
 private:
  Dense level1; // First level of the MLP network
  Dense level2; // Second level of the MLP network
  Dense level3; // Third level of the MLP network
  Dense level4; // Fourth level of the MLP network

 public:
  /**
   * @Constructor.
   * @param weights Array of weight matrices for each level.
   * @param biases Array of bias matrices for each level.
   */
  MlpNetwork(const Matrix weights[], const Matrix biases[]);

  /**
   * @Operator overload for evaluating the MLP network on an input matrix.
   * @param input Input matrix to evaluate.
   * @return Identified digit and its probability.
   */
  digit operator()(Matrix &input) const;
};

#endif // MLPNETWORK_H
