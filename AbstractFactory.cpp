#include"AbstractFactory.h"

AbstractFactory FactoryProducer::getFactory()
{
    AbstractFactory Factory;
    cout<<"AbstractFactory start to work"<<endl;
    return Factory;
}

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