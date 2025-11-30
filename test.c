/* 
bai toan: toi uu gia tri x trong [-10,10] de ham f(x) = x^2 la nho nhat
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POP_SIZE 20
#define GENERATIONS 50

double rand_double(double a, double b) {
    return a + (b - a) * ((double) rand() / RAND_MAX);
}

double fitness(double x) {
    return -x * x;
}

double crossover(double a, double b) {
    return (a + b) / 2.0;
}

double mutate(double x) {
    return x + rand_double(-0.5, 0.5);
}

int main() {
    srand(time(NULL));

    double pop[POP_SIZE];
    for (int i = 0; i < POP_SIZE; i++)
        pop[i] = rand_double(-10, 10);

    for (int gen = 0; gen < GENERATIONS; gen++) {

        int best1 = 0, best2 = 1;
        for (int i = 0; i < POP_SIZE; i++) {
            if (fitness(pop[i]) > fitness(pop[best1])) {
                best2 = best1;
                best1 = i;
            } else if (fitness(pop[i]) > fitness(pop[best2]) && i != best1) {
                best2 = i;
            }
        }

        double child = crossover(pop[best1], pop[best2]);
        child = mutate(child);

        pop[rand() % POP_SIZE] = child;
    }

    int best = 0;
    for (int i = 1; i < POP_SIZE; i++)
        if (fitness(pop[i]) > fitness(pop[best]))
            best = i;

    printf("Gia tri x tot nhat: %f\n", pop[best]);
    printf("Gia tri f(x): %f\n", pop[best] * pop[best]);

    return 0;
}
