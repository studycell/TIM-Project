#ifndef F_H_
#define F_H_
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class list_calendar
{
public:
    int caid;
    string content;
    string holiday;
};

class Calendar
{
private:
    vector<list_calendar> calendarname;
    int num=0;
public:
    int visit(int i_caid);
    void modify(int i_caid);
    void create();
};

class list_schedule
{
public:
    int scid;
    string title;
    string location;
    string people;
    string content;
};
int label_cai=-1;
int label_sci=-1;
int label_toi=-1;
void Calendar::create()
{
    int i_caid=-1;
    string i_holiday;
    string i_content;
    cout<<"please input date holiday（节日） content（提醒内容）"<<endl;
    cin>>i_caid>>i_holiday>>i_content;
    if(i_caid<0)
    {
        cout<<"invalid input. please input num>0."<<endl;
        return;
    }
    for(int i=0;i<Calendar::num;i++)
    {
        if(calendarname[i].caid==i_caid)
        {
            cout<<"the date has existed. please change other num."<<endl;
            return;
        }
    }
    list_calendar temp;
    temp.caid=i_caid;
    temp.content=i_content;
    temp.holiday=i_holiday;
    calendarname.push_back(temp);
    Calendar::num++;
    cout<<"[create]the new calendarname has added."<<endl;
    cout<<calendarname[num-1].caid<<" "<<calendarname[num-1].holiday<<" "<<calendarname[num-1].content<<endl;
    return;
}
int Calendar::visit(int i_caid)
{
    for(label_cai=0;label_cai<Calendar::num;label_cai++)
    {
        if(i_caid==calendarname[label_cai].caid)
        {
            break;
        }
    }
    if(label_cai>=num)
    {
        cout<<"the calendarname is not exist."<<endl;
        return -1;
    }
    cout<<"[visit]the calendarname information:"<<endl;
    cout<<calendarname[label_cai].caid<<" "<<calendarname[label_cai].holiday<<" "<<calendarname[label_cai].content<<endl;
    return label_cai;
}
void Calendar::modify(int i_caid) {
    int cai_mdf;
    int visit_i;
    string holiday_mdf, content_mdf;
    //cout << "please input the caid that you want to modify" << endl;
    //cin >> i_caid;
    visit_i = Calendar::visit(i_caid);
    if (visit_i < 0) {
        cout << "you can’t change no exist calendarname." << endl;
        return;
    }
    cout << "please input: (if you won‘t change,please input the same)" << endl;
    cin >> cai_mdf >> holiday_mdf >> content_mdf;
    calendarname[visit_i].caid = cai_mdf;
    calendarname[visit_i].holiday = holiday_mdf;
    calendarname[visit_i].content = content_mdf;
    cout << "[modify]the calendarname has changed" << endl;
    Calendar::visit(cai_mdf);
    return;
}
class Schedule
{
private:
    vector<list_schedule> schedulename;
    int num=0;
public:
    int visit(int i_scid);
    void modify(int i_scid);
    void create();
};
void Schedule::create()
{
    int i_scid=-1;
    string i_title;
    string i_location;
    string i_people;
    string i_content;
    cout<<"please input scid title location people content"<<endl;
    cin>>i_scid>>i_title>>i_location>>i_people>>i_content;
    if(i_scid<0)
    {
        cout<<"invalid input. please input num>0."<<endl;
        return;
    }
    for(int i=0;i<num;i++)
    {
        if(schedulename[i].scid==i_scid)
        {
            cout<<"the caid has existed. please change other num."<<endl;
            return;
        }
    }
    list_schedule temp;
    temp.scid=i_scid;
    temp.title=i_title;
    temp.location=i_location;
    temp.people=i_people;
    temp.content=i_content;
    schedulename.push_back(temp);
    Schedule::num++;
    cout<<"[create]the new schedulename has added."<<endl;
    cout<<schedulename[num-1].scid<<" "<<schedulename[num-1].title<<" "<<schedulename[num-1].location<<" "<<schedulename[num-1].people<<" "<<schedulename[num-1].content<<endl;
    return;
}
int Schedule::visit(int i_scid)
{
    for(label_sci=0;label_sci<Schedule::num;label_sci++)
    {
        if(i_scid==schedulename[label_sci].scid)
        {
            break;
        }
    }
    if(label_sci>=num)
    {
        cout<<"the calendarname is not exist."<<endl;
        return -1;
    }
    cout<<"[visit]the schedulename information:"<<endl;
    cout<<schedulename[label_sci].scid<<" "<<schedulename[label_sci].title<<" "<<schedulename[label_sci].location<<" "<<schedulename[label_sci].people<<" "<<schedulename[label_sci].content<<endl;
    return label_sci;
}
void Schedule::modify(int i_scid)
{
    int sci_mdf;
    int visit_i;
    string title_mdf,location_mdf,people_mdf,content_mdf;
    visit_i=Schedule::visit(i_scid);
    if(visit_i<0)
    {
        cout<<"you cant change no exist calendarname."<<endl;
        return;
    }
    cout<<"please input: (if you wont change,please input the same)"<<endl;
    cin>>sci_mdf>>title_mdf>>location_mdf>>people_mdf>>content_mdf;
    schedulename[visit_i].scid=sci_mdf;
    schedulename[visit_i].title=title_mdf;
    schedulename[visit_i].location=location_mdf;
    schedulename[visit_i].people=people_mdf;
    schedulename[visit_i].content=content_mdf;
    cout<<"[modify]the schedulename has changed"<<endl;
    Schedule::visit(sci_mdf);
    return;
}
class list_todo
{
public:
    int toid;
    string content;
    bool state;
};

