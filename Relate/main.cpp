//
//  main.cpp
//  软件工程
//
//  Created by takeahint on 2021/12/25.
//
#include "relate.h"

int main() {
    menu();
    int n;
    string num;
    bool running=1;
    while(running){
        cout<<"Please choose:";
        cin>>n;
        if(!(n>=1&&n<=8)){
            cout<<"Invalid number"<<endl;
            continue;
        }
        switch(n){
            case 1:{
                cout<<"Please input your friend's number:";
                cin>>num;
                if(num.length()>11||num.size()<8){
                    cout<<"Invalid number"<<endl;
                    break;
                }
                a.addfriends();
                break;
            }
            case 2:{
                cout<<"Please input your friend's number:";
                cin>>num;
                if(num.length()>11||num.size()<8){
                    cout<<"Invalid number"<<endl;
                    break;
                }
                a.deletefriends();
                break;
            }
            case 3:{
                cout<<"Please input your friend's number:";
                cin>>num;
                if(num.length()>11||num.size()<8){
                    cout<<"Invalid number"<<endl;
                    break;
                }
                
                a.defriend();
                break;
            }
            case 4:{
                cout<<"Please input the group's name:";
                cin>>num;
                a.creategroups();
                break;
            }
            case 5:{
                cout<<"Please input the group's number:";
                cin>>num;
                if(num.length()>11||num.size()<8){
                    cout<<"Invalid number"<<endl;
                    break;
                }
                a.joingroups();
                break;
            }
            case 6:{
                cout<<"Please input the group's number:";
                cin>>num;
                if(num.length()>11||num.size()<8){
                    cout<<"Invalid number"<<endl;
                    break;
                }
                a.dissolvegroups();
                break;
            }
            case 7:{
                cout<<"Please input your friend's number:";
                cin>>num;
                if(num.length()>11||num.size()<8){
                    cout<<"Invalid number"<<endl;
                    break;
                }
                a.exitgroups();
                break;
            }
            case 8:{
                running=0;
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
