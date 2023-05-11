#ifndef datatype_H
#define datatype_H
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

class basetype;
template <class T> class FibNode;
class person;


//数据类型比较下，有修正
class person_info{
    public:
        int ID;
        string name;        //姓名拼写 ZHANGSAN  姓加名
        int address_x;
        int address_y;      //坐标（x，y）
        string phone;        //11位手机号
        string wechat;      //花里胡哨
        string email;       //花里胡哨，too
        int job_grade;      //0-6，0 first
        int birth_year;
        int birth_month; 
        int birth_day;    
        int registration_year;
        int registration_month;
        int registration_day; 
        int registration_time;
        int appoint_time_year;
        int appoint_time_month;
        int appoint_time_day;
        int age_grade;      //0-7  ，0 first
        int risk_grade;     //0-3 0 no risk, 1 low risk, 2 middle risk,3 high risk       
        int waiting_time; 
};


class basetype
{
private:
    /* data */
public:
    basetype(/* args */);
    basetype( person_info* per ){
        ID = per->ID;
        bedelete = false;
        blockID = -1;
        countin = -1;
        countout = -1;
        betreated = false;
        waiting_time = 0;
    }
    ~basetype();
    int ID;
    bool bedelete;
    int blockID;
    int countin;
    int countout;
    bool betreated;
    int waiting_time;
};
basetype::basetype(){
    ID = 0;
    bedelete = false;
    blockID = -1;
    countin = -1;
    countout = -1;
    betreated = false;
    waiting_time = 0;
    
}


template <class T>
class FibNode
{
    public:
        T key;                
        int degree;           
        FibNode<T> *left;    
        FibNode<T> *right;    
        FibNode<T> *child;    
        FibNode<T> *parent;  
        bool marked; 
        int ID;
        FibNode(person* value);
        FibNode(FibNode<T>* N){
    
        left   = this;
        right  = this;
        parent = NULL;
        child  = NULL;

        key=N->key;
        degree=N->degree;
        marked = N->marked; 
        ID = N->ID;
        }
};



class person: public basetype
{
private:
    /* data */
public:
    person(/* args */);
    ~person();
    string name;        //姓名拼写 ZHANGSAN  姓加名
    int address_x;
    int address_y;      //坐标（x，y）
    string phone;        //11位手机号
    string wechat;      //花里胡哨
    string email;       //花里胡哨，too
    int job_grade;      //0-6，0 first
    int birth_year;
    int birth_month; 
    int birth_day;    
    int registration_year;
    int registration_month;
    int registration_day; 
    int registration_time;
    int appoint_time_year;
    int appoint_time_month;
    int appoint_time_day;
    int appointcount;
    int age_grade;      //0-7  ，0 first
    int risk_grade;     //0-3 0 no risk, 1 low risk, 2 middle risk,3 high risk       
    int key;
    int date;
    int treatchoose;
    void getkey();
    int getkeyvalue();
    void getkey2();
    int getkeyvalue2();
    void getkey3();
    int getkeyvalue3();
    void getage_grade();

    
};

class medicalstatus: public basetype
{
private:
    /* data */
public:
    int risk_grade;
    medicalstatus(/* args */);
    medicalstatus(person* per){
        ID = per->ID;
        blockID = -1;
        risk_grade = per->risk_grade;
        countin = per->countin;
    }
    ~medicalstatus();
};


class registration: public basetype
{
private:
    /* data */
public:
    registration(/* args */);
    ~registration();
    registration(person* per){
        ID = per->ID;
        blockID = -1;
        registration_year = per->registration_year;
        registration_month = per->registration_month;
        registration_day = per->registration_day;
        registration_time = per->registration_time;
        countin = per->countin;
    };
    int registration_year;
    int registration_month;
    int registration_day; 
    int registration_time;
};

class treatment: public basetype
{

public:
    treatment();
    ~treatment();
    treatment(FibNode<int>* node){
        ID = node->ID;
        treat_time_year = -1;
        treat_time_month = -1;
        treat_time_day = -1;
    };
    int treat_time_year;
    int treat_time_month;
    int treat_time_day;
};




#endif