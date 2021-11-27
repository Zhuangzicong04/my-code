#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* status macro definition */
#define OK 1
#define ERROR 0
#define OVER_FLOW -2

/* memory length macro definition */
#define MAXNAMELEN 15
#define MAXBOOKNUMBERLEN 20
#define MAXREADERNUM 20 //the max amount of all readers
#define MAXREADERCODEDIGIT 5 //max reader code digits
#define INDENTATION 0 //for printing the BiTree

/* some macros related to AVLTree */
#define EQ(a,b) (!strcmp((a),(b)))
#define LT(a,b) (strcmp((a),(b))<0)
#define LH +1
#define EH 0
#define RH -1

typedef int Status;
typedef enum {FALSE,TRUE} boolean;
typedef char *KeyType;
typedef char NameType[MAXNAMELEN];
typedef char *BookNum,BookNumType[MAXBOOKNUMBERLEN];
typedef char TeleType[11+1]; //telephone: 11digits
typedef unsigned int DateType; //return date
//typedef Book DataType; //data type in TNode

typedef struct{
    BookNumType number; //no prefix 'ISBN'
    NameType name;
    NameType author;
    int stock; //current amount of the book
    int total; //total amount of the book
}Book,DataType;

typedef struct TNode{
    DataType data;
    int bf; //balance factor
    struct TNode *lchild,*rchild;
}TNode,*AVLTree;

typedef struct ArcBox{
    BookNumType bknum;
    NameType bknam;
    DateType return_date; //e.g. 20010205
    struct ArcBox *next;
}ArcBox;

typedef struct{
    int code;
    NameType name;
    TeleType tele; //telephone
    ArcBox *first_arc;
}Reader;

typedef struct{
    Reader *readers;
    int length,size;
}AdjList;

class LibManage{
public:
    AVLTree tree;
    AdjList reader_list;
    DateType current_date;
    LibManage();
    ~LibManage() {DestoryTree(tree);}
    void Menu();
    void AddBook();
    void LendBook();
    void ReturnBook();
    void EraseBook();
    void OutputBooks();
    void OutputReaders();
    void TestMode();
private:
    void gettime();
    void PrintBook(Book b);
    void PrintBiTree_Simple(AVLTree T,int indent);
    void PrintBiTree_Detail(AVLTree T);
    void BookCpy(Book *a,Book b);
    void L_Rotate(AVLTree *t);
    void R_Rotate(AVLTree *t);
    void L_Balance(AVLTree *t);
    void R_Balance(AVLTree *t);
    TNode* SearchAVLTree(AVLTree T,BookNum bn);
    Status InsertAVLTree(AVLTree *T,boolean *taller,DataType elem);
    Status DeleteAVLTree(AVLTree *curT,AVLTree preT,boolean *shorter,KeyType bknum);
    Status InitAdjList(AdjList &list);
    Status AddReader(AdjList &list,const Reader &r);
    Status AddReaderBook(Reader &r,const ArcBox &ab);
    Status SearchReader(AdjList list,int code);
    Status DeleteReader(AdjList &list,int code);
    Status CheckBorrowPermission(Reader r,BookNum bknum=NULL);
    ArcBox* SearchBorrowedBook(Reader r,KeyType bknum,ArcBox* &prep);
    void ReaderCpy(Reader &r1,const Reader &r2);
    void PrintReader(const Reader &r);
    void PrintBorrowedBooks(Reader r);
    void DestoryTree(AVLTree &T);
};

void LibManage::gettime(){
    //get system time and convert it to unsigned int
    time_t rawtime;
    struct tm *ptminfo;
    time(&rawtime); //get time raw info
    ptminfo=localtime(&rawtime); //convert raw time info to processed and readable time info
    current_date=((ptminfo->tm_year)+1900)*10000+(ptminfo->tm_mon)*100+(ptminfo->tm_mday);
    printf("Set current time:%u successfully! \n",current_date);
}

