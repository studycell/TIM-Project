#include"AbstractFactory.h"
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
            cout<<"exiting ... success";
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
int main()
{
    FactoryProduce_menu();
    return 1;
}