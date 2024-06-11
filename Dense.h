// Dense.h
#ifndef DENSE_H
#define DENSE_H

#include <functional>
#include "Activation.h"

/**
 * @brief Typedef for Activation Function.
 */
typedef Matrix (*ActivationFunc)(const Matrix &);

class Dense {
 private:
  Matrix weights;          // Weight matrix
  Matrix bias;             // Bias matrix
  ActivationFunc activ;    // Activation function

 public:
  /**
   * @brief Constructor.
   * @param weights Weight matrix.
   * @param bias Bias matrix.
   * @param activ Activation function.
   */
  Dense(const Matrix &weights, const Matrix &bias, ActivationFunc activ);

  /**
   * @brief Operator overload for evaluating the Dense layer
   * on an input matrix.
   * @param input Input matrix.
   * @return Output matrix after applying the Dense layer.
   */
  Matrix operator()(const Matrix &input) const;

  /**
   * @brief Get the weight matrix.
   * @return Reference to the weight matrix.
   */
  const Matrix &get_weights() const;

  /**
   * @brief Get the bias matrix.
   * @return Reference to the bias matrix.
   */
  const Matrix &get_bias() const;

  /**
   * @brief Get the activation function.
   * @return Reference to the activation function.
   */
  const ActivationFunc &get_activation() const;
};

#endif // DENSE_H