LibManage::LibManage() {
    tree=NULL; //initialize tree
    InitAdjList(reader_list); //initialize AdjList
    printf("Launch Library Management System Successfully! \n");
    gettime();
    
    /* Simulate a library, so add some items first */
    //book={number,name,author,stock,total}
    boolean taller=FALSE;
    Book book1={"01","PromisedLand","Obama",6,8};
    Book book2={"02","Humans","Stanton",4,5};
    Book book3={"03","Becoming","Michelle",0,3};
    Book book4={"04","DeepEnd","Kinney",0,6};
    InsertAVLTree(&tree,&taller,book1);
    InsertAVLTree(&tree,&taller,book2);
    InsertAVLTree(&tree,&taller,book3);
    InsertAVLTree(&tree,&taller,book4);
    //reader={code,name,telephone,firstarc}
    Reader reader1={1,"Sylvan","95566",NULL};
    Reader reader2={2,"JIXIANG","10086",NULL};
    AddReader(reader_list,reader1);
    AddReader(reader_list,reader2);
    //reader={booknumber,bookname,return date,*next}
    ArcBox arcbox1={"01","PromisedLand",20251211,NULL};
    ArcBox arcbox2={"02","Humans",20300201,NULL};
    AddReaderBook(reader_list.readers[0],arcbox1);
    AddReaderBook(reader_list.readers[0],arcbox2);
    AddReaderBook(reader_list.readers[1],arcbox1);
}

void LibManage::DestoryTree(AVLTree &T){
    //free the memory of the tree, using post-order traverse to guarantee that the node's parent won't get lost
    if(!T) return;
    DestoryTree(T->lchild);
    DestoryTree(T->rchild);
    free(T); T=NULL;
}

//the following function is related to AVLTree

void LibManage::L_Rotate(AVLTree *t){
    //left rotate root node, and update the root
    TNode *rc=(*t)->rchild;
    (*t)->rchild=rc->lchild;
    rc->lchild=*t;
    (*t)=rc;
}
void LibManage::R_Rotate(AVLTree *t){
    //right rotate root node, and update the root
    TNode *lc=(*t)->lchild;
    (*t)->lchild=lc->rchild;
    lc->rchild=*t;
    (*t)=lc;
}
void LibManage::L_Balance(AVLTree *t){
    //adjust the root to make left tree balanced
    TNode *lc=(*t)->lchild,*rd;
    switch(lc->bf){ //check condition: LL or LR, through BF of root's lchild
        case EH: //a case when deleting the node
            (*t)->bf=LH; lc->bf=RH;
            R_Rotate(t);
            break;
        case LH: //LL
            (*t)->bf=lc->bf=EH; //modify BF
            R_Rotate(t); //R rotate root node
            break;
        case RH: //LR
            rd=lc->rchild;
            switch(rd->bf){ //modify BF according to different BF conditions
                case LH: lc->bf=rd->bf=EH;  (*t)->bf=RH; break;
                case EH: lc->bf=(*t)->bf=EH; break;
                case RH: rd->bf=(*t)->bf=EH; lc->bf=LH; break;
            }//switch(rd->bf)
            L_Rotate(&((*t)->lchild)); //part Left rotation, firstly
            R_Rotate(t); //root Right rotation, then
            break;
    }//switch(lc->bf)
}
void LibManage::R_Balance(AVLTree *t){
    //adjust the root to make right tree balanced
    TNode *rc=(*t)->rchild,*ld;
    switch(rc->bf){ //check condition: RL or RR, through BF of root's rchild
        case EH: //a case when deleting the node
            (*t)->bf=RH; rc->bf=LH;
            L_Rotate(t);
            break;
        case RH: //RR
            (*t)->bf=rc->bf=EH; //modify BF
            L_Rotate(t); //L rotate root node
            break;
        case LH: //RL
            ld=rc->lchild;
            switch(ld->bf){ //modify BF according to different BF conditions
                case LH: (*t)->bf=rc->bf=EH; ld->bf=RH; break;
                case EH: rc->bf=(*t)->bf=EH; break;
                case RH: ld->bf=rc->bf=EH; (*t)->bf=LH; break;
            }//switch(rd->bf)
            R_Rotate(&((*t)->rchild)); //part Right rotation, firstly
            L_Rotate(t); //root Left rotation, then
            break;
    }//switch(lc->bf)
}

TNode* LibManage::SearchAVLTree(AVLTree T,BookNum bn){
    /* if the booknum can be found in AVLTree, then return its address, else return NULL */
    if(!T) return NULL;
    if(EQ(bn,T->data.number)) return T;
    if(LT(bn,T->data.number)) return SearchAVLTree(T->lchild,bn);
    return SearchAVLTree(T->rchild,bn);
}

