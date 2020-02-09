#include <iostream>
#include <fstream>
#include <exception>
#include "ID3v2Tag.hpp"

using namespace std;

int main(int argc, char * argv[]){
    if (argc > 1){
        try{
            ifstream musicFile (argv[1], fstream::in | fstream::binary);
            musicFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
            ID3v2Tag tag(musicFile);
            cout << "Tag Count: " << tag.frames.size() << endl;
            musicFile.close();
        }
        catch(InvalidMagicNumber ex){
            cout << ex.what() << endl;
        }
    }
    return 0;
}
