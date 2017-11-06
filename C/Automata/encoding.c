#include <stdio.h>
#include <stdlib.h>


#define ENCL 0
#define SEQU 1

void output_enclosure(char *sequ, size_t size) {
    if (size <= 0)
        return;
    fputc('1', stdout);
    for(size_t i = 0; i<size; i++) {
        if(*sequ == '1')
            fputc(*sequ, stdout);
        fputc(*sequ++, stdout);
    } 
    fputc('1', stdout);
} 

void output_runlength(char chr, size_t size) {
    fputc(size + '0', stdout);
    fputc(chr, stdout);
}

void encode(char *srce) {
    char chr;
    char last = 0;
    char *sequ = srce;
    int  size = 0;
    int  type = ENCL;
    
    for(;;) {
        chr = *srce;
        if (chr == '\n') {
            if(type == ENCL) 
                output_enclosure(sequ, size);
            else
                output_runlength(last, size);
            break;
        } 
        if (chr == last) {
            if (type == ENCL) {
                output_enclosure(sequ, size-1);
                sequ--;
                size=1;
                type = SEQU;
            }
            else if (size == 9) {
                output_runlength(last, size);
                size = 1;
                sequ = srce;
                type = ENCL;
                srce++;
                continue;
            }
        } else {
            if (type == SEQU) {
                output_runlength(last,size);
                sequ = srce;
                size = 0;
                type = ENCL;
            }
        }
        size++;
        last = chr;
        srce++;
    }
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
    // return run_all_tests();
    return 0;
}
