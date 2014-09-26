#ifndef STUFF_HPP_INCLUDED
#define STUFF_HPP_INCLUDED

#include <vector>

vector<wchar_t> mbVtowcV(const vector<char> &mbText);//convert multi-byte text vector to wide character vector
vector<char> wcVtombV(const vector<wchar_t> &wcText);//converse to function above


#endif // STUFF_HPP_INCLUDED
