#ifndef GAMMAENCRYPTER_HPP_INCLUDED
#define GAMMAENCRYPTER_HPP_INCLUDED

class GammaEncrypter{
	vector<wchar_t> gamma;


public:

	GammaEncrypter(const vector<wchar_t> &gamma);


	vector<wchar_t> encrypt(const vector<char> &src) const;
	vector<char> decrypt(vector<wchar_t> src) const;


};

#endif // GAMMAENCRYPTER_HPP_INCLUDED
