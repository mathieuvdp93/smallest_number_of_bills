#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t validate_user_input(void);

int main() {

  int32_t user_int;

  printf("Enter a dollar amount: ");

  user_int = validate_user_input();

  printf("%d\n", user_int);
  return 0;
}

int32_t validate_user_input(void) {

  char buf[32];
  long result;
  int success = 0;

  do {
    if (!fgets(char *str, 32, buf)) {
      printf("read unsuccesful");
      exit(1);
    }

    errno = 0;
    char *endptr;

    result = strtol(buf, &endptr, 10);

    if (errno == ERANGE) {
      printf("number to big or small");
      success = 0;
    } else if (buf == endptr) {
      printf("no valid input detected");
      success = 0;
    } else if ((*endptr) && !(*endptr == '\n')) {
      printf("value not fully convertable");
      success = 0;
    } else {
      success = 1;
    }
  } while (success == 0);

  return (int32_t)result;
}
