#include <iostream>
#include <cstdint>

size_t deserializeSyncSafeInt(std::istream& in, size_t length){
    // Used to read a variable width sync safe int from a stream
    // SyncSafe ints always have the highest bit unset, and this
    // must be undone before the value can be used.
    size_t size = 0;
    uint8_t tmp = 0;
    for (int i = 0; i < length; ++i){
        in.read((char*)&tmp, sizeof(tmp));
        size = size << 7;
        size += tmp;
    }
    return size;
}

