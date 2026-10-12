#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    if (new_node == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// 头插
void insert_at_head(Node** head, int n) {
    Node* new_node = create_node(n);
    if (new_node == NULL) return;
    
    new_node->next = *head;
    *head = new_node;
}

// 尾插
void insert_at_tail(Node** head, int n) {
    Node* new_node = create_node(n);
    if (new_node == NULL) return;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// 打印
void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//查找元素
int find_node(Node* head, int n){
    Node* temp = head;
    int index = 1;
    
    while(temp != NULL){
        if(temp->data == n){
            return index;
        }
        temp = temp->next;
        index++;

    }
    return -1;
}

//删除
int delete_node(Node** head, int n) {
    if (*head == NULL || n <= 0) return 0;

        if (n == 1) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return 1;
    }

    Node* prev = *head;
    Node* curr = (*head)->next;
    int count = 2;

    while (curr != NULL && count < n) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == NULL) return 0;

    prev->next = curr->next;
    free(curr);
    return 1;
}

//反转
Node* reverse_list(Node* head) {
    Node* prev = NULL; 
    Node* curr = head; 
    Node* next = NULL; 

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;      
        curr = next;      
    }
    return prev; 
}

int main(void) {
    printf("=== 1. 初始化链表 ===\n");
    Node *head = create_node(0);
    insert_at_tail(&head, 20);
    insert_at_tail(&head, 30);
    insert_at_tail(&head, 40);
    printf("初始链表：");
    print_list(head); // 预期：0->20->30->40->NULL

    printf("\n=== 2. 测试头插 ===\n");
    insert_at_head(&head, 10);
    printf("头插 10 后：");
    print_list(head); // 预期：10->0->20->30->40->NULL

    printf("\n=== 3. 测试查找 ===\n");
    int pos = find_node(head, 20);
    if (pos != -1) {
        printf("找到数据 20，位置是：第 %d 个节点\n", pos); // 预期：第 3 个
    }
    
    pos = find_node(head, 99);
    if (pos == -1) {
        printf("数据 99 不存在于链表中\n");
    }

    printf("\n=== 4. 测试删除 ===\n");
    if (delete_node(&head, 2) == 1) {
        printf("删除第 2 个节点后：");
        print_list(head); // 预期：10->20->30->40->NULL
    }
    
    if (delete_node(&head, 10) == 0) {
        printf("链表节点数不足，删除第 10 个节点失败\n");
    }

    printf("\n=== 5. 测试反转 ===\n");
    head = reverse_list(head); // 必须用 head 接住新头指针
    printf("反转后链表：");
    print_list(head); // 预期：40->30->20->10->NULL

    return 0;
}