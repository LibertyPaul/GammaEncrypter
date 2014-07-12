#ifndef KEYHOLDER_HPP_INCLUDED
#define KEYHOLDER_HPP_INCLUDED

class KeyHolder{
	vector<wchar_t> key;

public:

	KeyHolder();
	KeyHolder(const vector<wchar_t> &key);
	KeyHolder(const string &key);

	void generate(size_t length);

	vector<wchar_t> get() const;
};

#endif // KEYHOLDER_HPP_INCLUDED
