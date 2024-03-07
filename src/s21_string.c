#include "s21_string.h"

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// strlen

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (*str != '\0') {
    length++;
    str++;
  }
  return length;
}

// strerror

char *s21_strerror(int errnum) {
  static char mas[32];

#if defined(__APPLE__)
  const char *const *errors = errors_mac;
  if (errnum < 0 || errnum >= ERR_COUNT) {
    snprintf(mas, sizeof(mas), "Unknown error: %d", errnum);
    return mas;
  }
#elif defined(__linux__)
  const char *const *errors = errors_linux;
  if (errnum < 0 || errnum >= ERR_COUNT) {
    snprintf(mas, sizeof(mas), "Unknown error %d", errnum);
    return mas;
  }
#else
  //неподдерживаемая платформа
  return "Unknown error";
#endif
  return (char *)errors[errnum];
}

// strstr
char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {  // Если needle - пустая строка, вернуть haystack
    return (char *)haystack;
  }
  while (*haystack) {  // Пока не достигнут конец haystack
    const char *h = haystack;
    const char *n = needle;

    while (*h && *n && (*h == *n)) {  // Сравниваем символы в haystack и needle
      h++;
      n++;
    }

    if (*n == '\0') {  // Если достигнут конец needle, значит needle найдена в
                       // haystack
      return (char *)haystack;
    }

    haystack++;
  }
  return S21_NULL;  // Если needle не найдена в haystack
}

// strrchr
char *s21_strrchr(const char *str, int c) {
  char *last = 0;

  while (*str) {
    if (*str == (char)c) {
      last = (char *)str;
    }
    str++;
  }

  if (*str == (char)c) {
    return (char *)str;
  }

  return last;
}

// memchr
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *s = (const unsigned char *)str;
  unsigned char ch = (unsigned char)c;

  for (s21_size_t i = 0; i < n; i++) {
    if (s[i] == ch) {
      return (void *)&s[i];
    }
  }

  return S21_NULL;
}

// strchr
char *s21_strchr(const char *str, int c) {
  char ch = (char)c;
  while (*str != '\0') {
    if (*str == ch) {
      return (char *)str;
    }
    str++;
  }
  if (ch == '\0') {
    return (char *)str;
  }
  return S21_NULL;
}

// strtok
char *s21_strtok(char *str, const char *delim) {
  static char *next_token = NULL;
  char *token;
  if (str != NULL) {
    next_token = str;
  } else if (next_token == NULL) {
    return NULL;
  }
  while (*next_token && s21_strchr(delim, *next_token)) {
    next_token++;
  }
  if (!*next_token) {
    next_token = NULL;
    return NULL;
  }
  token = next_token;
  while (*next_token && !s21_strchr(delim, *next_token)) {
    next_token++;
  }
  if (!*next_token) {
    next_token = NULL;
  }  // else {
     //*next_token++ = '\0';
  //}
  return token;
}

// memcmp
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *a1 = str1, *a2 = str2;
  int res = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < n && !flag; i++) {
    if (a1[i] < a2[i]) {
      res = -1;
      flag = 1;
    } else if (a1[i] > a2[i]) {
      res = 1;
      flag = 1;
    }
  }
  return res;
}

// memcpy
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  unsigned char *s = (unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}

// strncat
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  // Находим конец строки в dest
  char *dest_end = dest;
  while (*dest_end) {
    dest_end++;
  }

  // Добавляем src в конец dest, длиной до n символов
  while (*src && n > 0) {
    *dest_end = *src;
    dest_end++;
    src++;
    n--;
  }

  // Добавляем символ конца строки
  *dest_end = '\0';

  return dest;
}
// strncmp
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  while (n > 0 && *str1 && *str2 && *str1 == *str2) {
    str1++;
    str2++;
    n--;
  }
  if (n == 0) {
    res = 0;
  }
  res = *(unsigned char *)str1 - *(unsigned char *)str2;
  return res;
}

