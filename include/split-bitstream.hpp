#ifndef SPLIT_BITSTREAM
#define SPLIT_BITSTREAM

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

//using namespace std;

class SplitBitstream{
  public:
    SplitBitstream(char hex_value);
    //virtual                  ~SplitBitstream();

    void setHex2bin(char hex_value);

    void hex2bin();

  private:
    char hex2bin_value;

};


#endif // SPLIT_BITSTREAM
