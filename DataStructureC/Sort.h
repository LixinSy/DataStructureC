
#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>
using namespace std;

///简单插入排序，稳定，时间复杂度O(n^2)，空间复杂度O(1)
void InsertSort(vector<int> &vec)
{
    int j, tmp;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < vec[i-1])
        {
            tmp = vec[i];
            for (j = i-1; j < vec.size() && j >= 0 && tmp < vec[j]; j -= 1)
            {
                vec[j+1] = vec[j];
            }
            vec[j+1] = tmp;
        }
    }
}

///shell排序， 不稳定，时间复杂度不能确定，空间复杂度O(1)
void Shell(vector<int> &vec, int dlta)
{
    int j, tmp;
    for (int i = dlta; i < vec.size(); i += 1)
    {
        if (vec[i] < vec[i-dlta])
        {
            tmp = vec[i];
            for (j = i-dlta; j < vec.size() && tmp < vec[j]; j -= dlta)
            {
                vec[j+dlta] = vec[j];
            }
            vec[j+dlta] = tmp;
        }
    }
}
void ShellSort(vector<int> &vec)
{
    //dltas里的值应该为质数，且最后一个必须为1
    vector<int> dltas = {5, 3, 1};
    for (int i=0; i < dltas.size(); i++)
    {
        Shell(vec, dltas[i]);
    }
}


///简单冒泡排序，稳定，时间复杂度O(n^2)，空间复杂度O(1)
void BubbleSort(vector<int> &vec)
{
    int tmp;
    for (int i=1; i <= vec.size()-1; i++) //len-1趟排序
    {
        for (int j=0; j < vec.size()-i; j++) //每趟len-i次比较
        {
            if (vec[j] > vec[j+1])
            {
                tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
        }
    }
}

///快速排序， 不稳定，时间复杂度O(nlogn)，空间复杂度O(logn)
/// 1、每次Partition便确定一个数pivot_key的位置，且pivot_key都大于左边的数，都小于右边的数
int Partition(vector<int> &vec, int low, int high)
{
    int pivot_key = vec[low];
    while(low < high)
    {
        while(low < high && pivot_key <= vec[high])
            high --;
        vec[low] = vec[high];
        while(low < high && pivot_key >= vec[low])
            low ++;
        vec[high] = vec[low];
    }
    //最终 low == high
    vec[low] = pivot_key;
    return low;
}
void QSort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        //执行一次Partition，pivot_key的位置便确定在pivot_loc
        int pivot_loc = Partition(vec, low, high);
        QSort(vec, low, pivot_loc-1);
        QSort(vec, pivot_loc+1, high);
    }
}
void QuickSort(vector<int> &vec)
{
    QSort(vec, 0, vec.size()-1);
}


///简单选择排序，不稳定，时间复杂度O(n^2)，空间复杂度O(1)
void SelectSort(vector<int> &vec)
{
    int tmp, k;
    for (int i = 0; i < vec.size()-1; i++)
    {
        k = i;//k 为最小值的index
        for (int j=i+1; j<vec.size(); j++)
        {
            if (vec[j] < vec[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            tmp = vec[i];
            vec[i] = vec[k];
            vec[k] = tmp;
        }
    }
}

///堆排序， 不稳定，时间复杂度O(nlogn)，空间复杂度O(1)
/// 1、用顺序表表示完全二叉树
/// 2、从 n / 2个节点开始Adjust，最后一个节点的父节点
/// 3、heap的index从 1 开始, heap[0]可以当作tmp
void HeapAdjust(vector<int>& heap, int parent_index, int last_index)
{
    //HeapAdjust方向是从上往下
    heap[0] = heap[parent_index];
    int index = 2*parent_index;
    for (; index <= last_index; index = 2*index)
    {
        if (index < last_index && heap[index] < heap[index+1])
            index ++;
        if (heap[0] < heap[index])
        {
            heap[parent_index] = heap[index];
            parent_index = index;
        }
    }
    heap[parent_index] = heap[0];
}
void HeapSort(vector<int>& vec)
{
    //构建大（小）顶堆方向从下往上
    vector<int> heap = {0};
    heap.insert(heap.end(), vec.begin(), vec.end());
    for (int i= (heap.size()-1)/2; i > 0; i--)
    {
        HeapAdjust(heap, i, heap.size()-1);
    }
    for (int i=heap.size()-1; i>1; i--)
    {
        heap[0] = heap[1];
        heap[1] = heap[i];
        heap[i] = heap[0];
        HeapAdjust(heap, 1, i-1);
    }
    vec.assign(heap.begin()+1, heap.end());
}


///归并排序， 稳定，时间复杂度O(nlogn)，空间复杂度O(n)
void Merge(vector<int> &src, vector<int> &dst, int start, int mid, int last)
{
    int li = start, ri = mid+1, j = start;
    for (; li <= mid && ri <= last; j++)
    {
        if (src[li] > src[ri])
        {
            dst[j] = src[ri++];
        }
        else
        {
            dst[j] = src[li++];
        }
    }
    while (li <= mid)
    {
        dst[j] = src[li++];
        j++;
    }
    while (ri <= last)
    {
        dst[j] = src[ri++];
        j++;
    }
}
void MSort(vector<int> &src, vector<int> &dst, int start, int last)
{
    if (start == last)
    {   //边界条件
        //dst[start] = src[start];
        return;
    }
    else
    {
        int mid = (start+last) / 2;
        MSort(dst, src, start, mid);
        MSort(dst, src, mid+1, last);
        Merge(src, dst, start, mid, last);
    }
}
void MergeSort(vector<int> &vec)
{
    if (vec.size() <= 1)
        return;
    vector<int> tmp = vec;
    MSort(tmp, vec, 0, vec.size()-1);
}


/// 基数排序， 稳定，时间复杂度O(d(n+r))，空间复杂度O(r)
/// 数字排序中：r=10, d=最大数字位数，n=元素个数
/// 一趟分配O(n)，一趟收集O(r)，进行d趟分配和收集，则时间复杂度为O(d(n+r))
void RadixSort()
{

}


#endif
