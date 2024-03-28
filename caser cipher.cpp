#include <stdio.h>
#include <ctype.h>

char shiftChar(char ch, int shift, int isEncrypt) {
  int newAscii;
  if (isalpha(ch)) {
    int offset = isEncrypt ? shift : -shift;
    newAscii = ch + offset;
    // Handle wrap around for uppercase and lowercase
    if (isupper(ch)) {
      newAscii = (newAscii - 'A') % 26 + 'A';
    } else {
      newAscii = (newAscii - 'a') % 26 + 'a';
    }
  }
  return (char)newAscii;
}

void caesarCipher(char *text, int shift, int isEncrypt) {
  for (int i = 0; text[i] != '\0'; i++) {
    text[i] = shiftChar(text[i], shift, isEncrypt);
  }
}

int main() {
  char text[100];
  int shift, choice;

  printf("Enter a message: ");
  fgets(text, sizeof(text), stdin);

  printf("Enter shift value (1-25): ");
  scanf("%d", &shift);

  printf("Encrypt (1) or Decrypt (2): ");
  scanf("%d", &choice);

  if (choice == 1) {
    caesarCipher(text, shift, 1);
    printf("Encrypted message: %s\n", text);
  } else if (choice == 2) {
    caesarCipher(text, shift, 0);
    printf("Decrypted message: %s\n", text);
  } else {
    printf("Invalid choice\n");
  }

  return 0;
}