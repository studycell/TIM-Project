#include "file.h"

set<MyFile> TimDiskFile;
set<MyFile> LocalFile;
set<MyFile> WeiyunDiskFile;

void initfile(){
    TimDiskFile.insert(MyFile("book","/usr/src"));
    TimDiskFile.insert(MyFile("newspaper","/root"));
    TimDiskFile.insert(MyFile("article","/etc"));

    LocalFile.insert(MyFile("the world","D:/file"));
    LocalFile.insert(MyFile("jojo","D:/file"));

    WeiyunDiskFile.insert(MyFile("book","/home"));
    WeiyunDiskFile.insert(MyFile("paper","/home"));
}

bool IsExistTimDisk(string filename,string fileroad){
    set<MyFile>::iterator it;
    for(it=TimDiskFile.begin();it!=TimDiskFile.end();it++){
        if(it->filename==filename&&it->fileroad==fileroad)
            return 1;
    }
    return 0;
}

bool IsExistWeiyunDisk(string filename,string fileroad){
    set<MyFile>::iterator it;
    for(it=WeiyunDiskFile.begin();it!=WeiyunDiskFile.end();it++){
        if(it->filename==filename&&it->fileroad==fileroad)
            return 1;
    }
    return 0;
}

bool IsExistLocalDisk(string filename,string fileroad){
    set<MyFile>::iterator it;
    for(it=LocalFile.begin();it!=LocalFile.end();it++){
        if(it->filename==filename&&it->fileroad==fileroad)
            return 1;
    }
    return 0;  
}



