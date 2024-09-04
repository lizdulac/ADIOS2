#ifndef ADIOS2_HASH_H
#define ADIOS2_HASH_H

#include <vector>

std::vector<uint8_t> stateDiffHash(float *blockData, size_t blockSize);
#endif
