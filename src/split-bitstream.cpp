#include<split-bitstream.hpp>
#include<string.h>

using namespace std;


SplitBitstream::SplitBitstream(char *hex_value){
    this->hex2bin_value = hex_value;
    cout << this->hex2bin_value << endl;
}

void SplitBitstream::getHex2bin(char *hex_value){
     //hex_value = this->hex2bin_value.c_str();
     strcpy(hex_value, this->bitstream_value.c_str());
}

void SplitBitstream::hex2bin()
{

    for(unsigned int i = 0; i<this->hex2bin_value.size(); i++)
    {
        //switch(x[i])
        switch(this->hex2bin_value[i])
        {
        case '0': this->bitstream_value = this->bitstream_value + "0000"; cout << "0000"; break;
        case '1': this->bitstream_value = this->bitstream_value + "0001"; cout << "0001"; break;
        case '2': this->bitstream_value = this->bitstream_value + "0010"; cout << "0010"; break;
        case '3': this->bitstream_value = this->bitstream_value + "0011"; cout << "0011"; break;
        case '4': this->bitstream_value = this->bitstream_value + "0100"; cout << "0100"; break;
        case '5': this->bitstream_value = this->bitstream_value + "0101"; cout << "0101"; break;
        case '6': this->bitstream_value = this->bitstream_value + "0110"; cout << "0110"; break;
        case '7': this->bitstream_value = this->bitstream_value + "0111"; cout << "0111"; break;
        case '8': this->bitstream_value = this->bitstream_value + "1000"; cout << "1000"; break;
        case '9': this->bitstream_value = this->bitstream_value + "1001"; cout << "1001"; break;
        case 'A': this->bitstream_value = this->bitstream_value + "1010"; cout << "1010"; break;
        case 'B': this->bitstream_value = this->bitstream_value + "1011"; cout << "1011"; break;
        case 'C': this->bitstream_value = this->bitstream_value + "1100"; cout << "1100"; break;
        case 'D': this->bitstream_value = this->bitstream_value + "1101"; cout << "1101"; break;
        case 'E': this->bitstream_value = this->bitstream_value + "1110"; cout << "1110"; break;
        case 'F': this->bitstream_value = this->bitstream_value + "1111"; cout << "1111"; break;
        }
    }

    cout << endl;
}
