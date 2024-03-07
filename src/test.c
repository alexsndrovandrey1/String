#include <check.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

// strlen

START_TEST(strlen1) {
  const char *str = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen2) {
  const char *str = "Hello, School 21";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen3) {
  const char *str =
      "A string that consists of many words in order to make sure that the "
      "function works as it should.";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen4) {
  const char *str = "A string with a null character: \0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen5) {
  const char *str = "A string with a newline character: \n";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen6) {
  const char *str = "A line with a tab character: \t";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen7) {
  const char *str =
      "          A line in which there are spaces at the beginning";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen8) {
  const char *str = "A string with spaces at the end           ";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

// strerror
START_TEST(strerror1) {
  for (int i = 0; i < 135; i++) {
    char *res1 = s21_strerror(i);
    char *res2 = strerror(i);
    ck_assert_str_eq(res1, res2);
  }
}
END_TEST

START_TEST(strerror2) {
  const char *res1 = s21_strerror(-1);
  char *res2 = strerror(-1);
  ck_assert_str_eq(res1, res2);
}
END_TEST

// strstr
START_TEST(strstr1) {
  const char *haystack = "Hello, world!";
  const char *needle = "Hello";
  const char *res1 = s21_strstr(haystack, needle);
  const char *res2 = strstr(haystack, needle);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strstr2) {
  const char *haystack = "Hello, world!";
  const char *needle = "world!";
  const char *res1 = s21_strstr(haystack, needle);
  const char *res2 = strstr(haystack, needle);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strstr3) {
  const char *haystack = "QwertyQwsedrfr";
  const char *needle = "zz";
  const char *res1 = s21_strstr(haystack, needle);
  const char *res2 = strstr(haystack, needle);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strstr4) {
  const char *haystack = "QwertyQwsedrfr";
  const char *needle = "Qw";
  const char *res1 = s21_strstr(haystack, needle);
  const char *res2 = strstr(haystack, needle);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strstr5) {
  const char *haystack = "QwertyQwsedrfr";
  const char *needle = "Qw";
  const char *res1 = s21_strstr(haystack, needle);
  const char *res2 = strstr(haystack, needle);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strstr6) {
  const char *haystack = "hi, my username is leatrice!";
  const char *needle = " leat";
  const char *res1 = s21_strstr(haystack, needle);
  const char *res2 = strstr(haystack, needle);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strstr7) {
  const char *haystack = "hi, my username is leatrice!";
  const char *needle = " leat";
  const char *res1 = s21_strstr(haystack, needle);
  const char *res2 = strstr(haystack, needle);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strstr8) {
  const char *haystack = "hi, my username is leatrice!";
  const char *needle = "";
  const char *res1 = s21_strstr(haystack, needle);
  const char *res2 = strstr(haystack, needle);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// strrchr

START_TEST(strrchr1) {
  char *str = "Hello!";
  int sub = 'z';
  char *res1 = s21_strrchr(str, sub);
  char *res2 = strrchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strrchr2) {
  char *str = "";
  int sub = 'n';
  char *res1 = s21_strrchr(str, sub);
  char *res2 = strrchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strrchr3) {
  char *str = "fgh";
  int sub = 'r';
  char *res1 = s21_strrchr(str, sub);
  char *res2 = strrchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strrchr4) {
  char *str = " ";
  int sub = 'o';
  char *res1 = s21_strrchr(str, sub);
  char *res2 = strrchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}

START_TEST(strrchr5) {
  char *str = "This string contains \0 a null character";
  int sub = '\0';
  char *res1 = s21_strrchr(str, sub);
  char *res2 = strrchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strrchr6) {
  char *str = "This string has multiple spaces before the text.";
  int sub = 'b';
  char *res1 = s21_strrchr(str, sub);
  char *res2 = strrchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strrchr7) {
  char *str = "Now or never!";
  int sub = '!';
  char *res1 = s21_strrchr(str, sub);
  char *res2 = strrchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strrchr8) {
  char *str =
      "When you start thinking a lot about your past, it becomes your present "
      "and you can nott see your future without it.";
  int sub = 'W';
  char *res1 = s21_strrchr(str, sub);
  char *res2 = strrchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strrchr9) {
  char *str = "ppppppppPPPppppWppppW";
  int sub = 'P';
  char *res1 = s21_strrchr(str, sub);
  char *res2 = strrchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// memchr

START_TEST(memchr1) {
  char s[] = "Hello, world!";
  char *result1 = s21_memchr(s, 'w', s21_strlen(s));
  char *result2 = memchr(s, 'w', strlen(s));
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(memchr2) {
  char s[] = "Hello, world!";
  char *result1 = s21_memchr(s, 'z', s21_strlen(s));
  char *result2 = memchr(s, 'z', strlen(s));
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(memchr3) {
  char s[] = "Now or never!";
  char *result1 = s21_memchr(s, '!', s21_strlen(s));
  char *result2 = memchr(s, '!', strlen(s));
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(memchr4) {
  char s[] = "Hello, world!";
  char *result1 = memchr(s, 'o', 5);
  char *result2 = s21_memchr(s, 'o', 5);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(memchr5) {
  char s[] = "Qwerty ytnhf jjhflkhf";
  char *result1 = memchr(s, 'Q', 0);
  char *result2 = s21_memchr(s, 'Q', 0);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

// strchr
START_TEST(strchr1) {
  char *str = "Now or never!";
  int sub = '!';
  char *res1 = s21_strchr(str, sub);
  char *res2 = strchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strchr2) {
  char *str = "Now or never!";
  int sub = 'N';
  char *res1 = s21_strchr(str, sub);
  char *res2 = strchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strchr3) {
  char *str = "!Now or never!";
  int sub = '!';
  char *res1 = s21_strchr(str, sub);
  char *res2 = strchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strchr4) {
  char *str = "qqqqQqqqqqqQqqqq";
  int sub = 'Q';
  char *res1 = s21_strchr(str, sub);
  char *res2 = strchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strchr5) {
  char *str = "qqqqQqqqqqqQqqqq";
  int sub = 'q';
  char *res1 = s21_strchr(str, sub);
  char *res2 = strchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strchr6) {
  char *str = "Hi, world)))";
  int sub = '\0';
  char *res1 = s21_strchr(str, sub);
  char *res2 = strchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strchr7) {
  char *str = "Hi, wo\nrld)))";
  int sub = '\n';
  char *res1 = s21_strchr(str, sub);
  char *res2 = strchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strchr8) {
  char *str = "Hi, world)\t))";
  int sub = '\t';
  char *res1 = s21_strchr(str, sub);
  char *res2 = strchr(str, sub);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// strtok
START_TEST(strtok1) {
  char str[] = "";
  char delim[] = " ,.";
  char *res1, *res2;
  res1 = strtok(str, delim);
  res2 = s21_strtok(str, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strtok2) {
  char str[] = " ,.";
  char delim[] = " ,.";
  char *res1, *res2;
  res1 = strtok(str, delim);
  res2 = s21_strtok(str, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strtok3) {
  char str[] = "token";
  char delim[] = " ,.";
  char *res1, *res2;
  res1 = strtok(str, delim);
  res2 = s21_strtok(str, delim);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strtok4) {
  char str[] = "This is a string, with some commas.";
  char delim[] = " ,.";
  char *res1, *res2;
  res1 = strtok(str, delim);
  res2 = s21_strtok(str, delim);
  while (res1 != NULL && res2 != NULL) {
    ck_assert_str_eq(res1, res2);
    res2 = s21_strtok(NULL, delim);
    res1 = strtok(NULL, delim);
  }
  ck_assert_ptr_eq(res2, NULL);
}
END_TEST

START_TEST(strtok5) {
  char str[] = " ,,., ";
  char delim[] = " ,.";
  char *res1, *res2;
  res1 = strtok(str, delim);
  res2 = s21_strtok(str, delim);
  while (res1 != NULL && res2 != NULL) {
    ck_assert_str_eq(res1, res2);
    res1 = s21_strtok(NULL, delim);
    res2 = strtok(NULL, delim);
  }
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strtok6) {
  char str[] = ",";
  char delim[] = " ,.";
  char *res1, *res2;
  res1 = strtok(str, delim);
  res2 = s21_strtok(str, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(strtok7) {
  char str[] = "!";
  char delim[] = "\0";
  char *res1, *res2;
  res1 = strtok(str, delim);
  res2 = s21_strtok(str, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// memcmp
START_TEST(memcmp1) {
  int res1 = s21_memcmp("", "", 0);
  int res2 = memcmp("", "", 0);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp2) {
  int res1 = s21_memcmp("qwert", "qwe", 3);
  int res2 = memcmp("qwert", "qwe", 3);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp3) {
  int res1 = s21_memcmp("1234", "1233", 4);
  int res2 = memcmp("1234", "1233", 4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp4) {
  int res1 = s21_memcmp("werp", "we", 2);
  int res2 = memcmp("werp", "we", 2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp5) {
  int res1 = s21_memcmp("a12we", "b12we", 4);
  int res2 = memcmp("a12we", "b12we", 4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp6) {
  int res1 = s21_memcmp("fgh", "r", 1);
  int res2 = memcmp("fgh", "r", 1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp7) {
  int res1 = s21_memcmp("", "n", 1);
  int res2 = memcmp("", "n", 1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(memcmp8) {
  int res1 = s21_memcmp("ab", "dc", 2);
  int res2 = memcmp("ab", "bc", 2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// memcpy
START_TEST(memcpy1) {
  int src[] = {1, 2, 3, 4, 5};
  int dest[5];
  size_t n = 5 * sizeof(int);

  memcpy(dest, src, n);
  s21_memcpy(dest, src, n);

  ck_assert_mem_eq(dest, src, n);
}
END_TEST

START_TEST(memcpy2) {
  char src[] = "";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy3) {
  char src[] = "x";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy4) {
  char src[] = "this is a test";
  s21_size_t kByte = sizeof(src);
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy5) {
  char src[] = "this is a very large array";
  s21_size_t kByte = 10;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy6) {
  char src[] = "this\0is\0a\0test";
  s21_size_t kByte = sizeof(src);
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy7) {
  char src[] = "I hate memcmp";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

// strncat
START_TEST(strncat1) {
  char src[] = "qwerty";
  char res[10] = "";
  char res2[10] = "";
  s21_size_t n = 0;
  s21_strncat(res, src, n);
  strncat(res2, src, n);
  ck_assert_mem_ge(res, res2, n);
}
END_TEST

START_TEST(strncat2) {
  char src[] = "";
  char res[10] = "sd";
  char res2[10] = "sd";
  s21_size_t n = 0;
  s21_strncat(res, src, n);
  strncat(res2, src, n);
  ck_assert_mem_ge(res, res2, n);
}
END_TEST

START_TEST(strncat3) {
  char src[] = "tEsT";
  char res[10] = "";
  char res2[10] = "";
  s21_size_t n = 4;
  s21_strncat(res, src, n);
  strncat(res2, src, n);
  ck_assert_mem_ge(res, res2, n);
}
END_TEST

START_TEST(strncat4) {
  char src[] = "- work)";
  char res[20] = "function";
  char res2[20] = "function";
  s21_size_t n = 7;
  s21_strncat(res, src, n);
  strncat(res2, src, n);
  ck_assert_mem_eq(res, res2, s21_strlen(res2));
}
END_TEST

START_TEST(strncat5) {
  char src[] = "test";
  char res[10] = "145";
  char res2[10] = "145";
  s21_size_t n = 10;
  s21_strncat(res, src, n);
  strncat(res2, src, n);
  ck_assert_mem_eq(res, res2, s21_strlen(res2));
}
END_TEST

START_TEST(strncat6) {
  char src[] = "test";
  char res[10] = "145";
  char res2[10] = "145";
  s21_size_t n = 2;
  s21_strncat(res, src, n);
  strncat(res2, src, n);
  ck_assert_mem_eq(res, res2, s21_strlen(res2));
}
END_TEST

// strncmp
START_TEST(strncmp1) {
  const char *str1 = "hello";
  const char *str2 = "world";
  const int n = 5;
  const int res1 = strncmp("hello", "world", 5);
  const int res2 = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strncmp2) {
  const char *str1 = "hello";
  const char *str2 = "hello";
  const int n = 5;
  const int res1 = strncmp("hello", "hello", 5);
  const int res2 = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strncmp3) {
  const char *str1 = "hi";
  const char *str2 = "string.h";
  const int n = 5;
  const int res1 = strncmp("hi", "string.h", 5);
  const int res2 = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strncmp4) {
  const char *str1 = "string.h";
  const char *str2 = "hi";
  const int n = 5;
  const int res1 = strncmp("string.h", "hi", 5);
  const int res2 = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strncmp5) {
  const char *str1 = "";
  const char *str2 = "hi";
  const int n = 5;
  const int res1 = strncmp("", "hi", 5);
  const int res2 = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strncmp6) {
  const char *str1 = "string.h";
  const char *str2 = "";
  const int n = 5;
  const int res1 = strncmp("string.h", "", 5);
  const int res2 = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strncmp7) {
  const char *str1 = "string.h";
  const char *str2 = "qwwewerwt";
  const int n = 5;
  const int res1 = strncmp("string.h", "qwwewerwt", 5);
  const int res2 = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strncmp8) {
  const char *str1 = "hi";
  const char *str2 = "an";
  const int n = 10;
  const int res1 = strncmp("hi", "an", 10);
  const int res2 = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// strncpy
START_TEST(strncpy1) {
  char src[] = "source string";
  char dest[20] = {0};
  char dest2[20] = {0};
  s21_strncpy(dest, src, 6);
  strncpy(dest2, src, 6);
  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(strncpy2) {
  char src[] = "source";
  char dest[10] = {0};
  char dest2[10] = {0};
  s21_strncpy(dest, src, 10);
  strncpy(dest2, src, 10);
  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(strncpy3) {
  char src[] = "";
  char dest[5] = {0};
  char dest2[5] = {0};
  s21_strncpy(dest, src, 5);
  strncpy(dest2, src, 5);
  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(strncpy4) {
  char src[] = "source string";
  char dest[20] = {0};
  char dest2[20] = {0};
  s21_strncpy(dest, src, s21_strlen(src));
  strncpy(dest2, src, s21_strlen(src));
  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(strncpy5) {
  char src[] = "123";
  char dest[7] = "123";
  char dest2[7] = "123";
  s21_size_t n = 2;
  s21_strncpy(dest, src, n);
  strncpy(dest2, src, n);
  ck_assert_str_eq(dest, dest2);
}
END_TEST

// strcspn
START_TEST(strcspn1) {
  const char *str1 = "qwe";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn2) {
  const char *str1 = "";
  const char *str2 = "qwe";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn3) {
  const char *str1 = "aaaaaa";
  const char *str2 = "a";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn4) {
  const char *str1 = "abcdefg";
  const char *str2 = "hijlhbl";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn5) {
  const char *str1 = "abcdefg";
  const char *str2 = "cdefgh";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn6) {
  const char *str1 = "abcdefg";
  const char *str2 = "cba";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn7) {
  const char *str1 = "abcde";
  const char *str2 = "axyz";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// strpbrk
START_TEST(strpbrk1) {
  char *str1 = "hello";
  const char *str2 = "lo";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk2) {
  char *str1 = "hello";
  const char *str2 = "z";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk3) {
  char *str1 = "";
  const char *str2 = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk4) {
  char *str1 = "qwerty";
  const char *str2 = "qw";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk5) {
  char *str1 = "hello";
  const char *str2 = "o";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk6) {
  char *str1 = "qqqqqqqqqqqqqq";
  const char *str2 = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk7) {
  char *str1 = "worlld";
  const char *str2 = "ll";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

// memset
START_TEST(memset1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char replace = 'g';
  s21_size_t n = s21_strlen(str1);
  s21_memset(str1, replace, n);
  memset(str2, replace, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset2) {
  char str1[50] = "kaif";
  char str2[50] = "kaif";
  ck_assert_str_eq(memset(str1, '*', 6), s21_memset(str2, '*', 6));
}
END_TEST

START_TEST(memset3) {
  char str1[50] = "stringi_kaiff";
  char str2[50] = "stringi_kaiff";
  ck_assert_str_eq(memset(str1, '#', 3), s21_memset(str2, '#', 3));
  ck_assert_str_eq(memset(str1, '|', 1), s21_memset(str2, '|', 1));
}
END_TEST

START_TEST(memset4) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char replace = 'g';
  s21_size_t n = sizeof(str1);
  s21_memset(str1, replace, n);
  memset(str2, replace, n);
  ck_assert_mem_eq(str1, str2, n);
}
END_TEST

// toupper
START_TEST(toupper1) {
  const char *str = "hello";
  char *res1 = s21_to_upper(str);
  int res2 = toupper(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
END_TEST

START_TEST(toupper2) {
  const char *str = "WORLD";
  char *res1 = s21_to_upper(str);
  int res2 = toupper(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
END_TEST

START_TEST(toupper3) {
  const char *str = "Hello World";
  char *res1 = s21_to_upper(str);
  int res2 = toupper(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
END_TEST

START_TEST(toupper4) {
  const char *str = "QwErTyUiO";
  char *res1 = s21_to_upper(str);
  int res2 = toupper(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
START_TEST(toupper5) {
  const char *str = "";
  char *res1 = s21_to_upper(str);
  int res2 = toupper(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
END_TEST

START_TEST(toupper6) {
  const char *str = "123!@#";
  char *res1 = s21_to_upper(str);
  int res2 = toupper(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
END_TEST

// tolower
START_TEST(tolower1) {
  const char *str = "hello";
  char *res1 = s21_to_lower(str);
  int res2 = tolower(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
END_TEST

START_TEST(tolower2) {
  const char *str = "WORLD";
  char *res1 = s21_to_lower(str);
  int res2 = tolower(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
END_TEST

START_TEST(tolower3) {
  const char *str = "Hello World";
  char *res1 = s21_to_lower(str);
  int res2 = tolower(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
END_TEST

START_TEST(tolower4) {
  const char *str = "QwErTyUiO";
  char *res1 = s21_to_lower(str);
  int res2 = tolower(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
START_TEST(tolower5) {
  const char *str = "";
  char *res1 = s21_to_lower(str);
  int res2 = tolower(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
END_TEST

START_TEST(tolower6) {
  const char *str = "123!@#";
  char *res1 = s21_to_lower(str);
  int res2 = tolower(*str);
  ck_assert_int_eq(*res1, res2);
  free(res1);
}
END_TEST

// insert

START_TEST(insert1) {
  const char *src = "";
  const char *str = "";
  s21_size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);

  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(insert2) {
  const char *src = "world";
  const char *str = "Hello, ";
  s21_size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);

  ck_assert_str_eq(result, "Hello, world");
  free(result);
}
END_TEST

START_TEST(insert3) {
  const char *src = "Hello, world";
  const char *str = "beautiful ";
  s21_size_t start_index = 7;

  char *result = s21_insert(src, str, start_index);

  ck_assert_str_eq(result, "Hello, beautiful world");
  free(result);
}
END_TEST

START_TEST(insert4) {
  const char *src = "Hello, ";
  const char *str = "world";
  s21_size_t start_index = 7;

  char *result = s21_insert(src, str, start_index);

  ck_assert_str_eq(result, "Hello, world");
  free(result);
}
END_TEST

// trim
START_TEST(trim1) {
  char str[] = " Hello World ";
  char trim_chars[] = " ";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, "Hello World");
}
END_TEST

START_TEST(trim2) {
  char str[] = "This is a test";
  char trim_chars[] = "ti";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, "Ths s a es");
}
END_TEST

START_TEST(trim3) {
  char str[] = "AAAAAAA";
  char trim_chars[] = "A";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, "AAAAA");
}
END_TEST

START_TEST(trim4) {
  char str[] = "12345";
  char trim_chars[] = "6789";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, "12345");
}
END_TEST

START_TEST(trim5) {
  char str[] = "SCHOOL21 STRINGPLUS";
  char trim_chars[] = "S";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, "CHOOL21 STRINGPLU");
}
END_TEST

START_TEST(trim6) {
  char str[] = "BAAAAAAB";
  char trim_chars[] = "B";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, "AAAAAA");
}
END_TEST

// sprintf
START_TEST(sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf13) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf21) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf22) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf23) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf27) {
  const wchar_t wch = L'Я';
  char result[10];
  s21_sprintf(result, "%lc", wch);
  ck_assert_str_eq(result, "");
}
END_TEST

START_TEST(sprintf28) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15s";
  char *val = "21 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf34) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%s";
  char *val =
      "21 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%s%s%s%s";
  char *val =
      "21 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));
  ck_assert_str_eq(str1, str2);
}

START_TEST(sprintf36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf45) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf46) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %f %lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_suite(void) {
  Suite *s = suite_create("Library tests");
  // strlen
  TCase *tc1 = tcase_create("leatrice, strlen");
  suite_add_tcase(s, tc1);
  tcase_add_test(tc1, strlen1);
  tcase_add_test(tc1, strlen2);
  tcase_add_test(tc1, strlen3);
  tcase_add_test(tc1, strlen4);
  tcase_add_test(tc1, strlen5);
  tcase_add_test(tc1, strlen6);
  tcase_add_test(tc1, strlen7);
  tcase_add_test(tc1, strlen8);
  // strerror
  TCase *tc2 = tcase_create("leatrice, strerror");
  suite_add_tcase(s, tc2);
  tcase_add_test(tc2, strerror1);
  tcase_add_test(tc2, strerror2);
  // strstr
  TCase *tc3 = tcase_create("leatrice, strstr");
  suite_add_tcase(s, tc3);
  tcase_add_test(tc3, strstr1);
  tcase_add_test(tc3, strstr2);
  tcase_add_test(tc3, strstr3);
  tcase_add_test(tc3, strstr4);
  tcase_add_test(tc3, strstr5);
  tcase_add_test(tc3, strstr6);
  tcase_add_test(tc3, strstr7);
  tcase_add_test(tc3, strstr8);
  // strrchr
  TCase *tc4 = tcase_create("leatrice, strrchr");
  suite_add_tcase(s, tc4);
  tcase_add_test(tc4, strrchr1);
  tcase_add_test(tc4, strrchr2);
  tcase_add_test(tc4, strrchr3);
  tcase_add_test(tc4, strrchr4);
  tcase_add_test(tc4, strrchr5);
  tcase_add_test(tc4, strrchr6);
  tcase_add_test(tc4, strrchr7);
  tcase_add_test(tc4, strrchr8);
  tcase_add_test(tc4, strrchr9);
  // memchr
  TCase *tc5 = tcase_create("leatrice, memchr");
  suite_add_tcase(s, tc5);
  tcase_add_test(tc5, memchr1);
  tcase_add_test(tc5, memchr2);
  tcase_add_test(tc5, memchr3);
  tcase_add_test(tc5, memchr4);
  tcase_add_test(tc5, memchr5);
  // strchr
  TCase *tc6 = tcase_create("leatrice, strchr");
  suite_add_tcase(s, tc6);
  tcase_add_test(tc6, strchr1);
  tcase_add_test(tc6, strchr2);
  tcase_add_test(tc6, strchr3);
  tcase_add_test(tc6, strchr4);
  tcase_add_test(tc6, strchr5);
  tcase_add_test(tc6, strchr6);
  tcase_add_test(tc6, strchr7);
  tcase_add_test(tc6, strchr8);
  TCase *tc7 = tcase_create("leatrice, strtok");
  suite_add_tcase(s, tc7);
  tcase_add_test(tc7, strtok1);
  tcase_add_test(tc7, strtok2);
  tcase_add_test(tc7, strtok3);
  tcase_add_test(tc7, strtok4);
  tcase_add_test(tc7, strtok5);
  tcase_add_test(tc7, strtok6);
  tcase_add_test(tc7, strtok7);
  // memcmp
  TCase *tc8 = tcase_create("leatrice, memcmp");
  suite_add_tcase(s, tc8);
  tcase_add_test(tc8, memcmp1);
  tcase_add_test(tc8, memcmp2);
  tcase_add_test(tc8, memcmp3);
  tcase_add_test(tc8, memcmp4);
  tcase_add_test(tc8, memcmp5);
  tcase_add_test(tc8, memcmp6);
  tcase_add_test(tc8, memcmp7);
  tcase_add_test(tc8, memcmp8);
  // memcpy
  TCase *tc9 = tcase_create("leatrice, memcpy");
  suite_add_tcase(s, tc9);
  tcase_add_test(tc9, memcpy1);
  tcase_add_test(tc9, memcpy2);
  tcase_add_test(tc9, memcpy3);
  tcase_add_test(tc9, memcpy4);
  tcase_add_test(tc9, memcpy5);
  tcase_add_test(tc9, memcpy6);
  tcase_add_test(tc9, memcpy7);
  // strncat
  TCase *tc10 = tcase_create("leatrice, strncat");
  suite_add_tcase(s, tc10);
  tcase_add_test(tc10, strncat1);
  tcase_add_test(tc10, strncat2);
  tcase_add_test(tc10, strncat3);
  tcase_add_test(tc10, strncat4);
  tcase_add_test(tc10, strncat5);
  tcase_add_test(tc10, strncat6);
  // strncmp
  TCase *tc11 = tcase_create("leatrice, strncmp");
  suite_add_tcase(s, tc11);
  tcase_add_test(tc11, strncmp1);
  tcase_add_test(tc11, strncmp2);
  tcase_add_test(tc11, strncmp3);
  tcase_add_test(tc11, strncmp4);
  tcase_add_test(tc11, strncmp5);
  tcase_add_test(tc11, strncmp6);
  tcase_add_test(tc11, strncmp7);
  tcase_add_test(tc11, strncmp8);
  // strncpy
  TCase *tc12 = tcase_create("leatrice, strncpy");
  suite_add_tcase(s, tc12);
  tcase_add_test(tc12, strncpy1);
  tcase_add_test(tc12, strncpy2);
  tcase_add_test(tc12, strncpy3);
  tcase_add_test(tc12, strncpy4);
  tcase_add_test(tc12, strncpy5);
  // strcsnp
  TCase *tc13 = tcase_create("leatrice, strcspn");
  suite_add_tcase(s, tc13);
  tcase_add_test(tc13, strcspn1);
  tcase_add_test(tc13, strcspn2);
  tcase_add_test(tc13, strcspn3);
  tcase_add_test(tc13, strcspn4);
  tcase_add_test(tc13, strcspn5);
  tcase_add_test(tc13, strcspn6);
  tcase_add_test(tc13, strcspn7);
  // strpbrk
  TCase *tc14 = tcase_create("leatrice, strpbrk");
  suite_add_tcase(s, tc14);
  tcase_add_test(tc14, strpbrk1);
  tcase_add_test(tc14, strpbrk2);
  tcase_add_test(tc14, strpbrk3);
  tcase_add_test(tc14, strpbrk4);
  tcase_add_test(tc14, strpbrk5);
  tcase_add_test(tc14, strpbrk6);
  tcase_add_test(tc14, strpbrk7);
  // memset
  TCase *tc15 = tcase_create("leatrice, memset");
  suite_add_tcase(s, tc15);
  tcase_add_test(tc15, memset1);
  tcase_add_test(tc15, memset2);
  tcase_add_test(tc15, memset3);
  tcase_add_test(tc15, memset4);
  // toupper
  TCase *tc16 = tcase_create("leatrice, toupper");
  suite_add_tcase(s, tc16);
  tcase_add_test(tc16, toupper1);
  tcase_add_test(tc16, toupper2);
  tcase_add_test(tc16, toupper3);
  tcase_add_test(tc16, toupper4);
  tcase_add_test(tc16, toupper5);
  tcase_add_test(tc16, toupper6);
  // tolower
  TCase *tc17 = tcase_create("leatrice, tolower");
  suite_add_tcase(s, tc17);
  tcase_add_test(tc17, tolower1);
  tcase_add_test(tc17, tolower2);
  tcase_add_test(tc17, tolower3);
  tcase_add_test(tc17, tolower4);
  tcase_add_test(tc17, tolower5);
  tcase_add_test(tc17, tolower6);
  // s21_insert
  TCase *tc18 = tcase_create("leatrice, insert");
  suite_add_tcase(s, tc18);
  tcase_add_test(tc18, insert1);
  tcase_add_test(tc18, insert2);
  tcase_add_test(tc18, insert3);
  tcase_add_test(tc18, insert4);
  // trim
  TCase *tc19 = tcase_create("letrice, trim");
  suite_add_tcase(s, tc19);
  tcase_add_test(tc19, trim1);
  tcase_add_test(tc19, trim2);
  tcase_add_test(tc19, trim3);
  tcase_add_test(tc19, trim4);
  tcase_add_test(tc19, trim5);
  tcase_add_test(tc19, trim6);
  // sprintf
  TCase *tc20 = tcase_create("leatrice, sprintf");
  suite_add_tcase(s, tc20);
  tcase_add_test(tc20, sprintf1);
  tcase_add_test(tc20, sprintf2);
  tcase_add_test(tc20, sprintf3);
  tcase_add_test(tc20, sprintf4);
  tcase_add_test(tc20, sprintf5);
  tcase_add_test(tc20, sprintf_6);
  tcase_add_test(tc20, sprintf7);
  tcase_add_test(tc20, sprintf8);
  tcase_add_test(tc20, sprintf9);
  tcase_add_test(tc20, sprintf10);
  tcase_add_test(tc20, sprintf11);
  tcase_add_test(tc20, sprintf12);
  tcase_add_test(tc20, sprintf13);
  tcase_add_test(tc20, sprintf14);
  tcase_add_test(tc20, sprintf15);
  tcase_add_test(tc20, sprintf16);
  tcase_add_test(tc20, sprintf17);
  tcase_add_test(tc20, sprintf18);
  tcase_add_test(tc20, sprintf19);
  tcase_add_test(tc20, sprintf20);
  tcase_add_test(tc20, sprintf21);
  tcase_add_test(tc20, sprintf22);
  tcase_add_test(tc20, sprintf23);
  tcase_add_test(tc20, sprintf24);
  tcase_add_test(tc20, sprintf25);
  tcase_add_test(tc20, sprintf26);
  tcase_add_test(tc20, sprintf27);
  tcase_add_test(tc20, sprintf28);
  tcase_add_test(tc20, sprintf29);
  tcase_add_test(tc20, sprintf30);
  tcase_add_test(tc20, sprintf31);
  tcase_add_test(tc20, sprintf32);
  tcase_add_test(tc20, sprintf33);
  tcase_add_test(tc20, sprintf34);
  tcase_add_test(tc20, sprintf35);
  tcase_add_test(tc20, sprintf36);
  tcase_add_test(tc20, sprintf37);
  tcase_add_test(tc20, sprintf38);
  tcase_add_test(tc20, sprintf39);
  tcase_add_test(tc20, sprintf40);
  tcase_add_test(tc20, sprintf41);
  tcase_add_test(tc20, sprintf42);
  tcase_add_test(tc20, sprintf43);
  tcase_add_test(tc20, sprintf44);
  tcase_add_test(tc20, sprintf45);
  tcase_add_test(tc20, sprintf46);
  return s;
}

int main() {
  int success = 0;
  Suite *s;
  SRunner *runner;
  s = test_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  success = srunner_ntests_failed(runner);
  srunner_free(runner);
  if (success == 0) {
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
