#pragma once
#include <vector>
#include <iostream>

class ID3v2TagFrame{

private:
    char ID[5];
    size_t size;
    char *data;
public:
    enum statusFlag { // TODO: Document and possibly rename these flags
        TAG_PRESERVE = 1<<6,
        FILE_PRESERVE = 1<<5,
        READ_ONLY = 1<<4,
    };

    enum formatFlag{
        GROUPING = 1<<6,
        COMPRESSION = 1<<3,
        ENCRYPTION = 1<<2,
        UNSYNC = 1<<1,
        DATA_LEN_IND = 1<<0
    };
private:
    statusFlag statusFlags;
    formatFlag formatFlags;

public:
    ID3v2TagFrame(std::istream&);

    void setFlags(ID3v2TagFrame::statusFlag);
    void setFlags(ID3v2TagFrame::formatFlag);

    bool flagIsset(ID3v2TagFrame::statusFlag);
    bool flagIsset(ID3v2TagFrame::formatFlag);

    void getData();

};
