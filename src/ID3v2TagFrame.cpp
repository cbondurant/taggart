#include <iostream>

#include "ID3v2TagFrame.hpp"
#include "ID3.hpp"

ID3v2TagFrame::ID3v2TagFrame(std::istream &in){
    in.read(ID, sizeof(ID)-1); // leave one byte free for null termination
    ID[4] = 0x0;
    size = deserializeSyncSafeInt(in, 4);
    in.read((char*)&statusFlags, sizeof(char));
    in.read((char*)&formatFlags, sizeof(char));
    data = new char[size];
    in.read(data, size);
}
