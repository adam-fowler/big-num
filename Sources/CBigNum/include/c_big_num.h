#include <openssl/bn.h>

// if OpenSSL version is 1.1 or greater create dummy `bignum_st` type for swift code to hang off
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
struct bignum_st {
};
#endif
