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

#include "knapsack.h"

Knapsack::Knapsack(int itens_number, int knapsack_max_weight){
  this->itens_number = itens_number;
  this->knapsack_max_weight = knapsack_max_weight;
}

void Knapsack::addItemtoVector(Item* item){
  this->itens_vector.push_back(item);
}

void Knapsack::initializeMatrix(Matrix* matrix){
  this->auxMatrix = (*matrix).matrix;
}

int Knapsack::checkWeight(int knapsack_weight, Item* item){
  if(knapsack_weight >= item->weight){
    return item->value;
  }
  else return -1;
}

void Knapsack::createMatrix(){
  //vector<vector<int>> *auxMatrix = (*matrix).matrix;
  for(int i=1; i<this->itens_number+1; i++){
    for(int j=1; j<this->knapsack_max_weight+1; j++){
      int value = checkWeight(j, this->itens_vector[i-1]);
      if(value > 0){
        int nextIndex = j - this->itens_vector[i-1]->weight;
        value += (*auxMatrix)[i-1][nextIndex];
        if(value >= (*auxMatrix)[i-1][j]){
          (*auxMatrix)[i][j] = value;
        }
        else (*auxMatrix)[i][j] = (*auxMatrix)[i-1][j];
      }
      else (*auxMatrix)[i][j] = (*auxMatrix)[i-1][j];
    }
  }
}

void Knapsack::checkWhatItemsAreInBag(){
  int row = this->itens_number;
  int column = this->knapsack_max_weight;
  //cout << "This vector has " << row << " rows and " << column << " columns." << endl;
  while(row != 0){
    if((*auxMatrix)[row][column] != (*auxMatrix)[row-1][column]){
      column = column - this->itens_vector[row-1]->weight;
      this->itensIndex.push_back(row);
      //cout << "The new column will be: " << column << endl;
    }
    row--;
  }
}

int Knapsack::printItens(int flag){
  int total_weight = 0;
  for (vector<int>::iterator it = itensIndex.begin(); it != itensIndex.end(); it++){
    total_weight += this->itens_vector[*it-1]->weight;
    if(flag)
      cout << "The robber will take the item with weight: " << this->itens_vector[*it-1]->weight
    << " and value: " << this->itens_vector[*it-1]->value << endl;
  }
  return total_weight;
}

void Knapsack::executeAlgorithm(){
  createMatrix();
  checkWhatItemsAreInBag();
  int total_weight = printItens(0);
  cout << "The total weight is: " << total_weight << endl;
  cout << "The total value is " << (*auxMatrix)[this->itens_number][this->knapsack_max_weight] << endl;
}
