
#include <stdio.h>
#include <string.h>

// char a[16] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
//               0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50};

char d[16] = {0x76, 0x58, 0xB4, 0x49, 0x8D, 0x1A, 0x5F, 0x38,
              0xD4, 0x23, 0xF8, 0x34, 0xEB, 0x86, 0xF9, 0xAA};
char c[16] = {0xEF, 0xBE, 0xAD, 0xDE, 0xAD, 0xDE, 0xE1, 0xFE,
              0x37, 0x13, 0x37, 0x13, 0x66, 0x74, 0x63, 0x67};
char b[16] = {0x02, 0x06, 0x07, 0x01, 0x05, 0x0B, 0x09, 0x0E,
              0x03, 0x0F, 0x04, 0x08, 0x0A, 0x0C, 0x0D, 0x00};

char r[16] = {0};
char a[16];

int main(void)
{
     int i;
     int tab[4];

     scanf("%15s", a);

     for (i = 0; i < 16; i++)
          r[i] = (b[i] > 0xe) ? 0 : a[b[i] % 16];

     tab[0] = *(int *)c + *(int *)r;
     tab[1] = *(int *)(c + 4) + *(int *)(r + 4);
     tab[2] = *(int *)(c + 8) + *(int *)(r + 8);
     tab[3] = *(int *)(c + 12) + *(int *)(r + 12);

     tab[0] ^= *(int *)d;
     tab[1] ^= *(int *)(d + 4);
     tab[2] ^= *(int *)(d + 8);
     tab[3] ^= *(int *)(d + 12);

     if (!strncmp((const char *)a, (const char *)tab, 0x10) && !strncmp((const char *)tab, "CTF{", 4))
     {
          puts("SUCCESS");
     }
     else
     {
          puts("FAILURE");
     }
     return 0;
}
