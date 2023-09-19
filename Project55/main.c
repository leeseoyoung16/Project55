#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    double data; 
    struct TreeNode* left, * right;
} TreeNode;

// 2+3+4*5-6/7+9
TreeNode n1 = { 4.00, NULL, NULL };
TreeNode n2 = { 5.00, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 3.00, NULL, NULL };
TreeNode n5 = { '+', &n3, &n4 };
TreeNode n6 = { 2.00, NULL, NULL };
TreeNode n7 = { '+', &n5, &n6 };
TreeNode n8 = { 6.00, NULL, NULL };
TreeNode n9 = { 7.00, NULL, NULL };
TreeNode n10 = { '/', &n8, &n9 };
TreeNode n11 = { '-', &n7, &n10 };
TreeNode n12 = { 9.00, NULL, NULL };
TreeNode n13 = { '+', &n11, &n12 };
TreeNode* exp = &n13;

double evaluate(TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    else {
        double op1 = evaluate(root->left);
        double op2 = evaluate(root->right);
        printf("%.2lf %c %.2lf = ", op1, (char)root->data, op2);
        switch ((char)root->data) {
        case '+':
            printf("%.2lf\n", op1 + op2);
            return op1 + op2;
        case '-':
            printf("%.2lf\n", op1 - op2);
            return op1 - op2;
        case '*':
            printf("%.2lf\n", op1 * op2);
            return op1 * op2;
        case '/':
            printf("%.2lf\n", op1 / op2);
            return op1 / op2;
        }
    }
    return 0;
}

//이진 트리의 노드 수를 반복적 방법으로 계산하고 출력.
int get_node_count(TreeNode* root) {
    if (root == NULL)
        return 0;

    int count = 0;
    TreeNode* stack[100]; 
    int top = -1; 

    stack[++top] = root; 

    while (top >= 0) {
        TreeNode* current = stack[top--]; 
        count++;

        if (current->right)
            stack[++top] = current->right;
        if (current->left)
            stack[++top] = current->left; 
    }

    return count;
}

int main(void) {
    printf("수식의 값은 %.2lf입니다. \n\n", evaluate(exp));
    printf("총 노드의 수는 %d개 입니다. \n", get_node_count(exp));
}