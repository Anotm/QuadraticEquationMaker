#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>

typedef struct Quadratic {
   int a;
   int b;
   int c;
   int x1;
   int x2;
   int r;
   int s;
} QUAD;

void make_randQUAD(QUAD *q, bool a){
   if (a){
      q->x1 = 1;
      q->x2 = 1;
   }
   else{
      q->x1 = rand() % 11;
      q->x2 = rand() % 11 - 5;
   }
   q->r = rand() % 21;
   q->s = rand() % 21 - 10;
   q->a = q->x1 * q->x2;
   q->b = q->x2*q->r + q->x1*q->s;
   q->c = q->r * q->s;
}

void print_equation(QUAD q, FILE *f){
   fprintf(f, "%dx²%+dx%+d\n", q.a, q.b, q.c);
}
void print_answer(QUAD q, FILE *f){
   fprintf(f, "(%dx%+d)(%dx%+d)\n", q.x1, q.r, q.x2, q.s);
}

int main() {
   srand(time(NULL));
   FILE *equations, *answers;
   equations = fopen("equations.txt", "a");
   answers= fopen("answers.txt", "a");
   assert(equations != NULL);
   assert(answers != NULL);

   QUAD q;
   int num;
   char c;
   bool a;
   printf("Number of Equations: ");
   scanf("%d", &num);

   printf("Set a=1? (y/n): ");
   scanf(" %c",&c); c = toupper(c);
   assert(c == 'Y' || c == 'N');
   a = c=='Y' ? true : false;

   for (int i = 0; i < num; i++){

      make_randQUAD(&q, a);
      print_equation(q, equations);
      print_answer(q, answers);
   }
   fclose(equations);
   fclose(answers);
   return 0;
}