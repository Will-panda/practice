/*
* CopyRight (C) 2020 by LiWenqiang. All rights reserved.
* Li Wenqiang <liwq93@163.com>
*/

#include <unordered_map>
#include <vector>
#include <string>

class VirTual
{
private:
  /* data */
  int64_t num1;
  int64_t num2;

public:
  VirTual(/* args */) = default;
  virtual ~VirTual() = default;
};

class NoVirTual
{
private:
  /* data */
  int64_t num1;
  int64_t num2;

public:
  NoVirTual(/* args */) = default;
  ~NoVirTual() = default;
};


int main(int argc, char **argv) {

  /*
  * if a class have virtual funcion, the size of the class will increased by 8
  * due to a extra pointer to virtual function list
  */
  printf("virtual size: %d\n", sizeof(VirTual));
  printf("virtual size: %d\n", sizeof(NoVirTual));

  return 0;
}
