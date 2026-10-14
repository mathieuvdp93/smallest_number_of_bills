#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t validate_user_input(void);
void discard_leftover_input(void);
void calculate_smallest_number_of_bills(int32_t);
int compare_ints(const void *, const void *);
void array_and_loop_calculation_of_bills(int32_t);

int main() {

  int32_t user_int;

  user_int = validate_user_input();

  printf("%d\n", user_int);

  calculate_smallest_number_of_bills(user_int);

  array_and_loop_calculation_of_bills(user_int);

  return 0;
}

int32_t validate_user_input(void) {

  char buf[32];
  long result;
  int success = 0;

  do {

    printf("Enter a dollar amount: ");
    if (!fgets(buf, sizeof buf, stdin)) {
      printf("read unsuccesful");
      exit(1);
    }

    if (strchr(buf, '\n') == NULL) {
      printf("your input was too many chars for the buffer\n");
      discard_leftover_input();
      continue;
    }

    errno = 0;
    char *endptr;

    result = strtol(buf, &endptr, 10);

    if (errno == ERANGE) {
      printf("number to big or small\n");
      success = 0;
    } else if (INT32_MIN > result || result > INT32_MAX) {
      printf("number to big or small for int32_t");
      success = 0;
    } else if (buf == endptr) {
      printf("no valid input detected\n");
      success = 0;
    } else if ((*endptr) && !(*endptr == '\n')) {
      printf("value not fully convertable\n");
      success = 0;
    } else {
      success = 1;
    }
  } while (success == 0);

  return (int32_t)result;
}

void discard_leftover_input() {

  int character;
  while ((character = getchar()) != '\n' && character != EOF) {
    ;
  }
}

void calculate_smallest_number_of_bills(int32_t input) {

  int32_t number_20_dollar_bills = 0;
  int32_t number_10_dollar_bills = 0;
  int32_t number_5_dollar_bills = 0;
  int32_t number_1_dollar_bills = 0;

  number_20_dollar_bills = input / 20;
  input = input % 20;
  number_10_dollar_bills = input / 10;
  input = input % 10;
  number_5_dollar_bills = input / 5;
  input = input % 5;
  number_1_dollar_bills = input;

  printf("20$ bills: %d\n", number_20_dollar_bills);
  printf("10$ bills: %d\n", number_10_dollar_bills);
  printf("5$ bills: %d\n", number_5_dollar_bills);
  printf("1$ bills: %d\n", number_1_dollar_bills);
}

void array_and_loop_calculation_of_bills(int32_t input) {

  int32_t bill_values[] = {5, 10, 1, 20};
  size_t number_of_values = sizeof(bill_values) / sizeof(bill_values[0]);

  qsort(bill_values, number_of_values, sizeof(bill_values[0]), compare_ints);

  for (size_t i = 0; i < number_of_values; i++) {
    int32_t number_of_bills = input / bill_values[i];
    printf("%d bills: %d\n", bill_values[i], number_of_bills);
    input = input % bill_values[i];
  }
}

int compare_ints(const void *a, const void *b) {

  int arg1 = *(const int *)a;
  int arg2 = *(const int *)b;

  if (arg1 < arg2)
    return 1;
  if (arg1 > arg2)
    return -1;
  return 0;
}
