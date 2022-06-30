#include<iostream>

using namespace std;
#include "iGraphics.h"

#define scrWidth 1366
#define scrHeight 768
#define enemyNumber 10
#define enemy2Number 10
#define heartNumber 10
#define fireNumber 150
#define fireSpeed 70
#define jumpLimit 310
#define enemyHeight 130
#define enemyWidth 80
#define heartHeight 100
#define enemy2Height 100
#define enemy2Width 70
#define heartWidth 50
#define rightMove 20
#define leftMove 20
#define livesCount 10
#define heartSpeed 20
#define heartRecycleWidth 2500
#define heartHeight 350
#define enemy2HeightfromOrigin 420
#define enemy2speed 20
#define enemy1HeightfromOrigin 120
#define enemy1speed 25
#define jumpSpeed 40
#define musicIconX (scrWidth-100)
#define musicIconY 20
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: VARIABLES ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

char button [6][25] = {"menu\\playnow.bmp","menu\\controls.bmp","menu\\highscore.bmp","menu\\credits.bmp","menu\\exit.bmp","menu\\menu.bmp"};
char buttonHover[6][25] = {"menu\\pnhover.bmp","menu\\controlsHover.bmp","menu\\hsHover.bmp","menu\\creditsHover.bmp","menu\\exitHover.bmp","menu\\menuHover.bmp"};
char home_menuPage[25] = {"menu\\menup.bmp"};
char high_scorePage[25] = {"menu\\hsp.bmp"};
char creditsPage [25] = {"menu\\cp.bmp"};
char controlsPage[25] = {"menu\\ControlsPage.bmp"};
char musicButton[2][40] = {"game_elements\\musicOn_icon.bmp", "game_elements\\musicOff_icon.bmp"};

char story[12][40] = {"story\\1.bmp","story\\2.bmp","story\\3.bmp","story\\4.bmp","story\\5.bmp","story\\6.bmp","story\\7.bmp","story\\8.bmp","story\\9.bmp","story\\10.bmp","story\\11.bmp","story\\12.bmp"};
int storyPage = 0;
bool storyMode = true;

int OptionState = 0;
int gameState = 0;
int mposx, mposy; // This variables are used to hold the mouse pointer location in iPassiveMouse function



bool musicOn = true;
bool musicIntro = true;
bool musicStory = false;
bool musicLvl1 = false;
bool musicGameOver = false;
bool started = true;


int streetIndex = 0;
char background[1][20] = {"bg_img\\planets1.bmp"};
char street[57][100] = {"bg_img\\stb0.bmp","bg_img\\stb1.bmp","bg_img\\stb2.bmp","bg_img\\stb3.bmp","bg_img\\stb4.bmp","bg_img\\stb5.bmp","bg_img\\stb6.bmp","bg_img\\stb7.bmp","bg_img\\stb8.bmp","bg_img\\stb9.bmp",
						"bg_img\\stb10.bmp","bg_img\\stb11.bmp","bg_img\\stb12.bmp","bg_img\\stb13.bmp","bg_img\\stb14.bmp","bg_img\\stb15.bmp","bg_img\\stb16.bmp","bg_img\\stb17.bmp","bg_img\\stb18.bmp","bg_img\\stb19.bmp",
						"bg_img\\stb20.bmp","bg_img\\stb21.bmp","bg_img\\stb22.bmp","bg_img\\stb23.bmp","bg_img\\stb24.bmp","bg_img\\stb25.bmp","bg_img\\stb26.bmp","bg_img\\stb27.bmp","bg_img\\stb28.bmp","bg_img\\stb29.bmp",
						"bg_img\\stb30.bmp","bg_img\\stb31.bmp","bg_img\\stb32.bmp","bg_img\\stb33.bmp","bg_img\\stb34.bmp","bg_img\\stb35.bmp","bg_img\\stb36.bmp","bg_img\\stb37.bmp","bg_img\\stb38.bmp","bg_img\\stb39.bmp",
						"bg_img\\stb40.bmp","bg_img\\stb41.bmp","bg_img\\stb42.bmp","bg_img\\stb43.bmp","bg_img\\stb44.bmp","bg_img\\stb45.bmp","bg_img\\stb46.bmp","bg_img\\stb47.bmp","bg_img\\stb48.bmp","bg_img\\stb49.bmp",
						"bg_img\\stb50.bmp","bg_img\\stb51.bmp","bg_img\\stb52.bmp","bg_img\\stb53.bmp","bg_img\\stb54.bmp","bg_img\\stb55.bmp","bg_img\\stb56.bmp"};



