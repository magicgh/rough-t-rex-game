//
// Created by magicgh on 5/25/2020.
//

#include "obstacle.h"
LogSpeed cac_v(3,1,2);

Cactus::Cactus(const int type, const double diff) {
    const char *img_file_path[3][3]={
            {
                    "static\\cactus_1.png", //0
                    "static\\cactus_2.png", //1
                    "static\\cactus_3.png", //2
            },
            {
                    "static\\cactus_1.png", //0
                    "static\\cactus_2.png", //1
                    "static\\cactus_3.png", //2
            },
            {
                    "static\\city_1.png", //0
                    "static\\city_2.png", //1
                    "static\\city_3.png", //2
            }
    }; //构造函数获取障碍物图片

    this->diff = diff; //难度系数的设定
    for(int i=0; i<3; i++){
        img_file.push_back(newimage());
        getimage(img_file[i], img_file_path[type][i]); //导入角色图片
        img_size.push_back((Point){getwidth(img_file[i]),getheight(img_file[i])}); //导入角色图片大小
    }
}

void Cactus::generate(){
    int obs_type = getObsType(img_file.size(), diff); //获取随机生成的障碍物
    if (obs_type == -1) return; //没有障碍物则直接返回

    cac_list.push_back(Rect(Point(WIDTH,HEIGHT-img_size[obs_type].y-25),img_size[obs_type])); //导入障碍物的大小
    cac_type.push_back(obs_type); //导入障碍物类型
}
void Cactus::draw() {

    generate(); //生成障碍物


    for(int i=0;i<cac_list.size();i++){
        putimage_withalpha(NULL, img_file[cac_type[i]], cac_list[i].getLeft(), cac_list[i].getUp());
    } //插入图片到界面

    move(); //移动
}

void Cactus::move() {

    while(!cac_list.empty()&&cac_list.front().getLeft()<-img_size[cac_type.front()].x){
        cac_list.pop_front();
        cac_type.pop_front(); //更新障碍物位置
        PlaySound(TEXT("static\\check_point.wav"),NULL,SND_FILENAME | SND_ASYNC);
    } //判断游戏是否结束

    for(auto &cac:cac_list){
        cac.move((Vec){-cac_v.getSpeed(),0});
    } //移动障碍物

}

bool Cactus::empty(){
    return cac_list.empty();
} //设置难度系数


void Cactus::setDiff(const double &diff) {
    this->diff = diff;
}

double Cactus::getDiff() {
    return this->diff;
} //获取难度系数


Rect Cactus::frontRect() {
    return cac_list.front();
} //获取障碍物前方位置

void Cactus::reset(){
    cac_v.reset();
    while(!cac_list.empty()) {
        cac_list.pop_back();
        cac_type.pop_back();
    }
}

