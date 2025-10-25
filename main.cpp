#include <iostream>
#include <limits>

int get_max_int();
bool is_mult_overflow(int a, int b, int c);
bool is_sum_overflow(int a, int b);
bool is_every_number_natural(int a, int b, int c);
int get_max(int a, int b, int c);
int get_first(int a, int b, int c);
int get_second(int a, int b, int c);
bool is_pythagoric(int a, int b, int c);

int main()
{
  std::cout << "Start\n";
  return 0;
}

bool is_pythagoric(int a, int b, int c)
{
  if (!is_every_number_natural(a, b, c))
  {
    return false;
  }
  int maximum = get_max(a, b, c);
  int first = get_first(a, b, c);
  int second = get_second(a, b, c);
  if (is_mult_overflow(maximum, first, second))
  {
    throw std::overflow_error("Overflow error due to multiply!");
  }
  if (is_sum_overflow(first*first, second*second))
  {
    throw std::overflow_error("Overflow error due to addition!");
  }
  return maximum*maximum == first*first + second*second;
}

bool is_every_number_natural(int a, int b, int c)
{
  return a >= 1 && b >= 1 && c >= 1;
}

int get_max(int a, int b, int c)
{
  if (a >= b && a >= c)
  {
    return a;
  }
  else if (b >= a && c >= a)
  {
    return b;
  }
  return c;
}

int get_first(int a, int b, int c)
{
  if (a == get_max(a, b, c))
  {
    return b;
  }
  return a;
}

int get_second(int a, int b, int c)
{
  if (c == get_max(a, b, c))
  {
    return b;
  }
  return c;
}

int get_max_int()
{
  return std::numeric_limits<int>::max();
}

bool is_mult_overflow(int a, int b, int c)
{
  bool condition = a > get_max_int()/a;
  condition = condition && (b > get_max_int()/b);
  condition = condition && (c > get_max_int()/c);
  return condition;
}

bool is_sum_overflow(int a, int b)
{
  return a > get_max_int() - b;
}
