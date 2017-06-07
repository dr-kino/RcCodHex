#include "split-bitstream_wrapper.h"
#include "split-bitstream.hpp"

using namespace std;

extern "C"{

CSplitBitstream * SplitBitstream_new (char *hex_value){
    SplitBitstream *p = new SplitBitstream(hex_value);

    //p->setHex2bin(hex_value);
    
    cout << hex_value << endl;

    return (CSplitBitstream *)p;
}

void Chex2bin(const CSplitBitstream *chex_value){
    SplitBitstream *p = (SplitBitstream*)chex_value;
    //cout << sizeof() << endl;
    p->hex2bin();
    //cout << chex_value << endl;
}

void getSplitBitstream(CSplitBitstream *chex_value, char *get_value){
    SplitBitstream *p = (SplitBitstream *)chex_value; 

    p->getHex2bin(get_value);
}

void SplitBitstream_delete(CSplitBitstream *chex_value){
    SplitBitstream *p = (SplitBitstream *)chex_value; 

    delete p;
}

}