// strncpy
char *s21_strncpy(char *destination, const char *source, s21_size_t n) {
  char *start =
      destination;  // сохраняем начало destination для возврата в конце
  while (n > 0 && *source != '\0') {
    *destination = *source;
    destination++;
    source++;
    n--;
  }
  while (n > 0) {
    *destination = '\0';  // Заполняем оставшуюся часть destination нулями
    destination++;
    n--;
  }
  return start;
}

// strcspn
s21_size_t s21_strcspn(const char *str, const char *sym) {
  s21_size_t length = 0;
  const char *ptr;
  while (*str) {
    ptr = sym;
    while (*ptr) {
      if (*str == *ptr) {
        return length;
      }
      ptr++;
    }
    str++;
    length++;
  }
  return length;
}

// strpbrk

char *s21_strpbrk(char *str, const char *sym) {
  char *res = S21_NULL;
  while (*str != '\0') {
    const char *cmp = sym;
    while (*cmp != '\0') {
      if (*str == *cmp) {
        res = str;
        return res;
      }
      cmp++;
    }
    str++;
  }
  return res;
}

// memset
void *s21_memset(void *destination, int c, s21_size_t n) {
  unsigned char *d = (unsigned char *)destination;
  while (n--) {
    *d++ = (unsigned char)c;
  }
  return destination;
}

// toupper
void *s21_to_upper(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *copy = (char *)malloc(
      (len + 1) * sizeof(char));  // Выделение памяти для копии строки
  if (str == S21_NULL) {
    copy = S21_NULL;  // Обработка случая, когда входная строка равна NULL
  }
  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      copy[i] =
          str[i] - ('a' - 'A');  // Преобразование символа в верхний регистр
    } else {
      copy[i] = str[i];
    }
  }
  copy[len] = '\0';  // Добавление завершающего нулевого символа
  return copy;
}

// tolower
void *s21_to_lower(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *copy = (char *)malloc(
      (len + 1) * sizeof(char));  // Выделение памяти для копии строки

  if (str == S21_NULL) {
    copy = S21_NULL;  // Обработка случая, когда входная строка равна NULL
  }
  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      copy[i] =
          str[i] - ('A' - 'a');  // Преобразование символа в нижний регистр
    } else {
      copy[i] = str[i];
    }
  }
  copy[len] = '\0';  // Добавление завершающего нулевого символа

  return copy;
}

// insert
char *s21_strcat(char *dest, const char *src) {
  char *p = dest;
  while (*p) { /* Найти конец dest */
    p++;
  }
  while (*src) { /* Копировать src в конец dest */
    *p++ = *src++;
  }
  *p = '\0'; /* Установить нулевой символ в конце строки */
  return dest;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  char *new_str =
      (char *)malloc((src_len + str_len + 1) *
                     sizeof(char));  // Выделяем память для новой строки

  if (src == NULL || str == NULL) {
    new_str = NULL;  // Проверка наличия строк
  } else {
    // Копируем часть исходной строки до позиции вставки
    s21_strncpy(new_str, src, start_index);
    new_str[start_index] = '\0';

    // Добавляем вставляемую строку
    s21_strcat(new_str, str);

    // Добавляем оставшуюся часть исходной строки
    s21_strcat(new_str, src + start_index);
  }
  return new_str;
}

// trim
void s21_removeCharacter(char *str, char ch) {
  int len = s21_strlen(str);
  int len_ch = s21_strlen(&ch);
  int first = -1;
  int last = -1;

  // Поиск последнего вхождения символа
  for (int i = 0; i < len; i++) {
    if (str[i] == ch) {
      last = i;
    }
  }

  // Поиск первого вхождения символа
  for (int i = len - 1; i >= 0; i--) {
    if (str[i] == ch) {
      first = i;
    }
  }

  // Если первое и последнее вхождение символа найдены
  if (first != -1 && last != -1) {
    if (len_ch == 6) {
      // Сдвиг всех символов на одну позицию влево, начиная с индекса last
      for (int i = last; i < len - 1; i++) {
        str[i] = str[i + 1];
      }

      // Замена последнего символа на нулевой символ
      str[len - 1] = '\0';
    } else {
      // Сдвиг всех символов на одну позицию влево, начиная с индекса last
      for (int i = last; i < len - 1; i++) {
        str[i] = str[i + 1];
      }

      // Замена последнего символа на нулевой символ
      str[len - 1] = '\0';

      // Сдвиг всех символов на одну позицию влево, начиная с индекса first
      for (int i = first; i < len - 2; i++) {
        str[i] = str[i + 1];
      }
      str[len - 2] = '\0';
    }
  }
}

