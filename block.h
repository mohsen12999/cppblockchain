#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <functional> 

using namespace std;

size_t easy_hash(string data)
{
    hash<string> mystdhash; 
    return mystdhash(data);
}

class Block
{
    public:
        string data;
        time_t timestamp;

        size_t hash;
        size_t prev_hash;

        Block(string,size_t);
        void print();
        bool valid();
};

Block::Block(string b,size_t phash)
{
    data = b;
    timestamp = time(0);
    prev_hash = phash;
    hash= easy_hash(data+ctime(&timestamp));
}

void Block::print()
{
  cout<<"data: "<<data<<endl;
  cout<<"time: "<<ctime(&timestamp)<<endl;
  cout<<"hash: "<<hash<<endl;
  cout<<"-------------"<<endl;
}

bool Block::valid()
{
    if(hash == easy_hash(data+ctime(&timestamp)))
        return true;
    return false;
}