class Todo
{
private:
    vector<list_todo> todoname;
    int num=0;
public:
    void create();
    void modify(int i_toid);
    int visit(int i_toid);
};
void Todo::create()
{
    int i_toid=-1;
    string i_content;
    cout<<"please input toid content"<<endl;
    cin>>i_toid>>i_content;
    if(i_toid<0)
    {
        cout<<"invalid input. please input num>0."<<endl;
        return;
    }
    for(int i=0;i<num;i++)
    {
        if(todoname[i].toid==i_toid)
        {
            cout<<"the caid has existed. please change other num."<<endl;
            return;
        }
    }
    list_todo temp;
    temp.toid=i_toid;
    temp.content=i_content;
    temp.state=false;
    todoname.push_back(temp);
    num++;
    cout<<"[create]the new todoname has added."<<endl;
    cout<<todoname[num-1].toid<<" "<<todoname[num-1].content<<" "<<todoname[num-1].state<<endl;
    return;
}
int Todo::visit(int i_toid)
{
    for(label_toi=0;label_toi<num;label_toi++)
    {
        if(i_toid==todoname[label_toi].toid)
        {
            break;
        }
    }
    if(label_toi>=num)
    {
        cout<<"the calendarname is not exist."<<endl;
        return -1;
    }
    cout<<"[visit]the schedulename information:"<<endl;
    cout<<todoname[label_toi].toid<<" "<<todoname[label_toi].content<<" "<<todoname[label_toi].state<<endl;
    return label_toi;
}
void Todo::modify(int i_toid)
{
    int toi_mdf;
    int visit_i;
    string content_mdf;
    bool state_mdf;
    visit_i=Todo::visit(i_toid);
    if(visit_i<0)
    {
        cout<<"you cant change no exist calendarname."<<endl;
        return;
    }
    cout<<"please input: (if you wont change,please input the same)"<<endl;
    cin>>toi_mdf>>content_mdf>>state_mdf;
    todoname[visit_i].toid=toi_mdf;
    todoname[visit_i].content=content_mdf;
    todoname[visit_i].state=state_mdf;
    cout<<"[modify]the schedulename has changed"<<endl;
    Todo::visit(toi_mdf);
    return;
}

class collect_filetype
{
public:
    string file;
    string content;
    string note;
    string picture;
    void show(char firstchar);
};
void collect_filetype::show(char firstchar)
{
    switch (firstchar)
    {
        case 'f':cout<<"file ";break;
        case 'c':cout<<"content ";break;
        case 'p':cout<<"picture ";break;
        case 'n':cout<<"note ";break;
        default:cout<<"error run";break;
    }
    return;
}

