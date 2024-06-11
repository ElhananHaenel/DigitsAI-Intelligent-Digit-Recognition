# DigitsAI:-Intelligent-Digit-Recognition

This repository contains the solution for the digit recognition exercise in C++.

## Description

In this exercise, we implement a program for recognizing handwritten digits using a neural network model. The program takes an image of a digit (0 to 9) as input and returns the identified digit as output. This is achieved by constructing a neural network model, which achieves approximately 96% accuracy in digit recognition.

## Background

A neural network is a machine learning model inspired by the structure of the human brain. It consists of interconnected neurons that process and transmit electrical signals. Neural networks are used in various applications such as image recognition, natural language understanding, and more.

## Implementation Details

### Network Architecture

The network consists of four layers:

1. Input layer (28x28 nodes)
2. Hidden layer 1 (128 nodes)
3. Hidden layer 2 (64 nodes)
4. Hidden layer 3 (20 nodes)
5. Output layer (10 nodes)

Each layer performs specific operations on the input data, such as matrix multiplication, bias addition, and activation functions.

### Activation Functions

Two activation functions are implemented:

1. ReLU (Rectified Linear Unit)
2. Softmax

### Running the Program

To run the program, compile and execute `main.cpp` with the weights and biases files as command-line arguments:

```bash
./mlpnetwork w1 w2 w3 w4 b1 b2 b3 b4
```

- `w1`, `w2`, `w3`, `w4`: Paths to the weight files for each layer
- `b1`, `b2`, `b3`, `b4`: Paths to the bias files for each layer