void s21_trim(char *src, char *trim_chars) {
  int i = 0;
  int len = s21_strlen(trim_chars);
  for (i = 0; i < len; i++) {
    char del = trim_chars[i];
    s21_removeCharacter(src, del);
  }
}

// sprintf
int s21_atoi(const char *str) {
  int i = 0;
  int result = 0;
  int sign = 1;
  while (str[i] == '0' || str[i] == ' ') i++;
  if (str[i] == '-') {
    sign = -1;
    i++;
  }
  while (48 <= str[i] && str[i] <= 57) {
    result = result * 10 + ((int)str[i] - 48);
    i++;
  }
  return result * sign;
}

int s21_sprintf(char *str, const char *format, ...) {
  flags flag = {0};
  va_list v_l;
  va_start(v_l, format);
  char *str_begin = str;
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      s21_memset(&flag, 0, sizeof(flags));
    }
    format = get_flags(format, &flag);
    format = get_width(format, &flag, v_l);
    format = get_precision(format, &flag, v_l);
    format = get_length(format, &flag);
    flag.specifier = *format;
    format++;
    char buff[BUFF_SIZE] = {'\0'};
    handle_value(flag, buff, v_l);
    for (int i = 0; buff[i]; i++, str++) {
      *str = buff[i];
    }
    if (flag.specifier == 'n') {
      int *ret = va_arg(v_l, int *);
      *ret = str - str_begin;
    }
  }
  *str = '\0';
  va_end(v_l);
  return str - str_begin;
}

const char *get_flags(const char *format, flags *flag) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '0') {
    if (*format == '0') {
      flag->zero = true;
    }
    if (*format == '-') {
      flag->minus = true;
    }
    if (*format == '+') {
      flag->plus = true;
    }
    if (*format == ' ') {
      flag->space = true;
    }
    format++;
  }
  return format;
}

int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }

const char *get_width(const char *format, flags *flag, va_list v_l) {
  if (*format == '*') {
    format++;
    flag->width = va_arg(v_l, int);
  } else if (s21_isdigit(*format)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++) {
      tmp[i] = *format;
    }
    flag->width = s21_atoi(tmp);
  }
  return format;
}

const char *get_precision(const char *format, flags *flag, va_list v_l) {
  if (*format == '.') {
    flag->is_precision_set = true;
    format++;
  }
  if (*format == '*') {
    format++;
    flag->precision = va_arg(v_l, int);
  }
  if (s21_isdigit(*format)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++) {
      tmp[i] = *format;
    }
    flag->precision = s21_atoi(tmp);
  }
  return format;
}

const char *get_length(const char *format, flags *flag) {
  if (*format == 'h') {
    flag->lenght = 'h';
    format++;
  }
  if (*format == 'l') {
    flag->lenght = 'l';
    format++;
  }
  return format;
}

void handle_value(flags flag, char *buff, va_list v_l) {
  if (flag.specifier == 'd' || flag.specifier == 'i')
    parse_int(flag, buff, v_l);
  else if (flag.specifier == 'u')
    parse_unsigned(flag, buff, v_l);
  else if (flag.specifier == '%')
    buff[0] = '%';
  else if (flag.specifier == 'c')
    parse_char(flag, buff, v_l);
  else if (flag.specifier == 's')
    parse_string(flag, buff, v_l);
  else if (flag.specifier == 'f')
    parse_float(flag, buff, v_l);
}

