#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 100
#define MAX_BIT_LENGTH 50

typedef struct HuffmanNode {
    char character;
    float weight;
    int parent;
    int leftChild;
    int rightChild;
} HuffmanNode;

typedef struct HuffmanTree {
    int size;
    HuffmanNode *nodes;
} HuffmanTree;

typedef struct HuffmanCode {
    int size;
    char **codes;
} HuffmanCode;

// ��ʼ������
void initialize(HuffmanTree *tree) {
    int n;
    printf("�������ַ����Ĵ�Сn��");
    scanf("%d", &n);

    tree->size = 2 * n - 1;
    tree->nodes = (HuffmanNode *)malloc(tree->size * sizeof(HuffmanNode));

    for (int i = 0; i < n; i++) {
        printf("�������%d���ַ�����Ȩֵ��", i + 1);
        scanf(" %c%f", &(tree->nodes[i].character), &(tree->nodes[i].weight));
        tree->nodes[i].parent = -1;
        tree->nodes[i].leftChild = -1;
        tree->nodes[i].rightChild = -1;
    }//����

    for (int i = n; i < tree->size; i++) {
        tree->nodes[i].character = '\0';
        tree->nodes[i].weight = 0;
        tree->nodes[i].parent = -1;
        tree->nodes[i].leftChild = -1;
        tree->nodes[i].rightChild = -1;
    }//��n����ʼ��

    // ������������
    for (int i = n; i < tree->size; i++) {
        int min1_idx = -1;
        int min2_idx = -1;

        for (int j = 0; j < i; j++) {
            if (tree->nodes[j].parent == -1) {
                if (min1_idx == -1 || tree->nodes[j].weight < tree->nodes[min1_idx].weight) {
                    min2_idx = min1_idx;
                    min1_idx = j;
                } else if (min2_idx == -1 || tree->nodes[j].weight < tree->nodes[min2_idx].weight) {
                    min2_idx = j;
                }
            }
        }//�ҳ���С�������ڵ�

        tree->nodes[i].weight = tree->nodes[min1_idx].weight + tree->nodes[min2_idx].weight;//���ڵ�Ȩ������С����֮��
        tree->nodes[i].leftChild = min1_idx;//������С
        tree->nodes[i].rightChild = min2_idx;//�Һ������
        tree->nodes[min1_idx].parent = i;//��������������ָ�򸸽ڵ�
        tree->nodes[min2_idx].parent = i;
    }
}

// ���뺯��
void encode(HuffmanTree *tree, HuffmanCode *code, char *originalText, char *encodedText) {
    int n = tree->size / 2 + 1;

    // ���������
    code->size = n;
    code->codes = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        code->codes[i] = (char *)malloc(MAX_BIT_LENGTH * sizeof(char));
    }

    for (int i = 0; i < n; i++) {
        int current = i;
        int parent = tree->nodes[current].parent;
        int bitIndex = 0;

        while (parent != -1) {
            if (tree->nodes[parent].leftChild == current) {
                code->codes[i][bitIndex++] = '0';//����Ϊ0
            } else {
                code->codes[i][bitIndex++] = '1';//�Һ���Ϊ1
            }

            current = parent;
            parent = tree->nodes[current].parent;
        }//�������ֻ�з�ת�ı�����Ϊ�Ǵ������ǰ���д

        // ��ת�����ַ�
        for (int j = 0; j < bitIndex / 2; j++) {
            char temp = code->codes[i][j];
            code->codes[i][j] = code->codes[i][bitIndex - j - 1];
            code->codes[i][bitIndex - j - 1] = temp;
        }

        code->codes[i][bitIndex] = '\0';
    }

    // ʹ�ù����������б���
    int index = 0;
    for (int i = 0; originalText[i] != '\0'; i++) {
        for (int j = 0; j < n; j++) {
            if (originalText[i] == tree->nodes[j].character) {
                strcat(encodedText, code->codes[j]);
                index += strlen(code->codes[j]);
                break;
            }
        }
    }

    encodedText[index] = '\0';
}

// ���뺯��(D)
    void decode(HuffmanTree *tree, HuffmanCode *code, char *encodedText, char *decodedText) {
    int n = tree->size / 2 + 1;

    int index = 0;
    int current = 2 * n - 2;

    for (int i = 0; encodedText[i] != '\0'; i++) {
        if (encodedText[i] == '0') {//���Ϊ���������
            current = tree->nodes[current].leftChild;
        } else if (encodedText[i] == '1') {//�������ұ�
            current = tree->nodes[current].rightChild;
        }

        if (tree->nodes[current].leftChild == -1 && tree->nodes[current].rightChild == -1) {
            decodedText[index++] = tree->nodes[current].character;
            current = 2 * n - 2;
        }
    }

    decodedText[index] = '\0';
}

// �ı��ȽϺ���(V)
int    comparetext(char *file1, char *file2) {
    char ch1, ch2;int isDifferent =0;
    while (*file1 != '\0'&&*file2!='\0') {
        if (*file1 != *file2) {
            isDifferent = 1;
            break;
        }
        file1++;
        file2++;
    }
    return isDifferent;
}

int main() {
    HuffmanTree tree;
    HuffmanCode code;
    char originalText[MAX_CHARACTERS];
    char encodedText[MAX_CHARACTERS]="";
    char decodedText[MAX_CHARACTERS]="";

    initialize(&tree);

    printf("��������Ҫ������ı�:");
    scanf("%s", originalText);
    encode(&tree, &code, originalText, encodedText);
    printf("�����Ľ��Ϊ��%s\n", encodedText);
    decode(&tree, &code, encodedText, decodedText);
    printf("�����Ľ��Ϊ��%s\n", decodedText);
    if (comparetext(originalText, decodedText)) {
        printf("����������д��ڴ���\n");
    } else {
        printf("�����������ȷ\n");
    }

    return 0;
}