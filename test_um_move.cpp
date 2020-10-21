/*
* CopyRight (C) 2020 by LiWenqiang. All rights reserved.
* Li Wenqiang <liwq93@163.com>
*/

#include <unordered_map>
#include <vector>
#include <string>

int main(int argc, char **argv) {

  /*
  * map1 and map2 have a pointer to spaces for its data
  * but data's address is differen with variable's address
  * see example below
  */
  std::unordered_map<std::string, std::string> map1{{"1", "x"}, {"2", "y"}, {"3", "z"}};
  printf("map1 address: %p\n", &map1);
  for (auto &element : map1) {
    printf("data %s address: %p\n", element.second.c_str(), &element);
  }

  printf("\n----------------------------------\n");
  printf("move map1 to map2\n");

  std::unordered_map<std::string, std::string> map2(std::move(map1));
  printf("map2 address: %p\n", &map2);
  printf("map1 address: %p\n", &map1);

  /*
  * After move. map1 become emtry while map2 contain each element in map1
  * The address of map1 still valid and unchanged
  * The adrress of map2 is different from map1
  * The data address is the same
  */

  for (auto &element : map2) {
    printf("data %s address: %p\n", element.second.c_str(), &element);
  }

  /*
   * case 1: stack variable, its data's store at heap, address of variable is at stack
   * case 2: heap variable which use new operator, the address of variable and its data are both at heap
   * Note: The data address is not adjacient to its variable's address in both case
  */

  printf("\n----------------------------------\n");
  std::vector<int> vec_a(9,0);
  printf("vec_a address: %p\n", &vec_a);
  for (auto &element : vec_a) {
    printf("data %d address: %p\n", element, &element);
  } 

  printf("\n----------------------------------\n");
  std::vector<int>* vec_b = new std::vector<int>(9,0);
  printf("vec_b address: %p\n", vec_b);

  printf("vec_b data 0 pointer address: %p\n", vec_b->data());

  for (auto &element : *vec_b) {
    printf("data %d address: %p\n", element, &element);
  }
  return 0;
}
