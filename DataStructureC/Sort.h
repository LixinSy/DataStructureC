
#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>
using namespace std;

///�򵥲��������ȶ���ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
void InsertSort(vector<int> &vec)
{
    int j, tmp;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < vec[i-1])
        {
            tmp = vec[i];
            for (j = i-1; j < vec.size() && tmp < vec[j]; j -= 1)
            {
                vec[j+1] = vec[j];
            }
            vec[j+1] = tmp;
        }
    }
}

///shell���� ���ȶ���ʱ�临�ӶȲ���ȷ�����ռ临�Ӷ�O(1)
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
    //dltas���ֵӦ��Ϊ�����������һ������Ϊ1
    vector<int> dltas = {5, 3, 1};
    for (int i=0; i < dltas.size(); i++)
    {
        Shell(vec, dltas[i]);
    }
}


///��ð�������ȶ���ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
void BubbleSort(vector<int> &vec)
{
    int tmp;
    for (int i=1; i <= vec.size()-1; i++) //len-1������
    {
        for (int j=0; j < vec.size()-i; j++) //ÿ��len-i�αȽ�
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

///�������� ���ȶ���ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(logn)
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
    //���� low == high
    vec[low] = pivot_key;
    return low;
}
void QSort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        //ִ��һ��Partition��pivot_key��λ�ñ�ȷ����pivot_loc
        int pivot_loc = Partition(vec, low, high);
        QSort(vec, low, pivot_loc-1);
        QSort(vec, pivot_loc+1, high);
    }
}
void QuickSort(vector<int> &vec)
{
    QSort(vec, 0, vec.size()-1);
}


///��ѡ�����򣬲��ȶ���ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
void SelectSort(vector<int> &vec)
{
    int tmp, k;
    for (int i = 0; i < vec.size()-1; i++)
    {
        k = i;//k Ϊ��Сֵ��index
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

///������ ���ȶ���ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)
/// 1����˳����ʾ��ȫ������
/// 2���� n / 2���ڵ㿪ʼAdjust
/// 3��heap��index�� 1 ��ʼ, heap[0]���Ե���tmp
void HeapAdjust(vector<int>& heap, int parent_index, int last_index)
{
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
void HeapSort(vector<int>& heap)
{
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
}


///�鲢���� �ȶ���ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(n)
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
    {   //�߽�����
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


/// �������� �ȶ���ʱ�临�Ӷ�O(d(n+r))���ռ临�Ӷ�O(r)
/// ���������У�r=10, d=�������λ����n=Ԫ�ظ���
/// һ�˷���O(n)��һ���ռ�O(r)������d�˷�����ռ�����ʱ�临�Ӷ�ΪO(d(n+r))
void RadixSort()
{

}


#endif