class collect_function
{
public:
    void create();
    void visit();
    void modify();
    void upload();
    void download();
};
void collect_function::upload()
{
    cout<<"upload loading..."<<endl;
    cout<<"upload success..."<<endl;
    return;
}
void collect_function::download()
{
    cout<<"download request..."<<endl;
    cout<<"download success  !"<<endl;
    return;
}
void collect_function::create()
{
    cout<<"create loading..."<<endl;
    cout<<"create success  !"<<endl;
    return;
}
void collect_function::modify()
{
    cout<<"modify request..."<<endl;
    cout<<"modifying     ..."<<endl;
    cout<<"modify success  !"<<endl;
    return;
}
void collect_function::visit()
{
    cout<<"visit request..."<<endl;
    cout<<"visit success   ! the information is here"<<endl;
    cout<<"visit end..."<<endl;
}
class Collect
{
private:
    collect_function function;
    collect_filetype filetype;
public:
    void use();
};
void Collect::use()
{
    string i_file;
    string i_func;
    collect_filetype filename;
    collect_function function;
    cout<<"please input the 'file' and 'function'"<<endl;
    cout<<"'filename':file content picture note"<<endl;
    cout<<"'function':create visit modify upload download"<<endl;
    cin>>i_file>>i_func;
    if(i_file=="file")
    {
        filename.show('f');
    }
    else if(i_file=="content")
    {
        filename.show('c');
    }
    else if(i_file=="picture")
    {
        filename.show('p');
    }
    else if(i_file=="note")
    {
        filename.show('n');
    }
    if (i_func=="create")
    {
        function.create();
    }
    else if(i_func=="visit")
    {
        function.visit();
    }
    else if(i_func=="modify")
    {
        function.modify();
    }
    else if(i_func=="upload")
    {
        function.upload();
    }
    else if(i_func=="download")
    {
        function.download();
    }
    return;
}
/*   AbstractFactory  */
class AbstractFactory
{
public:
    Calendar getCalendar();
    Schedule getSchedule();
    Todo getTodo();
    Collect getCollect();
};


