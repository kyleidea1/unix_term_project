#include "../include/linkedlist.h"
#include <assert.h>
#include <string.h>

void verify(char*, char*[], int);

int main() {
    char* testCase1[] = { "music_3", "music_4", "music_5" };
    char* testCase2[] = {"music_1", "music_2", "music_3", "music_4", "music_5"};
    char* testCase3[] = {"music_1", "music_2", "music_4","music_3", "music_5"};
    char* testCase4[] = {"music_1", "music_4", "music_3", "music_5"};
    char* testCase5[] = {"music_1", "music_4", "music_3"};

    append(8, "music_3");
    append(8, "music_4");
    append(8, "music_5");
    verify("append", testCase1, 3);

    append_left(8, "music_2");
    append_left(8, "music_1");
    verify("append_left", testCase2, 5);

    Node* cur = get_node(2);
    insert_after(cur, get_node(3));
    char* temp = testCase2[2];
    testCase2[2] = testCase2[3];
    testCase2[3] = temp;
    verify("insert_after", testCase3, 5);

    cur = get_node(1);
    delete_node(cur);
    verify("delete_node", testCase4, 4);

    delete("music_5");
    verify("delete", testCase5, 3);

    return 0;
}

void verify(char* function_name, char* answer[], int length) {
    Node* cur = first();
    int i;

    printf("Testing %s\n...\n", function_name);
    assert(length == size());

    for (i = 0; i < length; ++i) {
        assert(strcmp(answer[i], cur->data) == 0);
        cur = cur->next;
    }
    printf("Ok.\n\n");
}
