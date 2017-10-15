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

void Matrix::createMatrix(){
  for(int i=1; i<(*matrix).size(); i++){
    for(int j=1; j<(*matrix)[0].size(); j++){
      int value = checkWeight(j, knapsack->itens_vector[i-1]);
      if(value > 0){
        int nextIndex = j - knapsack->itens_vector[i-1]->weight;
        value += (*matrix)[i-1][nextIndex];
        (*matrix)[i][j] = value;
      }
      else (*matrix)[i][j] = (*matrix)[i-1][j];
    }
  }
}

void Matrix::checkWhatItemsAreInBag(){
  int row = (*matrix).size()-1;
  int column = (*matrix)[0].size()-1;
  //cout << "This vector has " << row << " rows and " << column << " columns." << endl;
  while(row != 0){
    if((*matrix)[row][column] != (*matrix)[row-1][column]){
      column = column - knapsack->itens_vector[row-1]->weight;
      this->itensIndex.push_back(row);
      //cout << "The new column will be: " << column << endl;
    }
    row--;
  }
}

void Matrix::printItens(){
  for (vector<int>::iterator it = itensIndex.begin(); it != itensIndex.end(); it++){
    cout << "The robber will take the item with weight: " << knapsack->itens_vector[*it-1]->weight
    << " and value: " << knapsack->itens_vector[*it-1]->value << endl;
  }
}

void Matrix::executeAlgorithm(){
  createMatrix();
  printMatrix();
  checkWhatItemsAreInBag();
  printItens();
}
