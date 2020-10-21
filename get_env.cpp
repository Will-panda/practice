/*
* CopyRight (C) 2020 by LiWenqiang. All rights reserved.
* Li Wenqiang <liwq93@163.com>
*/

#include <unordered_map>
#include <vector>
#include <string>

int main(int argc, char **argv) {

  /*
  * get environment viarable
  * to set a environment viarable, you can use export env_name=value
  */
  char* p = getenv("test_a");
  printf("host ip: %s\n ", p);

  return 0;
}
