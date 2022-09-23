#include <stdio.h>

int next_turn(int total, int possible) {
  unsigned long long first = 1ull, second = 1ull;
  unsigned long long matr_fib [60] = {0};
  int ss[60] = {0};
  int fib_MAX, idx, id, zap, y = 1;

  if (total == 1) fib_MAX = 1;
  else {
    for (idx = 1; second < total; ++idx) {
      unsigned long long tmp = second;
      second = second + first;
      first = tmp;
    }

    if (second == total) { 
      fib_MAX = idx; }
    else {    
      fib_MAX = idx-1;
    }     
  }

  id = fib_MAX;
  first = 1ull;
  second = 1ull;

  matr_fib[1] = 1;
  for (int i = 2; i <= id; ++i) {
    unsigned long long tmp = second;
    second = second + first;
    first = tmp;
    matr_fib[i] = second; 
  }

  ss[id]=1;
  zap=id;
  idx-=2; 

  for (;fib_MAX>0; fib_MAX--) {
    if (matr_fib[zap]+matr_fib[fib_MAX]<=total) {
        total = total-matr_fib[zap];
        zap = fib_MAX;
        ss [fib_MAX] = 1;
        fib_MAX--;      
    } 
  } 

  for (; y <= id; y++) 
    if (ss[y] == 1) 
        break; 

  if (possible >= matr_fib[y]) 
    return (int)matr_fib[y];
  else 
    return 1; 

}

int main() {
    int kol, num, a, pom = 0, poss = 0; 

    printf("Введите количество монет.\n");
    scanf("%d", &kol);
    printf("\nКаким по счету игроком хотите быть?\n");
    scanf("%d", &num);
    printf("\n");

    if (num == 1) {
        pom = kol - 1;
        while (kol > 0) {
            printf("Ваш ход, но возьмите не больше, чем %d.\n", pom);
            scanf("%d", &a);
            kol -= a;

            if (kol > 0) {
              pom = next_turn(kol, 2*a);
              printf("А это мой ход: %d\n\n", pom);
              kol -= pom;
              if (kol == 0) {
                printf("Я выиграл ха-ха\n");
                break;
              } else printf("Осталось монет: %d\n", kol);
              pom = 2*pom;
            } else {
              printf ("\nВы выиграли, поздравляю!\n");
              break;
            }
        }
    } else if (num == 2) {
        poss = kol - 1;
        while (kol > 0) {
            pom = next_turn(kol, poss);
            printf("\nМой ход: %d.\n\n", pom);
            kol -= pom;
            if (kol > 0){
            printf("Осталось монет: %d\n", kol);
            printf("А теперь ваш ход, но возьмите не больше, чем %d.\n", pom*2);
            scanf("%d", &a);
            kol -= a;
            if (kol == 0) {
                printf("Вы выиграли, поздравляю!\n");
                break;
            }
            poss = 2*a;
            } else {
              printf("Я выиграл ха-ха\n");
              break;
            }
        }
    }

    return 0;
}