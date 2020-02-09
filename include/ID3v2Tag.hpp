#pragma once
#include <vector>
#include <cstdint>
#include <iostream>
#include <exception>

#include "ID3v2TagFrame.hpp"
#include "ID3.hpp"

class InvalidMagicNumber: public std::runtime_error {

public:
    InvalidMagicNumber()
        :runtime_error("Attempted to parse tag with invalid magic number."){}
};

class ID3v2Tag{

public:
    enum flag : uint8_t {
        UNSYNC = 1<<7, // If unsyncronization is applied 1
        EXTEND_HEADER = 1<<6, // If there is an extended header segment of the tag
        EXPEREMENTAL = 1<<5, // For experemental extentions to tags
        FOOTER = 1<<4 // Tag uses a footer variable for reverse searching.
    };
private: // enum must be public and needs to come first to be defined, room for improvement here.
    flag flags;
    const char * IDENT = "ID3";
    uint8_t majorVersion, minorVersion;
    size_t size;
public:

    std::vector<ID3v2TagFrame> frames;

    ID3v2Tag(std::istream& in);

    void setFlags(ID3v2Tag::flag mask);

    bool flagIsset(ID3v2Tag::flag mask);

    uint8_t getMajorVersion();
    uint8_t getMinorVersion();
    

};

