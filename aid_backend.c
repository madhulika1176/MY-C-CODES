#include <string.h>
#include <stdio.h>

void get_instruction(const char* symptom, char* result) {
    FILE *file = fopen("instructions.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, symptom) == line) {
            strcpy(result, strchr(line, ':') + 2);
            fclose(file);
            return;
        }
    }
    strcpy(result, "No instructions found.");
    fclose(file);
}