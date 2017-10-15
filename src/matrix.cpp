/*

Author: Luzenildo de Sousa Batista Junior
E-Mail: luzejunior94@gmail.com

License:

MIT License

Copyright (c) 2017 Luzenildo de Sousa Batista Junior

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "matrix.h"

Matrix::Matrix(int row, int column, Knapsack* knapsack){
  this->matrix = new vector<vector<int>>(row+1, vector<int>(column+1));
  this->knapsack = knapsack;
}

int Matrix::checkWeight(int knapsack_weight, Item* item){
  if(knapsack_weight >= item->weight){
    return item->value;
  }
  else return -1;
}

void Matrix::printMatrix(){
  for(int i=0; i<knapsack->itens_number+1; i++){
    for(int j=0; j<knapsack->knapsack_max_weight+1; j++){
      cout << "[" << (*matrix)[i][j] << "]";
    }
    cout << endl;
  }
}

void Matrix::executeAlgorithm(){
  for(int j=1; j<knapsack->itens_number+1; j++){
    for(int i=1; i<knapsack->knapsack_max_weight+1; i++){
      int value = checkWeight(i, knapsack->itens_vector[j-1]);
      if(value > 0){
        int nextIndex = i - j;
        value += (*matrix)[j-1][nextIndex];
        (*matrix)[j][i] = value;
      }
      else (*matrix)[j][i] = (*matrix)[j-1][i];
    }
  }
  printMatrix();
}