Calendar AbstractFactory::getCalendar()
{
    Calendar calendar;
    cout<<"calendar start to work."<<endl;
    return calendar;
}
Schedule AbstractFactory::getSchedule()
{
    Schedule schedule;
    cout<<"schedule start to work."<<endl;
    return schedule;
}
Todo AbstractFactory::getTodo()
{
    Todo todo;
    cout<<"todo start to work."<<endl;
    return todo;
}
Collect AbstractFactory::getCollect()
{
    Collect collect;
    cout<<"collect start to work."<<endl;
    return collect;
}
class FactoryProducer
{
public:
    AbstractFactory getFactory();
};
AbstractFactory FactoryProducer::getFactory()
{
    AbstractFactory Factory;
    cout<<"AbstractFactory start to work"<<endl;
    return Factory;
}
/*  menu  */
void AbstractFactory_menu();
void Calendar_menu();
void Schedule_menu();
void Todo_menu();
void Collect_menu();
void FactoryProduce_menu()
{
    int state_fp=1;
    int num_fp;
    while(state_fp)
    {
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"\t\t\t\t     1.FactoryProducer               *"<<endl;
        cout<<"\t\t\t\t     2.exit                          *"<<endl;
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"please input num to run"<<endl;
        cin>>num_fp;
        switch (num_fp)
        {
            case 1:
            {
                FactoryProducer factoryproducer;
                factoryproducer.getFactory();
                AbstractFactory_menu();
                break;
            }
            case 2:
            {
                cout<<"exiting ... success";
                state_fp=0;
                break;
            }
            default:
            {
                cout<<"error run"<<endl;
                state_fp=0;
                break;
            }
        }
    }
    return;
}
void AbstractFactory_menu()
{
    int state_abf=1;
    int num_abf;
    while(state_abf)
    {
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"\t\t\t\t     1.Calendar                      *"<<endl;
        cout<<"\t\t\t\t     2.Schedule                      *"<<endl;
        cout<<"\t\t\t\t     3.Todo                          *"<<endl;
        cout<<"\t\t\t\t     4.Collect                       *"<<endl;
        cout<<"\t\t\t\t     5.exit                          *"<<endl;
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"please input num to run"<<endl;
        cin>>num_abf;
        switch (num_abf)
        {
            case 1:
            {
                AbstractFactory abstractfactory;
                abstractfactory.getCalendar();
                Calendar_menu();
                break;
            }
            case 2:
            {
                AbstractFactory abstracfactory;
                abstracfactory.getSchedule();
                Schedule_menu();
                break;
            }
            case 3:
            {
                AbstractFactory abstracfactory;
                abstracfactory.getTodo();
                Todo_menu();
                break;
            }
            case 4:
            {
                AbstractFactory abstracfactory;
                abstracfactory.getCollect();
                Collect_menu();
                break;
            }
            case 5:
            {
                cout<<"exiting ... success"<<endl;
                state_abf=0;
                break;
            }
            default:
            {
                cout<<"error run"<<endl;
                state_abf=0;
                break;
            }
        }
    }
    return;
}
void Calendar_menu()
{
    Calendar calendar;
    int state_ca=1;
    int num_ca;
    int i_caid_menu;
    while(state_ca)
    {
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"\t\t\t\t     1.create                        *"<<endl;
        cout<<"\t\t\t\t     2.modify                        *"<<endl;
        cout<<"\t\t\t\t     3.visit                         *"<<endl;
        cout<<"\t\t\t\t     4.exit                          *"<<endl;
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"please input num to run"<<endl;
        cin>>num_ca;
        switch (num_ca)
        {
            case 1:
            {
                calendar.create();
                break;
            }
            case 2:
            {
                cout<<"please input the caid that you want to modify"<<endl;
                cin>>i_caid_menu;
                calendar.modify(i_caid_menu);
                break;
            }
            case 3:
            {
                int visit_num=-1;
                cout<<"please input the caid that you want to visit"<<endl;
                cin>>i_caid_menu;
                visit_num=calendar.visit(i_caid_menu);
                (void)visit_num;
                break;
            }
            case 4:
            {
                cout<<"exiting...success"<<endl;
                state_ca=0;
                break;
            }
            default:
            {
                cout<<"error run"<<endl;
                state_ca=0;
                break;
            }
        }
    }
    return;
}
void Schedule_menu()
{
    Schedule schedule;
    int state_sc=1;
    int num_sc;
    int i_scid_menu;
    while(state_sc)
    {
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"\t\t\t\t     1.create                        *"<<endl;
        cout<<"\t\t\t\t     2.modify                        *"<<endl;
        cout<<"\t\t\t\t     3.visit                         *"<<endl;
        cout<<"\t\t\t\t     4.exit                          *"<<endl;
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"please input num to run"<<endl;
        cin>>num_sc;
        switch (num_sc)
        {
            case 1:
            {
                schedule.create();
                break;
            }
            case 2:
            {
                cout<<"please input the scid that you want to modify"<<endl;
                cin>>i_scid_menu;
                schedule.modify(i_scid_menu);
                break;
            }
            case 3:
            {
                int visit_num=-1;
                cout<<"please input the scid that you want to visit"<<endl;
                cin>>i_scid_menu;
                visit_num=schedule.visit(i_scid_menu);
                (void)visit_num;
                break;
            }
            case 4:
            {
                cout<<"exiting...success"<<endl;
                state_sc=0;
                break;
            }
            default:
            {
                cout<<"error run"<<endl;
                state_sc=0;
                break;
            }
        }
    }
    return;
}
void Todo_menu()
{
    Todo todo;
    int state_to=1;
    int num_to;
    int i_todi_menu;
    while(state_to)
    {
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"\t\t\t\t     1.create                        *"<<endl;
        cout<<"\t\t\t\t     2.modify                        *"<<endl;
        cout<<"\t\t\t\t     3.visit                         *"<<endl;
        cout<<"\t\t\t\t     4.exit                          *"<<endl;
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"please input num to run"<<endl;
        cin>>num_to;
        switch(num_to)
        {
            case 1:
            {
                todo.create();
                break;
            }
            case 2:
            {
                cout<<"please input the toid that you want to modify"<<endl;
                cin>>i_todi_menu;
                todo.modify(i_todi_menu);
                break;
            }
            case 3:
            {
                int visit_num=-1;
                cout<<"pleas input the toid that you want to visit"<<endl;
                cin>>i_todi_menu;
                visit_num=todo.visit(i_todi_menu);
                (void)visit_num;
                break;
            }
            case 4:
            {
                cout<<"exiting...success"<<endl;
                state_to=0;
                break;
            }
            default:
            {
                cout<<"error run"<<endl;
                state_to=0;
                break;
            }
        }
    }
    return;
}
void Collect_menu()
{
    Collect collect;
    int state_co=1;
    int num_co;
    while(state_co)
    {
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"\t\t\t\t     1.use                           *"<<endl;
        cout<<"\t\t\t\t     2.exit                          *"<<endl;
        cout<<"\t\t\t\t**************************************"<<endl;
        cout<<"please input num to run"<<endl;
        cin>>num_co;
        switch(num_co)
        {
            case 1:
            {
                collect.use();
                break;
            }
            case 2:
            {
                cout<<"exiting...success"<<endl;
                state_co=0;
                break;
            }
            default:
            {
                cout<<"error run"<<endl;
                state_co=0;
                break;
            }
        }
    }
    return;
}
void gongzuotai()
{
    FactoryProduce_menu();
}







#endif