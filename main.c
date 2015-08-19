#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void to_hex(char ascii, char **out);
char * fixed_xor(char *hex, char *mask);

const char HEX_CHARS[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

int main(int argc, char *argv[])
{
  FILE *plaintext;
  plaintext = fopen("plaintext.txt", "r");
  if (plaintext == NULL)
  {
    fprintf(stderr, "plaintext.txt not found\n");
    exit(1);
  }

  char c;
  int text_length = 0;
  while((c = fgetc(plaintext)) != EOF)
  {
    text_length++;
  }
  rewind(plaintext);

  char encrypted_msg[text_length*2];
  char *key = "ICE";

  while((c = fgetc(plaintext)) != EOF)
  {
    // convert to hex (no need to "convert to decimal" - chars ARE decimals)


    // xor against key
    // plop in array
  }

  char *hex;
  to_hex('k', &hex);
  printf("k is %s\n", hex);
  return 0;
}

void to_hex(char ascii, char **out) {
  *out = (char *) malloc(3);
  (*out)[0] = HEX_CHARS[ascii/16];
  (*out)[1] = HEX_CHARS[ascii%16];
  (*out)[2] = '\0';
}

char * fixed_xor(char *hex, char *mask)
{
  mpz_t decimal;
  mpz_t decimal_mask;
  mpz_t xored_decimal;
  mpz_init_set_str (decimal, hex, 16);
  mpz_init_set_str (decimal_mask, mask, 16);
  mpz_init(xored_decimal);

  mpz_xor(xored_decimal, decimal, decimal_mask);

  char *xored_hex = mpz_get_str(NULL, 16, xored_decimal);

  printf("XORED HEX: ");
  return xored_hex;
}
