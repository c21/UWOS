# 1 "test.c"
# 1 "<command-line>"
# 1 "test.c"
# 1 "test.h" 1


struct plane {
  int x;
  int y;
};
# 2 "test.c" 2
# 1 "test.h" 1


struct plane {
  int x;
  int y;
};
# 3 "test.c" 2

int main(int argc, char *argv[]) {
  struct plane p;
  return p.x + p.y - 1;
}
