#ifndef DATA_H
#define DATA_H
/*
#include "fb_template.cpp"
#include "listext_template.cpp"
#include "person_info_template.cpp"*/
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include "typename.h"
#include "BPlus_tree.cpp"
//#include "B_tree.h"

int block_id = 0;
static const int m = 3;  //定义最小度为3
static const int key_max = 2*m-1;//关键字最大个数
static const int key_min = m - 1;//关键字最小个数
static const int child_max = key_max + 1;//子节点最大个数(这里可以看出子节点数与关键字数有关)
static const int child_min = key_min + 1;//子节点最小个数

template<class T> class block;
template <class T> class BTree;//前置声明
class node;


//改了buildqueue的声明
template<class P> class Listext
{
public:
    Listext(int size = 20);
    P &operator[](int index);
    int getlength(void);
    P getitem(int index);
    void setitem(int index,P value);
    void append(P value);
    void insert(int index, P value);
    void removeindex(int index);
    void remove(P elem);
    void removeID(int ID);
    void removeR(P elem);
    void concat(Listext<P> &list);
    bool member(P value);
    bool memberID(P value);
    bool memID(int ID);
    bool equal(Listext<P> &list);
    bool sublist(Listext<P> &list);
    void removerepeat();
    void prettyprint(void);
    void build_queue();
    void clear();
//private:
    int numitems;
    P *reprarray;
    int maxsize, minsize;
    int withdrawnum;
    void allocate(void);
    void deallocate(void);
    void list_printper(string file_name);
    void list_print(string file_name);
    int list_wait_time();

};


class CSV {
    public:
        vector<string>  data;
        string const& operator[](int i) const { return data[i]; }
    
        void read(string line)
        {
            string c;
	        stringstream stream(line);
        
            data.clear();
            while (getline(stream, c, ',')) {
                data.push_back(c);
            }
            if (!stream && c.empty()) {
                data.push_back("");
            }
        }
};

template<class P> 
class Hospital: public Listext<P>
{
    public:
        int hos_id;
        int Address_x;
        int Address_y;
        int capacity;
         Hospital(int id, int x, int y, int ca){
             hos_id = id;
             Address_x = x;
             Address_y = y;
             capacity = ca;
         }
         Hospital(int id){
             hos_id = id;
             Address_x = -1;
             Address_y = -1; 
             capacity = 0;
         }
        ~Hospital();
};




template <class T>
class FibHeap {
    public:
        int keyNum;         //number of items
        int maxDegree;      
        FibNode<T> *min;    //the point of minmum key node
        FibNode<T> **cons;    //when we need to delete the node, the temporary space to store the value

    public:
        FibHeap();
        ~FibHeap();                                               //build a node of key value and add into the heap
        void removeMin();                                                   //remove the node which have minimun key value
        void combine(FibHeap<T> *other);                                    //combine the other heap with current heap
        bool minimum(T *pkey);                                              //find the minimum key value and saved into pkey point
        void update(T oldkey, T newkey);                                    //change the keyvalue of node with oldkeyvalue in the heap by new keyvalue
        void remove(T key);                                                 //delete the node have keyvalue in the heap
        bool contains(T key);                                               //judge if the heap have node with keyvalue =key
        void print();                                                       //print the heapvalue 
        void destroy();

    
        void removeNode(FibNode<T> *node);                                      //delete the node from the current double list
        void addNode(FibNode<T> *node, FibNode<T> *root);                       //add the node before the root node
        void catList(FibNode<T> *a, FibNode<T> *b);                             //list double list b after double list a
        void insert(FibNode<T> *node);                                          //insert the node into heap
        FibNode<T>* extractMin();                                               //delete the minNode
        void link(FibNode<T>* node, FibNode<T>* root);                          //link the node under the root
        void makeCons();                                                        //build the space for the consolidate step
        void consolidate();                                                     //build the tree with same degree in the heap
        void renewDegree(FibNode<T> *parent, int degree);                       //change the degree number
        void cut(FibNode<T> *node, FibNode<T> *parent);                         //delete the node from the child list of parent node, and add the node into root list
        void cascadingCut(FibNode<T> *node) ;                                   //级联剪切
        void decrease(FibNode<T> *node, T key);                                 //decrease the keyvalue of node into new key value
        void increase(FibNode<T> *node, T key);                                 //increase the keyvalue of node into new key value
        void update(FibNode<T> *node, T key);                                   //change the keyvalue of node into new keyvalue
        FibNode<T>* search(FibNode<T> *root, T key);                            //find the node with keyvalue in the root list
        FibNode<T>* search(T key);                                              //find the node with keyvalue in the whole heap
        FibNode<T>* searchID(FibNode<T> *root, T ID);                            //find the node with keyvalue in the root list
        FibNode<T>* searchID(T ID);
        void remove(FibNode<T> *node);                                          //delete the node
        void destroyNode(FibNode<T> *node);                                     
        void print(FibNode<T> *node, FibNode<T> *prev, int direction);
        void fibnode_print(string file_name);
        int fibnode_wait_time();
};



template <class T>
class BTnode
{
  friend class BTree<T>;//友元函数
public:
    BTnode();
    void inserts(T values);//在已有key的list中插入blockid
    int deletes(T values);//在已有key的list中删除blockid，返回值为list中元素数量，若数量为零，不用再删除
    Listext<int>* finds(T values);//返回key对应的list的指针
    bool isleaf;//判断节点是否是叶子节点
    int keyNum;//关键字个数
    BTnode<T>* parent;//指向父节点
    BTnode<T>* pchild[child_max];//子树指针数组
    T   keyvalue[key_max];//关键字数组
};


