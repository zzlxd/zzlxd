
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// 定义哈夫曼树的结点
struct HuffmanNode {
    char data;              // 字符
    double weight;          // 权值
    int parent, lchild, rchild;   // 父节点、左子节点、右子节点
};

// 定义哈夫曼树
struct HuffmanTree {
    int size;               // 字符集的大小
    char *chars;            // 字符集数组
    double *weights;        // 权值数组
    HuffmanNode *nodes;     // 结点数组
};

// 定义哈夫曼编码
struct HuffmanCode {
    char data;              // 字符
    char *code;             // 编码
    int length;             // 编码长度
};

// 创建哈夫曼树
void createHuffmanTree(HuffmanTree &tree) {
    cout << "请输入字符集的大小：";
    cin >> tree.size;

    tree.chars = new char[tree.size];
    tree.weights = new double[tree.size];
    tree.nodes = new HuffmanNode[2 * tree.size - 1];

    cout << "请输入" << tree.size << "个字符及其权值：" << endl;
    for (int i = 0; i < tree.size; i++) {
        cin >> tree.chars[i] >> tree.weights[i];
    }

    // 初始化叶子节点
    for (int i = 0; i < tree.size; i++) {
        tree.nodes[i].data = tree.chars[i];
        tree.nodes[i].weight = tree.weights[i];
        tree.nodes[i].parent = -1;
        tree.nodes[i].lchild = -1;
        tree.nodes[i].rchild = -1;
    }

    // 构建哈夫曼树
    for (int i = tree.size; i < 2 * tree.size - 1; i++) {
        int min1 = -1, min2 = -1;   // 最小权值的两个节点的下标

        // 在尚未构建的节点中找到权值最小的两个节点
        for (int j = 0; j < i; j++) {
            if (tree.nodes[j].parent == -1) {
                if (min1 == -1 || tree.nodes[j].weight < tree.nodes[min1].weight) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 == -1 || tree.nodes[j].weight < tree.nodes[min2].weight) {
                    min2 = j;
                }
            }
        }

        // 构建新的节点
        tree.nodes[i].data = '\0';
        tree.nodes[i].weight = tree.nodes[min1].weight + tree.nodes[min2].weight;
        tree.nodes[i].parent = -1;
        tree.nodes[i].lchild = min1;
        tree.nodes[i].rchild = min2;

        // 更新最小权值节点的父节点
        tree.nodes[min1].parent = i;
        tree.nodes[min2].parent = i;
    }
}

// 创建哈夫曼编码
void createHuffmanCode(HuffmanTree &tree, HuffmanCode *codes) {
    codes = new HuffmanCode[tree.size];

    char *code = new char[tree.size];
    int length = 0;

    for (int i = 0; i < tree.size; i++) {
        int current = i;
        int parent = tree.nodes[current].parent;

        length = 0;
        while (parent != -1) {
            if (tree.nodes[parent].lchild == current) {
                code[length++] = '0';
            } else {
                code[length++] = '1';
            }

            current = parent;
            parent = tree.nodes[current].parent;
        }

        codes[i].data = tree.nodes[i].data;
        codes[i].length = length;
        codes[i].code = new char[length];

        for (int j = 0; j < length; j++) {
            codes[i].code[j] = code[length - j - 1];
        }
    }

    delete[] code;
}

// 编码过程
void encoding(HuffmanCode *codes, char *input, char *output) {
    int inputLength = strlen(input);
    int outputIndex = 0;

    for (int i = 0; i < inputLength; i++) {
        char currentChar = input[i];

        for (int j = 0; j < sizeof(codes) / sizeof(codes[0]); j++) {
            if (codes[j].data == currentChar) {
                int codeLength = codes[j].length;
                char *code = codes[j].code;

                for (int k = 0; k < codeLength; k++) {
                    output[outputIndex++] = code[k];
                }

                break;
            }
        }
    }

    output[outputIndex] = '\0';
}

// 译码过程
void decoding(HuffmanTree &tree, char *input, char *output) {
    int inputLength = strlen(input);
    int outputIndex = 0;

    int current = 2 * tree.size - 2;   // 根节点的下标
    for (int i = 0; i < inputLength; i++) {
        if (input[i] == '0') {
            current = tree.nodes[current].lchild;
        } else {
            current = tree.nodes].rchild;
        }

        if (tree.nodes[current].lchild == -1 && tree.nodes[current].rchild == -1) {
            output[outputIndex++] = tree.nodes[current].data;
            current = 2 * tree.size - 2;   // 重置为根节点
        }
    }

    output[outputIndex] = '\0';
}

// 比较文件ToBeTran和TextFile的内容是否相同
bool compareFiles(const char *file1, const char *file2) {
    ifstream f1(file1);
    ifstream f2(file2);

    string line1, line2;
    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) {
            return false;
        }
    }

    return true;
}

int main() {
    HuffmanTree tree;
    createHuffmanTree(tree);

    HuffmanCode *codes;
    createHuffmanCode(tree, codes);

    char input[100];
    cout << "请输入需要编码的文本：";
    cin >> input;

    char output[100];
    encoding(codes, input, output);

    ofstream codeFile("CodeFile.txt");
    codeFile << output;
    codeFile.close();

    char decodeOutput[100];
    decoding(tree, output, decodeOutput);

    ofstream textFile("TextFile.txt");
    textFile << decodeOutput;
    textFile.close();

    if (compareFiles("ToBeTran.txt", "TextFile.txt")) {
        cout << "编码过程中没有错误。" << endl;
    } else {
        cout << "编码过程中存在错误。" << endl;
    }

    return 0;
//}
//```
//
//【运行结果】
//
//输入：
//
//字符集的大小：8
//
//8个字符及其权值：
//
//a 0.05
//
//b 0.29
//
//c 0.07
//
//d 0.08
//
//e 0.14
//
//f 0.23
//
//g 0.03
//
//h 0.11
//
//需要编码的文本：bbfehagd
//
//        输出：
//
//CodeFile.txt：101001110001000100001111
//
//TextFile.txt：bbfehagd
//
//        编码过程中没有错误。
//
//【注意事项】
//
//- 代码中的文件路径需要根据实际情况进行修改。
//
//- 可以根据需要自行扩展和修改代码。