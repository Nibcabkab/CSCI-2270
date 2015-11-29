#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main () {
  ofstream myfile;
  srand (time(NULL));
  myfile.open ("random_numbers.txt");
  string numbers = "";
  for(int i = 0; i < 10000; i++){
      numbers += to_string(rand()%10000 + 1) + "\n";
  }
  myfile << numbers + "\n";
  myfile.close();
  return 0;
}
