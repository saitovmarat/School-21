#include "s21_string.h"

#ifdef __APPLE__
#define MAX_NUMBER 107
#define MIN_NUMBER -1
#define ERROR "Unknown error: "
static const char *error_list[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full",
};
#elif defined(__linux__)
#define MAX_NUMBER 134
#define MIN_NUMBER -1
#define ERROR "Unknown error: "
static const char *error_list[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error",

};
#endif

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *result = s21_NULL;
  char *cur = (char *)str;
  for (; n > 0; n--) {
    if (*(cur) == (char)c) {
      result = cur;
      n = 1;
      continue;
    }
    cur++;
  }
  return (void *)result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  const unsigned char *p1 = (const unsigned char *)str1;
  const unsigned char *p2 = (const unsigned char *)str2;
  for (int i = 0; i < (int)n; i++) {
    if (p1[i] != p2[i]) {
      result = p1[i] - p2[i];
      n = i;
    }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *p_dest = (unsigned char *)dest;
  const unsigned char *p_src = (const unsigned char *)src;
  for (int i = 0; i < (int)n; i++) {
    p_dest[i] = p_src[i];
  }
  return p_dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  if (str == s21_NULL) return s21_NULL;
  char *result = (char *)str;
  for (s21_size_t i = 0; i < n; i++) result[i] = (char)c;
  return result;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  while (*ptr != '\0') {
    ptr++;
  }
  while (*src != '\0' && n > 0) {
    *ptr = *src;
    ptr++;
    src++;
    n--;
  }
  *ptr = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  if (str != s21_NULL) {
    size_t len = s21_strlen(str) + 1;
    for (size_t i = 0; i < len; i++) {
      if (str[i] == (char)c) {
        result = (char *)str + i;
        break;
      }
    }
  }
  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    if (str1[i] != str2[i]) {
      return (unsigned char)str1[i] - (unsigned char)str2[i];
    }
  }
  return 0;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; ++i) {
    dest[i] = src[i];
  }
  for (; i < n; ++i) {
    dest[i] = '\0';
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  for (s21_size_t i = 0; str1[i] != '\0'; i++) {
    for (s21_size_t j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        return i;
      }
    }
    len++;
  }
  return len;
}

char *s21_strerror(int errnum) {
  static char result[64];
  if (errnum >= MAX_NUMBER || errnum <= MIN_NUMBER) {
    s21_sprintf(result, "%s%d", ERROR, errnum);
  } else {
    s21_strncpy(result, error_list[errnum], s21_strlen(error_list[errnum]));
  }

  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  for (; *(str + length); ++length)
    ;
  return length;
}

char *s21_strpbrk(const char *str_one, const char *str_too) {
  if (str_one == s21_NULL || str_too == s21_NULL) return s21_NULL;
  const char *start;
  char *result = s21_NULL;
  int flag = 1;
  while (*str_one != '\0' && flag == 1) {
    start = str_too;
    while (*start != '\0' && flag == 1) {
      if (*str_one == *start) {
        result = (char *)str_one;
        flag = 0;
        continue;
      }
      start++;
    }
    str_one++;
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  for (; *str; ++str) {
    if (*str == c) result = (char *)str;
  }
  if (c == '\0') result = (char *)str;
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  for (; *haystack; ++haystack) {
    if (!(*needle)) {
      result = (char *)haystack;
      break;
    } else if (*haystack == *needle) {
      const char *h = haystack;
      const char *n = needle;
      for (; *h && *n && *h == *n; ++h, ++n)
        ;
      if (!(*n)) {
        result = (char *)haystack;
        break;
      }
    }
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  char *result = s21_NULL;
  static char *next_token = s21_NULL;
  char *current_token = s21_NULL;
  if (str != s21_NULL) {
    next_token = str;
  }
  if (next_token == s21_NULL) {
    result = s21_NULL;
  } else {
    for (; *next_token && s21_strchr(delim, *next_token) != s21_NULL;
         ++next_token)
      ;
    if (!*next_token) {
      result = s21_NULL;
    } else {
      current_token = next_token;
      for (; *next_token && s21_strchr(delim, *next_token) == s21_NULL;
           ++next_token)
        ;
      if (!*next_token) {
        next_token = s21_NULL;
      } else {
        *next_token = '\0';
        ++next_token;
      }
      result = current_token;
    }
  }
  return result;
}

// Part 5
void *s21_to_upper(const char *str) {
  char *str_copy = s21_NULL;
  if (str != s21_NULL) {
    int len = s21_strlen(str);
    str_copy = malloc(sizeof(char) * (len + 1));
    if (str_copy) {
      for (int i = 0; i <= len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
          str_copy[i] = (str[i] - 'a') + 'A';
        else
          str_copy[i] = str[i];
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}

void *s21_to_lower(const char *str) {
  char *str_copy = s21_NULL;
  if (str != s21_NULL) {
    int len = s21_strlen(str);
    str_copy = malloc(sizeof(char) * (len + 1));
    if (str_copy) {
      for (int i = 0; i <= len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
          str_copy[i] = (str[i] - 'A') + 'a';
        else
          str_copy[i] = str[i];
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = s21_NULL;
  if (src && str) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t new_len = src_len + str_len;
    if (start_index <= new_len) {
      new_str = malloc((new_len + 1) * sizeof(char));
      if (str == s21_NULL && start_index == 0)
        s21_strncpy(new_str, src, str_len);
      else {
        for (s21_size_t i = 0, m = 0, n = 0; i < new_len; i++) {
          if (i < start_index || i >= start_index + str_len) {
            new_str[i] = src[n];
            n++;
          } else {
            new_str[i] = str[m];
            m++;
          }
        }
      }
      new_str[new_len] = '\0';
    }
  } else if (str) {
    s21_size_t str_len = s21_strlen(str);
    if (str_len > 0) {
      new_str = malloc(s21_strlen(str) * sizeof(char));
      s21_strncpy(new_str, str, str_len);
    }
  }
  return new_str;
}

int find_ind(const char *src, const char *trim_chars, int index) {
  index -= 1;
  int res = 0;
  int len = s21_strlen(trim_chars);
  for (int i = 0; i < len; i++) {
    if (src[index] == trim_chars[i]) res = 1;
  }
  return res;
}
void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = s21_NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      int left = 1, right = s21_strlen(src);
      while (find_ind(src, trim_chars, left)) left++;
      if (left != right) {
        while (find_ind(src, trim_chars, right)) right--;
      }
      int new_len = right - left;
      new_str = malloc(sizeof(char) * new_len + 1);
      if (new_str) {
        for (int i = left - 1, j = 0; i <= right; i++, j++) {
          new_str[j] = src[i];
        }
        new_str[new_len + 1] = '\0';
      } else {
        new_str = "";
      }
    } else {
      new_str = s21_trim(src, "\t\n ");
    }
  }
  return new_str;
}