Status LibManage::InsertAVLTree(AVLTree *T,boolean *taller,DataType elem){
    /* insert an elem to AVLTree, and adjust the tree to keep its balance. If elem has existed, then return ERROR, else return OK */
    /* parameter 'taller' means that after inserting the elem, the tree is taller or not. */
    if(!*T) { //create a new node
        *T=(TNode*)malloc(sizeof(TNode));
        if(!*T) exit(OVER_FLOW);
        BookCpy(&((*T)->data),elem);
        (*T)->bf=EH;
        (*T)->lchild=(*T)->rchild=NULL;
        *taller=TRUE;
    }
    else if(EQ(elem.number,(*T)->data.number)) {
        //if the node has already existed
        PrintBook((*T)->data);
        printf("ERROR: book <%s> has already been in the AVL Tree. \n",elem.name);
        *taller=FALSE;
        return ERROR;
    }
    else if(LT(elem.number,(*T)->data.number)) {
        //insert its left child tree
        if(!InsertAVLTree(&((*T)->lchild),taller,elem)) return ERROR;
        if(!*taller) return OK;
        switch((*T)->bf) { //update the BF of the node
            case LH:
                //adjust to make it balanced
                L_Balance(T);
                *taller=FALSE; break;
            case EH: (*T)->bf=LH; *taller=TRUE; break;
            case RH: (*T)->bf=EH; *taller=FALSE; break;
            }//switch((*T)->bf)
        }
    else {
        //insert its right child tree
        if(!InsertAVLTree(&((*T)->rchild),taller,elem)) return ERROR;
        if(!*taller) return OK;
        switch((*T)->bf) { //update the BF of the node
            case LH: (*T)->bf=EH; *taller=FALSE; break;
            case EH: (*T)->bf=RH; *taller=TRUE; break;
            case RH:
                //adjust to make it balanced
                R_Balance(T);
                *taller=FALSE; break;
            }//switch((*T)->bf)
    }
    return OK;
}

