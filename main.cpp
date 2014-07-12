#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;
#include "GammaEncrypter.hpp"
#include "KeyHolder.hpp"

void man(const string &progName){
	cout << "Usage: " << endl;
	cout << progName << " srcFileName dstFileName encrypt|decrypt key" << endl;
}

int main(int argc, char **argv){
	setlocale (LC_ALL, "");

	string progName(argv[0]);
	if(argc < 5){
		man(progName);
		return 0;
	}

	string srcFileName(argv[1]);
	string dstFileName(argv[2]);
	string mode(argv[3]);
	string key(argv[4]);
	KeyHolder keyHolder(key);
	vector<wchar_t> keyV = keyHolder.get();

	cout << "Ключ '" << key << "' в десятичном представлении:" << endl;
	for(auto wchar : keyV)
		cout << wchar << endl;

	GammaEncrypter ge(keyV);

	ifstream srcFile(srcFileName, ios_base::in | ios_base::binary);
	ofstream dstFile(dstFileName, ios_base::out | ios_base::trunc | ios_base::binary);

	if(!srcFile || !dstFile)
		throw runtime_error("File openning error");

	srcFile.seekg(0, srcFile.end);
	size_t srcFileSize = srcFile.tellg();
	srcFile.seekg(0, srcFile.beg);


	if(mode == "encrypt"){
		vector<char> mbText(srcFileSize);
		srcFile.read(&mbText[0], srcFileSize);

		vector<wchar_t> encrypted = ge.encrypt(mbText);
		dstFile.write(reinterpret_cast<const char *>(&encrypted[0]), encrypted.size() * sizeof(wchar_t));
	}
	else if(mode == "decrypt"){
		if(srcFileSize % sizeof(wchar_t) != 0)
			throw runtime_error("Wrong file size");

		vector<wchar_t> src(srcFileSize / sizeof(wchar_t));
		srcFile.read(reinterpret_cast<char *>(&src[0]), srcFileSize);

		vector<char> dst = ge.decrypt(src);
		dstFile.write(&dst[0], dst.size());
	}
	else{
		man(progName);
		return 0;
	}

	cout << "Файл зашифрован." << endl;


    return 0;
}








