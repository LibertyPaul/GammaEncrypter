#include <vector>

using namespace std;
#include "stuff.hpp"
#include "GammaEncrypter.hpp"



GammaEncrypter::GammaEncrypter(const vector<wchar_t> &gamma): gamma(gamma){}


vector<wchar_t> GammaEncrypter::encrypt(const vector<char> &src) const{
	size_t currentGammaPos = 0;
	vector<wchar_t> wcText = mbVtowcV(src);

	for(auto &wchar : wcText)
		wchar ^= gamma.at(currentGammaPos++ % gamma.size());

	return wcText;

}

vector<char> GammaEncrypter::decrypt(vector<wchar_t> src) const{
	size_t currentGammaPos = 0;
	for(auto &wchar : src)
		wchar ^= gamma.at(currentGammaPos++ % gamma.size());
	return wcVtombV(src);
}

