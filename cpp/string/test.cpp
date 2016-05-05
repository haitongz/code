#include <stdio.h>
#include <string>

int main(void) {
  char source[] = "hello, world! welcome to china!";
  char delim[] = " ,!";
  char abcd[10] = "10!";
  char char_array[10]={0};
  char* aa;
  aa = NULL;

  char *s = strdup(source);
  char *token;
  for(token = strsep(&s, delim); token != NULL; token = strsep(&s, delim)) {
    printf(token);
    printf("%d\n", strlen(token));
    printf("+");
  }
  printf("\n");

  std::string abc;
  std::string aaa;
  std::string ccc;
  int num = 10;
  abc = "cosnt" + (std::string)source + (std::string)delim + abcd;
  printf("abc:%s\n", abc.c_str());
  aaa = aa ?(std::string)aa:"" + (std::string)abcd;
  printf("aa:%s\n", aaa.c_str());
  ccc = (aa?(std::string)aa:"") + "const" + (std::string)char_array;
  printf("ccc:%s\n", ccc.c_str());
  return 0;
}
