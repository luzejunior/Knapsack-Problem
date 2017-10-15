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
#include <fstream>
#include <sstream>
#include "src/knapsack.h"
#include "src/matrix.h"

using namespace std;

int main(void){
  int knapsack_max_weight, total_itens;
  string line;

  ifstream file("samples/mochila02.txt.txt");
  getline(file, line);
  stringstream ss(line);
  ss >> total_itens >> knapsack_max_weight;

  Knapsack k1(total_itens, knapsack_max_weight);

  while(getline(file, line)){
    int weight, value;
    stringstream ss1(line);
    while(ss1 >> weight >> value){
      k1.addItemtoVector(new Item(weight, value));
    }
  }

  sort(k1.itens_vector.begin(), k1.itens_vector.end(), [](const Item* lhs, const Item* rhs){ return lhs->value < rhs->value; });
  for(vector<Item*>::iterator it = k1.itens_vector.begin(); it != k1.itens_vector.end(); it++){
    cout << "This knapsack item has weight: " << (*it)->weight << " and value: " << (*it)->value << endl;
  }

  Matrix m1(k1.itens_number, k1.knapsack_max_weight);

  k1.initializeMatrix(&m1);
  k1.executeAlgorithm();

  m1.printMatrix();
  return 0;
}
