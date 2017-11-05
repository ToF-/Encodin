#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

int tests_run = 0;

static int foo = 7;
static int bar = 5;

static char *test_foo() {
    mu_assert("error, foo != 7", foo == 7);
    return 0;
}

static char *test_bar() {
    mu_assert("error, bar != 5", bar == 5);
    return 0;
}

static char *all_tests() {
    mu_run_test(test_foo);
    mu_run_test(test_bar);
    return 0;
}

int run_all_tests() {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
    return result != 0; 
}
    
int encode(char *srce, char *dest) {
    char last = '\0';
    char count;
    while(*srce != '\n') {
        if (*srce != last) {
            last = *srce;
            if (count > 0) {
                *dest++ = count + '0';
                *dest++ = last;
            }
            count = 0;
        } else {
            if(count == 9) {
                *dest++ = count + '0';
                *dest++ = last;
                count = 0;
            }
        }
        count++;
        srce++;
    }
    *dest++ = count + '0';
    *dest++ = last;
    *dest++ = '\n';
    *dest++ = '\0';
    return 0;
}

void process() {
    char *srce = NULL;
    char *dest = NULL;
    size_t len = 0;
    size_t read = 0;
    while(read != -1) {
        read = getline(&srce, &len, stdin);
        if (read == -1)
            break;
        dest = (char *)malloc(len); 
        encode(srce, dest);
        fputs(dest, stdout);
        free(dest);
    }   
}

int main(int argc, char **argv) {
    process();
    // return run_all_tests();
    return 0;
}

