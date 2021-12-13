#include <stdio.h>
#include <windows.h>

// Карта игрового поля имеет фиксированный размер, инициализируется бордюром - '#' и свободным полем - символом пробел ' '
char caMap[30][120+1] = {
  "########################################################################################################################",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "########################################################################################################################"
};

int main(int argc, char *argv[]) {
  //Вывести карту игрового поля на экран
  printf("%s\n",caMap[0]);
  printf("%s\n",caMap[1]);
  printf("%s\n",caMap[2]);
  printf("%s\n",caMap[3]);
  printf("%s\n",caMap[4]);
  printf("%s\n",caMap[5]);
  printf("%s\n",caMap[6]);
  printf("%s\n",caMap[7]);
  printf("%s\n",caMap[8]);
  printf("%s\n",caMap[9]);
  printf("%s\n",caMap[10]);
  printf("%s\n",caMap[11]);
  printf("%s\n",caMap[12]);
  printf("%s\n",caMap[13]);
  printf("%s\n",caMap[14]);
  printf("%s\n",caMap[15]);
  printf("%s\n",caMap[16]);
  printf("%s\n",caMap[17]);
  printf("%s\n",caMap[18]);
  printf("%s\n",caMap[19]);
  printf("%s\n",caMap[20]);
  printf("%s\n",caMap[21]);
  printf("%s\n",caMap[22]);
  printf("%s\n",caMap[23]);
  printf("%s\n",caMap[24]);
  printf("%s\n",caMap[25]);
  printf("%s\n",caMap[26]);
  printf("%s\n",caMap[27]);
  printf("%s\n",caMap[28]);
  printf("%s\n",caMap[29]);
  return 0;
}
