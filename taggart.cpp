#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>
#include <iomanip>

using namespace std;

int main(int argc, char * argv[]){
    if (argc > 1){
        ifstream musicFile (argv[1], fstream::in | fstream::binary);
        char ident[4];
        musicFile.read(ident, 3); // one less than ident to allow for null termination
        ident[3] = 0x00;

        char majorVersion;
        musicFile.read((char*)&majorVersion, sizeof(majorVersion));

        char minorVersion;
        musicFile.read((char*)&minorVersion, sizeof(minorVersion)); 

        uint8_t flags;
        musicFile.read((char*)&flags, sizeof(flags));

        unsigned int size = 0;
        uint8_t sizeBlock[4];
        musicFile.read((char*)&sizeBlock, sizeof(sizeBlock));


        // To prevent 11 set bits in a row (the start of frame headers in mp3)
        // the 7th bit of each byte is unset and must be removed to reconstruct the correct size
        for (uint8_t &part : sizeBlock){
            size = size << 7;
            size += part;
        }

        int tagEnd = musicFile.tellg();
        tagEnd += size;

        if ( flags & 1<<7 ){ // Extended header flag
            // Parse extended header
        }
        
        while(musicFile.tellg() < tagEnd){ // Till we reach end of the tag
            char frameID[4];
            musicFile.read(frameID, sizeof(frameID));
            uint8_t frameSizeBlock[4];
            int frameSize = 0; 
            musicFile.read((char*)frameSizeBlock, sizeof(frameSizeBlock));
                
            for (uint8_t &part : frameSizeBlock){
                frameSize = frameSize << 7;
                frameSize += part;
            }
            uint16_t tagFlags;
            musicFile.read((char*)&tagFlags, sizeof(tagFlags));

            char *data = new char[frameSize];
            musicFile.read(data, frameSize);
            cout << "ID: " << frameID << endl;
            cout << "Size: " << frameSize << endl;
            if (strcmp(frameID, "TXXX") == 0){
                char *val = 0;
                for (char* i = data; true; ++i){
                    if (*i == 0){
                        val = i + 1;
                        break;
                    }
                }
                cout << "Desc: " << (data+1) << endl;
                cout << "Value: " << (val) << endl;
            }
            cout << endl;
            delete[] data;
        }
         
        cout << "Magic: " << ident << endl;
        cout << "Major: " << static_cast<int>(majorVersion) << endl;
        cout << "Minor: " << static_cast<int>(minorVersion) << endl;
        cout << "Size: " << size << endl;
    }
}
