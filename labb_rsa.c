#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256
void printBN(char *msg, BIGNUM * a)
{
    /* Use BN_bn2hex(a) for hex string
    * Use BN_bn2dec(a) for decimal string */
    char * number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}
int main ()
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *p = BN_new();
    BIGNUM *p_1 = BN_new();
    BIGNUM *q_1 = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *res = BN_new();
    // Initialize a, b, n
    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
    BN_hex2bn(&p_1, "F7E75FDC469067FFDC4E847C51F452DE");
    BN_hex2bn(&q_1, "E85CED54AF57E53E092113E62F436F4E");
    BN_hex2bn(&e, "0D88C3");
    BN_mul(n, p, q, ctx);
    BN_mul(res, p_1, q_1, ctx);
    BN_mod_inverse(e, d, res, ctx);
    BN_generate_prime_ex(a, NBITS, 1, NULL, NULL, NULL);
    BN_dec2bn(&b, "273489463796838501848592769467194369268");
    BN_rand(n, NBITS, 0, 0);
    // res = a*b
    BN_mul(res, a, b, ctx);
    printBN("a * b = ", res);
    // res = aˆb mod n
    BN_mod_exp(res, a, b, n, ctx);
    printBN("aˆc mod n = ", res);
    return 0;
}
