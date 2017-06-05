#include "split-bitstream_wrapper.h"
#include "split-bitstream.hpp"

using namespace std;

extern "C"{

CSplitBitstream * SplitBitstream_new (char hex_value){
    cout << "passei aqui" << endl;
    SplitBitstream *p = new SplitBitstream(hex_value);

    //p->setHex2bin(hex_value);
    
    cout << hex_value << endl;

    return (CSplitBitstream *)p;
}

void Chex2bin(const CSplitBitstream *chex_value){
    cout << "passei aqui" << endl;
    SplitBitstream *p = (SplitBitstream*)chex_value;
    p->hex2bin();
    cout << chex_value << endl;
}

void SplitBitstream_delete(CSplitBitstream *chex_value){
    cout << "passei aqui" << endl;
    SplitBitstream *p = (SplitBitstream *)chex_value; 

    delete p;
}

}
