#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t read_uint32_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    uint32_t number;
    size_t read_size = fread(&number, sizeof(uint32_t), 1, file);
    if (read_size != 1) {
        perror("Error reading file");
        fclose(file);
        return 0;
    }

    fclose(file);
    return ntohl(number);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    uint32_t num1 = read_uint32_from_file(argv[1]);
    uint32_t num2 = read_uint32_from_file(argv[2]);
    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);
    return 0;
}

