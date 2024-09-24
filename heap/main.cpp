//#include <iostream>
//using namespace std;
//void heap(int a[],int s,int m){
//    if(m!=0){
//        if(m%2==1){
//            if(a[m]<a[m/2]){
//                int k;
//                k=a[m];
//                a[m]=a[m/2];
//                a[m/2]=k;
//                heap(a,0,m/2);
//            }
//        }
//        else{
//            if(a[m]<a[m/2-1]){
//                int k;
//                k=a[m];
//                a[m]=a[m/2-1];
//                a[m/2-1]=k;
//                heap(a,0,m/2-1);
//            }
//        }
//    }
//}
//int main() {
//    int n;
//    cin>>n;
//    int num[100];
//    for(int i=0;i<n;i++){
//        cin>>num[i];
//        heap(num,0,i);
//    }
//    for(int i=0;i<n;i++){
//        cout<<num[i]<<" ";
//    }
//    return 0;
//}
#include <stdio.h>
#define MAXN 100 //定义最大元素个数

//交换数组中的两个元素
void swap(int a[], int i, int j) { int temp = a[i]; a[i] = a[j]; a[j] = temp; }

//调整数组中的某个元素，使其满足小顶堆的性质
void adjust(int a[], int i, int n) { int min = i; //记录最小元素的下标
 int left = 2 * i + 1; //左孩子的下标
 int right = 2 * i + 2; //右孩子的下标 //如果左孩子存在且比当前最小元素小，更新最小元素的下标
  if (left < n && a[left] < a[min]) { min = left; } //如果右孩子存在且比当前最小元素小，更新最小元素的下标
   if (right < n && a[right] < a[min]) { min = right; } //如果最小元素的下标不是i，说明需要调整
   if (min != i) { //交换a[i]和a[min]]
        swap(a, i, min); //递归地调整a[min]，使其满足小顶堆的性质
         adjust(a, min, n); } }

////建立小顶堆
//void build_heap(int a[], int n) { //从最后一个非叶子节点开始，自下而上地调整每个元素
//     for (int i = n / 2 - 1; i >= 0; i--) { adjust(a, i, n); } }
//
////堆排序
//void heap_sort(int a[], int n) { //建立小顶
//     build_heap(a, n); //输出堆顶元素，并将其与最后一个元素交换，然后调整剩余的元素
//      for (int i = n - 1; i > 0; i--) { printf("%d ", a[0]); //输出堆顶元素
//       swap(a, 0, i); //交换堆顶元素和最后一个元素
//        adjust(a, 0, i);  }
//      printf("%d\n", a[0]);}
//
//int main
//
// () { int n; int a[MAXN];scanf("%d", &n); for (int i = 0; i < n; i++) { scanf("%d", &a[i]); }  heap_sort(a, n); return 0; }
#include<iostream>
#include<vector>
using namespace std;

//构建小顶堆 递归~~~
//len 是 num长度 index是第一个非叶子节点的下标
//确保此节点符合标准
void adjust2min(vector<int> &num, int len, int index) {
    int l = 2 * index + 1;  //左子节点
    int r = 2 * index + 2;  //右子节点

    int minIdx = index;
    if (l < len && num[l] < num[minIdx]) {
        minIdx = l;
    }
    if (r < len && num[r] < num[minIdx]) {
        minIdx = r;
    }
    if (minIdx != index) {
        swap(num[minIdx], num[index]);
        adjust2min(num, len, minIdx);
    }
}

void heapSort(vector<int> &num, int size) {
    //构建小根堆（从最后一个非叶子节点向上）
    for (int i = size / 2 - 1; i >= 0; i--) {
        adjust2min(num, size, i);
    }

    //调整小根堆（题干未要求）
//	for (int i = size - 1; i >= 1; i--) {
//		swap(num[0], num[i]); //尾部最小
//		adjust2min(num, i, 0); //继续堆排序
//	}
}

int main() {

    vector<int> num;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        num.push_back(k);
    }
    heapSort(num, num.size());
    for (int i = 0; i < n; i++) {
        cout << num[i] << ' ';
    }


}