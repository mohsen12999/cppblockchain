#include "block.h"
// #include "blockchain.h"

#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
  cout << "Hello! This is a C++ program.\n";
  Block b("first",0);
  b.print();
  cout<<"is valid"<<b.valid()<<endl;
  b.data="new";
  cout<<"is valid"<<b.valid()<<endl;

  // Blockchain bc;
  
  return 0;
}