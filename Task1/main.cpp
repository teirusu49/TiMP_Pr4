#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
using namespace std;
int main ()
{
    CryptoPP::SHA1 hash;

    cout <<"Name: " << hash.AlgorithmName() << endl;
    cout << "Diget size: " << hash.DigestSize() << endl;
    cout << "Block size: " << hash.BlockSize() << endl;

    string msg = "";
    string stroka;
    ifstream f("/home/teirusu/IDK/msg.txt");
    while (getline(f, stroka)) {
        msg += stroka;
    }

    vector<CryptoPP::byte> digest(hash.DigestSize());

    hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
    hash.Final(digest.data());

    cout << "Message: " << msg << endl;

    cout << "Digest: ";
    CryptoPP::StringSource(digest.data(), digest.size(), true, new CryptoPP::HexEncoder(new CryptoPP::FileSink(cout)));
    cout << endl;
    return 0;
}