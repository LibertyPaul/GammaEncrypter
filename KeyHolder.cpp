#include <string>
#include <random>

using namespace std;
#include "stuff.hpp"
#include "KeyHolder.hpp"

KeyHolder::KeyHolder(){}
KeyHolder::KeyHolder(const vector<wchar_t> &key): key(key){}
KeyHolder::KeyHolder(vector<wchar_t> &&key): key(key){}

KeyHolder::KeyHolder(const string &key){
	vector<char> mbKey;
	for(const auto ch : key)
		mbKey.push_back(ch);

	this->key = mbVtowcV(mbKey);
}


void KeyHolder::generate(size_t length){
	random_device rd;
	for(size_t i = 0; i < length; ++i)
		key.push_back(rd());
}

const vector<wchar_t> &KeyHolder::get() const{
	return key;
}

