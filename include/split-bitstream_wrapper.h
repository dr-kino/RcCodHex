#ifndef SPLIT_BITSTREAM_WRAPPER_H
#define SPLIT_BITSTREAM_WRAPPER_H 

typedef void CSplitBitstream;

#ifdef __cplusplus
extern "C"{
#endif

CSplitBitstream * SplitBitstream_new(char *hex_value);
void Chex2bin(const CSplitBitstream *chex_value);
void getSplitBitstream(CSplitBitstream *chex_value, char *get_value);
void SplitBitstream_delete(CSplitBitstream *p);

#ifdef __cplusplus
}
#endif

#endif // SPLIT_BITSTREAM_WRAPPER_H
