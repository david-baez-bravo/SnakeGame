#pragma once

#include "State.h"
#include "Snake.h"
#include "ofMain.h"
#include "entities.h"

enum Powerup{
    NA, // Not available
    SPEEDUP, 
    BETTERAPPLE,
    GODMODE
};

class GameState : public State {
    private:
        Powerup currentPower; 
        int framenumdivisor = 10; 
        int power_ticks = 0; 
        float red_decay = 255; // needs to be 150 for brown
        float green_decay = 0; // needs to be 75 for brown
        int decay_ticks = 0; // timer for decay
        vector<StaticEntity*> walls;

    public:
        GameState();
        ~GameState();
        void reset();
        void update();
        void draw();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void usePower(); 
        void resetPower();
        void setPower();
        void foodSpawner();
        void drawPowerIndicator();
        void drawFood();
        void drawPower();
        void obstacleSpawner();
        void drawObstacles();
        void drawStartScreen();
        void drawLostScreen();
        void drawBoardGrid();
        void drawScore();
        void changeSong(string filename);
        void gps();
        bool checkCollision_gpsHelper(int x, int y);
        // void drawPath_gpsHelper(int x, int y, int foodX, int foodY, int x_dir, int y_dir, bool& reachedFood);
        // void drawLineX_gpsHelperdrawLineX_gpsHelper(vector<int> head, int x, int cellSize, int currentFoodX);
        // void drawLineY_gpsHelper(vector<int> head, int y, int cellSize, int currentFoodY);

        ofSoundPlayer sound;
        vector<string>songs = {"Press_Fuse.mp3","cyberpunk_synthwave.mp3","80s_montage.mp3","welcome_to_the_grid.mp3"};
        float progress = 0;
        int song_index=0;

        vector<ofColor>colors = {
            ofColor::green, ofColor::cyan, ofColor::magenta, ofColor::beige, ofColor::brown, 
            ofColor::navy, ofColor::darkGreen, ofColor::hotPink, ofColor::gold, 
            ofColor::orange, ofColor::royalBlue, ofColor::seaGreen, ofColor::turquoise, ofColor::violet, ofColor::yellowGreen
        };
        //StaticEntity* wall;

        Snake* snake;

        bool foodSpawned = false;
        bool wallSpawned = false;
        bool isPower = false;
        bool startTimer = false;
        bool gps_on = false;
        // bool reachedFood = false;

        int score = 0;
        int currentFoodX;
        int currentFoodY;
        int currentObstacleX;
        int currentObstacleY;

        int boardSizeWidth, boardSizeHeight;
        int cellSize; // Pixels
};