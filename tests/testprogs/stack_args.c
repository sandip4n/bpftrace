#define ARG(x) int (x) __attribute((unused))

// Declare enough args that some are placed on the stack
#if defined(__aarch64__) || defined(__powerpc64__)
void too_many_args(ARG(a), ARG(b), ARG(c), ARG(d), ARG(e), ARG(f), ARG(g),
                   ARG(h), ARG(i), ARG(j)) {}
#else
void too_many_args(ARG(a), ARG(b), ARG(c), ARG(d), ARG(e), ARG(f), ARG(g),
                   ARG(h)) {}
#endif

int main(void)
{
#if defined(__aarch64__) || defined(__powerpc64__)
  too_many_args(0, 0, 0, 1, 2, 4, 8, 16, 32, 64);
#else
  too_many_args(0, 1, 2, 4, 8, 16, 32, 64);
#endif
  return 0;
}
