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

#include <iostream>
#include <algorithm>
#include "src/knapsack.h"
#include "src/matrix.h"

using namespace std;

int main(void){
  Knapsack k1(4, 30);

  k1.addItemtoVector(new Item(13, 23));
  k1.addItemtoVector(new Item(23, 29));
  k1.addItemtoVector(new Item(17, 27));
  k1.addItemtoVector(new Item(19, 25));

  sort(k1.itens_vector.begin(), k1.itens_vector.end(), [](const Item* lhs, const Item* rhs){ return lhs->weight < rhs->weight; });

  for(vector<Item*>::iterator it = k1.itens_vector.begin(); it != k1.itens_vector.end(); it++){
    cout << "This knapsack iten has weight: " << (*it)->weight << " and value: " << (*it)->value << endl;
  }

  Matrix m1(k1.itens_number, k1.knapsack_max_weight, &k1);

  vector<vector<int>> *auxMatrix = m1.matrix;
  for(int i=0; i<k1.knapsack_max_weight; i++){
    (*auxMatrix)[0][i] = 0;
  }

  for(int j=1; j<k1.itens_number+1; j++){
    for(int i=1; i<k1.knapsack_max_weight+1; i++){
      int value = m1.checkWeight(i, k1.itens_vector[j-1]);
      if(value > 0){
        int nextIndex = i - j;
        value += (*auxMatrix)[j-1][nextIndex];
        (*auxMatrix)[j][i] = value;
      }
      else (*auxMatrix)[j][i] = (*auxMatrix)[j-1][i];
    }
  }

  for(int i=0; i<k1.itens_number+1; i++){
    for(int j=0; j<k1.knapsack_max_weight+1; j++){
      cout << "[" << (*auxMatrix)[i][j] << "]";
    }
    cout << endl;
  }



  return 0;
}
