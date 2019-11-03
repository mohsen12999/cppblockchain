#include "block.h"

class Blockchain
{
    public:
        Block *blocks;

        int size;
        int max;

        Blockchain(int);

        bool add_block(string);
        void print_all();
};

Blockchain::Blockchain(int n)
{
    blocks = new Block[n];
    // Block first_block("Genesis",0)
    blocks[0].change("Genesis");
    max = n;
    size = 1;
}

bool Blockchain::add_block(string data)
{
    if (size >= max)
        return false;
    //Block new_block(data, blocks[size - 1].hash);
    blocks[size].change(data, blocks[size - 1].hash);
    size++;
    return true;
}

void Blockchain::print_all()
{
    cout << "------------------" << endl;
    cout << "block has" << size << " data" << endl;
    cout << "------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        blocks[i].print();
    }
}