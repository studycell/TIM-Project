//
//Created by hansl on 2021/12/23 8:41
//
#include <iostream>
#include <map>
#include <iterator>
#include <cstring>
#include "connection.h"
#include "kongjian.h"
#include "gongzuotai.h"
#include "Files.h"
using namespace std;

void menu_1();
int main() {

    int i;
    menu_1();

    while(1) {
        void menu_1();
        printf("\t\t\t请选择1登录（选择0退出）:\n");
        scanf("%d", &i);
        switch (i) {
            case 1:
                connection_main();
                break;
//            case 2:
//                //3space_main(name);
//                break;
//            case 3:
//                Workbench();
//                break;
//            case 4:
//                gongzuotai();
//                break;
//            case 5:
//                Relate_main();
//                break;
//            case 6:
//                system("cls");
//                menu();
//                break;
            case 0:
                return 0;
            default:
                printf("输入功能号有误！请重新输入：");

        }
    }

    system("pause");
}
void menu_1(){
    printf("\n\t\t****************************************\n");
    printf("\t\t\t      欢 迎 使 用 TIM 软 件\n");
    printf("\t\t\t\t 1.登录账户 \n");
//    printf("\t\t\t\t 2.TIM空间\n");
//    printf("\t\t\t\t 3.文件管理\n");
//    printf("\t\t\t\t 4.工作台\n");
//    printf("\t\t\t\t 5.关系系统\n");
//    printf("\t\t\t\t 6.返回主菜单\n");
    printf("\t\t\t\t 0.退出 \n");
    printf("\t\t****************************************\n");
}