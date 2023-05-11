#include "member_function_2.cpp"
#include "outsidefunctions.cpp"



int main(){
    
    //variables define:
    int counter = 0;
    string choose1;
    string choose2;
    string choose3;
    string choose4;
    string choose5;
    string name;
    center* totalbase = new center();
    Listext<person*>* weekreg = new Listext<person*>();
    Listext<person*>* weekregaftsort= new Listext<person*>();
    Listext<person*>* weekapp= new Listext<person*>();
    Listext<person*>* weekappaftsort= new Listext<person*>();
    Listext<treatment*>* weektre= new Listext<treatment*>();
    Listext<treatment*>* weektreaftersort= new Listext<treatment*>();
    Listext<person*>* weekreg2 = new Listext<person*>();
    Listext<person*>* weekregaftsort2= new Listext<person*>();
    Listext<person*>* weekapp2= new Listext<person*>();
    Listext<person*>* weekappaftsort2= new Listext<person*>();
    Listext<treatment*>* weektre2= new Listext<treatment*>();
    Listext<treatment*>* weektreaftersort2= new Listext<treatment*>();
    Listext<person*>* weekreg3 = new Listext<person*>();
    Listext<person*>* weekregaftsort3= new Listext<person*>();
    Listext<person*>* weekapp3= new Listext<person*>();
    Listext<person*>* weekappaftsort3= new Listext<person*>();
    Listext<treatment*>* weektre3= new Listext<treatment*>();
    Listext<treatment*>* weektreaftersort3= new Listext<treatment*>();

    //variables primary
    //cout << "please input the pramary time" << endl;
    int year, month, day;
    int h1x,h1y,h1c,h2x,h2y,h2c,h3x,h3y,h3c;

   /* cout << "year:" << endl;
    cin>> choose1;
    year = stoi(choose1);
    cout << "month:" << endl;
    cin>> choose1;
    month = stoi(choose1);
    cout << "day:" << endl;
    cin>> choose1;
    day = stoi(choose1);
    cout << "hospital 1  address_x:" << endl;
    cin>> choose1;
    h1x = stoi(choose1);
    cout << "hospital 1  address_y:" << endl;
    cin>> choose1;
    h1y = stoi(choose1);
    cout << "hospital 1  capacity_x:" << endl;
    cin>> choose1;
    h1c = stoi(choose1);
    cout << "hospital 2  address_x:" << endl;
    cin>> choose1;
    h2x = stoi(choose1);
    cout << "hospital 2  address_y:" << endl;
    cin>> choose1;
    h2y = stoi(choose1);
    cout << "hospital 2  capacity_x:" << endl;
    cin>> choose1;
    h2c = stoi(choose1);
    cout << "hospital 3  address_x:" << endl;
    cin>> choose1;
    h3x = stoi(choose1);
    cout << "hospital 3  address_y:" << endl;
    cin>> choose1;
    h3y = stoi(choose1);
    cout << "hospital 3  capacity_x:" << endl;
    cin>> choose1;
    h3c = stoi(choose1);*/
    h1x = 1;
    h1y = 50;
    h1c = 8;
    h2x = 100;
    h2y =1;
    h2c = 6;
    h3x = 1;
    h3y = 1;
    h3c = 7;
    year = 2022;
    month = 4;
    day = 1;
    totalbase->locationinput(h1x, h1y, h1c, h2x, h2y, h2c, h3x, h3y, h3c);
    
    int pcounter = pramarycounter(year,month,day);
   
    for (counter = pcounter; counter >=0;){
        int clock = 0;
        cout << "input 1 to assess the system"<< endl;
        cout << "input 2 to input file of seven day " << endl;
        cout << "input 3 to input file of one month " << endl;
        cout << "input 4 to quit" << endl;

        string chooseday;
        int choose_day;
         while (true)
            {
                cin >> chooseday ;
                choose_day = stoi(chooseday);
                if (cin.fail() || choose_day >= 5 || choose_day <= 0 ){
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                else break;
                cout << "input wrong, please input again!" << endl;
            }
            if (choose_day == 1) clock = 0;
            if (choose_day == 2) clock = 14;
            if (choose_day == 3) clock = 60;
            if (choose_day == 4) return 1;
        if (clock != 0){
            for (int tam = 0; tam < clock; tam++){
                totalbase->centercounter = counter;
                int choose_1 = 1;
                int choose_2;
                int choose_3;
                int choose_4;
                int choose_5;
                //工作人员部分
                if (choose_1 == 1){
                    totalbase->addallfilenew();
                    if (filen == 36){
                    cout << filen << endl;
                }
                    counter++;
                    totalbase->updatecountdown();
                    totalbase->updateday();
                    if (counter %2 == 0 ){
                        totalbase->treat_1->inputtreat(counter);
                        totalbase->treat_2->inputtreat(counter);
                        totalbase->treat_3->inputtreat(counter);
                        totalbase->popday(counter);
                        totalbase->treat_1->centralization();
                        totalbase->treat_2->centralization();
                        totalbase->treat_3->centralization();
                        totalbase->updatehos();
                    }
                

                     if ((counter - pcounter) % 14 == 0 && (counter -pcounter) != 0){
                        cout<< "Do you need week report?" << endl;
                        cout<< "if you need, please input 1!" << endl;
                        cout<< "if you don't need, please input 2!" << endl;
                        cin >> choose3;
                        choose_3 = stoi(choose3);
                        if (choose_3 <= 0 || choose_3 >=3){
                            cout<< "input wrongly, not required by default!" << endl;
                            cout << "return primary page" << endl;
                            continue;
                        }
                        if (choose_3 == 2){
                            cout<< "OK"<< endl;
                        }
                        if (choose_3 == 1){
                            cout << "which kind of sort do you want?" << endl;
                            cout << "sort by name,please input 1!" << endl;
                            cout << "sort by age, please input 2!" << endl;
                            cout << "sort by job, please input 3!" << endl;
                            cin >> choose4;
                            choose_4 = stoi(choose4);
                            if (choose_4 < 0 || choose_4 > 3){
                                cout << "input wrongly" << endl;
                                cout << "return primary page" << endl;
                                continue;
                            }
                                    weektreaftersort->clear();
                                    weekappaftsort->clear();
                                    weekregaftsort->clear();
                                    weekapp->clear();
                                    weekreg->clear();
                                    weektre->clear();
                                    weektreaftersort2->clear();
                                    weekappaftsort2->clear();
                                    weekregaftsort2->clear();
                                    weekapp2->clear();
                                    weekreg2->clear();
                                    weektre2->clear();
                                    weektreaftersort3->clear();
                                    weekappaftsort3->clear();
                                    weekregaftsort3->clear();
                                    weekapp3->clear();
                                    weekreg3->clear();
                                    weektre3->clear();
                            if (choose_4 == 1){
                                   
                            /* totalbase->treat_1->reg_B_tree->printpoint();
                                cout << "good" << endl;
                                totalbase->treat_1->appo_B_tree->printpoint();
                                cout << "good" << endl;
                                totalbase->treat_1->tre_B_tree->printpoint();*/
                                weekreg = totalbase->treat_1->getweeklistregpeo(counter);
                                weekapp = totalbase->treat_1->getweeklistapppeo(counter);
                                weektre = totalbase->treat_1->getweeklisttrepeo(counter);
                                insert_sort_name(weekapp,weekappaftsort);
                                insert_sort_name(weekreg,weekregaftsort);
                                insert_sort_treattime(weektre,weektreaftersort);
                                name =  getname(counter);
                                cout << "today is ";
                                cout << name << endl;
                                name = name + "treatment1";
                                weekly_report(weektreaftersort,weekappaftsort,weekregaftsort,name);
                                weekreg2 = totalbase->treat_2->getweeklistregpeo(counter);
                                weekapp2 = totalbase->treat_2->getweeklistapppeo(counter);
                                weektre2 = totalbase->treat_2->getweeklisttrepeo(counter);
                                insert_sort_name(weekapp2,weekappaftsort2);
                                insert_sort_name(weekreg2,weekregaftsort2);
                                insert_sort_treattime(weektre2,weektreaftersort2);
                                name =  getname(counter);
                                name = name + "treatment2";
                                weekly_report(weektreaftersort2,weekappaftsort2,weekregaftsort2,name);
                                weekreg3 = totalbase->treat_3->getweeklistregpeo(counter);
                                weekapp3 = totalbase->treat_3->getweeklistapppeo(counter);
                                weektre3 = totalbase->treat_3->getweeklisttrepeo(counter);
                                insert_sort_name(weekapp3,weekappaftsort3);
                                insert_sort_name(weekreg3,weekregaftsort3);
                                insert_sort_treattime(weektre3,weektreaftersort3);
                                name =  getname(counter);
                                name = name + "treatment3";
                                weekly_report(weektreaftersort3,weekappaftsort3,weekregaftsort3,name);
                                cout<< "your week report has been saved in the folder of this system, please check!" << endl;
                                cout<< "file name is today's date + treatment type + the type of list" << endl;
                            }
                            if (choose_4 == 2){
                                weekreg = totalbase->treat_1->getweeklistregpeo(counter);
                                weekapp = totalbase->treat_1->getweeklistapppeo(counter);
                                weektre = totalbase->treat_1->getweeklisttrepeo(counter);
                                insert_sort_age(weekapp,weekappaftsort);
                                insert_sort_age(weekreg,weekregaftsort);
                                insert_sort_treattime(weektreaftersort,weektreaftersort);
                                name =  getname(counter);
                                cout << "today is ";
                                cout << name << endl;
                                name = name + "treatment1";
                                weekly_report(weektre,weekappaftsort,weekregaftsort,name);
                                weekreg2 = totalbase->treat_2->getweeklistregpeo(counter);
                                weekapp2 = totalbase->treat_2->getweeklistapppeo(counter);
                                weektre2 = totalbase->treat_2->getweeklisttrepeo(counter);
                                insert_sort_age(weekapp2,weekappaftsort2);
                                insert_sort_age(weekreg2,weekregaftsort2);
                                insert_sort_treattime(weektre2,weektreaftersort2);
                                name =  getname(counter);
                                name = name + "treatment2";
                                weekly_report(weektreaftersort2,weekappaftsort2,weekregaftsort2,name);
                                weekreg3 = totalbase->treat_3->getweeklistregpeo(counter);
                                weekapp3 = totalbase->treat_3->getweeklistapppeo(counter);
                                weektre3 = totalbase->treat_3->getweeklisttrepeo(counter);
                                insert_sort_age(weekapp3,weekappaftsort3);
                                insert_sort_age(weekreg3,weekregaftsort3);
                                insert_sort_treattime(weektre3,weektreaftersort3);
                                name =  getname(counter);
                                name = name + "treatment3";
                                weekly_report(weektreaftersort3,weekappaftsort3,weekregaftsort3,name);
                                cout<< "your week report has been saved in the folder of this system, please check!" << endl;
                                cout<< "file name is today's date + treatment type + the type of list" << endl;
                            }
                            if (choose_4 == 3){
                                weekreg = totalbase->treat_1->getweeklistregpeo(counter);
                                weekapp = totalbase->treat_1->getweeklistapppeo(counter);
                                weektre = totalbase->treat_1->getweeklisttrepeo(counter);
                                insert_sort_job(weekapp,weekappaftsort);
                                insert_sort_job(weekreg,weekregaftsort);
                                insert_sort_treattime(weektre,weektreaftersort);
                                name =  getname(counter);
                                cout << "today is ";
                                cout << name << endl;
                                name = name + "treatment1";
                                weekly_report(weektreaftersort,weekappaftsort,weekregaftsort,name);
                                weekreg2 = totalbase->treat_2->getweeklistregpeo(counter);
                                weekapp2 = totalbase->treat_2->getweeklistapppeo(counter);
                                weektre2 = totalbase->treat_2->getweeklisttrepeo(counter);
                                insert_sort_job(weekapp2,weekappaftsort2);
                                insert_sort_job(weekreg2,weekregaftsort2);
                                insert_sort_treattime(weektre2,weektreaftersort2);
                                name =  getname(counter);
                                name = name + "treatment2";
                                weekly_report(weektreaftersort2,weekappaftsort2,weekregaftsort2,name);
                                weekreg3 = totalbase->treat_3->getweeklistregpeo(counter);
                                weekapp3 = totalbase->treat_3->getweeklistapppeo(counter);
                                weektre3 = totalbase->treat_3->getweeklisttrepeo(counter);
                                insert_sort_job(weekapp3,weekappaftsort3);
                                insert_sort_job(weekreg3,weekregaftsort3);
                                insert_sort_treattime(weektre3,weektreaftersort3);
                                name =  getname(counter);
                                name = name + "treatment3";
                                weekly_report(weektreaftersort3,weekappaftsort3,weekregaftsort3,name);
                                cout<< "your week report has been saved in the folder of this system, please check!" << endl;
                                cout<< "file name is today's date + treatment type + the type of list" << endl;
                            }
                            
                        }
                        
                    }
                    if ((counter - pcounter) % 60 == 0 && ((counter - pcounter) != 0)){
                        cout << "Do you need month report?" << endl;
                        cin>>choose5;
                        choose_5 = stoi(choose5);
                        if (choose_5 <= 0 || choose_5 > 3){
                                cout << "input wrongly" << endl;
                                cout << "return primary page" << endl;
                                continue;
                            }
                        if (choose_5 == 2){
                                cout << "OK!" << endl;
                                cout << "return primary page" << endl;
                                continue;
                        }
                        if (choose_5 == 1){
                                string name;
                                name = getname(counter);
                                cout << "today is ";
                                cout << name << endl;
                                name = name + "treatment1_" ;
                                name = name + "monthreport";
                                totalbase->treat_1->monthlyreport(counter,name);
                                name = getname(counter) + "treatment2_" ;
                                name = name + "monthreport";
                                totalbase->treat_2->monthlyreport(counter,name);
                                name = getname(counter) + "treatment3_" ;
                                name = name + "monthreport";
                                totalbase->treat_3->monthlyreport(counter,name);
                                cout<< "your month report has been saved in the folder of this system, please check!" << endl;
                                cout<< "file name is today's date + treatment type + the type of list" << endl;
                        }
                    }
                    continue;

                }
        }
        }
        if (clock == 0){
            totalbase->centercounter = counter;
            cout << "hello! Who are you" << endl;
            cout << "If you are staff and want to input the file, please input 1" << endl;
            cout << "If you are patient, please input 2" << endl;
            cout << "If you want to quit the system, please input 3!"<< endl;
            cin >> choose1;
            int choose_1 = stoi(choose1);
            int choose_2;
            int choose_3;
            int choose_4;
            int choose_5;
            if (choose_1 <= 0 || choose_1 >3){
                cout << "input wrongly" << endl;
                cout << "return primary page" << endl;
                continue;
            }


                
            //病人部分

            if (choose_1 == 3) return 1 ;
            if (choose_1 == 2){
                cout << "please choose the business" << endl;
                cout << "if you want to withdraw registion, please input 1!" << endl;
                cout << "if you want to change your information, input 2!" << endl;
                cin >> choose2;
                choose_2 = stoi(choose2);
                if (choose_2 <= 0 || choose_2 > 2){
                    cout << "input wrongly" << endl;
                    cout << "return primary page" << endl;
                    continue;
                }
                if (choose_2 == 1){
                    totalbase->withdraw();
                    cout << "good bye!"<< endl;
                    cout << "return primary page" << endl;
                    continue;
                }
                if (choose_2 == 2){
                    totalbase->update();
                    cout << "good bye!" << endl;
                    cout << "return primary page" << endl;
                    continue;
                    
                }
            }


            //工作人员部分
            if (choose_1 == 1){
                totalbase->addallfile();
                if (filen == 36){
                    cout << filen << endl;
                }
                counter++;
                totalbase->updatecountdown();
                totalbase->updateday();
                if (counter %2 == 0 ){
                
                    
                    totalbase->treat_1->inputtreat(counter);
                    totalbase->treat_2->inputtreat(counter);
                    totalbase->treat_3->inputtreat(counter);
                    totalbase->popday(counter);
                    totalbase->treat_1->centralization();
                    totalbase->treat_2->centralization();
                    totalbase->treat_3->centralization();
                    totalbase->updatehos();
                }
            

                if ((counter - pcounter) % 14 == 0 && (counter -pcounter) != 0){
                cout<< "Do you need week report?" << endl;
                cout<< "if you need, please input 1!" << endl;
                cout<< "if you don't need, please input 2!" << endl;
                cin >> choose3;
                choose_3 = stoi(choose3);
                if (choose_3 <= 0 || choose_3 >=3){
                    cout<< "input wrongly, not required by default!" << endl;
                    cout << "return primary page" << endl;
                    continue;
                }
                if (choose_3 == 2){
                    cout<< "OK"<< endl;
                }
                if (choose_3 == 1){
                    cout << "which kind of sort do you want?" << endl;
                    cout << "sort by name,please input 1!" << endl;
                    cout << "sort by age, please input 2!" << endl;
                    cout << "sort by job, please input 3!" << endl;
                    cin >> choose4;
                    choose_4 = stoi(choose4);
                    if (choose_4 < 0 || choose_4 > 3){
                        cout << "input wrongly" << endl;
                        cout << "return primary page" << endl;
                        continue;
                    }
                            weektreaftersort->clear();
                            weekappaftsort->clear();
                            weekregaftsort->clear();
                            weekapp->clear();
                            weekreg->clear();
                            weektre->clear();
                            weektreaftersort2->clear();
                            weekappaftsort2->clear();
                            weekregaftsort2->clear();
                            weekapp2->clear();
                            weekreg2->clear();
                            weektre2->clear();
                            weektreaftersort3->clear();
                            weekappaftsort3->clear();
                            weekregaftsort3->clear();
                            weekapp3->clear();
                            weekreg3->clear();
                            weektre3->clear();
                    if (choose_4 == 1){
                            
                        
                    /* totalbase->treat_1->reg_B_tree->printpoint();
                        cout << "good" << endl;
                        totalbase->treat_1->appo_B_tree->printpoint();
                        cout << "good" << endl;
                        totalbase->treat_1->tre_B_tree->printpoint();*/
                        weekreg = totalbase->treat_1->getweeklistregpeo(counter);
                        weekapp = totalbase->treat_1->getweeklistapppeo(counter);
                        weektre = totalbase->treat_1->getweeklisttrepeo(counter);
                        insert_sort_name(weekapp,weekappaftsort);
                        insert_sort_name(weekreg,weekregaftsort);
                        insert_sort_treattime(weektre,weektreaftersort);
                        name =  getname(counter);
                        cout << "today is ";
                        cout << name << endl;
                        name = name + "treatment1";
                        weekly_report(weektreaftersort,weekappaftsort,weekregaftsort,name);
                        weekreg2 = totalbase->treat_2->getweeklistregpeo(counter);
                        weekapp2 = totalbase->treat_2->getweeklistapppeo(counter);
                        weektre2 = totalbase->treat_2->getweeklisttrepeo(counter);
                        insert_sort_name(weekapp2,weekappaftsort2);
                        insert_sort_name(weekreg2,weekregaftsort2);
                        insert_sort_treattime(weektre2,weektreaftersort2);
                        name =  getname(counter);
                        name = name + "treatment2";
                        weekly_report(weektreaftersort2,weekappaftsort2,weekregaftsort2,name);
                        weekreg3 = totalbase->treat_3->getweeklistregpeo(counter);
                        weekapp3 = totalbase->treat_3->getweeklistapppeo(counter);
                        weektre3 = totalbase->treat_3->getweeklisttrepeo(counter);
                        insert_sort_name(weekapp3,weekappaftsort3);
                        insert_sort_name(weekreg3,weekregaftsort3);
                        insert_sort_treattime(weektre3,weektreaftersort3);
                        name =  getname(counter);
                        name = name + "treatment3";
                        weekly_report(weektreaftersort3,weekappaftsort3,weekregaftsort3,name);
                        cout<< "your week report has been saved in the folder of this system, please check!" << endl;
                        cout<< "file name is today's date + treatment type + the type of list" << endl;
                    }
                    if (choose_4 == 2){
                        weekreg = totalbase->treat_1->getweeklistregpeo(counter);
                        weekapp = totalbase->treat_1->getweeklistapppeo(counter);
                        weektre = totalbase->treat_1->getweeklisttrepeo(counter);
                        insert_sort_age(weekapp,weekappaftsort);
                        insert_sort_age(weekreg,weekregaftsort);
                        insert_sort_treattime(weektreaftersort,weektreaftersort);
                        name =  getname(counter);
                        cout << "today is ";
                        cout << name << endl;
                        name = name + "treatment1";
                        weekly_report(weektre,weekappaftsort,weekregaftsort,name);
                        weekreg2 = totalbase->treat_2->getweeklistregpeo(counter);
                        weekapp2 = totalbase->treat_2->getweeklistapppeo(counter);
                        weektre2 = totalbase->treat_2->getweeklisttrepeo(counter);
                        insert_sort_age(weekapp2,weekappaftsort2);
                        insert_sort_age(weekreg2,weekregaftsort2);
                        insert_sort_treattime(weektre2,weektreaftersort2);
                        name =  getname(counter);
                        name = name + "treatment2";
                        weekly_report(weektreaftersort2,weekappaftsort2,weekregaftsort2,name);
                        weekreg3 = totalbase->treat_3->getweeklistregpeo(counter);
                        weekapp3 = totalbase->treat_3->getweeklistapppeo(counter);
                        weektre3 = totalbase->treat_3->getweeklisttrepeo(counter);
                        insert_sort_age(weekapp3,weekappaftsort3);
                        insert_sort_age(weekreg3,weekregaftsort3);
                        insert_sort_treattime(weektre3,weektreaftersort3);
                        name =  getname(counter);
                        name = name + "treatment3";
                        weekly_report(weektreaftersort3,weekappaftsort3,weekregaftsort3,name);
                        cout<< "your week report has been saved in the folder of this system, please check!" << endl;
                        cout<< "file name is today's date + treatment type + the type of list" << endl;
                    }
                    if (choose_4 == 3){
                        weekreg = totalbase->treat_1->getweeklistregpeo(counter);
                        weekapp = totalbase->treat_1->getweeklistapppeo(counter);
                        weektre = totalbase->treat_1->getweeklisttrepeo(counter);
                        insert_sort_job(weekapp,weekappaftsort);
                        insert_sort_job(weekreg,weekregaftsort);
                        insert_sort_treattime(weektre,weektreaftersort);
                        name =  getname(counter);
                        cout << "today is ";
                        cout << name << endl;
                        name = name + "treatment1";
                        weekly_report(weektreaftersort,weekappaftsort,weekregaftsort,name);
                        weekreg2 = totalbase->treat_2->getweeklistregpeo(counter);
                        weekapp2 = totalbase->treat_2->getweeklistapppeo(counter);
                        weektre2 = totalbase->treat_2->getweeklisttrepeo(counter);
                        insert_sort_job(weekapp2,weekappaftsort2);
                        insert_sort_job(weekreg2,weekregaftsort2);
                        insert_sort_treattime(weektre2,weektreaftersort2);
                        name =  getname(counter);
                        name = name + "treatment2";
                        weekly_report(weektreaftersort2,weekappaftsort2,weekregaftsort2,name);
                        weekreg3 = totalbase->treat_3->getweeklistregpeo(counter);
                        weekapp3 = totalbase->treat_3->getweeklistapppeo(counter);
                        weektre3 = totalbase->treat_3->getweeklisttrepeo(counter);
                        insert_sort_job(weekapp3,weekappaftsort3);
                        insert_sort_job(weekreg3,weekregaftsort3);
                        insert_sort_treattime(weektre3,weektreaftersort3);
                        name =  getname(counter);
                        name = name + "treatment3";
                        weekly_report(weektreaftersort3,weekappaftsort3,weekregaftsort3,name);
                        cout<< "your week report has been saved in the folder of this system, please check!" << endl;
                        cout<< "file name is today's date + treatment type + the type of list" << endl;
                    }
                    
                }
                
            }
            if ((counter - pcounter) % 60 == 0 && ((counter - pcounter) != 0)){
                cout << "Do you need month report?" << endl;
                cout << "input 1 if you need" << endl;
                cout << "input 2 if you don't need"<< endl;
                cin>>choose5;
                choose_5 = stoi(choose5);
                if (choose_5 <= 0 || choose_5 > 3){
                        cout << "input wrongly" << endl;
                        cout << "return primary page" << endl;
                        continue;
                    }
                if (choose_5 == 2){
                        cout << "OK!" << endl;
                        cout << "return primary page" << endl;
                        continue;
                }
                if (choose_5 == 1){
                        string name;
                        name = getname(counter);
                        cout << "today is ";
                        cout << name << endl;
                        name = name + "treatment1_" ;
                        name = name + "monthreport";
                        totalbase->treat_1->monthlyreport(counter,name);
                        name = getname(counter) + "treatment2_" ;
                        name = name + "monthreport";
                        totalbase->treat_2->monthlyreport(counter,name);
                        name = getname(counter) + "treatment3_" ;
                        name = name + "monthreport";
                        totalbase->treat_3->monthlyreport(counter,name);
                        cout<< "your month report has been saved in the folder of this system, please check!" << endl;
                        cout<< "file name is today's date + treatment type + the type of list" << endl;
                }
            }
            cout << "return primary page" << endl;
            continue;

            }



        }
        




           
        }
    






    /*int num = center->personInfo->blocks->reprarray[0]->reparray->getlength();
    for (int i = 0 ; i < num ; i++){
        cout << center->personInfo->blocks->reprarray[0]->reparray->reprarray[i]->ID << endl;
    }
    cout << "good" << endl;
    center->removepe(10006,0);
    center->removepe(10007,0);
    center->removepe(10009,0);
    center->removepe(10001,0);
    center->removepe(10005,0);
    center->removepe(10003,0);
    center->removepe(10016,0);
    center->removepe(10018,0);
    center->removepe(10014,0);
    center->removepe(10011,0);
    center->removepe(10020,0);
    center->removepe(10021,0);
    center->removepe(10002,0);
    num = center->personInfo->blocks->reprarray[0]->size;
    cout << num << endl;
    cout << center->personInfo->blocks->reprarray[0]->overflowbuffer->getlength()<< endl;
    for (int i = 0 ; i < num ; i++){
        cout << center->personInfo->blocks->reprarray[0]->overflowbuffer->reprarray[i]->ID << endl;
    }
    center->addallfile();
    num = center->personInfo->blocks->reprarray[0]->size;
    cout << num << endl;
    cout << center->personInfo->blocks->reprarray[0]->overflowbuffer->getlength()<< endl;
    for (int i = 0 ; i < num ; i++){
        cout << center->personInfo->blocks->reprarray[0]->overflowbuffer->reprarray[i]->ID << endl;
    }*/
    /*person* p = center->retrieveperson(10006,0);
    cout << p->birth_day << endl;
    cout << p->ID << endl;
    center->removepe(10006,0);
    person* q = center->retrieveperson(10006,0);
    cout << "baga" << endl;
    if (q == NULL){
        cout << "kongde" << endl;
    }
    cout << q-> ID << endl;
    if (q->bedelete == true){
        cout << "delete success"<< endl;
    }*/
    return 1;
}