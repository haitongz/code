char* strcpy(char *to, const char *from)
{
  assert(to != NULL && from != NULL);
  char *p = to;
  while ((*p++ = *from++) != '\0')
    ;
  return to;
}
