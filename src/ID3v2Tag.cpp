#include <cstring>
#include <iostream>
#include "ID3v2Tag.hpp"


inline ID3v2Tag::flag operator| (ID3v2Tag::flag a, ID3v2Tag::flag b){ return static_cast<ID3v2Tag::flag>(a|b);}


ID3v2Tag::ID3v2Tag(std::istream& in){
    char ident[4];
    in.read(ident, sizeof(ident)-1); // Allow for null termination of the ident string
    ident[3] = 0x0;
    if (strcmp(ident, (const char*)IDENT)!=0){
       throw InvalidMagicNumber();
    }
    in.read((char*)&majorVersion, sizeof(majorVersion));
    in.read((char*)&minorVersion, sizeof(minorVersion));
    in.read((char*)&flags, sizeof(flags));
    size = deserializeSyncSafeInt(in, 4);
    std::cout << size << std::endl;
    int end = (int)in.tellg() + size;
    if ( flags & flag::EXTEND_HEADER ){
        // TODO: add extended header parsing
    }
    while(in.tellg() < end){
        frames.emplace_back(in);
    }
}

void ID3v2Tag::setFlags(ID3v2Tag::flag flags){
    flags = flags;
}
