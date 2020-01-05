#include "ID3v2Tag.hpp"

ID3v2Tag::ID3v2Tag(std::istream& in){
    in.read(ident, sizeof(ident)-1); // Allow for null termination of the ident string
    ident[3] = 0x0;
    in.read((char*)&majorVersion, sizeof(majorVersion));
    in.read((char*)&minorVersion, sizeof(minorVersion));
    in.read((char*)&flags, sizeof(flags));
    size = deserializeSyncSafeInt(in, 4);
    int end = (int)in.tellg() + size;
    if ( flags & flag::EXTEND_HEADER ){
        // TODO: add extended header parsing
    }

    while(in.tellg() < end){
        frames.emplace_back(in);
    }
}
