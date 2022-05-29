#include "textfilewriter.h"
#include "linkedlist.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void verify_input(char*[], int);
void verify_output(char* file_name, char* answer);

int main() {
	char* test_case1[6] = { "music_1", "music_2", "music_3", "music_4", "music_5", "music_6" };

	// read_file test
	read_file("test_text.txt");
	verify_input(test_case1, 6);

	insert_after(get_node(1), get_node(3));
	delete("music_1");
	
	write_file("test_text2");

	verify_output("test_text2", "5\nmusic_6\nmusic_5\nmusic_2\nmusic_4\nmusic_3\n");
	
}

void verify_input(char* answer[], int length) {
	Node* cur = first();
	int i;

	printf("Testing Input\n...\n");
	assert(length == size());

	for (i = 0; i < length; ++i) {
		assert(strcmp(answer[i], cur->data) == 0);
		cur = cur->next;
	}

	printf("Ok.\n\n");
}

void verify_output(char* file_name, char* answer) {
	FILE* f = fopen(file_name, "r");
	long lSize;
	char* buffer;

	fseek(f, 0, SEEK_END);
	lSize = ftell(f);
	rewind(f);
	
	buffer = (char*)malloc(sizeof(char) * lSize);

	fread(buffer, 1, lSize, f);
	
	printf("%s\n", buffer);

	assert(strcmp(answer, buffer) == 0);

	fclose(f);
	free(buffer);

}


