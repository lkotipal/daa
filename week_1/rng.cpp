#include "rng.h"

std::random_device RD;
std::mt19937 RNG(RD());