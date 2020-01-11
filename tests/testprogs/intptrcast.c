// a is on the stack
#ifdef __aarch64__
int fn(short x0, short x1, short x2, short x3, short x4, short x5, short x6,
       short x7, short a) {
    return x0 + x1 + x2 + x3 + x4 + x5 + x6 + x7 + a;
#elif defined(__powerpc64__)
int fn(short r3, short r4, short r5, short r6, short r7, short r8, short r9,
       short r10, short a) {
    return r3 + r4 + r5 + r6 + r7 + r8 + r9 + r10 + a;
#else
int fn(short rdi, short rsi, short rdx, short rcx, short r8, short r9, short a) {
    return rdi + rsi + rdx + rcx + r8 + r9 + a;
#endif
}

int main() {
#if defined(__aarch64__) || defined(__powerpc64__)
  fn(0x0, 0x0, 0x123, 0x456, 0x789, 0xabc, 0xdef, 0xfed, 0xcba);
#else
  fn(0x123, 0x456, 0x789, 0xabc, 0xdef, 0xfed, 0xcba);
#endif
  return 0;
}
