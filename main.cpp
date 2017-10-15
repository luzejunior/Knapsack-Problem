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
  Knapsack k1(7, 23);
  //Knapsack k1(4, 30);

  k1.addItemtoVector(new Item(1, 1));
  k1.addItemtoVector(new Item(2, 6));
  k1.addItemtoVector(new Item(5, 18));
  k1.addItemtoVector(new Item(6, 22));
  k1.addItemtoVector(new Item(7, 28));
  k1.addItemtoVector(new Item(9, 40));
  k1.addItemtoVector(new Item(11, 60));

  //k1.addItemtoVector(new Item(13, 23));
  //k1.addItemtoVector(new Item(23, 29));
  //k1.addItemtoVector(new Item(17, 27));
  //k1.addItemtoVector(new Item(19, 25));

  sort(k1.itens_vector.begin(), k1.itens_vector.end(), [](const Item* lhs, const Item* rhs){ return lhs->weight < rhs->weight; });

  // for(vector<Item*>::iterator it = k1.itens_vector.begin(); it != k1.itens_vector.end(); it++){
  //   cout << "This knapsack item has weight: " << (*it)->weight << " and value: " << (*it)->value << endl;
  // }

  Matrix m1(k1.itens_number, k1.knapsack_max_weight);

  k1.initializeMatrix(&m1);
  k1.executeAlgorithm();

  m1.printMatrix();
  //Matrix m1(k1.itens_number, k1.knapsack_max_weight, &k1);

  //m1.executeAlgorithm();



  return 0;
}