Status LibManage::DeleteAVLTree(AVLTree *curT,AVLTree preT,boolean *shorter,KeyType bknum){
    /* delete a node in AVLTree according to its book number, and adjust the tree to keep its balance. If elem has existed, then return OK, else return ERROR *///?SylvanDing
    /* parameter 'shorter' means that after deleting the node, the tree is shorter or not. */
    if(!*curT) {
        //if the node doesn't exist
        printf("ERROR: Can't find BOOK: ISBN %s \n",bknum);
        *shorter=FALSE;
        return ERROR;
    }//if(!*curT)
    else if(EQ(bknum,(*curT)->data.number)) {
        //find the node, and delete it
        if(!((*curT)->lchild)) {
            //if(the node has no left child or has neither left nor right one)
            if(!preT) *curT=(*curT)->rchild;
            //if(the node has no parent)
            else if(LT(bknum,preT->data.number)) preT->lchild=(*curT)->rchild;
            //check the current node is its parent's left child or its right one
            else preT->rchild=(*curT)->rchild;
            *shorter=TRUE;
        }//if(!((*curT)->lchild))
        else if(!((*curT)->rchild)) {
            //if(the node has no right child but has left one)
            if(!preT) *curT=(*curT)->lchild;
            //if(the node has no parent)
            else if(LT(bknum,preT->data.number)) preT->lchild=(*curT)->lchild;
            //check the current node is its parent's left child or its right one
            else preT->rchild=(*curT)->lchild;
            *shorter=TRUE;
        }//else if(!((*curT)->rchild))
        else {
            //if(the node has both right and left child)
            TNode *tempT=(*curT)->lchild; //enter curT's left child
            while(tempT->rchild) //find curNode's precursor in inorder traverse
                tempT=tempT->rchild;
            BookCpy(&((*curT)->data),tempT->data); //assign the precursor's data to the node that needs to be deleted
            DeleteAVLTree(&((*curT)->lchild),NULL,shorter, tempT->data.number); //delete the precursor of the deleted elem in curT's left child
            if(!*shorter) return OK;
            switch((*curT)->bf) {
                case LH: (*curT)->bf=EH; *shorter=TRUE; break;
                case EH: (*curT)->bf=RH; *shorter=FALSE; break;
                case RH:
                    //another 3 conditions need to be considered, according to curT's right child BF
                    switch((*curT)->rchild->bf) {
                        case LH: *shorter=TRUE; break;
                        case EH: *shorter=FALSE; break;
                        case RH: *shorter=TRUE; break;
                    }//switch((*curT)->rchild->bf)
                    R_Balance(curT);
            }//switch((*curT)->bf)
        }
    }//else if(EQ(bknum,(*curT)->data.number))
    else if(LT(bknum,(*curT)->data.number)) {
        //if the keynum is less than the curT's number
        if(!DeleteAVLTree(&((*curT)->lchild),*curT,shorter,bknum)) return ERROR;
        if(!*shorter) return OK;
        switch((*curT)->bf) {
            case LH: (*curT)->bf=EH; *shorter=TRUE; break;
            case EH: (*curT)->bf=RH; *shorter=FALSE; break;
            case RH:
                //another 3 conditions need to be considered, according to curT's right child BF
                switch((*curT)->rchild->bf) {
                    case LH: *shorter=TRUE; break;
                    case EH: *shorter=FALSE; break;
                    case RH: *shorter=TRUE; break;
                }//switch((*curT)->rchild->bf)
                R_Balance(curT);
        }//switch((*curT)->bf)
    }//else if(LT(bknum,(*curT)->data.number))
    else {
        //if the keynum is larger than the curT's number, enter its right child
        if(!DeleteAVLTree(&((*curT)->rchild),*curT,shorter,bknum)) return ERROR;
        if(!*shorter) return OK;
        switch((*curT)->bf) {
            case LH:
                //another 3 conditions need to be considered, according to curT's left child BF
                switch((*curT)->lchild->bf) {
                    case LH: *shorter=TRUE; break;
                    case EH: *shorter=FALSE; break;
                    case RH: *shorter=TRUE; break;
                }//switch((*curT)->rchild->bf)
                L_Balance(curT);
            case EH: (*curT)->bf=LH; *shorter=FALSE; break;
            case RH: (*curT)->bf=EH; *shorter=TRUE; break;
        }//switch((*curT)->bf)
    }//else
    return OK;
}

void LibManage::TestMode(){
    //this mode is for testing AVLTree's insertion and deletion quickly and easily
    Book bk={"","","",0,0};
    AVLTree testT=NULL; boolean flag;
    printf("- - - Testing Mode - - -\n");
    printf("//This mode allows you to test AVLTree's insertion and deletion quickly and easily. Whenever you insert or delete an item, it will print the AVLTree: KeyValue(BalanceFactor) \n//Have created a new Empty AVLTree for testing... \n//Input numbers(like 01,21,36...) to insert it, input 'end' to stop inserting. \n");
    //?SylvanDing
    do{
        flag=FALSE;
        scanf("%s",bk.number);
        getchar();
        if(EQ(bk.number,"end")) break;
        InsertAVLTree(&testT,&flag,bk);
        printf("* Tree Print * \n");
        PrintBiTree_Simple(testT,INDENTATION);
    }while(1);
    printf("//End inserting, and then you can input the item you wanna delete, input 'quit' to exit testing mode... \n");
    do{
        flag=FALSE;
        scanf("%s",bk.number);
        getchar();
        if(EQ(bk.number,"quit")) break;
        DeleteAVLTree(&testT,NULL,&flag,bk.number);
        printf("* Tree Print * \n");
        PrintBiTree_Simple(testT,INDENTATION);
    }while(1);
    printf("//Exit TESTING MODE... \n");
}

//the following function is about Library Management

void LibManage::Menu(){
    printf("* * * MENU * * *\n");
    printf("(1). Add books\n");
    printf("(2). Lend books\n");
    printf("(3). Return books\n");
    printf("(4). Erase books\n");
    printf("(5). Print All Books\n");
    printf("(6). Print All Readers\n");
    printf("(7). *(Testing MODE)\n");
    printf("(0). [ E X I T ]\n");
    printf("* * * * * * * * *\n");
}