bool pause = false;
int edwardX = 0, edwardY = 100;
int edwardIndex = 0;
char edwardStand[3][20] = {"char\\edward1.bmp","char\\edward2.bmp","char\\edward3.bmp"};
char edwardRun[6][40] = {"char\\edward4.bmp","char\\edward5.bmp","char\\edward6.bmp","char\\edward7.bmp","char\\edward8.bmp","char\\edward9.bmp"};
char edwardJump[1][20] = {"char\\edward10.bmp"};
char HitByEnemy[12][60] = {"char\\blank.bmp","char\\blank.bmp","char\\edward4.bmp","char\\edward5.bmp","char\\blank.bmp","char\\edward6.bmp","char\\blank.bmp","char\\edward7.bmp","char\\blank.bmp","char\\edward8.bmp","char\\blank.bmp","char\\edward9.bmp"};
char HitByEnenmyJump[12][60] = {"char\\blank.bmp","char\\blank.bmp","char\\edward10.bmp","char\\edward10.bmp","char\\blank.bmp","char\\edward10.bmp","char\\blank.bmp","char\\edward10.bmp","char\\blank.bmp","char\\edward10.bmp","char\\blank.bmp","char\\edward10.bmp"};
char fire[10][50] = {"char\\fire1.bmp","char\\fire2.bmp","char\\fire3.bmp","char\\fire4.bmp","char\\fire5.bmp","char\\fire6.bmp","char\\fire7.bmp","char\\fire8.bmp","char\\fire9.bmp","char\\fire10.bmp"};
//char edwardFire[1][20]={"char\\shooting.bmp"};
//char edwardPower[];


bool GotHit = false;
bool jump = false;
bool jumpHigh = false;
int edwardJumpY = 0;
int FireCount = 0;
int FireRemain = fireNumber;
int score = 0;


char pride[6][40] = {"enemy\\pride1.bmp","enemy\\pride2.bmp","enemy\\pride3.bmp","enemy\\pride4.bmp","enemy\\pride5.bmp","enemy\\pride6.bmp"};
char prideStrike[6][40] = {"enemy\\prideStrike1.bmp","enemy\\prideStrike1.bmp","enemy\\prideStrike1.bmp","enemy\\prideStrike1.bmp","enemy\\prideStrike1.bmp","enemy\\prideStrike1.bmp"};


char alien[6][40] = {"enemy\\alien.bmp","enemy\\alien.bmp","enemy\\alien.bmp","enemy\\alien.bmp","enemy\\alien.bmp","enemy\\alien.bmp"};
char alienStrike[6][40] = {"enemy\\alienBlast1.bmp","enemy\\alienBlast1.bmp","enemy\\alienBlast2.bmp","enemy\\alienBlast2.bmp","enemy\\alienBlast3.bmp","enemy\\alienBlast3.bmp"};


int lives = livesCount;
bool HealthDecrease = false;

char lifeBar[10][30]={"game_elements\\lifeBar1.bmp", "game_elements\\lifeBar1.bmp", "game_elements\\lifeBar2.bmp", "game_elements\\lifeBar2.bmp", "game_elements\\lifeBar3.bmp", "game_elements\\lifeBar4.bmp", "game_elements\\lifeBar5.bmp", "game_elements\\lifeBar5.bmp", "game_elements\\lifeBar6.bmp", "game_elements\\lifeBar7.bmp"};
char life[6][40] = {"game_elements\\life.bmp","game_elements\\life.bmp","game_elements\\life.bmp","game_elements\\life.bmp","game_elements\\life.bmp","game_elements\\life.bmp"};
char lifeStrike[6][40] = {"game_elements\\life.bmp","game_elements\\life.bmp","game_elements\\life.bmp","game_elements\\life.bmp","game_elements\\life.bmp","game_elements\\life.bmp"};


int scoreShowX = 1100;
int scoreShowY = 700;
int highScoreShowX = 450;
int highScoreShowY = 480;
char insertName[50];
char strScore[10];
char fireStr[10];
char st[100][100]; // Player names are stored here
char strScoreCount[10];
int numberArray[100]; // Scores are Stored here
int arrayIndex = 0;
int numIndex = 0;
int stringIndex = 0;
bool showInsertNameBox = true;
char enterNameBox[1][25] = {"menu\\enterNameBox.bmp"};
int nameBoxX = 490, nameBoxY = 220;


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MENU ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

// button Co-ordinates declaration
struct buttonCordinate
{
	int x;
	int y;
}bCordinate[6];

struct bMusicCord {
	int x;
	int y;
}bmc[1];


