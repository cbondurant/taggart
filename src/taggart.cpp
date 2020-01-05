#include <iostream>
#include <fstream>
#include "ID3v2Tag.hpp"

using namespace std;

int main(int argc, char * argv[]){
    if (argc > 1){
        ifstream musicFile (argv[1], fstream::in | fstream::binary);
        ID3v2Tag tag(musicFile);
        musicFile.close();
    }
}