class node
{
public:
    node()
    {
        key=-1;
        blockid=new Listext<int>();
    }
    node(int k, int id);
    int key;
    Listext<int> *blockid;
    void insertid(int id);
    int deleteid(int id);
    bool operator== (node node1)
    {
        return key==node1.key;
    }
    bool operator<= (node node1)
    {
        return key<=node1.key;
    }
    bool operator>= (node node1)
    {
        return key>=node1.key;
    }
    bool operator< (node node1)
    {
        return key<node1.key;
    }
    bool operator> (node node1)
    {
        return key>node1.key;
    }
      
};

//重载两个node类的比较符号


/*
类名:BTree
*/

template <class T>
class BTree
{
public:
    BTree()
    {
       root = NULL;
    }
    void B_insert(int key, int bid);          //外部只需调用此函数
    void B_delete(int key, int bid);          //外部只需调用此函数
    Listext<int>* B_find(int key);              //外部只需调用此函数
    void BTree_insert(T value);
    void SplitBlock(BTnode<T>* node_parent,int child_index,BTnode<T>* node_child);
    void Notfull_insert(BTnode<T>* node,T value);
    bool contain(T value);
    BTnode<T>* BTree_find(BTnode<T>* node_current,T value);
    void printpoint(BTnode<T>* node,int count);
    void printpoint();
    bool BTree_delete(T value);
    void MergeBlock(BTnode<T>* node_parent,int child_index);
    T getprev(BTnode<T>* node);
    T getnext(BTnode<T>* node);
    void BTree_deletebalance(BTnode<T>* node,T value);
//private:
	BTnode<T>* root;//根节点
};



template<class T> class block
{
private:
    /* data */
public:
    block(/* args */);
    ~block();
    int block_ID;
    Listext<T>* reparray;
    Listext<T>* overflowbuffer;
    int maxsize;
    int overflowbig;
    int overflowsmall;
    int size;
    bool isfull();
    bool isempty();
    void insert(T elem);
    void sort();
    void remove(T elem);
    void remove(int ID);
    T retrieve(int ID);
    T binarysearch(int ID);
    T ordsearch(int ID);
    void overtorep();
    void reptovoer();
    void updateday(int counter);
};



template<class T> class relation
{
private:
    /* data */
public:
    relation(/* args */);
    ~relation();
    Listext<block<T>*>* blocks;
    void insert(T elem);
    void remove(T elem);
    void remove(int ID, int bloID);
    T retrieve(int ID, int bloID);
    block<T>* retrieve(int bloID);
    int numitems();
    void updateday(int counter);
};


class database
{
private:
    /* data */
public:
    database(/* args */);
    ~database();
    relation<person*>*        personInfo;           
    relation<medicalstatus*>* medicalStatusInfo;       
    relation<registration*>*  registrationInfo;
    relation<treatment*>*     treatmentInfo;
    FibHeap<int>* heap;
    Listext<person*>* withdrawlist;
    Listext<person*>* midrisklist;
    Listext<person*>* highrisklist;
    Hospital<FibNode<int>*>* h1;
    Hospital<FibNode<int>*>* h2;
    Hospital<FibNode<int>*>* h3;
    CBPlusTree* IDpersontree;
    CBPlusTree* IDmedtree;
    CBPlusTree* IDretree;
    BTree<node>* reg_B_tree;
    BTree<node>* appo_B_tree;
    BTree<node>* tre_B_tree;
    Listext<treatment*>* treatlisttoday;
    Listext<treatment*>* treatlisttomorral;
    void insert(person* elem);
    void insert(medicalstatus* elem);
    void insert(registration* elem);
    void insert(treatment* elem);
    void remove(person* elem);
    void remove(medicalstatus* elem);
    void remove(registration* elem);
    void remove(treatment* elem);
    void removepe(int ID,int bloID);
    void removeme(int ID,int bloID);
    void removere(int ID,int bloID);
    void removetr(int ID,int bloID);
    person* retrieveperson(int ID, int bloID);
    medicalstatus* retrievemedstu(int ID, int bloID);
    registration* retrieverega(int ID, int bloID);
    treatment* retrievetreat(int ID, int bloID);
    void updateperson();
    void withdrawupdate();
    void hosupdate();
    void midupdate();
    void withdraw();
    void inputtreat(int counter);
    void updateday(int counter);
    void centralization();
    int getyear(int value);
    int getmonth(int value);
    int getday(int value);
    void poppeople(FibNode<int>* peo);
    int distance(person* peo, Hospital<FibNode<int>*>* hos);
    void popday(int counter);
    Listext<int>* getweeklistregblock(int counter);
    Listext<int>* getweeklistappblock(int counter);
    Listext<int>* getweeklisttreblock(int counter);
    Listext<person*>* getweeklistregpeo(int counter);
    Listext<person*>* getweeklistapppeo(int counter);
    Listext<treatment*>* getweeklisttrepeo(int counter);
    Listext<int>* getmonthblocklist(int counter);
    Listext<person*>* getmonthlist(int counter);
    Listext<int>* getmonthblocktrelist(int counter);
    Listext<treatment*>* getmonthtrelist(int counter);
    void monthlyreport(int counter,string name);
};


class center
{
private:
    /* data */
public:
    center(/* args */);
    ~center();
    database* treat_1;
    database* treat_2;
    database* treat_3;
    void addallfile();
    void addallfilenew();
    int centercounter;
    void locationinput(int h1x, int h1y, int h1c, int h2x, int h2y, int h2c, int h3x, int h3y, int h3c);
    void updatecountdown();
    void withdraw();
    void update();
    void popday(int counter);
    void updateday();
    void updatehos();
};


#endif