void LibManage::BookCpy(Book *a,Book b){
    //copy b's info and assign it to a
    strcpy(a->number,b.number);
    strcpy(a->name,b.name);
    strcpy(a->author,b.author);
    a->stock=b.stock;
    a->total=b.total;
}

void LibManage::PrintBook(Book b){
    printf("- - - - Book Info - - - -\n");
    printf("Name: %s\n",b.name);
    printf("Author: %s\n",b.author);
    printf("Number: ISBN %s\n",b.number);
    printf("Total: %d\n",b.total);
    printf("Stock: %d\n",b.stock);
    printf("- - - - - - - - - - - - -\n");
}

void LibManage::PrintBiTree_Simple(AVLTree T,int indent){
    if(!T) return;
    printf("%*s%s(%d)\n",indent,"",T->data.number,T->bf);
    PrintBiTree_Simple(T->lchild,indent+1);
    PrintBiTree_Simple(T->rchild,indent+1);
}

void LibManage::PrintBiTree_Detail(AVLTree T){
    if(!T) return;
    PrintBook(T->data);
    PrintBiTree_Detail(T->lchild);
    PrintBiTree_Detail(T->rchild);
}

void LibManage::AddBook(){
    //to add a new book when bknum-related book doesn't exist in AVLTree, or increase its original amount
    AVLTree *T=&tree;
    TNode *node=NULL; char flag;
    BookNumType bknum; int amount;
    printf("- - - - Add Book - - - -\n");
    printf("Book Number: ISBN ");
    scanf("%s",bknum);
    printf("Increment: ");
    scanf("%d",&amount);
    getchar();
    if(!(node=SearchAVLTree(*T,bknum))) {
        boolean taller=FALSE;
        Book new_book; NameType bk_name,aut_name;
        printf("ERROR: Can't find BOOK: ISBN %s \n Would you like to create a new item? (y/n)...\n",bknum);
        scanf("%c",&flag);
        switch(flag){
            case 'n':
            case 'N': return; break;
            case 'y':
            case 'Y':
                printf("Number: ISBN %s\n",bknum);
                printf("Stock/Total: %d\n",amount);
                printf("Name: ");
                scanf("%s",bk_name);
                printf("Author: ");
                scanf("%s",aut_name);
                strcpy(new_book.number,bknum);
                strcpy(new_book.name,bk_name);
                strcpy(new_book.author,aut_name);
                new_book.stock=new_book.total=amount;
                if(!InsertAVLTree(T,&taller,new_book)) return;
                PrintBook(new_book);
                printf("Add new book successfully!  \n");
                break;
            default: printf("Error: Wrong command, try again...\n");
        }//switch(flag)
    }//if(!(node=SearchAVLTree(*T,bknum)))
    else {
        printf("Find the BOOK...\nWould you like to increase it? (y/n)...\n");
        scanf("%c",&flag);
        switch(flag){
            case 'n':
            case 'N': return; break;
            case 'y':
            case 'Y':
                printf("Original stock: %d \nOriginal total amount: %d \n",node->data.stock,node->data.total);
                node->data.stock+=amount;
                node->data.total+=amount;
                PrintBook(node->data);
                printf("Increase successfully! \n");
                break;
            default: printf("Error: Wrong command, try again...\n");
        }//switch(flag)
    }//else
}

