#include "cmd.h"
extern set<MyFile> TimDiskFile;
extern set<MyFile> LocalFile;
extern set<MyFile> WeiyunDiskFile;

void TimDiskReceiver::upload(string filename,string fileroad,string des){
    if(IsExistLocalDisk(filename,fileroad)){
        TimDiskFile.insert(MyFile(filename,des));
        cout<<filename<<" upload success"<<endl;
    }
    else{
        cout<<filename<<" is not exist in local "<<fileroad<<endl;
    }
}

void TimDiskReceiver::download(string filename,string fileroad,string des){
    if(IsExistTimDisk(filename,fileroad)){
        LocalFile.insert(MyFile(filename,des));
        cout<<filename<<" download success"<<endl;
    }
    else{
        cout<<filename<<" is not exist in TimDisk "<<fileroad<<endl;
    }
}

void WeiyunDiskReceiver::upload(string filename,string fileroad,string des){
    if(IsExistLocalDisk(filename,fileroad)){
        WeiyunDiskFile.insert(MyFile(filename,des));
        cout<<filename<<" upload success"<<endl;
    }
    else{
        cout<<filename<<" is not exist in local "<<fileroad<<endl;
    }
}

void WeiyunDiskReceiver::download(string filename,string fileroad,string des){
    if(IsExistWeiyunDisk(filename,fileroad)){
        LocalFile.insert(MyFile(filename,des));
        cout<<filename<<" download success"<<endl;
    }
    else{
        cout<<filename<<" is not exist in WeiyunDisk "<<fileroad<<endl;
    }
}