void parse_int(flags flag, char *buff, va_list v_l) {
  int64_t val = va_arg(v_l, int64_t);
  if (flag.lenght == 0) {
    val = (int32_t)val;
  } else if (flag.lenght == 'h') {
    val = (int16_t)val;
  }
  whole_num_to_string(val, buff, 10);
  format_precision(buff, flag);
  format_flags(buff, flag);
}

void whole_num_to_string(int64_t val, char *ret, int base) {
  char tmp[BUFF_SIZE] = {'\0'};
  int idx = BUFF_SIZE - 2;
  bool negativ = val < 0 ? 1 : 0;
  val = negativ ? -val : val;
  if (val == 0) tmp[idx] = '0';
  while (val > 0) {
    idx--;
    tmp[idx] = "0123456789abcdef"[val % base];
    val /= base;
  }
  for (int j = 0; tmp[idx]; idx++, j++) {
    if (negativ && j == 0) {
      ret[j++] = '-';
    }
    ret[j] = tmp[idx];
  }
}

char *s21_strcpy(char *dest, const char *src) {
  char *temp = dest;
  while (*src) {
    *temp++ = *src++;
  }
  *temp = '\0';  // добавляем в конец символ окончания строки
  return dest;
}

void format_precision(char *buff, flags flag) {
  char tmp[BUFF_SIZE] = {'\0'};
  int sing = 0;
  int len = s21_strlen(buff);
  if (buff[0] == '-') {
    tmp[0] = '-';
    len--;
    sing = 1;
  }
  if (flag.precision > len) {
    int idx;
    for (idx = sing; idx < flag.precision - len + sing; idx++) tmp[idx] = '0';
    for (int i = sing; buff[i]; i++, idx++) tmp[idx] = buff[i];
    s21_strcpy(buff, tmp);
  }
  if (flag.is_precision_set && flag.precision == 0 &&
      check_integer_specifier(flag.specifier) && buff[0] == '0')
    buff[0] = '\0';
}

bool check_integer_specifier(char c) {
  char spec[] = {'d', 'i', 'u'};
  bool res = false;
  for (s21_size_t i = 0; i < sizeof(spec); i++) {
    if (spec[i] == c) {
      res = true;
      break;
    }
  }
  return res;
}

void format_flags(char *buff, flags flag) {
  char tmp[BUFF_SIZE + 1] = {'\0'};
  if (flag.plus && flag.specifier != 'u') {
    tmp[0] = buff[0] == '-' ? buff[0] : '+';
    s21_strcpy(tmp + 1, buff[0] == '-' ? buff + 1 : buff);
    s21_strcpy(buff, tmp);
  } else if (flag.space && buff[0] != '-' && flag.specifier != 'u') {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, buff);
    s21_strcpy(buff, tmp);
  }
  if (flag.width > (int)s21_strlen(buff)) {
    int idx = flag.width - s21_strlen(buff);
    if (!flag.minus) {
      s21_memset(tmp, flag.zero ? '0' : ' ', idx);
      s21_strcpy(tmp + idx, buff);
    } else {
      s21_strcpy(tmp, buff);
      s21_memset(tmp + s21_strlen(tmp), ' ', idx);
    }
    s21_strcpy(buff, tmp);
  }
}

void unsigned_num_to_string(uint64_t val, char *ret, int base) {
  char buf[BUFF_SIZE + 1] = {'\0'};
  int idx = BUFF_SIZE - 1;
  if (val == 0) {
    buf[idx] = '0';
    idx--;
  }
  for (; val && idx; idx--, val /= base)
    buf[idx] = "0123456789abcdef"[val % base];
  for (int j = 0; buf[idx + 1]; idx++, j++) ret[j] = buf[idx + 1];
}

