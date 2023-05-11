#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "centerdatabase.h"
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <cstring>
#include <iostream>
int filen = 0;

/// the member functions of Listext
template<class P> Listext<P>::Listext(int size)
{
    maxsize = size;
    if (size < 20)
        minsize = size;
    else
        minsize = 20;
    numitems = 0;
    withdrawnum = 0;
    reprarray = new P[maxsize];
}

template<class P> P &Listext<P>::operator[](int index)
{
    return reprarray[index];
};

template<class P> int Listext<P>::getlength(void)
{   

    return numitems;
};

template<class P> void Listext<P>::setitem(int index,P value)
{
    if ((index >= 0) && (index < numitems))
    {
        reprarray[index] = value;
        return;
    }
    else
        cout << "Index error: index out or range\n";
};

template<class P> P Listext<P>::getitem(int index)
{
    if ((index >= 0) && (index < numitems))
    {
        return reprarray[index];
    }
    else
    {
        cout << "Index error: index out or range\n";
        exit(EXIT_FAILURE);
    }
};

template<class P> void Listext<P>::append(P value)
{
    if (numitems == maxsize)
        allocate();
    reprarray[numitems] = value;
    ++numitems;
    return;
};

template<class P> void Listext<P>::insert(int index, P value)
{
    if (numitems == maxsize)
        allocate();
    if (index < numitems)
    {
        for (int j = numitems; j > index; --j)
        {
            reprarray[j] = reprarray[j-1];
        }
        reprarray[index] = value;
        ++numitems;
        return;
    }
    else
    {
        append(value);
        return;
    }
};

template<class P> void Listext<P>::allocate(void)
{
    int newsize = 2 * maxsize;
    P *newarray = new P[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
};

template<class P> void Listext<P>::removeindex(int index)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    if (index < numitems)
    {
        for (int j = index; j < numitems-1; ++j)
        {
            reprarray[j] = reprarray[j+1];
        }
        --numitems;
        return;
    }
    else
        cout << "Index error: list index out of range\n";
};

