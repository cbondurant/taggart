#include <vector>
#include <iostream>

class ID3v2TagFrame{

    char ID[5];
    size_t size;
    uint8_t statusFlags, formatFlags;
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

    ID3v2TagFrame(std::istream& in);

};
