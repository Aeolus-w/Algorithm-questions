/*
对于输入的各种插入序列,判断他们是否能生成一样的二叉搜索树
*/

/*
分别建两棵搜索树比较
不建树,递归为比较左右子树一不一样
建一棵树,别的与这棵树比较
*/

#include <iostream>

 typedef struct TreeNode *Tree;
 struct TreeNode{
    int v;
    Tree Left, Right;
    int flag;//用于判别是否一致
 };

 

Tree NewNode(int V){
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->v = V;
    T->Left = T->Right = NULL;
    T->flag = 0;
    return T;
}

Tree Insert(Tree T, int V){
    if(!T)
        T = NewNode(V);
    else{
        if(V > T->v)
            T->Right = Insert(T->Right, V);
        else
            T->Left = Insert(T->Left, V); 
    }
    return T;
}
 Tree MakeTree(int N){
    Tree T;
    int i, V;
    scanf("%d",&V);
    T = NewNode(V);
    for(i = 1; i < N; i++){
        scanf("%d",&V);
        T = Insert(T,V);
    }
    return T;
 }



int check(Tree T, int V){
    if(T->flag){
        if(V < T->v)
            return check(T->Left,V);
        else if(V > T->v)
            return check(T->Right,V);
        else 
            return 0;
    }
    else {
        if(V == T->v){
            T->flag = 1;
            return 1;
        }
        else 
            return 0;
    }
}

int Judge(Tree T, int N){//有bug
    int i, V;
    int flag = 0;//flag:0表示目前还是一致的,1表示已经不一致了
    scanf("%d",&V);
    if(V != T->v)
        flag = 1;//return 0;
    else    
        T->flag = 1;
    for(i = 1; i < N; i++){
        scanf("%d",&V);
        if((!flag) && (!check(T,V)))
            flag = 1;//return 0;//这里不能直接退出,否则会把这一次剩下的序列当成下一组的序列
    }
    if(flag)
        return 0;
    else
        return 1;

}

void ResetT(Tree T){
    if(T->Left)
        ResetT(T->Left);
    if(T->Right)
        ResetT(T->Right);
    T->flag = 0;
}

void FreeTree(Tree T){
    if(T->Left) 
        FreeTree(T->Left);
    if(T->Right)
        FreeTree(T->Right);
    free(T);
}

int main (){
    int N,L,i;
    Tree T;

    scanf("%d",&N);
    while(N){
        scanf("%d",&L);
        T = MakeTree(N);
        for(i = 0; i < L; i++){
            if(Judge(T,N))
                printf("Yes\n");
            else
                printf("No\n");
            ResetT(T);
        }
        FreeTree(T);
        scanf("%d",&N);
    }
    return 0;
}