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
    BIGNUM *S = BN_new();
    BIGNUM *M = BN_new(); 
    BIGNUM *c = BN_new();
    BIGNUM *res = BN_new();
    BIGNUM *res2 = BN_new();

    // Initialize, b, n
    //PRIVATE KEY: UNKNOWN (It's private, duh)
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
    BN_hex2bn(&S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");
    //Jesse, JESSE- Did you just ask Gus launch a nuclear missile?
    BN_mod_exp(res, S, e, n, ctx);
    printBN("verified: ", res);
    //Yes mr white

    //Corrupted
    BN_hex2bn(&S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F"); //...2F -> ...3F
    //Jesse, JESSE- The signature is corrupted Jesse
    BN_mod_exp(res2, S, e, n, ctx);
    printBN("verified: ", res2);
    return 0;
}
