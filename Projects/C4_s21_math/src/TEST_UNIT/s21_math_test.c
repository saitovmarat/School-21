#include "s21_math_test.h"

void run_test(Suite *s, int *no_failde) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *no_failde = srunner_ntests_failed(runner);
  srunner_free(runner);
}
int main() {
  int no_failed = 0;
  run_test(suite_abs(), &no_failed);
  run_test(suite_fabs(), &no_failed);
  run_test(suite_ceil(), &no_failed);
  run_test(suite_exp(), &no_failed);
  run_test(suite_floor(), &no_failed);
  run_test(suite_pow(), &no_failed);
  run_test(suite_log(), &no_failed);
  run_test(suite_asin(), &no_failed);
  run_test(suite_acos(), &no_failed);
  run_test(suite_atan(), &no_failed);
  run_test(suite_fmod(), &no_failed);
  run_test(suite_sqrt(), &no_failed);
  run_test(suite_tan(), &no_failed);
  run_test(suite_sin(), &no_failed);
  run_test(suite_cos(), &no_failed);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}