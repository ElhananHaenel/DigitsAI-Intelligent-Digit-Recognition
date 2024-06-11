#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"
#include <cmath>

namespace activation
{
    /**
* Applys relu algorithm
* @param matrix
* @return matrix after relu
*/

    Matrix relu (const Matrix &a);

    // Softmax activation function
    /**
 * Applys softmax algorithm
 * @param matrix
 * @return matrix after softmax algorithm
 */
    Matrix softmax (const Matrix &a);
}

#endif //ACTIVATION_H