void parse_unsigned(flags flag, char *buff, va_list v_l) {
  uint64_t val = va_arg(v_l, uint64_t);
  if (flag.lenght == 'h')
    val = (uint16_t)val;
  else if (flag.lenght == 'l')
    val = (uint64_t)val;
  else if (flag.lenght == 0)
    val = (uint32_t)val;
  unsigned_num_to_string(val, buff, 10);
  format_precision(buff, flag);
  format_flags(buff, flag);
}

void format_wchar(flags flag, char *buff, wchar_t w_c) {
  if (!flag.minus && flag.width) {
    for (int i = 0; i < flag.width; i++) {
      buff[i] = ' ';
      if (i == flag.width - 1) wcstombs(buff, &w_c, BUFF_SIZE);
    }
  } else if (flag.width) {
    wcstombs(buff, &w_c, BUFF_SIZE);
    for (int i = s21_strlen(buff); i < flag.width; i++) buff[i] = ' ';
  } else
    wcstombs(buff, &w_c, BUFF_SIZE);
}

void format_char(flags flag, char *buff, char c) {
  if (!flag.minus && flag.width > 1) {
    for (int i = 0; i < flag.width - 1; i++) {
      buff[i] = ' ';
    }
    buff[flag.width - 1] = c;
  } else if (flag.width > 1) {
    buff[0] = c;
    for (int i = 1; i < flag.width; i++) buff[i] = ' ';
  } else
    buff[0] = c;
}

void parse_char(flags flag, char *buff, va_list v_l) {
  if (flag.lenght == 'l') {
    wchar_t w_c;
    w_c = va_arg(v_l, wchar_t);
    format_wchar(flag, buff, w_c);
  } else {
    char c;
    c = va_arg(v_l, int);
    format_char(flag, buff, c);
  }
}

void format_string(flags flag, char *buff, char *str) {
  char tmp[BUFF_SIZE] = {'\0'};
  s21_strcpy(tmp, str);
  if (flag.is_precision_set) tmp[flag.precision] = '\0';
  int shift = flag.width - s21_strlen(tmp);
  int len = s21_strlen(tmp);
  if (flag.minus && shift > 0) {
    s21_strcpy(buff, tmp);
    s21_memset(buff + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(buff, ' ', shift);
    s21_strcpy(buff + shift, tmp);
  } else {
    s21_strcpy(buff, tmp);
  }
}

void parse_string(flags flag, char *buff, va_list v_l) {
  char *str = va_arg(v_l, char *);
  format_string(flag, buff, str);
}

void double_to_string(long double val, char *ret, flags flag) {
  char buff[BUFF_SIZE] = {'\0'};
  int idx = BUFF_SIZE - 2;
  bool negativ = val < 0 ? 1 : 0;
  val = negativ ? val * -1 : val;
  long double l = 0, r = modfl(val, &l);
  if (flag.precision == 0) {
    l = round(val);
    r = 0;
  }
  char fractions[BUFF_SIZE] = {'\0'};
  for (int i = 0; i < flag.precision; i++) {
    r = r * 10;
    fractions[i] = (int)r + '0';
  }
  long long right = round(r), left = l;
  if (!right) {
    for (int i = 0; i < flag.precision; idx--, i++) buff[idx] = '0';
  } else {
    for (int i = s21_strlen(fractions); right || i > 0; right /= 10, idx--, i--)
      buff[idx] = (int)(right % 10 + 0.05) + '0';
  }
  if ((flag.is_precision_set && flag.precision != 0) || (int)r ||
      (!flag.is_precision_set && val == 0) || s21_strlen(fractions))
    buff[idx--] = '.';
  if (!left) {
    buff[idx] = '0';
    idx--;
  } else {
    for (; left; left /= 10, idx--) buff[idx] = (int)(left % 10) + '0';
  }
  for (int i = 0; buff[idx + 1]; idx++, i++) {
    ret[i] = buff[idx + 1];
  }
}

void parse_float(flags flag, char *buff, va_list v_l) {
  long double val = 0;
  val = va_arg(v_l, double);
  if (!flag.is_precision_set) {
    flag.precision = 6;
  }
  double_to_string(val, buff, flag);
  format_flags(buff, flag);
}
