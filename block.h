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

string time2str(time_t t) {
	char time_str[26];
	ctime_s(time_str, sizeof time_str, &t);
	return time_str;
}

class Block
{
public:
	string data;
	time_t timestamp;

	size_t hash;
	size_t prev_hash;

	Block();
	Block(string, size_t);

	void change(string);
	void change(string, size_t);
	void print();
	bool valid();
};

Block::Block()
{
	data = "";
}

Block::Block(string b, size_t phash)
{
	data = b;
	timestamp = time(0);
	prev_hash = phash;
	hash = easy_hash(data + time2str(timestamp) + to_string(prev_hash));
}

void Block::change(string b)
{
	data = b;
	timestamp = time(0);
	hash = easy_hash(data + time2str(timestamp)+to_string(prev_hash));
}

void Block::change(string b, size_t phash)
{
	data = b;
	timestamp = time(0);
	prev_hash = phash;
	hash = easy_hash(data + time2str(timestamp) + to_string(prev_hash));
}

void Block::print()
{
	cout << "data: " << data << endl;
	cout << "time: " << time2str(timestamp) << endl;
	cout << "hash: " << hash << endl;
	cout << "perv hash: " << prev_hash << endl;
	cout << "-------------" << endl;
}

bool Block::valid()
{
	if (hash == easy_hash(data + time2str(timestamp)))
		return true;
	return false;
}