//
// Created by magicgh on 5/31/2020.
//

#include "game.h"
const char *TITLE = "Jumping Elephant";

int begin_button()
{
    while (1) {
        mouse_msg mouseMsg = getmouse();
        if (mouseMsg.is_left() && mouseMsg.is_down()) {
            int x = mouseMsg.x;
            int y = mouseMsg.y;
            if (y >= 83 && y <= 168) {
                if(x >= 85 && x <= 176) return 0;
                else if(x >= 279 && x <= 337) return 1;
                else if(x >= 465 && x <= 515) return 2;
            }
        }
    }
}

bool restart_button()
{
    while (1) {
        mouse_msg mouseMsg = getmouse();
        if (mouseMsg.is_left() && mouseMsg.is_down()) {
            int x = mouseMsg.x;
            int y = mouseMsg.y;
            if (x >= 271 && x <= 330 && y >= 150 && y <= 204)
                return 1;
        }
    }
}

int Game::init(){
    initgraph(WIDTH,HEIGHT,0x0);
    setcaption(TITLE);
    setbkcolor(WHITE);
    setbkmode(TRANSPARENT);
    delay_ms(0);

    PIMAGE img=newimage();
    getimage(img,"static\\start.png");
    putimage_withalpha(NULL,img,0,0);

    return begin_button();
}

bool collided(Cactus &cac, Elephant &ele){
    return !cac.empty() && (cac.frontRect()&ele.getRect());
}

void Game::main() {

    int type = init();
    if(type == 2)setbkcolor(BLACK);
    Elephant ele(type);
    Cactus cac(type, 6);
    ScoreBoard sb(type);

    StartScene start_scene(type);
    GameScene game_scene(type);
    EndScene end_scene(type);
    Scene *current_scene=&start_scene;
    for(;is_run() ; delay_fps(FPS)) {
        cleardevice();
        current_scene->draw(ele, cac, sb);

        cac.setDiff(sb.getScore()/50+10);

        if(current_scene == &start_scene &&(keystate(key_space)))
            current_scene = &game_scene;
        if(collided(cac,ele)){
            PlaySound(TEXT("static\\die.wav"),NULL,SND_FILENAME | SND_ASYNC);
            current_scene = &end_scene;
            current_scene->draw(ele, cac, sb);
        }

        if (current_scene == &end_scene) {

            sb.save();
            flushmouse();
            //if(end_button()) break;
            if(restart_button()) {
                end_scene.restart(ele, cac, sb);
                current_scene = &start_scene;
            }
            else break;
        }

    }
    closegraph();
}
