#include"Factory.h"
int label_cai=-1;
int label_sci=-1;
int label_toi=-1;
void Calendar::create()
{
    int i_caid=-1;
    string i_holiday;
    string i_content;
    cout<<"please input caid holiday content"<<endl;
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
            cout<<"the caid has existed. please change other num."<<endl;
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
void Calendar::modify(int i_caid)
{
    int cai_mdf;
    int visit_i;
    string holiday_mdf,content_mdf;
    cout<<"please input the caid that you want to modify"<<endl;
    cin>>i_caid;
    visit_i=Calendar::visit(i_caid);
    if(visit_i<0)
    {
        cout<<"you cant change no exist calendarname."<<endl;
        return;
    }
    cout<<"please input: (if you wont change,please input the same)"<<endl;
    cin>>cai_mdf>>holiday_mdf>>content_mdf;
    calendarname[visit_i].caid=cai_mdf;
    calendarname[visit_i].holiday=holiday_mdf;
    calendarname[visit_i].content=content_mdf;
    cout<<"[modify]the calendarname has changed"<<endl;
    Calendar::visit(cai_mdf);
    return;
}

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