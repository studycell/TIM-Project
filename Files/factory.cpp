#include "factory.h"

extern set<MyFile> TimDiskFile;
extern set<MyFile> LocalFile;
extern set<MyFile> WeiyunDiskFile;

void Timfile::create_obj(string name,string road){
    
    filename=name;
    fileroad=road;
}

 

 
void WeiYunfile::create_obj(string name,string road){
    filename=name;
    fileroad=road;
}

void Localfile::create_obj(string name,string road){
    filename=name;
    fileroad=road;
}

File * Factory::getobj(int type){
    if(type==TIM_DISK_TYPE){
        return new Timfile();
    }
    else if(type==LOCAL_TYPE){
        return new Localfile();
    }
    else if(type==WEIYUN_DISK_TYPE){
        return new WeiYunfile();
    }
    return NULL;
}