template<class P> void Listext<P>::deallocate(void)
{
    int newsize = maxsize / 2;
    P *newarray = new P[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
};

template<class P> void Listext<P>::concat(Listext<P> &list)
{
    int length = list.getlength();
    for (int i = 0; i < length; ++i)
    {
        append(list[i]);
    }
    return;
};

template<class P> bool Listext<P>::member(P value)
{
    bool result = false;
    for (int i = 0; i < numitems; ++i)
    {
        if (reprarray[i] == value)
        {
            result = true;
            break;
        }
    }
    return result;
};

template<class P> bool Listext<P>::memberID(P value)
{
    bool result = false;
    for (int i = 0; i < numitems; ++i)
    {
        if (reprarray[i]->ID == value -> ID)
        {
            result = true;
            break;
        }
    }
    return result;
};

template<class P> bool Listext<P>::memID(int ID)
{
    bool result = false;
    for (int i = 0; i < numitems; ++i)
    {
        if (reprarray[i]->ID == ID)
        {
            result = true;
            break;
        }
    }
    return result;
};

template<class P> bool Listext<P>::equal(Listext<P> &list)
{
    bool result = true;
    if (numitems == list.getlength())
    {
        for (int i = 0; i < numitems; ++i)
        {
            if (reprarray[i] == list[i + 1])
                continue;
            else
            {
                result = false;
                break;
            }
        }
    }
    else
        result = false;
    return result;
};

template<class P> bool Listext<P>::sublist(Listext<P> &list)
{
    int length = list.getlength();
    bool result = true;
    for (int i = 0, j = 0; (i < length) && (j < numitems); ++i, ++j)
    {
        if (list[i] == reprarray[j])
        {
            if ((j == numitems - 1) && (i < length))
            {
                result = false;
                break;
            }
        }
        else
            if (j == numitems - 1)
            {
                result = false;
                break;
            }
            else
                --i;
    }
    return result;
};

template<class P> void Listext<P>::prettyprint(void)
{
    for (int i = 0; i < numitems; i++)
    {
        cout << i << ":  " << reprarray[i];
        if (i != numitems - 1)
            cout << "; ";
        cout << "\n";
    }
};

template<class P> void Listext<P>:: build_queue(){
    
    string filename;
    string choose1;
    int choose;
    
    while (true)
    {
        cout << "input 1 to input file!" << endl;/* code */
        cin >> choose1 ;
        choose = stoi(choose1);
        if (cin.fail() || choose != 1 ){
            cin.clear();
            cin.ignore(100,'\n');
        }
        else break;
        cout << "input wrong, please input again!" << endl;
    }
    
    
    
    filename = std::to_string(filen) + ".csv";
    filen++; 
    int ignorerow = 0;
   
    ifstream infile(filename);
    string s;
    getline(infile,s);
    CSV csv;
    csv.read(s);
    stringstream ss;
    while (infile.good() )
    {
        getline(infile,s);
        csv.read(s);
        person_info* badp = new person_info;
        int nr = 0;
        int nm = 0;
        int nl = 0;
        badp->ID = stoi(csv[1]);
        badp->name = csv[0];
        badp->address_x = stoi(csv[2]);
         badp->address_y = stoi(csv[3]);
        badp->phone = csv[4];
        badp->wechat = csv[5];
        badp->email = csv[6];
        badp->job_grade = stoi(csv[7]);
        badp->birth_year = stoi(csv[8]);
        badp->birth_month = stoi(csv[9]);
        badp->birth_day = stoi(csv[10]);
        badp->registration_year = stoi(csv[11]);
        badp->registration_month = stoi(csv[12]);
        badp->registration_day = stoi(csv[13]);
        badp->registration_time = stoi(csv[14]);
        badp->risk_grade = stoi(csv[15]);
        
        this->append(badp);
    }
    infile.close();
}

template<class P> void Listext<P>::clear(){
    int num = getlength();
    for (int i = 0; i < num; i++){
        reprarray[i]=NULL;
    }
    numitems = 0;
}

template<class P> void Listext<P>::list_printper(string file_name){
    ofstream outFile;
    file_name = file_name + ".csv";
    outFile.open(file_name, ios::out);
    outFile << "name" << "," << "ID" << "," <<"telephone"<<"," <<"register year"<< "," << "register month"<< ","<< "register day" << ",";
    outFile << "job_grade" << "," << "age_grade" << "," << "risk_grade" << "," << "waiting_time" << endl;
    for(int i=0; i < numitems;i++){
        outFile << reprarray[i]->name << "," << reprarray[i]->ID << "," << reprarray[i]->phone <<"," << reprarray[i]->registration_year <<",";
        outFile << reprarray[i]->registration_month <<","<< reprarray[i]->registration_day<<"," << reprarray[i]->job_grade << ",";
        outFile << reprarray[i]->age_grade << "," << reprarray[i]->risk_grade << "," << reprarray[i]->waiting_time << endl;
    }
    outFile.close();
}

template<class P> void Listext<P>::list_print(string file_name){
    ofstream outFile;
    file_name = file_name + ".csv";
    outFile.open(file_name, ios::out);
    outFile << "ID" << "," << "treat year" << "," << "treat month" << "," << "treat day" <<"," << "wait time"<< endl;
    for(int i=0; i < numitems;i++){
        outFile << reprarray[i]->ID << "," << reprarray[i]->treat_time_year << "," << reprarray[i]->treat_time_month << ",";
        outFile << reprarray[i]->treat_time_day << "," << reprarray[i]->waiting_time << endl;
    }
    outFile.close();
}

template<class P> int Listext<P>::list_wait_time(){
    int time = 0;
    int num = numitems;
    for(int i=0; i < num;i++){
        if ( reprarray[i]->waiting_time < 0 || reprarray[i]->waiting_time > 1000){
            continue;
        }
        time = time + reprarray[i]->waiting_time;
    }
    return time;
}

template<class P>
void Listext<P>::remove(P elem){
    if ((numitems == maxsize /4) && (maxsize > minsize)){
        deallocate();
    }
    int num = numitems;
    int index;
    for (int i = 0; i < num; i++){
        if (reprarray[i]->ID == elem -> ID){
            index = i;
            break;
        }
    }
    if (index < numitems){
        for (int j = index + 1 ; j < num ; ++j){
            reprarray[j-1] = reprarray[j] ;
        }
        numitems --;
        return;
    }
    else{
        cout << "Index error: list index out of range\n";
    }
}

template<class P>
void Listext<P>::removeID(int ID){
    if ((numitems == maxsize /4) && (maxsize > minsize)){
        deallocate();
    }
    int num = numitems;
    int index;
    for (int i = 0; i < num; i++){
        if (reprarray[i]->ID == ID){
            index = i;
            break;
        }
    }
    if (index < numitems){
        for (int j = index + 1 ; j < num ; ++j){
            reprarray[j-1] = reprarray[j] ;
        }
        numitems --;
        return;
    }
    else{
        cout << "Index error: list index out of range\n";
    }
}
    
template<class P>
void Listext<P>::removeR(P elem){
    if ((numitems == maxsize /4) && (maxsize > minsize)){
        deallocate();
    }
    int num = numitems;
    int index;
    for (int i = 0; i < num; i++){
        if (reprarray[i]== elem ){
            index = i;
            break;
        }
    }
    if (index < numitems){
        for (int j = index + 1 ; j < num ; ++j){
            reprarray[j-1] = reprarray[j] ;
        }
        numitems --;
        return;
    }
    else{
        cout << "Index error: list index out of range\n";
    }
}

template<class P> void Listext<P>::removerepeat()
{
   Listext<int>* temp = new Listext<int>();
   for (int i = 0; i < getlength(); i++)
   {
        if (temp->member(getitem(i)) == false)
        {
            temp->append(getitem(i));
        }
   }
   reprarray = temp->reprarray;
   maxsize = temp->maxsize;
   numitems = temp->numitems;
   return;
}

//the member function for person

void person::getage_grade(){
     int age = 2022 - this->birth_year;
    if (age <= 12 ) this->age_grade = 0;
    if (age > 12 && age <= 18) this->age_grade = 1;
    if (age > 18 && age <= 35) this->age_grade = 4;
    if (age > 35 && age <= 50) this->age_grade = 6;
    if (age > 50 && age <= 65) this->age_grade = 5;
    if (age > 65 && age <= 75) this->age_grade = 3;
    if (age > 75) this->age_grade = 2; 
}

person::person(){
    key = -1;
    address_x = -1;
    address_y = -1;
    appointcount = 0;
}


void person::getkey(){
    int keyvalue;
    int day;
    day = (365 * (this->registration_year - 2022) + 30 * (this->registration_month - 1 ) + this->registration_day) * 10 + 5 *this->registration_time ;
    this->key = day + this->age_grade * 10000 + this->job_grade *100000;
}

int person::getkeyvalue(){
    int keyvalue;
    int day;
    day = (365 * (this->registration_year - 2022) + 30 * (this->registration_month - 1 ) + this->registration_day) * 10 + 5 *this->registration_time ;
    keyvalue = day + this->age_grade * 10000 + this->job_grade *100000;
    return keyvalue;
}


void person::getkey2(){
    int keyvalue;
    int day;
    day = (365 * (this->registration_year - 2022) + 30 * (this->registration_month - 1 ) + this->registration_day) * 10 + 5 *this->registration_time ;
    this->key = day + this->age_grade * 100000 + this->job_grade *10000;
}

int person::getkeyvalue2(){
    int keyvalue;
    int day;
    day = (365 * (this->registration_year - 2022) + 30 * (this->registration_month - 1 ) + this->registration_day) * 10 + 5 *this->registration_time ;
    keyvalue = day + this->age_grade * 100000 + this->job_grade *10000;
    return keyvalue;
}


void person::getkey3(){
    int keyvalue;
    int day;
    day = (365 * (this->registration_year - 2022) + 30 * (this->registration_month - 1 ) + this->registration_day) * 10 + 5 *this->registration_time ;
    this->key = day*100 + this->age_grade * 10 + this->job_grade ;
}

int person::getkeyvalue3(){
    int keyvalue;
    int day;
    day = (365 * (this->registration_year - 2022) + 30 * (this->registration_month - 1 ) + this->registration_day) * 10 + 5 *this->registration_time ;
    keyvalue = day*100 + this->age_grade * 10 + this->job_grade;
    return keyvalue;
}

/*
类名:BTnode
*/
template <class T> BTnode<T>::BTnode()
{
	keyNum = 0;
	parent = NULL;//父节点初始化
   isleaf = true;
	int i ;
	for (i = 0;i < child_max;i++)//子树指针数组初始化
	{
		pchild[i] = NULL;
	}
	for (i = 0;i < key_max;i++)//关键字数组初始化
	{
		keyvalue[i] = node();
	}
}

template <class T> void BTnode<T>::inserts(T values)
{
   for(int i=0; i < keyNum; i++)
   {
      if (keyvalue[i] == values)
      {
         keyvalue[i].insertid(values.blockid->getitem(0));
      }
   }
}

template <class T> int BTnode<T>::deletes(T values)
{
   for(int i=0; i < keyNum; i++)
   {
      if (keyvalue[i] == values)
      {
         return keyvalue[i].deleteid(values.blockid->getitem(0));
      }
   }
   return -1;
}

template <class T> Listext<int>* BTnode<T>::finds(T values)
{
   for(int i=0; i< keyNum; i++)
   {
      if(keyvalue[i] == values)
      {
         return keyvalue[i].blockid;
      }
   }
   return NULL;
}

/*node类的函数*/

/*node::node()
{
   key=-1;
   blockid=new Listext<int>();
}
*/
node::node(int k, int id)
{
   key = k;
   blockid = new Listext<int>();
   blockid->append(id);
}

void node::insertid(int id)
{
   blockid->append(id);
}

int node::deleteid(int id)
{
   blockid->removeR(id);
   return blockid->numitems;
}

   
/*
类名:BTree
*/

/*
函数名:BTree
函数作用:无参构造函数
函数参数:无
函数返回值: 无
*/

/*template <class T> BTree<T>::BTree()
{
   root = NULL;
}
*/

template <class T> void BTree<T>::B_insert(int key, int bid){
   node node_temp = node(key, bid);
   BTree_insert(node_temp);
}

/*
函数名:BTree_insert
函数作用:插入关键字
函数参数:T value
函数返回值: bool类型判断插入是否成功
*/

template <class T> void BTree<T>::BTree_insert(T value)
{
   if (contain(value))//看树中是否有相同的关键字
   {
      BTnode<T>* current = BTree_find(root,value);
      current->inserts(value);
      //return false;
   }
   else
   {
      if (root == NULL)
      {
      	root = new BTnode<T>();
      }
      if (root->keyNum == key_max)
      {
         BTnode<T>* newnode = new BTnode<T>();
         newnode->pchild[0] = root;
         newnode->isleaf = false;//由上步操作可知newnode已经有子节点
         SplitBlock(newnode,0,root);//分块操作
         root = newnode;//更新根节点
      }
      	Notfull_insert(root,value);//插入块未满的操作
      	//return true;
   }
}
 
/*
函数名:SplitBlock
函数作用:把节点分裂
函数参数:BTnode<T>* node_parent,int child_index,BTnode<T>* node_child
函数返回值: 无
*/
template <class T> void BTree<T>::SplitBlock(BTnode<T>* node_parent,int child_index,BTnode<T>* node_child)
{
   BTnode<T>* node_right = new BTnode<T>();
   node_right->isleaf = node_child->isleaf;
   node_right->keyNum = key_min;
   int i;
   //node_right拷贝关键字
   for (i = 0;i < key_min;i++)
   {
      node_right->keyvalue[i] = node_child->keyvalue[i+child_min];
   }
   //判断分裂的节点是否是叶子节点,如果不是的话就要把它的孩子赋值过去
   if (!node_child->isleaf)
   {
      for (i = 0;i < child_min;i++)
      {
         node_right->pchild[i] = node_child->pchild[i+child_min];
         node_child->pchild[i+child_min]->parent = node_right->pchild[i];
      }
   }
   node_child->keyNum = key_min;//更新子节点的关键字数
   //把父节点关键字和子指针往后移 倒序赋值
   for (i = node_parent->keyNum;i > child_index;i--)
   {
      node_parent->keyvalue[i] = node_parent->keyvalue[i-1];
      node_parent->pchild[i+1] = node_parent->pchild[i];
      node_child->pchild[i]->parent = node_parent->pchild[i+1];
   }
   node_parent->keyNum++;//更新父节点关键字数
   node_parent->pchild[child_index+1] = node_right;
   node_right->parent = node_parent->pchild[child_index+1];
   //把中间的那个关键字上移到父节点
   node_parent->keyvalue[child_index] = node_child->keyvalue[key_min];
}   

/*
函数名:Notfull_insert
函数作用:往没有满的节点中增加关键字
函数参数:BTnode<T>* node,T value
函数返回值:无
*/
template <class T> void BTree<T>::Notfull_insert(BTnode<T>* node,T value)    
{
 
   int node_keynum = node->keyNum;//获取节点关键字数
   if (node->isleaf)//node是叶子节点
   {
      while (node_keynum > 0 && value < node->keyvalue[node_keynum-1])
      {
      	node->keyvalue[node_keynum] = node->keyvalue[node_keynum-1];//把关键字往后移动
      	--node_keynum;
      }
      node->keyvalue[node_keynum] = value;
      node->keyNum++;
   }
   else//node是内部节点
   {
      while (node_keynum > 0 && value < node->keyvalue[node_keynum-1])
      {
      	--node_keynum;
      }
      //在比它小和比它大中间那个子节点中找合适位置,
      //如果它比所有的都小则在第一个子节点中寻找
      BTnode<T>* node_child = node->pchild[node_keynum];
      if (node_child->keyNum == key_max)
      {
      	SplitBlock(node,node_keynum,node_child);
      	if (value > node->keyvalue[node_keynum])//插入值和子节点中间的值比较
      	{
      	  	node_child = node->pchild[node_keynum+1];
      	}
      }
      Notfull_insert(node_child,value);//继续往下寻找合适的位置
   }
}
    
/*
函数名:contain
函数作用:查找是否有相同元素在数中
函数参数:T value
函数返回值:bool类型s
*/
template <class T> bool BTree<T>::contain(T value)
{
   if (BTree_find(root,value) != NULL)
   {
      return true;
   }
   return false;
}
   
template <class T> Listext<int>* BTree<T>::B_find(int key)
{
   //node node_temp = node(int key, int 0);
   //node node_temp(int key, int 0);
   node node_temp = node(key, 0); 
   BTnode<T>* current = BTree_find(root,node_temp);
   if(current == NULL)
   {
      //cout<<"key not find!"<<endl;
      return NULL;
   }
   else
   {
      return current ->finds(node_temp);
   }
}
    
    
/*
函数名:BTree_find
函数作用:查找是否有相同元素在树中
函数参数:BTnode<T>* node_current,T value
函数返回值: BTnode<T>*
*/
template <class T> BTnode<T>* BTree<T>::BTree_find(BTnode<T>* node_current,T value)
{
   if (node_current == NULL)//当前节点为空的时候
   {
   	return NULL;
   }
   else//当前节点不为空
   {
   	int i;
      //在比它小和比它大的中间子节点中寻找相等的
   	for (i = 0; i < node_current->keyNum ;i++)
   	{
   	   if (value <= node_current->keyvalue[i])
         {
            break; 
         }
   	}
 
   	//校验当前的关键字是否等于查找的关键字
      if (i < node_current->keyNum && value == node_current->keyvalue[i])//i是下标最大值keyNum-1
      {
         return node_current;
      }
      else
      {
         //如果之前比查找关键没有相等的关键字并且当前节点是叶子节点的话
         //那么在B树中没有一样的关键字(因为后面比关键字更大)
         if (node_current->isleaf)
         {
         	return NULL;
         }
         else//如果不是叶子节点则在下面的子节点中寻找
         {
            return BTree_find(node_current->pchild[i],value);//这里的return别忘了
         }
      }
   }
}
  
/*
函数名:printpoint
函数作用:打印元素
函数参数:BTnode<T>* node,int count
函数返回值:无
*/
template <class T> void BTree<T>::printpoint(BTnode<T>* node,int count)
{
   if (node != NULL)//判断元素是否为空
   {
   	int i,j;
      //每个节点从小到大打印
   	for (i = 0;i < node->keyNum; i++)
   	{
      //判断是否叶节点,不是的话则要往子节点中寻找打印
   	   if (!node->isleaf)//判断是否是叶子节点
   	   {
            printpoint(node->pchild[i],count-3);
   	   }
   	   for (j = count;j >= 0; j--)
   	   {
   	   	cout<<"-";
   	   }
   	   cout<<"|"<<node->keyvalue[i].key<<"|"<<endl;
         node->keyvalue[i].blockid->prettyprint();
   	}
   	if (!node->isleaf)//子节点数比关键字数多一个
   	   {
            printpoint(node->pchild[i],count-3);
   	   }
   }
}
/*
函数名:printpoint
函数作用:printpoint无参函数传递值过去
函数参数:无
函数返回值:无
*/
template <class T> void BTree<T>::printpoint()
{
   printpoint(root,key_max*5);
}
/*
函数名:BTree_delete
函数作用:删除函数
函数参数:T value
函数返回值:bool类型
*/
template <class T> void BTree<T>::B_delete(int key,int bid)
{
   node node_temp = node(key, bid);
   BTnode<T>* current = BTree_find(root,node_temp);
   if (current==NULL)
   {
      cout<<"key can't find to delete!"<<endl;
      return;
   }
   int tmp=current->deletes(node_temp);
   if (tmp==0)
   {
      BTree_delete(node_temp);
   }
      
}

template <class T> bool BTree<T>::BTree_delete(T value)
{
   if (!contain(value))
   {
      return false;
   }
   if (root->keyNum == 1)
   {
      if (root->isleaf)
      {
         delete root;
         root = NULL;
         return true;
      }
      else//当根节点只有一个关键字时且不为叶子节点
      {
         BTnode<T>* node_child1 = root->pchild[0];
         BTnode<T>* node_child2 = root->pchild[1];
         //减少一层树的高度
         if (node_child1->keyNum == key_min && node_child2->keyNum == key_min)
         {
            MergeBlock(root,0);
            delete root;
            root = node_child1;
         }
      }
   }
   BTree_deletebalance(root,value);
   return true;
}

/*
函数名:MergeBlock
函数作用:合并块
函数参数:BTnode<T>* node_parent,int child_index
函数返回值:无
*/
template <class T> void BTree<T>::MergeBlock(BTnode<T>* node_parent,int child_index)
{
   BTnode<T>* node_child1 = node_parent->pchild[child_index];
   BTnode<T>* node_child2 = node_parent->pchild[child_index+1];
   //将父节点的节点对应的关键字下移
   node_child1->keyvalue[key_min] = node_parent->keyvalue[child_index];
   node_child1->keyNum = key_max;
   int i;
   for (i = 0;i < key_min;i++)
   {
      node_child1->keyvalue[child_min+i] = node_child2->keyvalue[i];
   }
   //判断node_child1是否是叶子节点,不是叶子节点则要将node_child2的子节点赋值给node_child1
   if (!node_child1->isleaf)
   {
      for (i = 0; i < child_min;i++)
      {
         node_child1->pchild[i+child_min] = node_child2->pchild[i];
      }
   }
   //因为父节点下移一个关键字,则关键字后的所有值要往前移动一个
   node_parent->keyNum--;
   for (i = child_index;i <  node_parent->keyNum;i++)
   {
      node_parent->keyvalue[i] = node_parent->keyvalue[i+1];
      //子节点也要往前移动一位
      node_parent->pchild[i+1] = node_parent->pchild[i+2];
   }
   delete node_child2;
   node_child2 = NULL;
}

/*
函数名:getprev
函数作用:在左边的兄弟节点中找一个最大的
函数参数:BTnode<T>* node
函数返回值:左边兄弟的最大的关键字
*/

template <class T> T BTree<T>::getprev(BTnode<T>* node)
{
   //在比节点位置小的节点中找一个最大的值最为
   while (!node->isleaf)
   {
      node = node->pchild[node->keyNum];
   }
   node->keyNum--;
   return node->keyvalue[node->keyNum-1];
}

/*
函数名:getnext
函数作用:在右边的兄弟节点中找一个最小的
函数参数:BTnode<T>* node
函数返回值:右边兄弟的最小的关键字
*/

template <class T> T BTree<T>::getnext(BTnode<T>* node)
{
   //在比节点位置大的节点中找一个最小的
   while (!node->isleaf)
   {
      node = node->pchild[0];
   }
   return node->keyvalue[0];
}

/*
函数名:BTree_deletebalance
函数作用:用递归删除并做修复
函数参数:BTnode<T>* node
函数返回值:无
*/
template <class T> void BTree<T>::BTree_deletebalance(BTnode<T>* node,T value)
{
   int i;
   //在当前节点中找合适坐标使得value在这个区间内
   for(i = 0;i < node->keyNum && value > node->keyvalue[i];i++)
   {
 
   }
   //如果当前i的关键字等于value
   if (i < node->keyNum && value == node->keyvalue[i])
   {
   //判断当前节点是否是叶子节点,如果是的话直接删除,下面的情况保证了如果value在叶子节点的话,叶子节点keyNum一定是>=child_min
      if (node->isleaf)
      {
         node->keyNum--;
         //把i后面的都往前移动一位
         for (;i < node->keyNum;i++)
         {
            node->keyvalue[i] = node->keyvalue[i+1];
         }
         return;
      }
      else//当前节点为内节点
      {
         //里面关键字都比value小的节点
         BTnode<T>* node_left = node->pchild[i];
         //里面关键字都比value大的节点
         BTnode<T>* node_right = node->pchild[i+1];
         if (node_left->keyNum >= child_min)//左子节点中的关键字数大于等于child_min
         {
            T prev_replace = getprev(node_left);
            //传递不平衡点让pre_replace
            BTree_deletebalance(node_left,prev_replace);
            //让前继的关键字替换当前删除的关键字
            node->keyvalue[i] = prev_replace;
            return;
         }
         else if (node_right->keyNum >= child_min)//右子节点中的关键字数大于等于child_min
         {
            T next_replace = getnext(node_right);
            //在左边中找到最大的那个递归替换
            BTree_deletebalance(node_right,next_replace);
            //让前继的关键字替换当前删除的关键字
            node->keyvalue[i] = next_replace;
            return;
         }
         else//左右子节点中的关键字数都等于key_min
         {
            //合并两个子节点
            MergeBlock(node,i);
            //在合并的节点中删除value值
            BTree_deletebalance(node_left,value);
         }
      }
   }
   else//关键字不在当前节点(下面步骤保证了遍历的所有节点关键字数都是大于等于child_min)
   {
      //在(<<value<<)的区间找
      BTnode<T>* node_child = node->pchild[i];//这里i = node->keyNum
      BTnode<T>*  node_left = NULL;
      BTnode<T>*  node_right = NULL;
      if (node_child->keyNum == key_min)//当前节点只有两个关键字,补给当前节点使之大于等于child_min
      {  
         //判断是否有左右兄弟节点
         if (i >0)
         {
            node_left = node->pchild[i-1];
         }
         if (i <= node->keyNum-1)
         {
            node_right = node->pchild[i+1];
         }
         int j;
         //当前左兄弟的关键字数大于等于child_min
         if (node_left && node_left->keyNum >= child_min)
         {   
            //把父节点的i-1对应的关键字下移
            for (j = node_child->keyNum;j > 0; j--)
            {
               node_child->keyvalue[j] = node_child->keyvalue[j-1];
            }
            node_child->keyvalue[0] = node->keyvalue[i-1];
            //如果子节点的左兄弟节点不是叶子节点
            if (!node_left->isleaf)
            {
               //把左兄弟最右边的子节点指针赋值给node_child
               for (j = node_child->keyNum+1;j > 0;j--)
               {
                  node_child->pchild[j-1]->parent = node_child->pchild[j]->parent;
                  node_child->pchild[j] = node_child->pchild[j-1];
 
               }
               node_left->pchild[node_left->keyNum]->parent =  node_child->pchild[0];
               node_child->pchild[0] = node_left->pchild[node_left->keyNum];
            }
            node_child->keyNum++;
            node->keyvalue[i-1] = node_left->keyvalue[node_left->keyNum-1];
            node_left->keyNum--;
         }
         else if (node_right && node_right->keyNum >= child_min)
         {
            //把父节点的i对应的关键字下移
            node_child->keyvalue[node_child->keyNum] = node->keyvalue[i];
            node_child->keyNum++;
            //把右兄弟节点最小的关键字赋值给父节点的i位置
            node->keyvalue[i] = node_right->keyvalue[0];
            node_right->keyNum--;
            //把右兄弟的关键字往前移动一位
            for (j = 0;j < node_right->keyNum;j++)
            {
               node_right->keyvalue[j] = node_right->keyvalue[j+1];
            }
            //如果右兄弟不是叶子节点则需要把右兄弟最左边的子节点指针赋值给node_child
            if (!node_right->isleaf)
            {
               node_right->pchild[0]->parent = node_child->pchild[node_child->keyNum]->parent;
               node_child->pchild[node_child->keyNum] = node_right->pchild[0];
               for (j = 0;j < node_right->keyNum+1;j++)
               {
                  node_right->pchild[j+1]->parent = node_right->pchild[j]->parent;
                  node_right->pchild[j] = node_right->pchild[j+1];
 
               }
                 
            }
         }
         else if (node_left)//node_left只有child_min-1个关键字
         {
            //把左兄弟合并
            MergeBlock(node,i-1);
            //更新子节点
            node_child = node_left;
         }
         else if (node_right)
         {
            //把右兄弟合并,子节点无需更新
            MergeBlock(node,i);
         }
      }
      BTree_deletebalance(node_child,value);
   }
}

// the member functions for block

template<class T>
block<T>::block(){
    overflowbuffer= new Listext<T>();
    reparray= new Listext<T>();
    block_ID = block_id;
    block_id++;
    maxsize = 20;
    overflowbig = maxsize * 2 / 3;
    overflowsmall = maxsize / 2;
    size = 0;
}

template<class T>
bool block<T>::isempty(){
    if (size == 0) 
        return true;
    return false;
}

template<class T>
bool block<T>::isfull(){
    if (size >= maxsize){
        return true;
    }
    return false;
}

template<class T>
void block<T>::sort(){
    int num = overflowbuffer->getlength() ;
    for (int i = 0; i < num - 1; ++i)
    {
        for (int j = i+1; j < num; ++j)
        {   
            if (overflowbuffer->reprarray[i]->ID > overflowbuffer->reprarray[j]->ID)
            {
                T temp;
                temp = overflowbuffer->reprarray[i];
                overflowbuffer->reprarray[i] = overflowbuffer->reprarray[j];
                overflowbuffer->reprarray[j] = temp;
            }
        }
    }
    return;
}

template<class T>
void block<T>::insert(T elem){
    if (isfull()){
        cout<< "FULL IN BLOCK"<< endl;
        return;
    }
    if (reparray->getlength() == 0){
        overflowbuffer->append(elem);
        size++;
        elem-> blockID = block_ID;
        if (overflowbuffer->getlength() == overflowbig){
            overtorep();
        }
    }
    else{
        int num = reparray->getlength();
        for (int i = 0; i < num ; i++){
            if (reparray->reprarray[i]->ID > elem->ID){
                reparray->insert(i,elem);
                elem-> blockID = block_ID;
                size++;
                break;
            }
            if(i==reparray->getlength()-1){
                reparray->append(elem);
                elem-> blockID = block_ID;
                size++;
            }
        }
    }
    
}

template<class T>
void block<T>::remove(T elem){
    if (isempty()){
        cout << "block is empty" << endl;
        return;
    }
    if ((!retrieve(elem->ID))){
        return;
    }
    if (reparray->getlength() == 0){
        for (int i = 0; i < overflowbuffer->getlength(); i++){
            if (overflowbuffer->reprarray[i] == elem ){
                overflowbuffer-> removeindex(i);
                size--;
                elem -> blockID = -1;
                return;
            }
        }
    }
    else{
        for(int i = 0; i < reparray->getlength(); i++){
           
            if (reparray->reprarray[i] == elem){
                reparray->reprarray[i]->bedelete = true;
                size--;
                elem -> blockID = -1;

                if (size <= overflowsmall){
                    reptovoer();
                }
                return;
            }
        }
    }

}

template<class T>
void block<T>::remove(int ID){
    remove(retrieve(ID));
}

template<class T>
T block<T>::ordsearch(int ID){
    int num = overflowbuffer->getlength();
    for (int i = 0; i < num ; i ++){
        if (overflowbuffer->reprarray[i]->ID == ID ){
            return overflowbuffer->reprarray[i];
        }
    }
    return NULL;
}

template< class T>
T block<T>::binarysearch(int ID){
	int low = 0, high = reparray->getlength(), middle = 0;
	while(low < high) {
		middle = (low + high)/2;
		if(ID == reparray->reprarray[middle]->ID) {
			return reparray->reprarray[middle];
		} else if(ID < reparray->reprarray[middle]->ID) {
			high = middle;
		} else if(ID > reparray->reprarray[middle]->ID) {
			low = middle + 1;
		}
	}
	return NULL;
}

template<class T>
T block<T>:: retrieve(int ID){
    T result;
    if (reparray->getlength() == 0){
        result = ordsearch(ID);
        if(result-> bedelete == true){
            return NULL;
        }
        return result;
    }
    result = binarysearch(ID);
    if(result-> bedelete == true){
            return NULL;
        }
    return result;
}

template<class T>
void block<T>::overtorep(){
    reparray->clear();
    sort();
    reparray->concat(*overflowbuffer);
    overflowbuffer->clear();
}

template<class T>
void block<T>::reptovoer(){
    overflowbuffer->clear();
    for (int i = 0; i < reparray->getlength(); i++){
        if (!reparray->reprarray[i]->bedelete){
            overflowbuffer->append(reparray->reprarray[i]);
        }
    }
    reparray->clear();
}

template<class T>
void block<T>::updateday(int counter){
    if (reparray->numitems != 0){
        int num = reparray->getlength();
        for (int i = 0; i < num; i++){
            if (reparray->reprarray[i]->betreated == false){
                reparray->reprarray[i]->countout = counter;
                reparray->reprarray[i]->waiting_time = (reparray->reprarray[i]->countout - reparray->reprarray[i]->countin)/2;
            }
            
        }
    }
    else{
        int num = overflowbuffer->getlength();
         for (int i = 0; i < num; i ++){
             if ( overflowbuffer->reprarray[i]->betreated == false){
                 overflowbuffer->reprarray[i]->countout = counter;
                 overflowbuffer->reprarray[i]->waiting_time = (overflowbuffer->reprarray[i]->countout -overflowbuffer->reprarray[i]->countin)/2;
             }
             
         }
    }
}


//the member function for relation
template<class T>
relation<T>::relation(){
    blocks = new Listext<block<T>*>();
}

template<class T>
int relation<T>::numitems(){
    return blocks->numitems;
}

template<class T>
void relation<T>::insert(T elem){
    block<T>* current = NULL;
    int num = blocks->getlength();
    
    for (int i = 0; i < num ; i++ ){
        if (!(blocks->reprarray[i]->isfull())){
            current = blocks->reprarray[i];
            break;
        }
    }

    if (current ==  NULL){
        current = new block<T>();
        blocks->append(current);
    }

    current->insert(elem);
}

template<class T>
block<T>* relation<T>::retrieve(int bloID){
    int low = 0, high = blocks->numitems, middle = 0;
	while(low < high) {
		middle = (low + high)/2;
		if(bloID == blocks->reprarray[middle]->block_ID) {
			return blocks->reprarray[middle];
		} else if(bloID < blocks->reprarray[middle]->block_ID) {
			high = middle;
		} else if(bloID > blocks->reprarray[middle]->block_ID) {
			low = middle + 1;
		}
	}
	return NULL;
}

template<class T>
T relation<T>::retrieve(int ID, int bloID){
    block<T>* currentblo = retrieve(bloID);
    if (currentblo == NULL){
        return NULL;
    }
    return currentblo->retrieve(ID);
}

template<class T>
void relation<T>::remove(T elem){
    if (elem == NULL){
        return;
    }
    int bloID = elem -> blockID;
    block<T>* currentblo = retrieve(bloID);
    if (currentblo == NULL){
        return;
    }
    currentblo->remove(elem);
}

template<class T>
void relation<T>::remove(int ID, int bloID){
    T elem = retrieve(ID, bloID);
    remove(elem);
}

template<class T>
void relation<T>::updateday(int counter){
    int num = blocks->getlength();
    for (int i = 0; i < num; i++){
        blocks->reprarray[i]->updateday(counter);
    }
}


//the member function for database
database::database(){
    personInfo = new relation<person*>();           
    medicalStatusInfo = new relation<medicalstatus*>();       
    registrationInfo = new relation<registration*>();
    treatmentInfo = new relation<treatment*>();
    withdrawlist = new Listext<person*>();
    midrisklist = new Listext<person*>();
    highrisklist = new Listext<person*>();
    h1 = new Hospital<FibNode<int>*>(1);
    h2 = new Hospital<FibNode<int>*>(2);
    h3 = new Hospital<FibNode<int>*>(3);
    treatlisttoday = new Listext<treatment*>();
    treatlisttomorral = new Listext<treatment*>();
    IDpersontree = new CBPlusTree();
    IDmedtree = new CBPlusTree();
    IDretree = new CBPlusTree();
    reg_B_tree = new BTree<node>();
    tre_B_tree = new BTree<node>();
    appo_B_tree = new BTree<node>();
    heap = new FibHeap<int>();
}

void database::insert(person* elem){
    personInfo->insert(elem);
}
void database::insert(medicalstatus* elem){
    medicalStatusInfo->insert(elem);
}
void database::insert(registration* elem){
    registrationInfo->insert(elem);
}
void database::insert(treatment* elem){
    treatmentInfo->insert(elem);
}

void database::remove(person* elem){
    personInfo->remove(elem);
}
void database::remove(medicalstatus* elem){
    medicalStatusInfo->remove(elem);
}
void database::remove(registration* elem){
    registrationInfo->remove(elem);
}
void database::remove(treatment* elem){
    treatmentInfo->remove(elem);
}

person* database::retrieveperson(int ID, int bloID){
    return personInfo->retrieve(ID,bloID);
}
medicalstatus* database::retrievemedstu(int ID, int bloID){
    return medicalStatusInfo->retrieve(ID,bloID);
}
registration* database::retrieverega(int ID, int bloID){
    return registrationInfo->retrieve(ID,bloID);
}
treatment* database::retrievetreat(int ID, int bloID){
    return treatmentInfo->retrieve(ID,bloID);
}

void database::removepe(int ID, int bloID){
    person* tmp = retrieveperson(ID,bloID);
    remove(tmp);
}
void database::removeme(int ID, int bloID){
    medicalstatus* tmp = retrievemedstu(ID,bloID);
    remove(tmp);
}
void database::removere(int ID, int bloID){
    registration* tmp = retrieverega(ID,bloID);
    remove(tmp);
}
void database::removetr(int ID, int bloID){
    treatment* tmp = retrievetreat(ID,bloID);
    remove(tmp);
}

void center::addallfile() {
    
    string filename;
    string choose1;
    int choose;
    
    while (true)
    {
        cout << "input 1 to input file!" << endl;/* code */
        cin >> choose1 ;
        choose = stoi(choose1);
        if (cin.fail() || choose != 1 ){
            cin.clear();
            cin.ignore(100,'\n');
        }
        else break;
        cout << "input wrong, please input again!" << endl;
    }
    
    
    
    filename = std::to_string(filen) + ".csv";
    filen++; 
    int ignorerow = 0;
   
    ifstream infile(filename);
    string s;
    getline(infile,s);
    CSV csv;
    csv.read(s);
    stringstream ss;

    while (infile.good() )
    {
        getline(infile,s);
        csv.read(s);
        person* badp = new person();
        badp->ID = stoi(csv[1]);
        badp->name = csv[0];
        badp->address_x = stoi(csv[2]);
        badp->address_y = stoi(csv[3]);
        badp->phone = csv[4];
        badp->wechat = csv[5];
        badp->email = csv[6];
        badp->job_grade = stoi(csv[7]);
        badp->birth_year = stoi(csv[8]);
        badp->birth_month = stoi(csv[9]);
        badp->birth_day = stoi(csv[10]);
        badp->registration_year = stoi(csv[11]);
        badp->registration_month = stoi(csv[12]);
        badp->registration_day = stoi(csv[13]);
        badp->registration_time = stoi(csv[14]);
        badp->risk_grade = stoi(csv[15]);
        badp->treatchoose = stoi(csv[16]);
        badp->getage_grade();
        badp->countin = centercounter;
        medicalstatus* meds = new medicalstatus(badp);
        registration* regs = new registration(badp);
        if (badp->treatchoose == 0){
            badp->getkey();
            treat_1->personInfo->insert(badp);
            treat_1->medicalStatusInfo->insert(meds);
            treat_1->registrationInfo->insert(regs);
            treat_1->IDpersontree->insert(badp->ID,badp->blockID);
            treat_1->IDmedtree->insert(meds->ID,meds->blockID);
            treat_1->IDretree->insert(regs->ID,regs->blockID);
            treat_1->reg_B_tree->B_insert(badp->countin,badp->blockID);
            if (badp->risk_grade == 2 ){
                treat_1->midrisklist->append(badp);
                badp->date = 60;
                continue;
            }
            if(badp->risk_grade == 3){
                treat_1->highrisklist->append(badp);
                continue;;
            }
            if(treat_1->withdrawlist->memberID(badp)){
                continue;
            }
            FibNode<int>* finod = new FibNode<int>(badp);
            treat_1->heap->insert(finod);
        }
        if (badp->treatchoose == 1){
            badp->getkey2();
            treat_2->personInfo->insert(badp);
            treat_2->medicalStatusInfo->insert(meds);
            treat_2->registrationInfo->insert(regs);
            treat_2->IDpersontree->insert(badp->ID,badp->blockID);
            treat_2->IDmedtree->insert(meds->ID,meds->blockID);
            treat_2->IDretree->insert(regs->ID,regs->blockID);
            treat_2->reg_B_tree->B_insert(badp->countin,badp->blockID);
            if (badp->risk_grade == 2 ){
                treat_2->midrisklist->append(badp);
                badp->date = 60;
                continue;
            }
             if(badp->risk_grade == 3){
                treat_2->highrisklist->append(badp);
                continue;;
            }
            if(treat_2->withdrawlist->memberID(badp)){
                continue;
            }
            FibNode<int>* finod = new FibNode<int>(badp);
            treat_2->heap->insert(finod);
        }
        if (badp->treatchoose == 2){
            badp->getkey3();
            treat_3->personInfo->insert(badp);
            treat_3->medicalStatusInfo->insert(meds);
            treat_3->registrationInfo->insert(regs);
            treat_3->IDpersontree->insert(badp->ID,badp->blockID);
            treat_3->IDmedtree->insert(meds->ID,meds->blockID);
            treat_3->IDretree->insert(regs->ID,regs->blockID);
            treat_3->reg_B_tree->B_insert(badp->countin,badp->blockID);
            if (badp->risk_grade == 2 ){
                treat_3->midrisklist->append(badp);
                badp->date = 60;
                continue;
            }
            if(treat_3->withdrawlist->memberID(badp)){
                continue;
            }
             if(badp->risk_grade == 3){
                treat_3->highrisklist->append(badp);
                continue;;
            }
            FibNode<int>* finod = new FibNode<int>(badp);
            treat_3->heap->insert(finod);
        }
        
        

    }
    infile.close();
}

void center::addallfilenew() {
    
    string filename;
    filename = std::to_string(filen) + ".csv";
    filen++; 
    int ignorerow = 0;
   
    ifstream infile(filename);
    string s;
    getline(infile,s);
    CSV csv;
    csv.read(s);
    stringstream ss;

    while (infile.good() )
    {
        getline(infile,s);
        csv.read(s);
        person* badp = new person();
        badp->ID = stoi(csv[1]);
        badp->name = csv[0];
        badp->address_x = stoi(csv[2]);
        badp->address_y = stoi(csv[3]);
        badp->phone = csv[4];
        badp->wechat = csv[5];
        badp->email = csv[6];
        badp->job_grade = stoi(csv[7]);
        badp->birth_year = stoi(csv[8]);
        badp->birth_month = stoi(csv[9]);
        badp->birth_day = stoi(csv[10]);
        badp->registration_year = stoi(csv[11]);
        badp->registration_month = stoi(csv[12]);
        badp->registration_day = stoi(csv[13]);
        badp->registration_time = stoi(csv[14]);
        badp->risk_grade = stoi(csv[15]);
        badp->treatchoose = stoi(csv[16]);
        badp->getage_grade();
        badp->countin = centercounter;
        medicalstatus* meds = new medicalstatus(badp);
        registration* regs = new registration(badp);
        
        if (badp->treatchoose == 0){
            badp->getkey();
            treat_1->personInfo->insert(badp);
            treat_1->medicalStatusInfo->insert(meds);
            treat_1->registrationInfo->insert(regs);
            treat_1->IDpersontree->insert(badp->ID,badp->blockID);
            treat_1->IDmedtree->insert(meds->ID,meds->blockID);
            treat_1->IDretree->insert(regs->ID,regs->blockID);
            treat_1->reg_B_tree->B_insert(badp->countin,badp->blockID);
            if (badp->risk_grade == 2 ){
                treat_1->midrisklist->append(badp);
                badp->date = 60;
                continue;
            }
            if(badp->risk_grade == 3){
                treat_1->highrisklist->append(badp);
                continue;;
            }
            if(treat_1->withdrawlist->memberID(badp)){
                continue;
            }
            FibNode<int>* finod = new FibNode<int>(badp);
            if (finod->ID == 109584){
                cout << "good" << endl;
            }
            treat_1->heap->insert(finod);
        }
        if (badp->treatchoose == 1){

            badp->getkey2();
            treat_2->personInfo->insert(badp);
            treat_2->medicalStatusInfo->insert(meds);
            treat_2->registrationInfo->insert(regs);
            treat_2->IDpersontree->insert(badp->ID,badp->blockID);
            treat_2->IDmedtree->insert(meds->ID,meds->blockID);
            treat_2->IDretree->insert(regs->ID,regs->blockID);
            treat_2->reg_B_tree->B_insert(badp->countin,badp->blockID);
            if (badp->risk_grade == 2 ){
                treat_2->midrisklist->append(badp);
                badp->date = 60;
                continue;
            }
             if(badp->risk_grade == 3){
                treat_2->highrisklist->append(badp);
                continue;;
            }
            if(treat_2->withdrawlist->memberID(badp)){
                continue;
            }
            FibNode<int>* finod = new FibNode<int>(badp);
            treat_2->heap->insert(finod);
        }
        if (badp->treatchoose == 2){
            badp->getkey3();
            treat_3->personInfo->insert(badp);
            treat_3->medicalStatusInfo->insert(meds);
            treat_3->registrationInfo->insert(regs);
            treat_3->IDpersontree->insert(badp->ID,badp->blockID);
            treat_3->IDmedtree->insert(meds->ID,meds->blockID);
            treat_3->IDretree->insert(regs->ID,regs->blockID);
            treat_3->reg_B_tree->B_insert(badp->countin,badp->blockID);
            if (badp->risk_grade == 2 ){
                treat_3->midrisklist->append(badp);
                badp->date = 60;
                continue;
            }
            if(treat_3->withdrawlist->memberID(badp)){
                continue;
            }
             if(badp->risk_grade == 3){
                treat_3->highrisklist->append(badp);
                continue;;
            }
            FibNode<int>* finod = new FibNode<int>(badp);
            treat_3->heap->insert(finod);
        }
        
        

    }
    infile.close();
}

void database::withdrawupdate(){
    int num = withdrawlist->numitems;
    for (int i = 0; i < num; i++ ){
        withdrawlist->reprarray[i]->date = withdrawlist->reprarray[i]->date - 1;
        if (withdrawlist->reprarray[i]->date <= 0 ){
            withdrawlist->remove(withdrawlist->reprarray[i]);
        }
    }
}

void database::midupdate(){
    int num = midrisklist->numitems;
    for (int i = 0; i < num; i++ ){
        midrisklist->reprarray[i]->date = midrisklist->reprarray[i]->date - 1;
        if (midrisklist->reprarray[i]->risk_grade < 2){
                FibNode<int>* nod = new FibNode<int>(midrisklist->reprarray[i]);
                heap->insert(nod);
                 midrisklist->remove(midrisklist->reprarray[i]);
            } 
        if (midrisklist->reprarray[i]->risk_grade == 3){
                highrisklist->append(midrisklist->reprarray[i]);
                midrisklist->remove(midrisklist->reprarray[i]);
            } 
        if (midrisklist->reprarray[i]->date <= 0 ){
            midrisklist->remove(midrisklist->reprarray[i]);
        }
    }
}

void database::updateperson(){
    string IDnum;
    string choose1;
    string choose2;
    string newjobgrade;
    string newriskgrade;
    int choose_1;
    int newjob; 
    int newrisk;
    cout<< "input your ID number !" << endl;
    cin >> IDnum;
    int ID = stoi(IDnum);
    int bloID = IDpersontree->select(ID,EQ)[0];
    person* persenchange = retrieveperson(ID,bloID);
    if (persenchange == NULL){
        cout << "You never registered, or you have withdrawed!" << endl;
        return;
    }
    if (retrievetreat(ID,bloID) != NULL){
        cout << "You have been treated!" << endl;
        return;
    }
    cout << "input the information you want to change" << endl;
    cout << "if you changed job, please input 1 ! " << endl;
    cout << "if your risk level changed, please input 2 !" << endl;
    cout << "if both are changed, please input 3 !" << endl;
    cin >> choose1;
    
    choose_1 = stoi(choose1);
    if (choose_1 <= 0 || choose_1 > 3){
        cout << "wrong input!" << endl;
        return;
    }
    if (choose_1 == 1){
        cout << "input your new job grade!" << endl;
        cin >> newjobgrade;
        newjob= stoi(newjobgrade);
        persenchange->job_grade = newjob;
        int newkey;
        if (persenchange->treatchoose == 0){
            persenchange->getkey();
            newkey = persenchange->getkeyvalue();
        }
        if (persenchange->treatchoose == 1){
            persenchange->getkey2();
            newkey = persenchange->getkeyvalue2();
        }
        if (persenchange->treatchoose == 2){
            persenchange->getkey3();
            newkey = persenchange->getkeyvalue3();
        }
        FibNode<int>* nod = heap->searchID(ID);
        if (nod == NULL){
            cout << "you have appointed" << endl;
            return;
        }
        heap->update(nod,newkey);
    }
    if (choose_1 == 2){
        cout << "input your new risk grade!" << endl;
        cin >> newriskgrade;
        newrisk = stoi(newriskgrade);
        int blomeID = IDmedtree->select(ID,EQ)[0];
        medicalstatus* medchange = retrievemedstu(ID,blomeID);
        if (medchange == NULL){
            cout <<"system wrong1! person data don't fit with med data!"<< endl;
            return;
        }
        if(persenchange->risk_grade == 3){
            if (newrisk == 2){
                highrisklist->remove(persenchange);
                midrisklist->append(persenchange);
            }
            if (newrisk < 2){
                FibNode<int>* finod = new FibNode<int>(persenchange);
                heap->insert(finod);
            }
        }
        medchange->risk_grade = newrisk;
        persenchange->risk_grade = newrisk;

    }
    if (choose_1 == 3 ){
        cout << "input your new job grade!" << endl;
        cin >> newjobgrade;
        persenchange->job_grade = newjob;
        int newkey;
        FibNode<int>* nod = heap->searchID(ID);
        if (persenchange->treatchoose == 0){
            persenchange->getkey();
            newkey = persenchange->getkeyvalue();
        }
        if (persenchange->treatchoose == 1){
            persenchange->getkey2();
            newkey = persenchange->getkeyvalue2();
        }
        if (persenchange->treatchoose == 2){
            persenchange->getkey3();
            newkey = persenchange->getkeyvalue3();
        }
        cout << "input your new risk grade!" << endl;
        cin >> newriskgrade;
        newrisk = stoi(newriskgrade);
        int blomeID = IDmedtree->select(ID,EQ)[0];
        medicalstatus* medchange = retrievemedstu(ID,blomeID);
        if (medchange == NULL){
            cout <<"system wrong1! person data don't fit with med data!"<< endl;
            return;
        }
        medchange->risk_grade = newrisk;
        persenchange->risk_grade = newrisk;
        if (nod == NULL){
            cout << "you have appointed" << endl;
            return;
        }
        heap->update(nod,newkey);
        }
    cout << "update successfully!" << endl;
    return;
}

void database::withdraw(){
    string IDnum;
    FibNode<int>* nod1;

    cout<< "input your ID number !" << endl;
    cin >> IDnum;
    int ID = stoi(IDnum);
    bool result1 = false;;
    bool result2 = false;
    bool result3 = false;
    bool result4 = false;
    bool result5 = false;
    FibNode<int>* nod =  heap->searchID(ID);
    result1 = h1->memID(ID);
    result2 = h2->memID(ID);
    result3 = h3->memID(ID);
    result4 = midrisklist->memID(ID);
    result5 = highrisklist->memID(ID);
    if((nod == NULL) && (result1 == false) && (result2 ==  false) && (result3 ==  false) && (result4 == false) && (result5 == false) ){
        cout << "You never registered or have been treated or have been withdrawed, and you can not withdraw!" << endl;
        return;}
    if (nod != NULL){
        person* per = retrieveperson(nod->ID,IDpersontree->select(nod->ID,EQ)[0]);
        medicalstatus* med = retrievemedstu(nod->ID, IDmedtree->select(nod->ID,EQ)[0]);
        registration* reg = retrieverega(nod->ID,IDretree->select(nod->ID, EQ)[0]);
        heap->remove(nod);
        medicalStatusInfo->remove(med);
        registrationInfo->remove(reg);
        IDpersontree->remove(nod->ID);
        IDmedtree->remove(nod->ID);
        IDretree->remove(nod->ID);
        reg_B_tree->B_delete(per->countin,per->blockID);
        personInfo->remove(per);
        withdrawlist->append(per);
        per->date = 28;
        cout << "withdraw successfully" << endl;
        withdrawlist->withdrawnum++;
        return;
    }
    if (result1 != false ){
        h1->removeID(ID);
        treatlisttomorral->removeID(ID);
        person* per = retrieveperson(ID,IDpersontree->select(ID,EQ)[0]);
        withdrawlist->append(per);
        medicalstatus* med = retrievemedstu(ID, IDmedtree->select(ID,EQ)[0]);
        registration* reg = retrieverega(ID,IDretree->select(ID, EQ)[0]);
        medicalStatusInfo->remove(med);
        registrationInfo->remove(reg);
        IDpersontree->remove(ID);
        IDmedtree->remove(ID);
        IDretree->remove(ID);
        reg_B_tree->B_delete(per->countin,per->blockID);
        appo_B_tree->B_delete(per->appointcount,per->blockID);
        personInfo->remove(per);
        per->date = 28;
        cout << "withdraw successfully" << endl;
        withdrawlist->withdrawnum++;
        return;
    }
    if (result2 != false ){
        h2->removeID(ID);
        treatlisttomorral->removeID(ID);
        person* per = retrieveperson(ID,IDpersontree->select(ID,EQ)[0]);
        withdrawlist->append(per);
        medicalstatus* med = retrievemedstu(ID, IDmedtree->select(ID,EQ)[0]);
        registration* reg = retrieverega(ID,IDretree->select(ID, EQ)[0]);
        medicalStatusInfo->remove(med);
        registrationInfo->remove(reg);
        IDpersontree->remove(ID);
        IDmedtree->remove(ID);
        IDretree->remove(ID);
        reg_B_tree->B_delete(per->countin,per->blockID);
        appo_B_tree->B_delete(per->appointcount,per->blockID);
        personInfo->remove(per);
        per->date = 28;
        cout << "withdraw successfully" << endl;
        withdrawlist->withdrawnum++;
        return;
    }
   if (result3 != false ){
        h3->removeID(ID);
        treatlisttomorral->removeID(ID);
        person* per = retrieveperson(ID,IDpersontree->select(ID,EQ)[0]);
        withdrawlist->append(per);
        medicalstatus* med = retrievemedstu(ID, IDmedtree->select(ID,EQ)[0]);
        registration* reg = retrieverega(ID,IDretree->select(ID, EQ)[0]);
        medicalStatusInfo->remove(med);
        registrationInfo->remove(reg);
        IDpersontree->remove(ID);
        IDmedtree->remove(ID);
        IDretree->remove(ID);
        reg_B_tree->B_delete(per->countin,per->blockID);
        appo_B_tree->B_delete(per->appointcount,per->blockID);
        personInfo->remove(per);
        per->date = 28;
        cout << "withdraw successfully" << endl;
        withdrawlist->withdrawnum++;
        return;
    }
    if (result4 != false ){
        midrisklist->removeID(ID);
        person* per = retrieveperson(ID,IDpersontree->select(ID,EQ)[0]);
        withdrawlist->append(per);
        medicalstatus* med = retrievemedstu(ID, IDmedtree->select(ID,EQ)[0]);
        registration* reg = retrieverega(ID,IDretree->select(ID, EQ)[0]);
        medicalStatusInfo->remove(med);
        registrationInfo->remove(reg);
        IDpersontree->remove(ID);
        IDmedtree->remove(ID);
        IDretree->remove(ID);
        reg_B_tree->B_delete(per->countin,per->blockID);
        //appo_B_tree->B_delete(per->appointcount,per->blockID);
        personInfo->remove(per);
        per->date = 28;
        cout << "withdraw successfully" << endl;
        withdrawlist->withdrawnum++;
        return;
    }
    if (result5 != false ){
        highrisklist->removeID(ID);
        person* per = retrieveperson(ID,IDpersontree->select(ID,EQ)[0]);
        withdrawlist->append(per);
        medicalstatus* med = retrievemedstu(ID, IDmedtree->select(ID,EQ)[0]);
        registration* reg = retrieverega(ID,IDretree->select(ID, EQ)[0]);
        medicalStatusInfo->remove(med);
        registrationInfo->remove(reg);
        IDpersontree->remove(ID);
        IDmedtree->remove(ID);
        IDretree->remove(ID);
        reg_B_tree->B_delete(per->countin,per->blockID);
        //appo_B_tree->B_delete(per->appointcount,per->blockID);
        personInfo->remove(per);
        per->date = 28;
        cout << "withdraw successfully" << endl;
        withdrawlist->withdrawnum++;
        return;
    }
       
}

void database::updateday(int counter){
    personInfo->updateday(counter);
    medicalStatusInfo->updateday(counter);
    registrationInfo->updateday(counter);
}

void database::centralization()
{
    int num = h1->numitems;
    int i;
    FibNode<int>* node;
    for (i = 0; i< num; i++){
        node = h1->reprarray[i];
        treatment* trea = new treatment(node);
        person* per = personInfo->retrieve(node->ID,IDpersontree->select(node->ID,EQ)[0]);
        trea->countin = per->countin;
        trea->waiting_time = per->waiting_time;
        treatlisttomorral->append(trea);
    }
    
    num = h2->numitems;
     for (i = 0; i< num; i++){
         node = h2->reprarray[i];
         treatment* trea = new treatment(node);
         person* per = personInfo->retrieve(node->ID,IDpersontree->select(node->ID,EQ)[0]);
        trea->countin = per->countin;
        trea->waiting_time = per->waiting_time;
        treatlisttomorral->append(trea);
    }
    num = h3->numitems;
     for (i = 0; i< num; i++){
        node = h3->reprarray[i];
        treatment* trea = new treatment(node);
        person* per = personInfo->retrieve(node->ID,IDpersontree->select(node->ID,EQ)[0]);
        trea->countin = per->countin;
        trea->waiting_time = per->waiting_time;
        treatlisttomorral->append(trea);
    }
};

int database::getyear(int value){
   int year = 2022;
    int four_year = value / 2922;
    int three_year = (value - four_year*2922) / 2192;
    return (year + 4*four_year + 3*three_year + (value-four_year*2922-three_year*2192)/730);
}

int database::getmonth(int value){
     int month = 1;
    int days_for_year;
    int years = getyear(value) - 2022;
    int four_years = years / 4;
    int three_years = (years - 4*four_years) / 3;
    days_for_year = 2922 * four_years + 2192 * three_years + (years - 4*four_years - 3*three_years) * 730;
    int days_for_month = (value - days_for_year)/2;
    int array_month_1[12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31};
    int array_month_2[12] = {31, 29, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31};

    if (getyear(value)%4 == 0)
    {
        for (int i = 1; i <= 12; i++)
        {
            if (days_for_month > array_month_2[i-1])
            {
                days_for_month -= array_month_2[i-1];
                month += 1;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        for (int i = 1; i <= 12; i++)
        {
            if (days_for_month > array_month_1[i-1])
            {
                days_for_month -= array_month_1[i-1];
                month += 1;
            }
            else
            {
                break;
            }
        } 
    }
    return month;
}

int database::getday(int value){
    int month = 1;
    int days_for_year;
    int years = getyear(value) - 2022;
    int four_years = years / 4;
    int three_years = (years - 4*four_years) / 3;
    days_for_year = 2922 * four_years + 2192 * three_years + (years - 4*four_years - 3*three_years) * 730;
    int days_for_month = (value - days_for_year)/2;
    int array_month_1[12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31};
    int array_month_2[12] = {31, 29, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31};

    if (getyear(value)%4 == 0)
    {
        for (int i = 1; i <= 12; i++)
        {
            if (days_for_month > array_month_2[i-1])
            {
                days_for_month -= array_month_2[i-1];
                month += 1;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        for (int i = 1; i <= 12; i++)
        {
            if (days_for_month > array_month_1[i-1])
            {
                days_for_month -= array_month_1[i-1];
                month += 1;
            }
            else
            {
                break;
            }
        } 
    }
    return days_for_month;
}

void database::inputtreat(int counter){
    int num = treatlisttomorral->getlength();
    for (int i = 0; i < num ; i++){
        treatment* trea =treatlisttomorral->reprarray[i];
        trea->treat_time_year = getyear(counter);
        trea->treat_time_month = getmonth(counter);
        trea->treat_time_day = getday(counter);
        trea->countout = counter;
        trea->waiting_time = (trea->countout - trea->countin)/ 2 ;
        trea->treat_time_year = getyear(counter);
        trea->treat_time_month = getmonth(counter);
        trea->treat_time_day = getday(counter);
        retrieveperson(trea->ID,IDpersontree->select(trea->ID,EQ)[0])->betreated = true;
        retrievemedstu(trea->ID,IDmedtree->select(trea->ID,EQ)[0])->betreated = true;
        retrieverega(trea->ID,IDretree->select(trea->ID,EQ)[0])->betreated = true;
        insert(trea);
        tre_B_tree->B_insert(trea->countout,trea->blockID);
        treatlisttoday->append(treatlisttomorral->reprarray[i]);

    } 
    treatlisttomorral->clear();
}

int database::distance(person* peo, Hospital<FibNode<int>*>* hos){
    int x1 = peo->address_x;
    int x2 = hos->Address_x;
    int y1 = peo->address_y;
    int y2 = hos->Address_y;
    int dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return dis;
};

void database::poppeople(FibNode<int>* peonod)
{       person* peo = retrieveperson(peonod->ID,IDpersontree->select(peonod->ID,EQ)[0]);
        int dis1 = distance(peo , h1);
        int dis2 = distance(peo , h2);
        int dis3 = distance(peo , h3);
        Hospital<FibNode<int>*>* first;
        Hospital<FibNode<int>*>* second;
        Hospital<FibNode<int>*>* third;
        if (dis1 < dis2 && dis1 < dis3){
            if (dis2 < dis3){
                first = h1;
                second = h2;
                third = h3;
            }
            first = h1;
            second = h3;
            third = h2;
        }
        if (dis2 < dis1 && dis2 < dis3){
            if (dis1 < dis3){
                first = h2;
                second = h1;
                third = h3;
            }
            first = h2;
            second = h3;
            third = h1;
        }
        if (dis3 < dis2 && dis3 < dis1){
            if (dis2 < dis1){
                first = h3;
                second = h2;
                third = h1;
            }
            first = h3;
            second = h1;
            third = h2;
        }
        if (first->numitems >= first->capacity){
            if (second->numitems >= second->capacity){
                third->append(peonod);
                return;
            }
            second->append(peonod);
            return;
        }
        first->append(peonod);
}

void database::popday(int counter){
    int tol_cap = h1->capacity + h2->capacity + h3->capacity;
    h1->clear();
    h2->clear();
    h3->clear();
    int peo = heap->keyNum;
    //IDpersontree->print();
    //IDpersontree->printData();
    for (int i = 0; i < tol_cap ; ){
        if(heap->keyNum <= 0 || heap->min->key == 0){
            for (int j = 0; j < tol_cap - i; j++){
            if (highrisklist->numitems == 0){
                return;
            }
            FibNode<int>* node = new FibNode<int>(highrisklist->reprarray[0]);
            person* per = retrieveperson(node->ID,IDpersontree->select(node->ID,EQ)[0]);
            appo_B_tree->B_insert(per->appointcount,per->blockID);
            poppeople(node);
            highrisklist->removeindex(0);
            i++;
            
        }
        return;
        }
        FibNode<int>* mn = new FibNode<int>(heap->min);
        person* per = retrieveperson(mn->ID, IDpersontree->select(mn->ID,EQ)[0]);
        if (per->risk_grade == 3 ){
            highrisklist->append(per);
            heap->remove(heap->min);
            continue;
        }
        if (per->risk_grade == 2){
            midrisklist->append(per);
            heap->remove(heap->min);
            continue;
        }
        per->appointcount = counter;
        per->appoint_time_year = getyear(counter);
        per->appoint_time_month = getmonth(counter);
        per->appoint_time_day = getday(counter);
        per->waiting_time = (per->appointcount - per->countin)/2;
        appo_B_tree->B_insert(per->appointcount,per->blockID);
        poppeople(mn);
        heap->remove(heap->min);
        i++;
    }
    
        
    
}

Listext<int>* database::getweeklistregblock(int counter){
    Listext<int>* ls = new Listext<int>();
    for (int i = 0; i < 14; i++){
        Listext<int>* sigle = reg_B_tree->B_find(counter - i-1);
        if (sigle == NULL){
            continue;
        }
        ls->concat(*sigle);
    }
    return ls;
}
Listext<int>* database::getweeklistappblock(int counter){
    Listext<int>* ls = new Listext<int>();
    for (int i = 0; i < 14; i++){
        Listext<int>* sigle = appo_B_tree->B_find(counter - i);
        if (sigle == NULL){
            continue;
        }
        ls->concat(*sigle);
    }
    return ls;
}
Listext<int>* database::getweeklisttreblock(int counter){
    Listext<int>* ls = new Listext<int>();
    for (int i = 0; i < 14; i++){
        Listext<int>* sigle = tre_B_tree->B_find(counter - i);
        if (sigle == NULL){
            continue;
        }
        ls->concat(*sigle);
    }
    return ls;
}

Listext<person*>* database::getweeklistregpeo(int counter){
    Listext<int>* ls = getweeklistregblock(counter);
    if (ls->numitems == 0){
            return NULL;
        }
    ls->removerepeat();
    Listext<person*>* result = new Listext<person*>();
    int num = ls->getlength();
    for (int i = 0; i < num; i ++){
        block<person*>* current = personInfo->retrieve(ls->reprarray[i]);
         if (current == NULL){
            continue;
        }
        if (current->reparray->numitems == 0){
            int numb = current->overflowbuffer->getlength();
            for (int j = 0; j < numb; j++ ){
                person* laji = current->overflowbuffer->reprarray[j];
                if (current->overflowbuffer->reprarray[j]->countin >= counter - 13){
                    result->append(current->overflowbuffer->reprarray[j]);
                }
            }
        }
        else{
            int numb = current->reparray->getlength();
            for (int j = 0; j < numb; j++ ){
                person* laji = current->reparray->reprarray[j];
                if (current->reparray->reprarray[j]->countin >= counter - 13){
                    result->append(current->reparray->reprarray[j]);
                }
            }
        }
    }
    return result;
} 

Listext<person*>* database::getweeklistapppeo(int counter){
   Listext<int>* ls = getweeklistappblock(counter);
   if (ls->numitems == 0){
            return NULL;
        }
    ls->removerepeat();
    Listext<person*>* result = new Listext<person*>();
    int num = ls->getlength();
    for (int i = 0; i < num; i ++){
        block<person*>* current = personInfo->retrieve(ls->reprarray[i]);
         if (current == NULL){
            continue;
        }
        if (current->reparray->numitems == 0){
            int numb = current->overflowbuffer->getlength();
            for (int j = 0; j < numb; j++ ){
                if (current->overflowbuffer->reprarray[j]->appointcount >= counter - 2){
                    result->append(current->overflowbuffer->reprarray[j]);
                }
            }
        }
        else{
            int numb = current->reparray->getlength();
            for (int j = 0; j < numb; j++ ){
                if (current->reparray->reprarray[j]->appointcount >= counter - 2){
                    result->append(current->reparray->reprarray[j]);
                }
            }
        }
    }
    return result;
} 

Listext<treatment*>* database::getweeklisttrepeo(int counter){
   Listext<int>* ls = getweeklisttreblock(counter);
   if (ls->numitems == 0){
            return NULL;
        }
    ls->removerepeat();
    Listext<treatment*>* result = new Listext<treatment*>();
    int num = ls->getlength();
    for (int i = 0; i < num; i ++){
        block<treatment*>* current = treatmentInfo->retrieve(ls->reprarray[i]);
        if (current == NULL){
            continue;
        }
        if (current->reparray->numitems == 0){
            int numb = current->overflowbuffer->getlength();
            for (int j = 0; j < numb; j++ ){
                if (current->overflowbuffer->reprarray[j]->countout >= counter - 13){    
                    result->append(current->overflowbuffer->reprarray[j]);
                }
            }
        }
        else{
            int numb = current->reparray->getlength();
            for (int j = 0; j < numb; j++ ){
                if (current->reparray->reprarray[j]->countout >= counter - 13){      
                    result->append(current->reparray->reprarray[j]);
                }
            }
        }
    }
    return result;
} 

Listext<int>* database::getmonthblocklist(int counter){
    Listext<int>* ls = new Listext<int>();
    for (int i = 0; i < 60; i++){
        Listext<int>* sigle = reg_B_tree->B_find(counter - i);
        if (sigle == NULL){
            continue;
        }
        ls->concat(*sigle);
    }
    return ls;
}

Listext<person*>* database::getmonthlist(int counter){
    Listext<int>* ls = getmonthblocklist(counter);
    if (ls->numitems == 0){
            return NULL;
        }
    ls->removerepeat();
    Listext<person*>* result = new Listext<person*>();
    int num = ls->getlength();
    for (int i = 0; i < num; i ++){
        block<person*>* current = personInfo->retrieve(ls->reprarray[i]);
        if (current == NULL){
            continue;
        }
        if (current->reparray->numitems == 0){
            int numb = current->overflowbuffer->getlength();
            for (int j = 0; j < numb; j++ ){
                if (current->overflowbuffer->reprarray[j]->countin >= counter - 59){
                    result->append(current->overflowbuffer->reprarray[j]);
                }
            }
        }
        else{
            int numb = current->reparray->getlength();
            for (int j = 0; j < numb; j++ ){
                if (current->reparray->reprarray[j]->countin >= counter - 59){ //00000000000000000000000000000000000000000000000000000000000
                    result->append(current->reparray->reprarray[j]);
                }
            }
        }
    }
    return result;
} 

Listext<int>* database::getmonthblocktrelist(int counter){
    Listext<int>* ls = new Listext<int>();
    for (int i = 0; i < 60; i++){
        Listext<int>* sigle = tre_B_tree->B_find(counter - i);
        if (sigle == NULL){
            continue;
        }
        ls->concat(*sigle);
    }
    return ls;
}

Listext<treatment*>* database::getmonthtrelist(int counter){
    Listext<int>* ls = getmonthblocktrelist(counter);
    if (ls->numitems == 0){
            return NULL;
        }
    ls->removerepeat();
    Listext<treatment*>* result = new Listext<treatment*>();
    int num = ls->getlength();
    for (int i = 0; i < num; i ++){
        block<treatment*>* current = treatmentInfo->retrieve(ls->reprarray[i]);
        if (current == NULL){
            continue;
        }
        if (current->reparray->numitems == 0){
            int numb = current->overflowbuffer->getlength();
            for (int j = 0; j < numb; j++ ){
                if (current->overflowbuffer->reprarray[j]->countin >= counter - 59){
                    result->append(current->overflowbuffer->reprarray[j]);
                }
            }
        }
        else{
            int numb = current->reparray->getlength();
            for (int j = 0; j < numb; j++ ){
                if (current->reparray->reprarray[j]->countin >= counter - 59){ //00000000000000000000000000000000000000000000000000000000000
                    result->append(current->reparray->reprarray[j]);
                }
            }
        }
    }
    return result;
} 

void database::monthlyreport(int counter, string name){
    //算各部分人数
    int h_num = (*h1).numitems+(*h2).numitems+(*h3).numitems;
    int w_num = (*withdrawlist).withdrawnum;
    int high_num = (*highrisklist).numitems;
    Listext<person*>* listmonth = getmonthlist(counter);
    Listext<treatment*>* listtremonth = getmonthtrelist(counter);
    int t_num = (*listmonth).numitems;
    int trea_num = listtremonth->numitems;
    //int f_num = (*heap).keyNum;
    int m_num = midrisklist->numitems;

    //计算各部分总等候时间
    int a_time = treatlisttomorral->list_wait_time();
    //int w_time = (*withdraw).list_wait_time();
    //int high_time = (*highrisklist).list_wait_time();
    int t_time = (*listmonth).list_wait_time();

    int h_time = treatlisttoday->list_wait_time();
    
    //建文件
    ofstream outFile;
    name = name + ".csv";
    outFile.open(name, ios::out);

    //打表头
    outFile << "total_people" << ',' << "now_wait_perople" << ',' << "treat_people" << "," << "average_wait_time" << "," << "withdraw_people" << endl;

    //输出
    //1.total_people
    int total_p = w_num + t_num;
    //2.now_wait_people
    int wait_p = total_p - w_num - trea_num;
    //3.treat_people
    //4.average_wait_time
    int ave_time = a_time + t_time ;
    if (wait_p != 0 && (total_p - wait_p) != 0){
        ave_time = ave_time / wait_p + h_time / (total_p - wait_p) ;
    }
    if (wait_p == 0 && (total_p - wait_p) != 0){
        ave_time = h_time / (total_p - wait_p) ;
    }
    if (wait_p != 0 && (total_p - wait_p) == 0){
        ave_time = ave_time / wait_p  ;
    }
    
    //5.withdraw_people

    outFile << total_p << ',' << wait_p << ',' << trea_num << "," << ave_time << "," << w_num << endl;
    outFile.close();
}





//the member function for center
center::center(){
    treat_1 = new database();
    treat_2 = new database();
    treat_3 = new database();
}

void center::locationinput(int h1x, int h1y, int h1c, int h2x, int h2y, int h2c, int h3x, int h3y, int h3c){
    treat_1->h1->Address_x = h1x;
    treat_1->h1->Address_y = h1y;
    treat_1->h1->capacity = h1c;
    treat_1->h2->Address_x = h2x;
    treat_1->h2->Address_y = h2y;
    treat_1->h2->capacity = h2c;
    treat_1->h3->Address_x = h3x;
    treat_1->h3->Address_y = h3y;
    treat_1->h3->capacity = h3c;
    treat_2->h1->Address_x = h1x;
    treat_2->h1->Address_y = h1y;
    treat_2->h1->capacity = h1c;
    treat_2->h2->Address_x = h2x;
    treat_2->h2->Address_y = h2y;
    treat_2->h2->capacity = h2c;
    treat_2->h3->Address_x = h3x;
    treat_2->h3->Address_y = h3y;
    treat_2->h3->capacity = h3c;
    treat_3->h1->Address_x = h1x;
    treat_3->h1->Address_y = h1y;
    treat_3->h1->capacity = h1c;
    treat_3->h2->Address_x = h2x;
    treat_3->h2->Address_y = h2y;
    treat_3->h2->capacity = h2c;
    treat_3->h3->Address_x = h3x;
    treat_3->h3->Address_y = h3y;
    treat_3->h3->capacity = h3c;
}

void center::updatecountdown(){
    treat_1->withdrawupdate();
    treat_2->withdrawupdate();
    treat_3->withdrawupdate();
    treat_1->midupdate();
    treat_2->midupdate();
    treat_3->midupdate();
}

void center::withdraw(){
    string choose1;
    int choose;
    while (true)
    {
        cout <<"input which treatment you want to withdraw" << endl;/* code */
        cout << "please input 1 to choose treatment_1"<< endl;
        cout << "please input 2 to choose treatment_2"<< endl;
        cout << "please input 3 to choose treatment_3"<< endl;
        cin >> choose1 ;
        choose = stoi(choose1);
        if (cin.fail() || (choose != 1 && choose != 2 && choose != 3)){
            cin.clear();
            cin.ignore(100,'\n');
        }
        else break;
        cout << "input wrong, please input again!" << endl;
    }
    if (choose == 1){
        treat_1->withdraw();
    }
    if (choose == 2){
        treat_2->withdraw();
    }
    if (choose == 3){
        treat_3->withdraw();
    }

}

void center::update(){
    string choose1;
    int choose;
    while (true)
    {
        cout <<"input which treatment you want to update" << endl;/* code */
        cout << "please input 1 to choose treatment_1"<< endl;
        cout << "please input 2 to choose treatment_2"<< endl;
        cout << "please input 3 to choose treatment_3"<< endl;
        cin >> choose1 ;
        choose = stoi(choose1);
        if (cin.fail() || (choose != 1 && choose != 2 && choose != 3)){
            cin.clear();
            cin.ignore(100,'\n');
        }
        else break;
        cout << "input wrong, please input again!" << endl;
    }
    if (choose == 1){
        treat_1->updateperson();
    }
    if (choose == 2){
        treat_2->updateperson();
    }
    if (choose == 3){
        treat_3->updateperson();
    }
}

void center::updateday(){
    treat_1->updateday(centercounter);
    treat_2->updateday(centercounter);
    treat_3->updateday(centercounter);
}

void center::popday(int counter){
    treat_1->popday(counter);
    treat_2->popday(counter);
    treat_3->popday(counter);
}

void center::updatehos(){
    if(centercounter % 2 ==0){
        treat_1->h1->clear();
        treat_1->h2->clear();
        treat_1->h3->clear();
        treat_2->h1->clear();
        treat_2->h2->clear();
        treat_2->h3->clear();
        treat_3->h1->clear();
        treat_3->h2->clear();
        treat_3->h3->clear();
    }
}

/// the member functions of FibHeap
template<class T>
FibHeap<T>::FibHeap(){
    keyNum = 0;
    maxDegree = 0;
    min = NULL;
    cons = NULL;
};

template<class T>
FibHeap<T>::~FibHeap()
{
};

template <class T>
void FibHeap<T>::addNode(FibNode<T> *node, FibNode<T> *root)                //insert the node before the root 
{
    node->left        = root->left;
    root->left->right = node;
    node->right       = root;
    root->left        = node;
};

template<class T>
void FibHeap<T>::removeNode(FibNode<T> *node){
    node->left->right  =node->right;
    node->right->left  =node->left;
};

template <class T>                                                          
void FibHeap<T>::insert(FibNode<T> *node)                                   //just insert the node before the node which have smallist keyvalue
{


    if (keyNum == 0)
        min = node;                                                         //if the node have smaller keyvalue, update the minimum
    else
       {
        addNode(node, min);
        if (node->key < min->key)
            min = node;
    }

    keyNum++;
};

template <class T>
void FibHeap<T>::catList(FibNode<T> *a, FibNode<T> *b)                      //list two double list, b is behand a
{
    FibNode<T> *tmp;

    tmp            = a->right;
    a->right       = b->right;
    b->right->left = a;
    b->right       = tmp;
    tmp->left      = b;
}

template <class T>
void FibHeap<T>::combine(FibHeap<T> *other)                                 
{
    if (other==NULL)
        return ;

    if(other->maxDegree > this->maxDegree)
        swap(*this, *other);

    if((this->min) == NULL)                // it means this is empty
    {
        this->min = other->min;
        this->keyNum = other->keyNum;
        free(other->cons);
        delete other;
    }
    else if((other->min) == NULL)           // it means other heap is empty
    {
        free(other->cons);
        delete other;
    }                                      
    else{   
        catList(this->min, other->min);             //list the root list
        if (this->min->key > other->min->key)       //update the new heap property
            this->min = other->min;
        this->keyNum += other->keyNum;
        free(other->cons);                      
        delete other;
    }
}

template <class T>
FibNode<T>* FibHeap<T>::extractMin()                //it means we will take out the min tree and all it's children out
{
    FibNode<T> *p = min;

    if (p == p->right)                              //if the heap just has one tree just return the tree.and the heap is empty, so the minmum is NULL
        min = NULL;                                 
    else
    {
        removeNode(p);
        min = p->right;
    }
    p->left = p->right = p;

    return p;
}
 
template <class T>
void FibHeap<T>::link(FibNode<T>* node, FibNode<T>* root)       //link the node into the root tree
{   
    removeNode(node);                                           //remove the node and the tree it lead from the formal heap
    if (root->child == NULL)                                    //if no child the root has, the node is the unique child of root
        root->child = node;         
    else
        addNode(node, root->child);                             //add the node before the root's child
    node->parent = root;                                        //update the tree property
    root->degree++;
    node->marked = false;
}
 
template <class T>
void FibHeap<T>::makeCons()                                         //build the space the consolidate need
{
    int old = maxDegree;
    maxDegree = (log(keyNum)/log(2.0)) + 1;
    if (old >= maxDegree)
        return ;
    cons = (FibNode<T> **)realloc(cons, 
            sizeof(FibHeap<T> *) * (maxDegree + 1));
}

template <class T>
void FibHeap<T>::consolidate()                                  //make the heap don't have trees which have same degree and update the minimum of heap
{
    int i, d, D;
    FibNode<T> *x, *y, *tmp;
    makeCons();
    D = maxDegree + 1;
    for (i = 0; i < D; i++)
        cons[i] = NULL;
    while (min != NULL)
    {
        x = extractMin();                
        d = x->degree;                            
        while (cons[d] != NULL)
        {
            y = cons[d];                
            if (x->key > y->key)        
                swap(x, y);
            link(y, x);  
            cons[d] = NULL;
            d++;
        }
        cons[d] = x;
    }
    min = NULL;
    for (i=0; i<D; i++)
    {
        if (cons[i] != NULL)
        {
            if (min == NULL)
                min = cons[i];
            else
            {
                addNode(cons[i], min);
                if ((cons[i])->key < min->key)
                    min = cons[i];
            }
        }
    }
}
 
template <class T>
void FibHeap<T>::removeMin()                                //delete the minmum node and add its children into the root list
{
    if (min==NULL)
        return ;

    FibNode<T> *child = NULL;
    FibNode<T> *m = min;
    while (m->child != NULL)
    {
        child = m->child;
        removeNode(child);
        if (child->right == child)
            m->child = NULL;
        else
            m->child = child->right;

        addNode(child, min);
        child->parent = NULL;
    }
    removeNode(m);
    if (m->right == m)
        min = NULL;
    else
    {
        min = m->right;
        consolidate();
    }
    keyNum--;
    delete m;
};

template<class T>
bool FibHeap<T>::minimum(T *pkey){                  //get the minmum and store the key value into the pkey point
    if (min == NULL || pkey == NULL){
        return false;
    }
    *pkey = min->key;
    return true;
};

template <class T>              
void FibHeap<T>::renewDegree(FibNode<T> *parent, int degree)            //change the degree of the node's parent
{
    parent->degree -= degree;
    if (parent-> parent != NULL)
        renewDegree(parent->parent, degree);
}
 
template <class T>
void FibHeap<T>::cut(FibNode<T> *node, FibNode<T> *parent)              //delete the node from it's parent list and add the node and it's children into root list
{
    removeNode(node);
    renewDegree(parent, node->degree);
    if (node == node->right) 
        parent->child = NULL;
    else 
        parent->child = node->right;
    node->parent = NULL;
    node->left = node->right = node;
    node->marked = false;
    addNode(node, min);
}

template <class T>
void FibHeap<T>::cascadingCut(FibNode<T> *node)             //if we use link instuction, the heap maybe can't fill the big heap property, then use this to change  
{
    FibNode<T> *parent = node->parent;
    if (parent != NULL)
    {
        if (node->marked == false) 
            node->marked = true;
        else
        {
            cut(node, parent);
            cascadingCut(parent);
        }
    }
}

template <class T>
void FibHeap<T>::decrease(FibNode<T> *node, T key)                  //decrease the keyvalue of node key into key
{
    FibNode<T> *parent;
    if (min==NULL ||node==NULL) 
        return ;
    if ( key>=node->key)
    {
        cout << "decrease failed: the new key(" << key <<") "
             << "is no smaller than current key(" << node->key <<")" << endl;
        return ;
    }
    node->key = key;
    parent = node->parent;
    if (parent!=NULL && node->key < parent->key)
    {
        cut(node, parent);
        cascadingCut(parent);
    }
    if (node->key < min->key)
        min = node;
}

template <class T>
void FibHeap<T>::increase(FibNode<T> *node, T key)                  //increase the keyvalue of node into key
{
    FibNode<T> *child, *parent, *right;

    if (min==NULL ||node==NULL) 
        return ;

    if (key <= node->key)
    {
        cout << "increase failed: the new key(" << key <<") " 
             << "is no greater than current key(" << node->key <<")" << endl;
        return ;
    }
    while (node->child != NULL)
    {
        child = node->child;
        removeNode(child);               
        if (child->right == child)
            node->child = NULL;
        else
            node->child = child->right;
        addNode(child, min);       
        child->parent = NULL;
    }
    node->degree = 0;
    node->key = key;
    parent = node->parent;
    if(parent != NULL)
    {
        cut(node, parent);
        cascadingCut(parent);
    }
    else if(min == node)
    {
        right = node->right;
        while(right != node)
        {
            if(node->key > right->key)
                min = right;
            right = right->right;
        }
    }
}

template<class T>
void FibHeap<T>::update(FibNode<T> *node, T key){                   //update the key value of node into key
    if (key == node->key) cout << "No need to update!" << endl;
    if (key < node->key)
        decrease(node,key);
    if (key > node->key)
        increase(node,key);
        
};

template<class T>
void FibHeap<T>::update(T oldkey, T newkey){                        //change the oldkey value node into new keyvalue
    FibNode<T>* node;
    node = search(oldkey);
    if (node != NULL)
        update(node, newkey);
}

template<class T>
bool FibHeap<T>:: contains( T key){
    return search(key) != NULL ? true : false;
}

template <class T>
void FibHeap<T>::remove(FibNode<T> *node)
{
    T m = min->key-1;
    decrease(node, m-1);
    removeMin();
}

template<class T>
void FibHeap<T>:: remove(T key){
    FibNode<T>* node;
    if (min == NULL)
        return;
    node = search(key);
    if (node == NULL)
        return;
    remove(node);
}

template<class T>
void FibHeap<T>::destroyNode(FibNode<T> *node){
    FibNode<T> *start = node;
    if (node == NULL)
        return;
    do{
        destroyNode(node->child);
        node = node->right;
        delete node->left;
    } while ( node != start);
}

template<class T>
void FibHeap<T>:: destroy(){
    destroyNode(min);
    free(cons);
}

template <class T>
void FibHeap<T>::print(FibNode<T> *node, FibNode<T> *prev, int direction)
 {
     FibNode<T> *start=node;
 
     if (node==NULL)
         return ;
     do
     {
        if (direction == 1)
             cout << setw(8) << node->key << "(" << node->degree << ") is "<< setw(2) << prev->key << "'s child" << prev->ID<< endl;
        else
             cout << setw(8) << node->key << "(" << node->degree << ") is "<< setw(2) << prev->key << "'s next" << prev->ID<< endl;
 
         if (node->child != NULL)
             print(node->child, node, 1);
 
         // 兄弟节点
         prev = node;
         node = node->right;
         direction = 2;
     } while(node != start);
 }

template <class T>
void FibHeap<T>::print()
 {
     int i=0;
     FibNode<T> *p;
 
     if (min==NULL)
         return ;
 
     cout << "== 斐波那契堆的详细信息: ==" << endl;
     p = min;
     do {
         i++;
         cout << setw(2) << i << ". " << setw(4) << p->key << "(" << p->degree << ") is root"  << p->ID<< endl;
 
         print(p->child, p, 1);
         p = p->right;
     } while (p != min);
     cout << endl;
 }

template<class T> void FibHeap<T>::fibnode_print(string file_name){
    ofstream outFile;
    file_name = file_name + ".csv";
    outFile.open(file_name, ios::out);
    outFile << "name" << "," << "ID" << "," << "job_grade" << "," << "age_grade" << "," << "risk_grade" << "," << "waiting_time" << endl;
    FibNode<T> *root = min;
    //遍历每一颗树
    do{
        FibNode<T>* degree = root->child;
        //遍历每一层
        outFile << root->name << "," << root->ID << "," << root->job_grade << ",";
        outFile << root->age_grade << "," << root->risk_grade << "," << root->waiting_time << endl;
        while(degree != NULL){
            //遍历每一点
            FibNode<T>* leave = degree;
            do{
                outFile << leave->name << "," << leave->ID << "," << leave->job_grade << ",";
                outFile << leave->age_grade << "," << leave->risk_grade << "," << leave->waiting_time << endl;
                leave = leave->left;
            }while(leave != degree);
            degree=degree->child;
        }
        root=root->left;
    }while(root != min);
    outFile.close();
}

template<class T> int FibHeap<T>::fibnode_wait_time(){
    int time;
    FibNode<T>* root = min;
    //遍历每一颗树
    do{
        FibNode<T>* degree = root->child;
        time = time + root->waiting_time;
        //遍历每一层
        while(degree != NULL){
            //遍历每一点
            FibNode<T>* leave = degree;
            do{
                leave = leave->left;
                time = time + leave->waiting_time;
            }while(leave != degree);
            degree=degree->child;
        }
        root=(*root).left;
    }while(root != min);
    return time;
}


// the member functions of FibNode
template<class T>
FibNode<T>::FibNode(person* value): degree(0), marked(false), 
            left(NULL),right(NULL),child(NULL),parent(NULL) {
            ID = value->ID;
            degree = 0;
            key = value->key;
            marked = false;
            left   = this;
            right  = this;
            parent = NULL;
            child  = NULL;
}

template<class T> 
FibNode<T>* FibHeap<T>:: search(FibNode<T> *root, T key){           //find if the node has keyvalue = key is in the tree of root
    FibNode<T>* t = root;
    FibNode<T> *p = NULL;
    if (root == NULL)
        return root;
    do{
        if (t->key == key){
            p = t;
            break;
        }
        else{
            if ((p = search(t->child,key)) != NULL)
                break;
            
        }
        t = t->right;
    } while ( t != root);
    return p;
}

template<class T> 
FibNode<T>* FibHeap<T>:: searchID(FibNode<T> *root, T ID){           //find if the node has keyvalue = key is in the tree of root
    FibNode<T>* t = root;
    FibNode<T> *p = NULL;
    if (root == NULL)
        return root;
    do{
        if (t->ID == ID){
            p = t;
            break;
        }
        else{
            if ((p = searchID(t->child,ID)) != NULL)
                break;
            
        }
        t = t->right;
    } while ( t != root);
    return p;
}

template<class T> 
FibNode<T>* FibHeap<T>:: searchID(T ID){
    if (min == NULL)
        return NULL;
    return searchID(min, ID);
}

template<class T> 
FibNode<T>* FibHeap<T>:: search(T key){
    if (min == NULL)
        return NULL;
    return search(min, key);
}
