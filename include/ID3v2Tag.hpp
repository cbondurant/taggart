#include <vector>
#include <cstdint>
#include <iostream>

#include "ID3v2TagFrame.hpp"
#include "ID3.hpp"

class ID3v2Tag{

    char ident[4];
    uint8_t majorVersion, minorVersion;
    uint8_t flags;
    size_t size;
    std::vector<ID3v2TagFrame> frames;

public:
    enum flag {
        UNSYNC = 1<<7, // If unsyncronization is applied 1
        EXTEND_HEADER = 1<<6, // If there is an extended header segment of the tag
        EXPEREMENTAL = 1<<5, // For experemental extentions to tags
        FOOTER = 1<<4 // Tag uses a footer variable for reverse searching.
    };
    

    ID3v2Tag(std::istream& in);
};

