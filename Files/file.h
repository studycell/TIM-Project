/*该头文件包含关于TIM网盘，微云网盘，本地文件相关信息*/
/*所有文件都是虚构*/

#ifndef FILE_H_
#define FILE_H_

#include<iostream>
#include<string>
#include<set>
#include<windows.h>
#include<iterator>

using namespace std;

//文件所在位置
enum{
    TIM_DISK_TYPE=0,
    WEIYUN_DISK_TYPE,  
    LOCAL_TYPE
};

//第一项为文件名，第二项为文件路径
struct MyFile{
    string filename;
    string fileroad;
    MyFile(string a,string b):filename(a),fileroad(b){}
    friend bool operator <(const MyFile& b,const MyFile& a){
        return a.filename<b.filename;
    }
};

void initfile();
bool IsExistTimDisk(string filename,string fileroad);
bool IsExistWeiyunDisk(string filename,string fileroad);
bool IsExistLocalDisk(string filename,string fileroad);


#endif