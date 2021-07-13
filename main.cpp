#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

FILE * readFile(char ** dirList, uint32_t index = 1, const char * mode = "rb") {
    return fopen(dirList[index], mode);
}

void fixByteOrder (uint32_t * n) {
    (*n) = ntohl(*n);
}

void printResult(uint32_t _1, uint32_t _2, uint32_t _3) {
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", _1, _1, _2, _2, _3, _3);
}

int main(int argc, char ** argv) {
    FILE * firstFP = readFile(argv, 1);
    FILE * secondFP = readFile(argv, 2);

    uint32_t firstNum;
    fread(&firstNum, sizeof(uint32_t), 1, firstFP);
    fixByteOrder(&firstNum);

    uint32_t secondNum;
    fread(&secondNum, sizeof(uint32_t), 1, secondFP);
    fixByteOrder(&secondNum);

    printResult(firstNum, secondNum, firstNum + secondNum);
    
    fclose(firstFP);
    fclose(secondFP);
}