void LibManage::
LendBook(){
    //to lend books
    int code,index; char flag;
    printf("- - - - Lend Book - - - -\n");
    printf("Reader Code: ");
    scanf("%d",&code);
    getchar();
    if((index=SearchReader(reader_list,code))<0) {
        index=reader_list.length;
        Reader newreader; newreader.first_arc=NULL;
        printf("ERROR: Can't find reader %0*d...\nWould you like to create one? (y/n)...\n",MAXREADERCODEDIGIT,code);
        scanf("%c",&flag);
        switch(flag){
            case 'n':
            case 'N': return; break;
            case 'y':
            case 'Y':
                printf("Code: %0*d \n",MAXREADERCODEDIGIT,code);
                newreader.code=code;
                printf("Name: ");
                scanf("%s",newreader.name);
                printf("Tele: ");
                scanf("%s",newreader.tele);
                if(!AddReader(reader_list,newreader)) return;
                PrintReader(reader_list.readers[reader_list.length-1]);
                printf("Add reader successfully! \n");
                break;
            default: printf("Error: Wrong command, try again...\n"); return;
        }//switch(flag)
    }//if(index<0)
    else {
        PrintReader(reader_list.readers[index]);
        if(!CheckBorrowPermission(reader_list.readers[index])) return;
    }//if(index>=0)
    BookNumType bknum; TNode *tptr;
    printf("Book Number to lend: ISBN ");
    scanf("%s",bknum);
    if(!CheckBorrowPermission(reader_list.readers[index],bknum)) return;
    if(!(tptr=SearchAVLTree(tree,bknum)))
        printf("ERROR: Can't find book: %s in Library System... \n",bknum);
    else if(tptr->data.stock<=0)
        printf("ERROR: Book Stock of <%s> is not enough... \n",tptr->data.name);
    else {
        ArcBox *new_arcbox=(ArcBox*)malloc(sizeof(ArcBox));
        if(!new_arcbox) exit(OVER_FLOW);
        --tptr->data.stock;
        printf("Return Date(e.g.20201230): ");
        scanf("%u",&(new_arcbox->return_date));
        strcpy(new_arcbox->bknum,bknum);
        strcpy(new_arcbox->bknam,tptr->data.name);
        new_arcbox->next=reader_list.readers[index].first_arc;
        reader_list.readers[index].first_arc=new_arcbox;
        printf("Lend Book Successfully! \n");
    }
}

void LibManage::ReturnBook(){
    //to return books
    int code,index; TNode *tptr;
    BookNumType bknum; ArcBox *abptr,*pre_abptr;
    printf("- - - - Return Book - - - -\n");
    printf("Reader Code: ");
    scanf("%d",&code);
    getchar();
    if((index=SearchReader(reader_list,code))<0) {
        printf("ERROR: Can't find reader %0*d...\n",MAXREADERCODEDIGIT,code);
        return;
    }
    PrintReader(reader_list.readers[index]);
    printf("Book Number to return: ISBN ");
    scanf("%s",bknum);
    if(!(abptr=SearchBorrowedBook(reader_list.readers[index],bknum,pre_abptr))) {
        printf("ERROR: No lended book: %s...\n",bknum);
        return;
    }
    if(!pre_abptr)
        reader_list.readers[index].first_arc=abptr->next;
    else
        pre_abptr->next=abptr->next;
    free(abptr);
    if(!reader_list.readers[index].first_arc) {
        printf("Warning: Reader %s has returned all books, now erase his or her info from the memory... \n",reader_list.readers[index].name);
        DeleteReader(reader_list,index);
        printf("Erased successfully! \n");
    }
    if((tptr=SearchAVLTree(tree,bknum)))
        ++tptr->data.stock;
    printf("Return Successfully! \n");
}

void LibManage::EraseBook(){
    //to erase book
    BookNumType bknum; boolean shorter;
    printf("- - - - Erase Book - - - -\n");
    printf("Book Number to erase: ISBN ");
    scanf("%s",bknum);
    getchar();
    if(DeleteAVLTree(&tree,NULL,&shorter,bknum))
        printf("Delete book successfully! \n");
}

void LibManage::OutputBooks(){
    //in-order traverse the AVLTree
    if(!tree){
        printf("No book... \n");
        return;
    }
    PrintBiTree_Detail(tree);
}

void LibManage::OutputReaders(){
    if(reader_list.length<=0) {
        printf("No reader... \n");
        return;
    }
    for(int i=0;i<reader_list.length;++i)
        PrintReader(reader_list.readers[i]);
}

//the following function is about Readers Management

Status LibManage::InitAdjList(AdjList &list){
    //initialize reader adjacency list
    if(!(list.readers=(Reader*)malloc(MAXREADERNUM*sizeof(Reader)))) exit(OVER_FLOW);
    list.length=0; list.size=MAXREADERNUM;
    return OK;
}

Status LibManage::AddReader(AdjList &list, const Reader &newr){
    //add a new reader to reader list
    if(list.length>=list.size) {
        printf("ERROR: System unable to hold more readers... \n");
        return ERROR;
    }
    ReaderCpy(list.readers[list.length++],newr);
    return OK;
}

