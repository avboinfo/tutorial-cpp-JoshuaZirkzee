/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, i;
int V[MAXN];
int sum;

int main() {
//  uncomment the following lines if you want to read/write from files
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &V[i]));

    
    for(int i=0; i<N; i++) {
        if(V[i] < 0) {
            V[i] = V[i-1];
        }
        sum = V[i] + sum;
    }

    printf("%d\n", sum); // print the result
    return 0;
}