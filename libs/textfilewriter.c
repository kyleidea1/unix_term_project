#include<stdio.h>
#include<string.h>

#define MAX_TITLE_SIZE 50

void creat_music_title(FILE* stram);

void read_file(char* file_name);

void write_file(char* file_name);include <string.h>
#include "../include/textfilewriter.h"
#include "../include/linkedlist.h"

#define MAX_TITLE_SIZE 50

void create_music_titles(FILE* stream) {
    int count = 0;
    char buffer[MAX_TITLE_SIZE];
    fscanf(stream, "%d", &count);
    clear();
    while (count-->0) {
        fscanf(stream, "%s", buffer);
        append_left(strlen(buffer), buffer);
    }
}

void read_file(char* file_name) {
    FILE* f = fopen(file_name, "r");
    create_music_titles(f);
    fclose(f);
}

void write_file(char* file_name) {
    FILE* f = fopen(file_name, "w");
    print_file(f);
    fclose(f);
}
