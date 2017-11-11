#include <stdio.h>
#include <stdlib.h>

#define MAXGROUPS 4000
struct {
    char   chr;
    size_t len;
} groups[MAXGROUPS];

int maxg = 0;

void make_groups(char *srce) {
    maxg = 0;
    char last   = '\0';
    char c;
    while ((c = *srce++)!='\n') {
        if(c != last || (maxg>0 && groups[maxg-1].len==9)) {
            if(maxg<MAXGROUPS) {
                groups[maxg].chr = c;
                groups[maxg].len = 1;
                maxg++;
            }
            last = c;
        }
        else {
            groups[maxg-1].len++;
        }
    }
}

void print_groups() {
    int last_len = 0;
    for(int g = 0; g < maxg; g++) {
        if(groups[g].len > 1) {
            if (last_len == 1) 
                fputc('1', stdout);
            fputc(groups[g].len + '0', stdout);
            fputc(groups[g].chr, stdout);
        } else {
            if(last_len > 1 || g == 0) 
                fputc('1', stdout);
            if(groups[g].chr == '1') 
                fputc('1', stdout);
            fputc(groups[g].chr, stdout);
        }
        last_len = groups[g].len;
    }
    if(last_len == 1) 
        fputc('1', stdout);
}
            
    
void encode(char *srce) {
    make_groups(srce);
    print_groups();
    fputc('\n', stdout);
}

void process() {
    char *srce = NULL;
    size_t len = 0;
    size_t read = 0;
    while(read != -1) {
        read = getline(&srce, &len, stdin);
        if (read == -1)
            break;
        encode(srce);
    }   
}

int main(int argc, char **argv) {
    process();
    return 0;
}
