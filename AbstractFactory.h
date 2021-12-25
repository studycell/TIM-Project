#ifndef AF_h_
#define AF_H_
#include"Factory.h"
class AbstractFactory
{
    public:
    Calendar getCalendar();
    Schedule getSchedule();
    Todo getTodo();
    Collect getCollect();
};
class FactoryProducer
{
    public:
    AbstractFactory getFactory();
};
#endif
