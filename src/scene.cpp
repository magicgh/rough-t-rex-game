//
// Created by magicgh on 5/25/2020.
//


#include "scene.h"
LogSpeed ground_v(3,1,2);
LogSpeed cloud_v(1,1,1);

void Ground::setType(const int type) {
    const char *img_file_path[3] = {
            "static\\ground_1.png",//0
            "static\\ground_1.png",//1
            "static\\ground_3.png",//2
    };
    getimage(img, img_file_path[type]);

    length = getwidth(img);
    square = (Vec){getwidth(img), getheight(img)};
    pos = Rect((Point){0,GROUND_DOWN},square);
}

void Ground::draw(){
    putimage_withalpha(NULL,img,pos.getLeft(),pos.getUp());
}

void Ground::drawLoop() {
    putimage_withalpha(NULL,img,pos.getLeft(),pos.getUp());
    putimage_withalpha(NULL,img,pos.getLeft()+length,pos.getUp());

    pos.move((Vec){-ground_v.getSpeed(),0});

    if(pos.getLeft()<=-length) pos = Rect((Point){pos.getLeft()+length,GROUND_DOWN},square);
}

void Ground::reset() {
    ground_v.reset();
}

void Cloud::setType(const int type) {
    const char *img_file_path[3] = {
            "static\\cloud_1.png",//0
            "static\\cloud_1.png",//1
            "static\\cloud_3.png",//2
    };
    getimage(img, img_file_path[type]);

    length = getwidth(img);
    square = (Vec){getwidth(img), getheight(img)};
    pos = Rect((Point){0,CLOUD_DOWN},square);
}

void Cloud::drawLoop() {
    putimage_withalpha(NULL,img,pos.getLeft(),pos.getUp());
    putimage_withalpha(NULL,img,pos.getLeft()+length,pos.getUp());

    pos.move((Vec){-cloud_v.getSpeed(),0});

    if(pos.getLeft()<=-length) pos = Rect((Point){pos.getLeft()+length,CLOUD_DOWN},square);
}

void Cloud::draw() {
    putimage_withalpha(NULL,img,pos.getLeft(),pos.getUp());
}

void Cloud::reset() {
    cloud_v.reset();
}

GameOver::GameOver(){
    const char *img_file_path = "static\\game_over.png";
    getimage(img, img_file_path);
}

void GameOver::draw() {
    putimage_withalpha(NULL,img,0,0);
}

StartScene::StartScene(const int type) {
    cloud.setType(type),ground.setType(type);
}

GameScene::GameScene(const int type) {
    cloud.setType(type),ground.setType(type);
}

EndScene::EndScene(const int type) {
    cloud.setType(type),ground.setType(type);
}

void StartScene::draw(Elephant &ele, Cactus &cac, ScoreBoard &sb) {
    cloud.draw(), ground.draw(), ele.drawStand();
    setfont(20, 0, "Press Start 2P");
    outtextxy(WIDTH/2 - 140, HEIGHT/2, "PRESS SPACE TO START");
}

void GameScene::draw(Elephant &ele, Cactus &cac, ScoreBoard &sb) {
    cloud.drawLoop(),ground.drawLoop(),ele.draw(),cac.draw(),sb.draw();
}

void EndScene::draw(Elephant &ele, Cactus &cac, ScoreBoard &sb) {
    game_over.draw(),ele.drawDead();
}

void EndScene::restart(Elephant &ele, Cactus &cac, ScoreBoard &sb) {
    cloud.reset(),ground.reset(),ele.reset(),cac.reset(),sb.reset();
}