void menuHover(){
	for(int i = 0; i< 6; i++){

			if (OptionState == 0){
				
				if(mposx >= bCordinate[i].x && mposx <= bCordinate[i].x + 200 && mposy >= bCordinate[i].y && mposy <= bCordinate[i].y + 80){
					
					if(i!=5 && gameState == 0){
						iShowBMP2(bCordinate[i].x,  bCordinate[i].y, buttonHover[i], 0);
					}
					else if(i==5 && (gameState == 2 || gameState == 3 || gameState == 4 )){ // MENU Hover
						iShowBMP2(bCordinate[i].x,  bCordinate[i].y, buttonHover[i], 0);
					}
				}

			}
			else if(OptionState == 2 && gameState == 7){ // GameOver Page

				if(i == 4){
					if(mposx >= bCordinate[i].x + 200 && mposx <= bCordinate[i].x + 400 && mposy >= bCordinate[i+1].y && mposy <= bCordinate[i+1].y + 80 ){
						iShowBMP2(bCordinate[4].x + 200,  bCordinate[5].y, buttonHover[4], 0); // Exit hover
					}
				}
				if(i == 5){
					if(mposx >= bCordinate[i].x - 100 && mposx <= bCordinate[i].x + 100 && mposy >= bCordinate[i].y && mposy <= bCordinate[i].y + 80 ){
						iShowBMP2(bCordinate[5].x - 100,  bCordinate[5].y, buttonHover[5], 0); // Menu Hover
				}
			}
		}
	}
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: BACKGROUND ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

// Lower Bg Move inc. Street
void BackGroundMmove(){
	if(gameState == 69 && !pause){
		streetIndex++;
		if(streetIndex >= 57){
			streetIndex = 0;
		}
	}
}

// Music Player
void changeMusicCheck(){ 
	if(musicOn){
		if(gameState == 0 && musicIntro && started){
			PlaySound("music\\FMAB_Hologram_8-bit_WAV.wav", NULL, SND_LOOP | SND_ASYNC);
			started = false;
		}else if(gameState == 1 && musicStory && started){
			PlaySound("music\\FMARB_OST 2_Battle_Scherzo.wav", NULL, SND_LOOP | SND_ASYNC);
			started = false;
		}else if(gameState == 69 && musicLvl1 && started){
			PlaySound("music\\FMAR_OST_Next_Chapter.wav", NULL, SND_LOOP | SND_ASYNC);
			started = false;
		}else if(gameState == 7 && musicGameOver && started){
			PlaySound("music\\FMAB_Rain_8-bit_WAV.wav", NULL, SND_LOOP | SND_ASYNC);
			started = false;
		}
	}
}

void changeMusic(){
	if(musicOn)
		{
			musicOn = false;
			PlaySound(0,0,0); // Sound Trigger
		}
		else {
			musicOn = true;
			started = true;

			musicIntro = false;
			musicStory = false;
			musicLvl1 = false;
			musicGameOver = false;
			
			if(gameState == 0){
				musicIntro = true;
			}else if(gameState == 1){
				musicStory = true;
			}else if(gameState == 69){
				musicLvl1 = true;
			}else if(gameState == 7){
				musicGameOver = true;
			}
			
			if(started){
				changeMusicCheck();
			}
		}
}


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: PLAYER ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
struct Fire
{
	int fireX, fireY;
	int fireIndex;
	bool fireShot;
}fire1[fireNumber];


void PlayerState(){
	
	//Jumping Higher in Space
	if(!pause) {
		if (jumpHigh){
			edwardJumpY += jumpSpeed;
			if (edwardJumpY >= jumpLimit ) {
				jumpHigh = false;
			}
		}
		//Coming down to ground level
		else if (edwardJumpY > 0){
			edwardJumpY -= jumpSpeed;
			if (edwardJumpY <=0)
				jump = false;
		}
	// Edward is running again
		else if(!GotHit){ 
			edwardIndex++;
			if(edwardIndex == 5){
				edwardIndex=0;
			}
		}
	// Edward gets hit by enemy
		else {
			edwardIndex++;
			if(edwardIndex == 11){
				GotHit = false;
				edwardIndex = 0;
			}
		}
	}
}

// FirePower remaining
void CountFire(){ 
	if (FireCount < fireNumber){
		FireCount++;
		FireRemain--;
		if(FireRemain == 0){
			OptionState = 2;
			gameState = 7;
			 
			// Change Music
			musicLvl1 = false;
			musicGameOver = true;
			started = true;
			if(started){
				changeMusicCheck();
			}
		}
	}
}

// Edward is Sooting
void SetFire(){ 
	CountFire();

	fire1[FireCount-1].fireShot = true;
	fire1[FireCount-1].fireX = edwardX + 20;
	fire1[FireCount-1].fireY = edwardY + edwardJumpY + 20;
}

// Fire Movement
void FireShot()
{	
	if(!pause){
		for(int i = 0; i < FireCount; i++)
		{
			if(fire1[i].fireShot){
				fire1[i].fireX += fireSpeed;
			}
		}
	}
}

// Show FIRE is called from iDraw()
void ShowFire(){
	for (int i = 0; i< FireCount; i++){
		if(fire1[i].fireShot){
			iShowBMP2(fire1[i].fireX, fire1[i].fireY, fire[0], 0);
		}
	}
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ENEMY1 ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
struct Enemies
{
	int prideX, prideY;
	int prideIndex;
	bool prideShow;
	bool HitEdward;
}enemy[enemyNumber];



// Enemy Set Function
void setEnemies()
{
	for(int i=0; i<enemyNumber; i++)
	{
		enemy[i].prideX = scrWidth + rand()%1500;	//As rand()% increase, object density decrease 
		enemy[i].prideY = enemy1HeightfromOrigin;
		enemy[i].prideIndex = i;
		enemy[i].prideShow = true;
		enemy[i].HitEdward = false;
	}
}

void EnemyGenerate(){
	// For Enemy Generate
		if(!pause){
		for(int i=0; i<enemyNumber; i++)
		{
			enemy[i].prideX -= enemy1speed;
			if(enemy[i].prideX <=0)
			{	
				enemy[i].prideShow = true;
				enemy[i].prideX = scrWidth + rand()%1500;
			}

			enemy[i].prideIndex++;
			if(enemy[i].prideIndex>=5)
			enemy[i].prideIndex = 0;
		}
	}
}

// Enemy Movement Function
void Enemy1MovementShow()
{
	for(int i=0; i<enemyNumber; i++)
	{
		if(enemy[i].prideShow && enemy[i].HitEdward == false){
			iShowBMP2(enemy[i].prideX, enemy[i].prideY, pride[enemy[i].prideIndex], 0);
		}
		else if(enemy[i].prideShow && enemy[i].HitEdward){
			iShowBMP2(enemy[i].prideX, enemy[i].prideY, prideStrike[enemy[i].prideIndex], 0);
			enemy[i].HitEdward = false;
		}
	}
}


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ENEMY2 ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
struct Enemies2
{
	int alienX, alienY;
	int alienIndex;
	bool alienShow;
	bool HitEdward;
}enemy2[enemy2Number];



// Enemy2 Set Function
void setEnemies2()
{
	for(int i=0; i<enemy2Number; i++)
	{
		enemy2[i].alienX = scrWidth + rand()%1500;	//As rand()% increase, object density decrease
		enemy2[i].alienY = enemy2HeightfromOrigin;
		enemy2[i].alienIndex = i; //rand()%20;
		enemy2[i].alienShow = true;
		enemy2[i].HitEdward = false;
	}
}

void Enemy2Generate(){
	// For Enemy2 Generate
		if(!pause)
		for(int i=0; i<enemy2Number; i++)
		{
			enemy2[i].alienX -= enemy2speed;
			if(enemy2[i].alienX <=0)
			{	
				enemy2[i].alienShow = true;
				enemy2[i].alienX = scrWidth + rand()%1500;
			}

			enemy2[i].alienIndex++;
			if(enemy2[i].alienIndex>=5)
			enemy2[i].alienIndex = 0;
		}
}

// Enemy2 Movement Function
void Enemy2MovementShow()
{
	for(int i=0; i<enemy2Number; i++)
	{
		if(enemy2[i].alienShow && enemy2[i].HitEdward == false){
			iShowBMP2(enemy2[i].alienX, enemy2[i].alienY, alien[enemy2[i].alienIndex], 0);
		}
		else if(enemy2[i].alienShow && enemy2[i].HitEdward){
			iShowBMP2(enemy2[i].alienX, enemy2[i].alienY, alienStrike[2], 0);
			enemy2[i].HitEdward = false;
		}
	}
}


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: HEARTS ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
struct Hearts
{
	int lifeX, lifeY;
	int lifeIndex;
	bool lifeShow;
	bool HitEdward;
}heart[heartNumber];


// Heart Set Function
void setHearts()
{
	for(int i=0; i<heartNumber; i++)
	{
		heart[i].lifeX = scrWidth + heartRecycleWidth; // hearts will generate in every 2500 px
		heart[i].lifeY = heartHeight;
		heart[i].lifeIndex = i; //rand()%1000;
		heart[i].lifeShow = true;
		heart[i].HitEdward = false;
	}
}

// Heart Generate Function
void HeartGenerate()
{
		if(!pause)
		for(int i=0; i<heartNumber; i++)
		{
			heart[i].lifeX -= heartSpeed;
			if(heart[i].lifeX <=0)
			{	
				heart[i].lifeShow = true;
				heart[i].lifeX = scrWidth + heartRecycleWidth; 
			}

			heart[i].lifeIndex++;
			if(heart[i].lifeIndex>=5)
			heart[i].lifeIndex = 0;
		}
}

// Heart Movement Function
void HeartMovementShow()
{
	for(int i=0; i<heartNumber; i++)
	{
		if(heart[i].lifeShow && heart[i].HitEdward == false){
			iShowBMP2(heart[i].lifeX, heart[i].lifeY, life[heart[i].lifeIndex], 0);
		}
		else if(heart[i].lifeShow && heart[i].HitEdward){
			iShowBMP2(heart[i].lifeX, heart[i].lifeY, lifeStrike[heart[i].lifeIndex], 0);
			heart[i].HitEdward = false;
		}
	}
}

// Check Life Bar, Called by iSetTimer()
void ChecklifeBar(){

	if(!pause){
		for(int i = 0; i < heartNumber; i++){
			if(heart[i].HitEdward == true && lives < livesCount){
				lives++;
			}
			
			else if(HealthDecrease && lives > 1){
				lives--;
				HealthDecrease = false;
			}
			else if (gameState == 69 && lives <= 1){
				OptionState = 2;
				gameState = 7;// Game OVER

				// Change Music
				musicLvl1 = false;
				musicGameOver = true;
				started = true;
				if(started){
					changeMusicCheck();
				}
			}
		}
	}
}

// Shows Life Bar BMP
void ShowLifeBar(){
	if(lives >=1){
		iShowBMP2(30, scrHeight - 70, lifeBar[lives-1], 0); // lifebar max index 10
	}
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Collision::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

// Fire Collision with Enemy 1
void CheckFireCollisionEnemy1(){
	for(int i = 0; i< enemyNumber; i++){
		
		if(edwardJumpY >=0 && edwardJumpY <= 30)
		{	
			if(enemy[i].prideShow == true && fire1[FireCount-1].fireShot == true && fire1[FireCount-1].fireX + 100 >= enemy[i].prideX){
				enemy[i].prideShow = false;
				fire1[FireCount-1].fireShot = false;
				score += 5;
			}
		}
	}
}

// Body Collision with Enemy 1
void CheckBodyCollisionEnemy1(){
	for(int i = 0; i< enemyNumber; i++){
		if(enemy[i].prideShow == true && edwardX + 20 >= enemy[i].prideX && edwardX <= enemy[i].prideX + enemyWidth && edwardY + edwardJumpY + 20 >= enemy[i].prideY && edwardY + edwardJumpY <= enemy[i].prideY + enemyHeight )
		{
			enemy[i].HitEdward = true;
			GotHit =  true;
			HealthDecrease = true;
		}
	}
}

// Heart Collison
void CheckCollisionHeart(){
	for(int i = 0; i< heartNumber; i++){
		if(heart[i].lifeShow == true && edwardX >= (heart[i].lifeX - 90) && edwardX <= (heart[i].lifeX + heartWidth) && (edwardY + edwardJumpY + 50) >= heart[i].lifeY && (edwardY + edwardJumpY) <= (heart[i].lifeY + heartHeight) )
		{
			heart[i].lifeShow = false;
			heart[i].HitEdward = true;
			GotHit =  true;
		}
	}
}

// Fire Collison with AlienShip
void CheckFireCollisionEnemy2(){
	for(int i = 0; i< enemy2Number; i++){

		if(edwardJumpY >= 250 && fire1[FireCount-1].fireShot == true)
		{
			if(enemy2[i].alienShow == true && (fire1[FireCount-1].fireX + 100 >= enemy2[i].alienX) && (fire1[FireCount-1].fireY + 100 >= enemy2[i].alienY))
			{
				for(int j = 0; j < 6; j++){
					iShowBMP2(enemy2[i].alienX, enemy2[i].alienY, alienStrike[j],0);
				}
				enemy2[i].alienShow = false;
				fire1[FireCount-1].fireShot = false;
				score += 10;
			}
		}
	}
}

// Body Collision with AlienShip
void CheckBodyCollisionEnemy2(){
	for(int i = 0; i< enemy2Number; i++){
		if(enemy2[i].alienShow == true && edwardX + 80 >= enemy2[i].alienX && edwardX <= (enemy2[i].alienX + enemy2Width) && (edwardY + edwardJumpY + 20) >= enemy2[i].alienY && (edwardY + edwardJumpY) <= (enemy2[i].alienY + enemy2Height) )
		{
			enemy2[i].HitEdward = true; 
			GotHit =  true;
			HealthDecrease = true;
		}
	}
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::HIGH SCORE & FIRE POWER COUNT::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
// open, read, show, close a File

// Live Fire Remaining Show
void firePowerRemainShow(){
	itoa(FireRemain, fireStr, 10); // integer to Ascii coversion
	iShowBMP2(30, scrHeight - 150,"game_elements\\firePowerRemaining.bmp",0);
	iSetColor(255, 255, 255); 
	iText(170, scrHeight - 120, fireStr, GLUT_BITMAP_TIMES_ROMAN_24);
}


// Live Score Show
void scoreShow()
{
	
	itoa(score, strScore, 10); // integer to Ascii coversion
	iSetColor(170, 85, 0);
	iShowBMP2(scoreShowX, scoreShowY-25,"game_elements\\scoreBoard.bmp",0);
	iSetColor(255, 255, 255); 
	iText(scoreShowX+50, scoreShowY+11, "Score:",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(scoreShowX+120, scoreShowY+9, strScore,GLUT_BITMAP_TIMES_ROMAN_24);
}

// Appending Score to the FILE
void appendScore(int n, char name[])
{
	FILE *fp = fopen("HighScore.txt", "a");

	if (fp != NULL)
	{
		fprintf(fp, "%s\n",name);
		fprintf(fp, "%d\n",n);
	}

	fclose(fp);

}

// Reading score from the FILE
void readHighScore()
{
	FILE *fp = fopen("HighScore.txt", "r");
	char str[100];
	
	if (fp != NULL)
	{
		while (fgets(str, 15, fp) != NULL) 
		{
			strcpy(st[stringIndex++], str); // Read Playername
			fgets(str, 15, fp);				// Read Points
			numberArray[arrayIndex++] = atoi(str);
	
		}
	}

	fclose(fp);
}

//Sorting the highScores and Call from showHighScore()
void sortingHighScore()
{
	int temp;
	char t[100];

	for (int i = 0; i < arrayIndex - 1; i++)
	{
		for (int j = 0; j < arrayIndex - 1; j++)
		{
			if (numberArray[j] < numberArray[j + 1])
			{
				//Score Sorting
				temp = numberArray[j];
				numberArray[j] = numberArray[j + 1];
				numberArray[j + 1] = temp;
				
				// Name Sorting according to Score
				strcpy(t, st[j]);
				strcpy(st[j], st[j+1]);
				strcpy(st[j+1], t);
			}
		}
	}
	

}

// Show High Score is called in iDraw()
void highScoreShow()
{	
	sortingHighScore();
	iClear();
	iShowBMP(0,0,"menu\\hsp.bmp");
	iText(highScoreShowX - 30, highScoreShowY, "#RANK", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(highScoreShowX + 160, highScoreShowY, "POINTS", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(highScoreShowX + 310, highScoreShowY, "NAME", GLUT_BITMAP_TIMES_ROMAN_24);

	for(int i=0,k=25;  i<10;  i++,k+=25) // Shows FIRST 10 Players POINTS & NAMES
	{	
		itoa(i+1, strScoreCount, 10);
		itoa(numberArray[i], strScore, 10);
		iSetColor(255, 255, 255);
		iText(highScoreShowX, highScoreShowY - k, strScoreCount, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 255, 255);
		iText(highScoreShowX + 180, highScoreShowY - k, strScore ,GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 255, 255);
		iText(highScoreShowX + 310, highScoreShowY - k, st[i] ,GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
}

// INSERT NAME BOX Prompt
void showName(){
	
	iSetColor(255,255,255);
	iShowBMP(nameBoxX, nameBoxY, enterNameBox[0]);
	iText(nameBoxX + 50, nameBoxY + 145, insertName, GLUT_BITMAP_TIMES_ROMAN_24);
}

// Called from iDraw when the Game Is Over
void gameOver()
{	if(FireRemain == 0){
		iShowBMP(0,0,"menu\\gameOverFinished.bmp");
	} else {
		iShowBMP(0,0,"menu\\gameOver.bmp");
	}
	itoa(score,strScore,10);
	iText(570,180,"Your Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(700,180,strScore,GLUT_BITMAP_TIMES_ROMAN_24);

}


// Enables Multiple Times High Score Page access
void readScoreVarReset(){
	stringIndex = 0;
	numIndex = 0;
	arrayIndex = 0;
}


// Reset All when go back to MENU or EXIT from the GAMEOVER Section
void resetAll(){
	setEnemies();
	setEnemies2();
	setHearts();
	score = 0;
	OptionState = 0;
	arrayIndex = 0;
	HealthDecrease = false;
	lives = livesCount;
	FireRemain = fireNumber;
	FireCount = 0;
	edwardJumpY = 0;
	jump = false;
	jumpHigh = false;
	GotHit = false;
	edwardX = 0;
	edwardY = 100;
	edwardIndex = 0;
	pause = false;
	gameState = 0;
	streetIndex = 0;
	musicOn = true;
	musicIntro = true;
	musicStory = false;
	musicLvl1 = false;
	musicGameOver = false;
	storyMode = true;
	storyPage = 0;
	numIndex = 0;
	insertName[0] = '\0';
	insertName[50];
	showInsertNameBox = true;
	arrayIndex = 0;
	numIndex = 0;
	stringIndex = 0;
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
/*
OptionState = 0 : HomeMenu
OptionState = 1 : In The Game
OptionState = 2 : Game Over

gameState = 0 : Home Menu Page
gameState = 1 : In the Game, Story Starts
gameState = 2 : Controls Page
gameState = 3 : High Score Page
gameState = 4 : Credits page
gameState = 5 : exit
gameState = 6 : MENU Button
gameState = 7 : Game Over
gameState = 69 : Game Starts Here

*/
void iDraw()
{
	iClear();

	// HOME MENU OPTION
	if (OptionState == 0){
		
		if(started)
			changeMusicCheck();

		if (gameState == 0)
		{	
			iShowBMP(0, 0, home_menuPage);

			if(musicOn)
				iShowBMP2(scrWidth - 100, 20, musicButton[0], 0);
			else
				iShowBMP2(scrWidth - 100, 20, musicButton[1], 0);

			// Buttons
			for (int i = 0; i < 5; i++)
			{	
				iShowBMP2(bCordinate[i].x, bCordinate[i].y, button[i], 0);
				menuHover();
			}
			
		}

	// CONTROLS Page
		else if (gameState == 2){
			iShowBMP(0, 0, controlsPage);
			iShowBMP2(bCordinate[5].x, bCordinate[5].y, button[5], 0); //MENU Button
			menuHover();
		}

	// HIGHSCORE Page
		else if (gameState == 3){
			iShowBMP(0 , 0 , "menu\\hsp.bmp");
			highScoreShow(); 
			iShowBMP2(bCordinate[5].x, bCordinate[5].y, button[5], 0);
			menuHover();
		}
	
	// CREDITS Page
		else if (gameState == 4){
			iShowBMP(0 , 0 , creditsPage);
			iShowBMP2(bCordinate[5].x, bCordinate[5].y, button[5], 0);
			menuHover();
		}

	// EXIT Button
		else if(gameState == 5){
			exit(0);
		}
	//MENU Button
		else if(gameState == 6){
			OptionState = 0;
			gameState = 0;
		}
	}





	// IN THE GAME
	else if(OptionState == 1){

		if (gameState == 1)
		{	// SENSITIVE LAYERWISE
			if(started)
				changeMusicCheck();

			if(storyMode)
			{	pause = true; //Initially All Stops
				iShowBMP(0, 0, story[storyPage]);
			}
		}
		// PLAY GAME
		else if(gameState == 69){
			
			iShowBMP2(0, 0, background[0], 0);
			iShowBMP2(0, 0, street[streetIndex], 0);
			

			// Jump feature
			if (jump) {
				iShowBMP2(edwardX, edwardY + edwardJumpY, edwardJump[0], 0);
			}
			else if(!GotHit){
				iShowBMP2(edwardX, edwardY, edwardRun[edwardIndex], 0); // Ignoring background color, 0 for black
			}
			else {
				iShowBMP2(edwardX, edwardY, HitByEnemy[edwardIndex], 0);	
			}

			//Fire, Enemy Functions Layer Wise
			Enemy1MovementShow();
			Enemy2MovementShow();
			HeartMovementShow();
			ShowFire();
			CheckFireCollisionEnemy1();
			CheckBodyCollisionEnemy1();
			CheckFireCollisionEnemy2();
			CheckBodyCollisionEnemy2();
			CheckCollisionHeart();
			ShowLifeBar();
			scoreShow();
			firePowerRemainShow();

		//iText(0, scrHeight-20, "Press m for ON/OFF music, p for pause, r for resume, END for exit.");
	    }
	}




	// GAME OVER
	else if (OptionState == 2){
		
	// GAME OVER

		 if(gameState == 7){
			if(showInsertNameBox){
				iShowBMP(0,0,"menu\\EA.bmp");
				showName();
			}
			else{
				gameOver();
				iShowBMP2(bCordinate[5].x - 100, bCordinate[5].y, button[5], 0); //MENU Button
				iShowBMP2(bCordinate[4].x + 200, bCordinate[5].y, button[4], 0); // EXIT Button
				menuHover();
			}
			
		}
	}

	
	
	
	
}



/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	mposx = mx;
	mposy = my;
}

void iMouse(int button, int state, int mx, int my)
{

	// BUTTON CLICK DETECTION
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		for(int i = 0; i < 6; i++)
		{	
			if (OptionState == 0) //HOME BUTTONS
			{	
				if(mx >= bCordinate[i].x && mx <= bCordinate[i].x + 200 && my >= bCordinate[i].y && my <= bCordinate[i].y + 80){
					gameState = i+1;
					
					if(gameState == 1){ // PLAY NOW BUTTON
						OptionState = 1;
						gameState = 1;

						musicIntro = false;
						musicStory = true;
						started = true;
						if(started)
							changeMusicCheck();
					}

					if(i == 2){	//HIGH SCORE BUTTON
						readScoreVarReset();
						readHighScore();
					}

				}

				// Left Click the music Icon to MUTE
				if(mx >= musicIconX && mx <= musicIconX + 80 && my >= musicIconY && my <= musicIconY + 81){
					if(musicOn){
						musicOn = false;
						PlaySound(0,0,0);
					}
				}
				
			}



			if (OptionState == 1){ // IN THE GAME
				
			}



			if (OptionState == 2) // GAME OVER
			{	
				if(gameState == 7) // GAME OVER State
				{
					
					if (i == 4) // GAMEOVER EXIT Button
					{	
						if(mx >= bCordinate[i].x + 200 && mx <= bCordinate[i].x + 400 && my >= bCordinate[i+1].y && my <= bCordinate[i+1].y + 80 )
						{
							// GAMEOVER Page
							//appendScore(score);
							exit(0);
						}
					}
					
					
					if(i == 5) // GAMEOVER MENU Button
					{
						if(mx >= bCordinate[i].x - 100 && mx <= bCordinate[i].x + 100 && my >= bCordinate[i].y && my <= bCordinate[i].y + 80 ){
							// GAMEOVER Page
							
							//appendScore(score);
							resetAll();
							OptionState = 0;
							gameState = 0;
							
						}
					}

				}

			}
		
		}
		
	}

	// Right click on the Music icon to UNMUTE
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		if(OptionState == 0 && gameState == 0){
			if(mx >= musicIconX && mx <= musicIconX + 80 && my >= musicIconY && my <= musicIconY + 81){
					if(!musicOn){
						changeMusic();
					}
				}
		} 
	}
	
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{	
	// Music
	if (key == 'm' || key == 'M') //bug at gameState == 7, showInsertNameBox
	{
		changeMusic();
		
	}

	

	//IN THE GAME
	if(OptionState == 1 && gameState ==69){

		// Jumping
		if (key == ' ') {
			if (!jump) {
				jump = true;
				jumpHigh = true;
			}
		}

		// Shooting/Firing
		if(key == 's' || key == 'S')
		{	
			SetFire();
		}

		//Pause
		if (key == 'p' || key == 'P'){
			if(!pause){
				pause = true;

			}
			// Music in pause menu
			if(musicOn)
			{
				musicOn = false;
				PlaySound(0,0,0);
			} 
			iPauseTimer(0);
		}

		// Resume
		if (key == 'r' || key == 'R')
		{	
			pause = false;
			musicOn = true;
			started = true;

			musicIntro = false;
			musicStory = false;
			musicLvl1 = false;
			musicGameOver = false;
			
			if(gameState == 0){
				musicIntro = true;
			}else if(gameState == 1){
				musicStory = true;
			}else if(gameState == 69){
				musicLvl1 = true;
			}else if(gameState == 7){
				musicGameOver = true;
			}
			
			if(started){
				changeMusicCheck();
			}
			iResumeTimer(0);
		}
	}
	


	if(OptionState == 1 && gameState == 1){
		// Story
		if((key == 'n' || key=='N') && storyMode==true)
		{
			storyPage++;

			if(storyPage > 11){
				storyMode = false;
				pause = false;
				OptionState = 1;
				gameState = 69; // PLAY GAME STARTS HERE

				musicStory = false;
				musicLvl1 = true;
				started = true;
				if(started){
					changeMusicCheck();
				}
			}
		}

		if((key == 'b' || key=='B') && storyMode==true)
		{
			storyPage--;

			if(storyPage<=0)
				storyPage=0;
		}
	}
	
	// INSERT NAME BOX IN GAME OVER STATE
	if(OptionState == 2 && gameState == 7){
		char chr;
		if((chr = key)!= '\r'){
			if(chr == '\b' && numIndex >= 1){	//BackSpace for resolving typing mistake
				arrayIndex--;
				insertName[--numIndex] = '\0';
			} 
			else {
				insertName[numIndex++] = chr;	//Characters Input
				insertName[numIndex] = '\0';
			}
		}

		if(key == '\r'){	// ENTER BUTTON
			appendScore(score, insertName);
			showInsertNameBox = false;
			gameState = 7;
		}

		
	}
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT && edwardX <scrWidth)
	{
		edwardX += rightMove;
	}
	if (key == GLUT_KEY_LEFT && edwardX>0)
	{
		edwardX -= leftMove;
	}
	
	if (key == GLUT_KEY_UP)
	{
		
	}
	if (key == GLUT_KEY_DOWN)
	{
		
	}
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	
}




int main()
{	
	srand(time(NULL)); //Generates Random numbers using real time in the rand() function 
	
	// Button Cordinates Arrangement // Bottom 2 Top
	int sum = 50;
	for (int i = 5; i >=0; i--)
	{
		bCordinate[i].x = 500;
		bCordinate[i].y = sum;
		sum += 100;
	}

	

	// Functions
		
	iSetTimer(160, BackGroundMmove);
	iSetTimer(140, PlayerState);
	iSetTimer(100, FireShot);
	
	setEnemies2();
	iSetTimer(100, Enemy2Generate);
	setEnemies();
	iSetTimer(150, EnemyGenerate);

	setHearts();
	iSetTimer(200, HeartGenerate);
	iSetTimer(100, ChecklifeBar);

	iInitialize(scrWidth, scrHeight, "Fullmetal Alchemist : Redemption");
	iStart();
	return 0;
}