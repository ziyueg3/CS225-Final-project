#include "centerdatabase.h"




//time functions
int getyear(int value){
    int year = 2022;
    int four_year = value / 2922;
    int three_year = (value - four_year*2922) / 2192;
    return (year + 4*four_year + 3*three_year + (value-four_year*2922-three_year*2192)/730);
}

int getmonth(int value){
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

int getday(int value){
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

int pramarycounter(int year, int month, int day){
     int yeargap = year - 2022;
    int days_for_year = 0;
    int days_for_month = 0;
    int array_year[4] = {730, 732, 730, 730};
    int array_month_1[12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31};
    int array_month_2[12] = {31, 29, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31};
    int days = 0;

    if (yeargap > 4)
    {
        days_for_year += (yeargap/4)*2922;
    }
    for (int i = 0; i < (yeargap % 4); i++)
    {
        days_for_year += array_year[i];
    }
    if (year%4)
    {
        for(int i = 0; i < (month - 1); i++)
        {
            days_for_month += array_month_1[i];
        }
    }
    else
    {
        for(int i = 0; i < (month - 1); i++)
        {
            days_for_month += array_month_2[i];
        }
    }
    days = days_for_month*2 + days_for_year + (day - 1) * 2;
    return days;
}






void weekly_report(Listext<treatment*>* treatinglist, Listext<person*>* appointlist, Listext<person*>* registerlist, string name){
    string tl = "treatinglist";
    string al = "appointlist";
    string rl = "registerlist";
    string nametl;
    string nameal;
    string namerl;
    nametl = name + tl;
    nameal = name + al;
    namerl = name + rl;

    registerlist->list_printper(namerl);
    treatinglist->list_print(nametl);
    appointlist->list_printper(nameal);
}

int compare_insert_value(string insert_string,string original_string){
    int len1=insert_string.size();
    int len2=original_string.size();
    int len=min(len1,len2);
    int insert=0;
    for(int i=0;i<len;i++){
        if(insert_string[i]<original_string[i]){
            insert=1;
            break;
        }else if(insert_string[i]>original_string[i]){
            insert=0;
            break;
        }
    }
    return insert;
}



void insert_sort_name(Listext<person*> *appointment,Listext <person*> *name_list){
    (*name_list).append((*appointment).reprarray[0]);
    for(int i=1;i<(*appointment).numitems;i++){
        int insert = 0;
        int num = (*name_list).numitems;
        for(int j=0;j<num;j++){
            //判断是否需要插入    
            insert=compare_insert_value((*(*appointment).reprarray[i]).name,(*(*name_list).reprarray[j]).name);
            if(insert == 1){
                (*name_list).insert(j,(*appointment).reprarray[i]);
                break;
            }
        }
        if(insert==0){
            (*name_list).append((*appointment).reprarray[i]);
        }
    }    
} 


void insert_sort_age(Listext <person*> *appointment,Listext <person*> *age_list){
    //Listext <FibNode<int>*> *age_list = new Listext <FibNode<int>*>();

    (*age_list).append((*appointment).reprarray[0]);
    for(int i=1;i<(*appointment).numitems;i++){
        int insert = 0;
        int num = (*age_list).numitems;
        for(int j=0;j<num;j++){
            //判断年      
            if((*(*appointment).reprarray[i]).birth_year > (*(*age_list).reprarray[j]).birth_year){
               (*age_list).insert(j,(*appointment).reprarray[i]);
                insert = 1;
                break;
                }
            //年相等
            else if((*(*appointment).reprarray[i]).birth_year == (*(*age_list).reprarray[j]).birth_year){
                //判断月
                if((*(*appointment).reprarray[i]).birth_month > (*(*age_list).reprarray[j]).birth_month){
                   (*age_list).insert(j,(*appointment).reprarray[i]);
                   insert = 1;
                   break;
                   }
                //月相等
                else if((*(*appointment).reprarray[i]).birth_month == (*(*age_list).reprarray[j]).birth_month){
                    //判断日
                    if((*(*appointment).reprarray[i]).birth_day >= (*(*age_list).reprarray[j]).birth_day){
                       (*age_list).insert(j,(*appointment).reprarray[i]);
                       insert = 1;
                       break;
                   }
               }
           }
        }
        if(insert==0){
            (*age_list).append((*appointment).reprarray[i]);
        }
    }
    
    return;
}

void insert_sort_treattime(Listext <treatment*> *source,Listext <treatment*> *result){
    //Listext <FibNode<int>*> *age_list = new Listext <FibNode<int>*>();

    (*result).append((*source).reprarray[0]);
    for(int i=1;i<(*source).numitems;i++){
        int insert = 0;
        int num = (*result).numitems;
        for(int j=0;j<num;j++){
            //判断年      
            if((*(*source).reprarray[i]).treat_time_year < (*(*source).reprarray[j]).treat_time_year){
               (*result).insert(j,(*source).reprarray[i]);
                insert = 1;
                break;
                }
            //年相等
            else if((*(*source).reprarray[i]).treat_time_year == (*(*result).reprarray[j]).treat_time_year){
                //判断月
                if((*(*source).reprarray[i]).treat_time_month < (*(*result).reprarray[j]).treat_time_month){
                   (*result).insert(j,(*source).reprarray[i]);
                   insert = 1;
                   break;
                   }
                //月相等
                else if((*(*source).reprarray[i]).treat_time_month == (*(*result).reprarray[j]).treat_time_month){
                    //判断日
                    if((*(*source).reprarray[i]).treat_time_day <= (*(*result).reprarray[j]).treat_time_day){
                       (*result).insert(j,(*source).reprarray[i]);
                       insert = 1;
                       break;
                   }
               }
           }
        }
        if(insert==0){
            (*result).append((*source).reprarray[i]);
        }
    }
    
    return;
}

//职业：等级从0排到7
void insert_sort_job(Listext <person*> *appointment,Listext <person*> *job_list){
    (*job_list).append((*appointment).reprarray[0]);
    for(int i=1;i<(*appointment).numitems;i++){
        int insert = 0;
        int num = (*job_list).numitems;
        for(int j=0;j<num;j++){
            //判断等级     
            if((*(*appointment).reprarray[i]).job_grade <= (*(*job_list).reprarray[j]).job_grade){
               (*job_list).insert(j,(*appointment).reprarray[i]);
                insert = 1;
                break;
                }
        }
        if(insert==0){
            (*job_list).append((*appointment).reprarray[i]);
        }
    }    
    return;
}



string getname(int counter){
    string year;
    string month;
    string day;
    string name;
    year = std::to_string(getyear(counter));
    month = std:: to_string(getmonth(counter));
    day =  std:: to_string(getday(counter));
    name = year + "-";
    name = name + month;
    name = name + "-";
    name = name + day;
    return name;
}