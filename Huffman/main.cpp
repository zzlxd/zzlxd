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

// 初始化函数
void initialize(HuffmanTree *tree) {
    int n;
    printf("请输入字符集的大小n：");
    scanf("%d", &n);

    tree->size = 2 * n - 1;
    tree->nodes = (HuffmanNode *)malloc(tree->size * sizeof(HuffmanNode));

    for (int i = 0; i < n; i++) {
        printf("请输入第%d个字符及其权值：", i + 1);
        scanf(" %c%f", &(tree->nodes[i].character), &(tree->nodes[i].weight));
        tree->nodes[i].parent = -1;
        tree->nodes[i].leftChild = -1;
        tree->nodes[i].rightChild = -1;
    }//输入

    for (int i = n; i < tree->size; i++) {
        tree->nodes[i].character = '\0';
        tree->nodes[i].weight = 0;
        tree->nodes[i].parent = -1;
        tree->nodes[i].leftChild = -1;
        tree->nodes[i].rightChild = -1;
    }//后n个初始化

    // 构建哈夫曼树
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
        }//找出最小的两个节点

        tree->nodes[i].weight = tree->nodes[min1_idx].weight + tree->nodes[min2_idx].weight;//父节点权重是最小两个之和
        tree->nodes[i].leftChild = min1_idx;//左孩子最小
        tree->nodes[i].rightChild = min2_idx;//右孩子其次
        tree->nodes[min1_idx].parent = i;//将左右两个孩子指向父节点
        tree->nodes[min2_idx].parent = i;
    }
}

// 编码函数
void encode(HuffmanTree *tree, HuffmanCode *code, char *originalText, char *encodedText) {
    int n = tree->size / 2 + 1;

    // 构建编码表
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
                code->codes[i][bitIndex++] = '0';//左孩子为0
            } else {
                code->codes[i][bitIndex++] = '1';//右孩子为1
            }

            current = parent;
            parent = tree->nodes[current].parent;
        }//这里仅仅只有反转的编码因为是从最后往前面编写

        // 反转编码字符
        for (int j = 0; j < bitIndex / 2; j++) {
            char temp = code->codes[i][j];
            code->codes[i][j] = code->codes[i][bitIndex - j - 1];
            code->codes[i][bitIndex - j - 1] = temp;
        }

        code->codes[i][bitIndex] = '\0';
    }

    // 使用哈夫曼树进行编码
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

// 译码函数(D)
    void decode(HuffmanTree *tree, HuffmanCode *code, char *encodedText, char *decodedText) {
    int n = tree->size / 2 + 1;

    int index = 0;
    int current = 2 * n - 2;

    for (int i = 0; encodedText[i] != '\0'; i++) {
        if (encodedText[i] == '0') {//如果为零往左边找
            current = tree->nodes[current].leftChild;
        } else if (encodedText[i] == '1') {//否则往右边
            current = tree->nodes[current].rightChild;
        }

        if (tree->nodes[current].leftChild == -1 && tree->nodes[current].rightChild == -1) {
            decodedText[index++] = tree->nodes[current].character;
            current = 2 * n - 2;
        }
    }

    decodedText[index] = '\0';
}

// 文本比较函数(V)
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

    printf("请输入需要编码的文本:");
    scanf("%s", originalText);
    encode(&tree, &code, originalText, encodedText);
    printf("编码后的结果为：%s\n", encodedText);
    decode(&tree, &code, encodedText, decodedText);
    printf("译码后的结果为：%s\n", decodedText);
    if (comparetext(originalText, decodedText)) {
        printf("编译码过程中存在错误\n");
    } else {
        printf("编译码过程正确\n");
    }

    return 0;
}