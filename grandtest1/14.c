#include <stdio.h>

int main() {
 char ch;
 printf("Enter :  ");
 scanf("%c", &ch);
 printf("Character: %c\n", ch);
 printf("Decimal value: %d\n", ch);
 printf("Hexadecimal value: %X\n", ch);
 printf("Binary value: ");
 for (int i = 7; i >= 0; i--) {
printf("%d", (ch >> i) & 1);
}
 return 0;
}
