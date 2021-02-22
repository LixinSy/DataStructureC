#ifndef BALANCED_TREE_HPP
#define BALANCED_TREE_HPP

#include <iostream>

using namespace std;

typedef int ElemType;

const int LH = 1;
const int EH = 0;
const int RH = -1;

struct BBTree
{
    ElemType data;
    struct BBTree *lchild;
    struct BBTree *rchild;
    int bf;         //平衡因子
};


//右旋,顺时针
void r_rotate(BBTree **p)
{
    BBTree *l = (*p)->lchild;
    (*p)->lchild = l->rchild;
    l->rchild = *p;
    *p = l;
}

//左旋，逆时针
void l_rotate(BBTree **p)
{
    BBTree *r = (*p)->rchild;
    (*p)->rchild = r->lchild;
    r->lchild = *p;
    *p = r;
}

void left_balance(BBTree **T)
{
    BBTree *l = (*T)->lchild;
    switch (l->bf)
    {
    case LH:
        (*T)->bf = l->bf = EH;
        r_rotate(T);
        break;
    case RH:
    {
        BBTree *lr = l->rchild;
        switch (lr->bf)
        {
        case LH:
            (*T)->bf = RH;
            l->bf = EH;
            break;
        case EH:
            (*T)->bf = l->bf = EH;
            break;
        case RH:
            (*T)->bf = EH;
            l->bf = LH;
            break;
        }
        lr->bf = EH;
        l_rotate(&(*T)->lchild);
        r_rotate(T);
        break;
    }
    default:
        break;
    }
}

void right_balance(BBTree **T)
{

}


// 递归
// taller反应T长高与否
bool insert_AVL(BBTree **T, ElemType e, bool &taller)
{
    if (*T == NULL)
    {
        BBTree *root = new BBTree;
        root->data = e;
        root->lchild = root->rchild = NULL;
        root->bf = EH;
        taller = true;
        return true;
    }
    if (e == (*T)->data)
    {
        taller = false;
        return false;
    }
    else if (e < (*T)->data)
    {
        if (!insert_AVL(&(*T)->lchild, e, taller))
        {
            return false;
        }
        if (taller)
        {
            switch ((*T)->bf)
            {
            case LH:
                left_balance(T);
                taller = false;
                break;
            case EH:
                (*T)->bf = LH;
                taller = true;
                break;
            case RH:
                (*T)->bf = EH;
                taller = false;
                break;
            }
        }
    }
    else if (e > (*T)->data)
    {
        if (!insert_AVL(&(*T)->rchild, e, taller))
        {
            return false;
        }
        if (taller)
        {
            switch ((*T)->bf)
            {
            case LH:
                (*T)->bf = EH;
                taller = false;
                break;
            case EH:
                (*T)->bf = RH;
                taller = true;
                break;
            case RH:
                right_balance(T);
                taller = false;
                break;
            }
        }
    }
    return true;
}


#endif // BALANCED_TREE_HPP
