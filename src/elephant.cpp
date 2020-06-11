 //
// Created by magicgh on 5/25/2020.
//

#include "elephant.h"
Timer run_timer;
FreeFall jump_v(-(2*JUMP_HEIGHT)/(JUMP_TIME*JUMP_TIME),(2*JUMP_HEIGHT)/JUMP_TIME);//FreeFall类的构造c需要参数加速度和速度
Elephant::Elephant(int type) {
    const char *img_file_path[3][4]={//以指针数组的形式存入三个人物分别四种状态
            {
                    "static\\elephant.png", //0
                    "static\\elephant_dead.png", //1
                    "static\\elephant_left.png", //2
                    "static\\elephant_right.png", //3
            },
            {
                    "static\\turtle_jump.png", //0
                    "static\\turtle_dead.png", //1
                    "static\\turtle_left.png", //2
                    "static\\turtle_right.png", //3
            },
            {
                    "static\\batman_jump.png", //0
                    "static\\batman_dead.png", //1
                    "static\\batman_left.png", //2
                    "static\\batman_right.png", //3
            }
    };

    jump_music.OpenFile("static\\jump.wav");

    for(int i=0; i<4; i++){
        img_file.push_back(newimage());//ima_file为vector容器，数据类型是<PIMAGE>
        getimage(img_file[i], img_file_path[type][i]);//参数：文件名和文件路径
        img_size.push_back((Point){getwidth(img_file[i]),getheight(img_file[i])});//传入图片的长和宽为Vec类
    }
    ele_rect.set((Point){LEFT_BOUNDARY,ELEPHANT_DOWN-img_size[0].y},img_size[NORMAL]);///参数：Point点坐标和Vec矢量
}

void Elephant::draw() {
    if(!jumping&&(keystate(key_space)||keystate(key_mouse_l))){//判断条件
        jumping=1,jump_v.reset();//reset（）继承于Timer
        PlaySound(TEXT("static\\jump.wav"),NULL,SND_FILENAME | SND_ASYNC);//跳跃音效
    }
    if(jumping) jump(0);
    else run();
}

void Elephant::drawStand() {
    putimage_withalpha(NULL, img_file[NORMAL],LEFT_BOUNDARY,ELEPHANT_DOWN-img_size[0].y);
}

void Elephant::drawDead() {
    if(jumping) jump(1);
    else putimage_withalpha(NULL, img_file[DEAD],LEFT_BOUNDARY,ELEPHANT_DOWN-img_size[0].y);
}

void Elephant::jump(bool type) {
    if(jump_v.getTime()>=JUMP_TIME*2)jumping=0,run();//如果起跳后的计时大于设定好的时间
    else{
        int dest_y=ELEPHANT_DOWN-img_size[0].y-jump_v.getSpeed();
        putimage_withalpha(NULL, img_file[type],LEFT_BOUNDARY,dest_y);
        ele_rect.set((Point){LEFT_BOUNDARY,dest_y},img_size[type]);
    }

}

void Elephant::run() {//为了体现换腿过程
    if(run_timer.getTime()>=6*SEC){
        side ^= 1;//异或
        run_timer.reset();
    }
    putimage_withalpha(NULL, img_file[LEFT+side],LEFT_BOUNDARY,ELEPHANT_DOWN-img_size[0].y);
    ele_rect.setLen(img_size[LEFT+side]);
}

void Elephant::reset() {
    run_timer.reset();
    jump_v.reset();
    ele_rect.set((Point){LEFT_BOUNDARY,ELEPHANT_DOWN-img_size[0].y},img_size[NORMAL]);
}

Rect Elephant::getRect() {
    return ele_rect;
}

