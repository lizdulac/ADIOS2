#ifndef HASH_H
#define HASH_H

#include <vector>

std::vector<uint8_t> stateDiffHash(void *blockData, size_t blockSize);
#endif
