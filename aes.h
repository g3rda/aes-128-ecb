// define size of block and key in words; number of rounds
#define Nb 4
#define Nk 4
#define Nr 10

// Rcon is a function that returns round constant
// Rcon array is used in aes.c, so the function is commented

// unsigned char Rcon(unsigned char n);

// xtime to calculate a*x
unsigned char xtime(unsigned char a);

// recursive xtime to calculate a*(x^power)
unsigned char power_xtime(unsigned char a, unsigned char power);

// multiplication of two numbers in GF(2^8)
unsigned char multiply(unsigned char a, unsigned char b);

// functions for encrypting
void SubBytes(unsigned char state[4][Nb]);
void ShiftRows(unsigned char state[4][Nb]);
void MixColumns(unsigned char state[4][Nb]);

// inverse functions for decrypting
void InvSubBytes(unsigned char state[4][Nb]);
void InvShiftRows(unsigned char state[4][Nb]);
void InvMixColumns(unsigned char state[4][Nb]);

// for decrypting and encrypting (the function is its own inverse)
void AddRoundKey(unsigned char state[4][Nb], unsigned char keys[Nb*(Nr+1)][4], unsigned char round);

// expand given key
void KeyExpansion(unsigned char key[4*Nk], unsigned char keys[Nb*(Nr+1)][4]);

// encrypt/decrypt 16 given bytes
void InvCipher(unsigned char state[4][Nb], unsigned char keys[Nb*(Nr+1)][4]);
void Cipher(unsigned char state[4][Nb], unsigned char keys[Nb*(Nr+1)][4]);

// encrypt/decrypt given pt/ct in ECB mode
void AES_ECB_Decrypt(unsigned char * ct, unsigned char * pt, int len, unsigned char key[4*Nk]);
void AES_ECB_Encrypt(unsigned char * pt, unsigned char * ct, int len, unsigned char key[4*Nk]);
