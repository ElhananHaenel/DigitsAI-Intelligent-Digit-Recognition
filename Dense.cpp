#include <functional>
#include "Matrix.h"
#include "Activation.h"
#include "Dense.h"
#include <ostream>
#include <istream>
#include <functional>

Dense::Dense (const Matrix &weights, const Matrix &bias,
              const ActivationFunc activ)
    : weights (weights), bias (bias), activ (activ)
{}
Matrix Dense::operator() (const Matrix &input) const
{
  // Apply the layer on the input and return the output matrix
  Matrix output = (weights * input) + bias;
  return activ (output);
}

const Matrix &Dense::get_weights () const
{
  return weights;
}

const Matrix &Dense::get_bias () const
{
  return bias;
}

const ActivationFunc &Dense::get_activation () const
{
  return activ;
}


