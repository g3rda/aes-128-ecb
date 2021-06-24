// stdio.h for printf()
#include <stdio.h>

#include "aes.h"

static int size_pt_e = 256;
//static int size_ct_d = 256;


int main(){

  // set the key value
  unsigned char key[4*Nk]= {0x3a, 0x7e, 0x15, 0x56, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

  // set pt value for encryption
  unsigned char pt_e[] = {0x22, 0x48, 0x6f, 0x77, 0x6c, 0x20, 0x68, 0x6f, 0x77, 0x6c, 0x20, 0x67, 0x61, 0x72, 0x67, 0x6c, 0x65, 0x20, 0x68, 0x6f, 0x77, 0x6c, 0x20, 0x67, 0x61, 0x72, 0x67, 0x6c, 0x65, 0x20, 0x68, 0x6f, 0x77, 0x6c, 0x20, 0x68, 0x6f, 0x77, 0x6c, 0x20, 0x68, 0x6f, 0x77, 0x6c, 0x20, 0x67, 0x61, 0x72, 0x67, 0x6c, 0x65, 0x20, 0x68, 0x6f, 0x77, 0x6c, 0x20, 0x67, 0x61, 0x72, 0x67, 0x6c, 0x65, 0x20, 0x68, 0x6f, 0x77, 0x6c, 0x20, 0x68, 0x6f, 0x77, 0x6c, 0x20, 0x67, 0x61, 0x72, 0x67, 0x6c, 0x65, 0x20, 0x67, 0x61, 0x72, 0x67, 0x6c, 0x65, 0x20, 0x68, 0x6f, 0x77, 0x6c, 0x20, 0x67, 0x61, 0x72, 0x67, 0x6c, 0x65, 0x20, 0x67, 0x61, 0x72, 0x67, 0x6c, 0x65, 0x20, 0x67, 0x61, 0x72, 0x67, 0x6c, 0x65, 0x20, 0x68, 0x6f, 0x77, 0x6c, 0x20, 0x73, 0x6c, 0x75, 0x72, 0x72, 0x70, 0x20, 0x75, 0x75, 0x75, 0x75, 0x72, 0x67, 0x68, 0x20, 0x73, 0x68, 0x6f, 0x75, 0x6c, 0x64, 0x20, 0x68, 0x61, 0x76, 0x65, 0x20, 0x61, 0x20, 0x67, 0x6f, 0x6f, 0x64, 0x20, 0x74, 0x69, 0x6d, 0x65, 0x2e, 0x20, 0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x20, 0x72, 0x65, 0x70, 0x65, 0x61, 0x74, 0x73, 0x2e, 0x20, 0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x63, 0x61, 0x70, 0x74, 0x61, 0x69, 0x6e, 0x20, 0x73, 0x70, 0x65, 0x61, 0x6b, 0x69, 0x6e, 0x67, 0x2c, 0x20, 0x73, 0x6f, 0x20, 0x73, 0x74, 0x6f, 0x70, 0x20, 0x77, 0x68, 0x61, 0x74, 0x65, 0x76, 0x65, 0x72, 0x20, 0x79, 0x6f, 0x75, 0x27, 0x72, 0x65, 0x20, 0x64, 0x6f, 0x69, 0x6e, 0x67, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x70, 0x61, 0x79, 0x20, 0x61, 0x74, 0x74, 0x65, 0x6e, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x22};

  unsigned char ct_e[size_pt_e];

  AES_ECB_Encrypt(pt_e, ct_e, size_pt_e, key);

  printf("Ciphertext: {");
  for (int i = 0; i<size_pt_e; i++){
    printf("%d", ct_e[i]);
    if(i!=size_pt_e-1) printf(", ");
  }
  printf("}\n");

  // uncomment to decrypt the same text
  /*
  // set ct value for decryption
  unsigned char ct_d[] = {0x54, 0xb4, 0xeb, 0x8b, 0x1c, 0x89, 0x79, 0xf8, 0xb3, 0xb1, 0x3e, 0x4f, 0x94, 0x29, 0x30, 0x9a, 0xdb, 0xb7, 0xcb, 0x16, 0x95, 0x28, 0x86, 0x25, 0x99, 0x6e, 0xab, 0x9b, 0xd0, 0xe5, 0x0b, 0xac, 0xb5, 0xb9, 0x77, 0x87, 0x9d, 0x38, 0x26, 0xcb, 0x44, 0xf9, 0xe4, 0xe3, 0x1a, 0xdc, 0x2c, 0x28, 0xeb, 0xcd, 0x8c, 0xca, 0xf5, 0xf4, 0x0a, 0x1a, 0x98, 0xfb, 0x6c, 0x54, 0x99, 0xf2, 0x5a, 0xc7, 0xc3, 0x2b, 0x3c, 0xc3, 0x89, 0xe0, 0x26, 0x5b, 0xab, 0xb1, 0x19, 0x0a, 0xc1, 0x82, 0x2f, 0xf6, 0x22, 0x3d, 0x12, 0xa6, 0xe8, 0xc8, 0xdd, 0xdf, 0x9f, 0xcb, 0x2d, 0x98, 0xd0, 0x18, 0x3f, 0x46, 0x82, 0x0e, 0x32, 0x22, 0x35, 0x0f, 0x1b, 0xdc, 0x92, 0x46, 0xf2, 0xe3, 0x65, 0x28, 0x69, 0x53, 0x79, 0xdb, 0xa9, 0x84, 0x93, 0x1a, 0x16, 0xf0, 0x6b, 0x31, 0xff, 0xdf, 0x40, 0x20, 0x41, 0x1c, 0xc4, 0xa1, 0xbb, 0x00, 0xe5, 0xb5, 0xfd, 0x54, 0x91, 0x92, 0xe9, 0xf6, 0x49, 0xb7, 0xc6, 0xee, 0xc0, 0x7d, 0x42, 0x38, 0x47, 0xbc, 0x8b, 0xe8, 0xdc, 0xdd, 0x52, 0x5f, 0x05, 0x4c, 0xd7, 0x71, 0xee, 0x16, 0xdb, 0xde, 0x4a, 0x13, 0x2d, 0xcb, 0xc7, 0x07, 0x38, 0x88, 0x42, 0x4f, 0x6a, 0xa5, 0x0d, 0xb1, 0x55, 0xd3, 0x0d, 0x26, 0x3f, 0x12, 0x1d, 0xd6, 0x92, 0x7a, 0xb1, 0x45, 0xd0, 0xb0, 0x5d, 0x15, 0x43, 0xeb, 0xc9, 0x52, 0x96, 0x41, 0x6c, 0xbc, 0xeb, 0x5f, 0x49, 0x48, 0x2d, 0x78, 0x7f, 0x10, 0x3f, 0xcb, 0x35, 0x8c, 0xb9, 0xa9, 0x75, 0xd3, 0x9f, 0xd0, 0xc1, 0x4f, 0x35, 0x78, 0x63, 0x8b, 0xe5, 0x4d, 0xbc, 0x2b, 0xd2, 0xf6, 0x4c, 0x7b, 0xec, 0x7c, 0x6d, 0x1e, 0xa5, 0x18, 0x7e, 0x62, 0x9d, 0x97, 0x2f, 0xa1, 0x8b, 0xf7, 0x1f, 0xaa, 0x10, 0x56, 0x9f, 0x1c, 0xdf, 0x9c};

  unsigned char pt_d[size_ct_d];

  AES_ECB_Decrypt(ct_d, pt_d, size_ct_d, key);

  printf("\nPlaintext: ");
  for(int i = 0; i<size_ct_d; i++){
    printf("%c", pt_d[i]);
  }
  printf("\n");
  */

  return 0;
}
