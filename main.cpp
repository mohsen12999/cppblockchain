#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

#include "block.h"
#include "blockchain.h"

using namespace std;

int main()
{
  std::cout << "little cpp block chain"<<endl; 

	// making block
	Block b("first", 0);
	b.print();
	cout << "befor change - validation status: " << b.valid() << endl;
	b.data = "new";
	cout << "after chabge - validation status: " << b.valid() << endl;

	// making block chain
	Blockchain bc(10);
	bc.print_all();
	bc.add_block("first");
	bc.add_block("second");
	bc.print_all();
}