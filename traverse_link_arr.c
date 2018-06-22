#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 40
#define SENTINAL_LOC -1

static int
traverse(int link_arr[], int value_arr[], int loc)
{
    return 0;
}

static int
insert_elem(int *head, int link_arr[], int val_arr[], int *length, int link, int val)
{
    int *cur_idx = head;
    int iter = 0;

    if (link > *length) {
        return -1;
    }

    if (*length == MAX_LEN) {
        return -1;
    }

    if (link < 0) {
        return -1;
    }

    for(iter = 0; iter < link; iter++) {
        cur_idx = &link_arr[*cur_idx];
    }

    val_arr[*length] = val;
    link_arr[*length] = *cur_idx;
    *cur_idx = *length;
    *length += 1;

    return 0;
}

static void
fill_up(int link_arr[], int val_arr[], int dummy_fill_cnt)
{
   
}

static void
test_print(int head, int link_arr[], int val_arr[], int n)
{
    int i = 0;

    printf("\n");

    printf("Head: %d \n", head);
    for(i = 0; i < n; i++) {
        printf(" %d -> %d", i, link_arr[i]);
    }
}

int
main(int argc, char* argv[])
{
    int link_arr[MAX_LEN] = { [0 ... MAX_LEN -1] = SENTINAL_LOC};
    int val_arr[MAX_LEN] = { [0 ... MAX_LEN -1] = 0};

    int length;
    int i;
    int last = -1;
    int test_count = 0;
    int head = 0;

    scanf("%d", &length);

    scanf("%d", &val_arr[i]);
    for (i = 1; i < length; i++) {
        scanf("%d", &val_arr[i]);
        link_arr[i-1] = i;
    }

    link_arr[i-1] = SENTINAL_LOC;

    test_print(head, link_arr, val_arr, length);
    scanf("%d", &test_count);

    while(test_count > 0) {
        int pos = SENTINAL_LOC;
        int val;
        scanf("%d %d", &pos, &val);
        insert_elem(&head, link_arr, val_arr, &length, pos, val);
        test_print(head, link_arr, val_arr, length);
        test_count--;
    }

    return 0;
}