Status LibManage::AddReaderBook(Reader &r,const ArcBox &ab){
    //for stimulating a whole library management
    //no real function
    ArcBox *abptr=(ArcBox*)malloc(sizeof(ArcBox));
    if(!abptr) exit(OVER_FLOW);
    strcpy(abptr->bknum,ab.bknum);
    strcpy(abptr->bknam,ab.bknam);
    abptr->return_date=ab.return_date;
    abptr->next=r.first_arc;
    r.first_arc=abptr;
    return OK;
}

Status LibManage::SearchReader(AdjList list,int code){
    //if 'code' exists, then return its index, else return -1
    int index=0;
    while(index<list.length&&code!=list.readers[index].code) ++index;
    if(index<list.length) return index;
    else return -1;
}

Status LibManage::DeleteReader(AdjList &list,int index){
    while(index<list.length) {
        ReaderCpy(list.readers[index],list.readers[index+1]);
        ++index;
    }
    --list.length;
    return OK;
}

Status LibManage::CheckBorrowPermission(Reader r,BookNum bknum){
    //if the second parameter 'bknum'=NULL, only check whether the borrower has overdue unreturned book, if he does, return 0, else return 1
    //if the 'bknum'!=NULL, then check if there has any same book that he has already borrowed. if he does, return 0, else return 1
    ArcBox *p=r.first_arc;
    if(!bknum) {
        while(p&&p->return_date>=current_date)
            p=p->next;
        if(p) {
            printf("No borrow permission: The reader has a book <%s> needs to be returned before %u \n",p->bknam,p->return_date);
            return 0;
        }
        else return 1;
    }//if(!bknum)
    else {
        while(p&&!EQ(bknum,p->bknum))
            p=p->next;
        if(p) {
            printf("No borrow permission: The reader has borrowed a same book <%s>. \n",p->bknam);
            return 0;
        }
        else return 1;
    }//else
}

ArcBox* LibManage::SearchBorrowedBook(Reader r,KeyType bknum,ArcBox* &prep){
    //if bknum can be found in reader's borrowed list, then return its arcbox's address, else return NULL.
    //prep return temp's precursor, when it has no precursor, return NULL
    ArcBox *temp=r.first_arc; prep=NULL;
    while(temp&&!EQ(bknum,temp->bknum)){
        prep=temp;
        temp=temp->next;
    }
    return temp;
}

void LibManage::ReaderCpy(Reader &r1,const Reader &r2){
    //copy reader's info from r2 to r1
    strcpy(r1.name,r2.name);
    strcpy(r1.tele,r2.tele);
    r1.code=r2.code;
    r1.first_arc=r2.first_arc;
}

void LibManage::PrintReader(const Reader &r){
    printf("- - - - Reader Info - - - -\n");
    printf("Name: %s\n",r.name);
    printf("Code: %0*d\n",MAXREADERCODEDIGIT,r.code);
    printf("Tele: %s\n",r.tele);
    PrintBorrowedBooks(r);
    printf("- - - - - - - - - - - - -\n");
}

void LibManage::PrintBorrowedBooks(Reader r){
    printf("Borrowed books: \n");
    if(!r.first_arc) printf("\t(Empty) \n");
    while(r.first_arc) {
        printf("<%s> | ISBN %s |  Deadline:%u(%s)\n",r.first_arc->bknam,r.first_arc->bknum,r.first_arc->return_date,current_date>r.first_arc->return_date? "![Overdue]!":"[Normal]");
        r.first_arc=r.first_arc->next;
    }
}

int main(int argc, char *argv[]){
    LibManage LMSystem;
    int opt;
    LMSystem.Menu();
    do{
        printf("Menu->Option: ");
        scanf("%d",&opt);
        getchar();
        switch(opt){
            case 0: break;
            case 1: LMSystem.AddBook(); break;
            case 2: LMSystem.LendBook(); break;
            case 3: LMSystem.ReturnBook(); break;
            case 4: LMSystem.EraseBook(); break;
            case 5: LMSystem.OutputBooks(); break;
            case 6: LMSystem.OutputReaders(); break;
            case 7: LMSystem.TestMode(); break;
            default: printf("ERROR: Wrong command, try again... \n"); break;
        }//switch(opt)
    }while(opt);
    return 0;
}
