#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"

int main(int argc,char *argv[])
{
    SDL_Surface *screen=NULL,*newgame=NULL,*load=NULL,*text=NULL;
    SDL_Surface *options=NULL,*credits=NULL,*quit=NULL,*background=NULL;
    SDL_Surface *newgame1=NULL,*load1=NULL,*options1=NULL,*credits1=NULL,*quit1=NULL;
    SDL_Rect pos_text,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back,pos_text2,pos_text3;
    Mix_Music *musique=NULL;
    Mix_Chunk *effect=NULL,*effect2=NULL;

    SDL_Event event;
    char ch[20];
    int done=1,i,t[5];
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Font *police=NULL;
    SDL_Color white={255,255,255};
    TTF_Init();

	for(i=0;i<5;i++)
	t[i]=0;

    screen=SDL_SetVideoMode(1000, 446, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    background=IMG_Load("background_menu.jpg");

    newgame=IMG_Load("new.png");
    load=IMG_Load("load.png");
    options=IMG_Load("options.png");
    credits=IMG_Load("credits.png");
    quit=IMG_Load("quit.png");

    newgame1=IMG_Load("new1.png");
    load1=IMG_Load("load1.png");
    options1=IMG_Load("options1.png");
    credits1=IMG_Load("credits1.png");
    quit1=IMG_Load("quit1.png");

    pos_back.x=0; pos_back.y=0;

    pos_new.x=0; pos_new.y=0;
    pos_load.x=0; pos_load.y=5;
    pos_options.x=0; pos_options.y=10;
    pos_credits.x=0; pos_credits.y=15;
    pos_quit.x=0; pos_quit.y=20;

    SDL_BlitSurface(background,NULL,screen,&pos_back);
    menu(screen,newgame,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);

    strcpy(ch,"The Treasure Hunt");
    pos_text.x = 250; pos_text.y = 15;
    pos_text2.x = 780; pos_text2.y = 400;
    pos_text3.x = 780; pos_text3.y = 420;

    text_ttf(ch,police,text,screen,pos_text,white,70);

    text_ttf("Press 'F' for full screen",police,text,screen,pos_text2,white,20);
    text_ttf("Press 'R' for regular screen",police,text,screen,pos_text3,white,20);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	musique = Mix_LoadMUS("maintheme.mp3");
	Mix_PlayMusic(musique,-1);

	effect = Mix_LoadWAV("selection.wav");
	effect2 = Mix_LoadWAV("choose.wav");

    while (done)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
	case SDL_MOUSEBUTTONDOWN :
	{
		if(event.button.button==SDL_BUTTON_LEFT)
		{
			if (event.button.x>50 && event.button.x<170 && event.button.y>45 && event.button.y<90)
			{
				Mix_PlayChannel(-1,effect2,0);
			}
			else if (event.button.x>50 && event.button.x<170 && event.button.y>155 && event.button.y<165)
			{
				Mix_PlayChannel(-1,effect2,0);
			}
			else if (event.button.x>50 && event.button.x<170 && event.button.y>190 && event.button.y<235)
			{
				Mix_PlayChannel(-1,effect2,0);
				sous_menu(screen,effect,effect2,text,police,white,musique);
				SDL_BlitSurface(background,NULL,screen,&pos_back);
				menu(screen,newgame,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
				text_ttf(ch,police,text,screen,pos_text,white,70);
				text_ttf("Press 'F' for full screen",police,text,screen,pos_text2,white,20);
				text_ttf("Press 'R' for regular screen",police,text,screen,pos_text3,white,20);
			}
			else if (event.button.x>50 && event.button.x<170 && event.button.y>260 && event.button.y<310)
			{
				Mix_PlayChannel(-1,effect2,0);
				credit(screen,effect,effect2,police,text,white);
				SDL_BlitSurface(background,NULL,screen,&pos_back);
				menu(screen,newgame,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
				text_ttf(ch,police,text,screen,pos_text,white,70);
				text_ttf("Press 'F' for full screen",police,text,screen,pos_text2,white,20);
				text_ttf("Press 'R' for regular screen",police,text,screen,pos_text3,white,20);
			}
			else if (event.button.x>50 && event.button.x<170 && event.button.y>335 && event.button.y<385)
			{
				Mix_PlayChannel(-1,effect2,0);
				done=0;
			}
		}
	break;
        }
	case SDL_KEYDOWN :
        {
            if(event.key.keysym.sym==SDLK_DOWN && t[0]==0 && t[1]==0 && t[2]==0 && t[3]==0 && t[4]==0)
            {
		menu(screen,newgame1,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=1;
                t[1]=0;
                t[2]=0;
                t[3]=0;
                t[4]=0;
            }
            else if(event.key.keysym.sym==SDLK_DOWN && t[0]==1)
            {
		menu(screen,newgame,load1,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=0;
                t[1]=1;
                t[2]=0;
                t[3]=0;
                t[4]=0;
            }
            else if(event.key.keysym.sym==SDLK_DOWN && t[1]==1)
            {
		menu(screen,newgame,load,options1,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=0;
                t[1]=0;
                t[2]=1;
                t[3]=0;
                t[4]=0;
            }
            else if(event.key.keysym.sym==SDLK_DOWN && t[2]==1)
            {
		menu(screen,newgame,load,options,credits1,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=0;
                t[1]=0;
                t[2]=0;
                t[3]=1;
                t[4]=0;
            }
            else if(event.key.keysym.sym==SDLK_DOWN && t[3]==1)
            {
		menu(screen,newgame,load,options,credits,quit1,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=0;
                t[1]=0;
                t[2]=0;
                t[3]=0;
                t[4]=1;
            }
            else if(event.key.keysym.sym==SDLK_DOWN && t[4]==1)
            {
		menu(screen,newgame1,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=1;
                t[1]=0;
                t[2]=0;
                t[3]=0;
                t[4]=0;
            }
            if(event.key.keysym.sym==SDLK_UP && t[0]==0 && t[1]==0 && t[2]==0 && t[2]==0 && t[3]==0 && t[4]==0)
            {
		menu(screen,newgame,load,options,credits,quit1,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=0;
                t[1]=0;
                t[2]=0;
                t[3]=0;
                t[4]=1;
            }
            else if(event.key.keysym.sym==SDLK_UP && t[4]==1)
            {
		menu(screen,newgame,load,options,credits1,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=0;
                t[1]=0;
                t[2]=0;
                t[3]=1;
                t[4]=0;
            }
            else if(event.key.keysym.sym==SDLK_UP && t[3]==1)
            {
		menu(screen,newgame,load,options1,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=0;
                t[1]=0;
                t[2]=1;
                t[3]=0;
                t[4]=0;
            }
            else if(event.key.keysym.sym==SDLK_UP && t[2]==1)
            {
		menu(screen,newgame,load1,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=0;
                t[1]=1;
                t[2]=0;
                t[3]=0;
                t[4]=0;
            }
            else if(event.key.keysym.sym==SDLK_UP && t[1]==1)
            {
		menu(screen,newgame1,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=1;
                t[1]=0;
                t[2]=0;
                t[3]=0;
                t[4]=0;
            }
            else if(event.key.keysym.sym==SDLK_UP && t[0]==1)
            {
		menu(screen,newgame,load,options,credits,quit1,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
                t[0]=0;
                t[1]=0;
                t[2]=0;
                t[3]=0;
                t[4]=1;

            }
	    else if(event.key.keysym.sym==SDLK_f)
		{
			screen = SDL_SetVideoMode(1000, 446, 32, SDL_SWSURFACE | SDL_FULLSCREEN);
			SDL_BlitSurface(background,NULL,screen,&pos_back);
			menu(screen,newgame1,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
			text_ttf("Press 'F' for full screen",police,text,screen,pos_text2,white,20);
			text_ttf("Press 'R' for regular screen",police,text,screen,pos_text3,white,20);
        		SDL_Flip(screen);
		}
	    else if(event.key.keysym.sym==SDLK_r)
		{
			screen = SDL_SetVideoMode(1000, 446, 32, SDL_SWSURFACE);
			SDL_BlitSurface(background,NULL,screen,&pos_back);
			menu(screen,newgame1,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
			text_ttf("Press 'F' for full screen",police,text,screen,pos_text2,white,20);
			text_ttf("Press 'R' for regular screen",police,text,screen,pos_text3,white,20);
        		SDL_Flip(screen);
		}
            else if(event.key.keysym.sym==SDLK_x)
                done = 0;
            
            else if(event.key.keysym.sym==SDLK_ESCAPE)
                done = 0;
	    if (event.key.keysym.sym==SDLK_RETURN && t[2]==1)
		{
		Mix_PlayChannel(-1,effect2,0);
		sous_menu(screen,effect,effect2,text,police,white,musique);
		SDL_BlitSurface(background,NULL,screen,&pos_back);
		menu(screen,newgame,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		text_ttf(ch,police,text,screen,pos_text,white,70);
		text_ttf("Press 'F' for full screen",police,text,screen,pos_text2,white,20);
		text_ttf("Press 'R' for regular screen",police,text,screen,pos_text3,white,20);
	    }
	    else if (event.key.keysym.sym==SDLK_RETURN && t[3]==1)
		{
		Mix_PlayChannel(-1,effect2,0);
		credit(screen,effect,effect2,police,text,white);
		SDL_BlitSurface(background,NULL,screen,&pos_back);
		menu(screen,newgame,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		text_ttf(ch,police,text,screen,pos_text,white,70);
		text_ttf("Press 'F' for full screen",police,text,screen,pos_text2,white,20);
		text_ttf("Press 'R' for regular screen",police,text,screen,pos_text3,white,20);
		}
	    else if (event.key.keysym.sym==SDLK_RETURN && t[4]==1)
		done=0;
            break;
        }
        
        case SDL_MOUSEMOTION :
        {
            if((event.motion.x >50) && (event.motion.x <170) && (event.motion.y >45) && (event.motion.y <90) )
            {
		menu(screen,newgame1,load,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
		t[0]=1;
                t[1]=0;
                t[2]=0;
                t[3]=0;
                t[4]=0;
            }
            else if((event.motion.x >50) && (event.motion.x <170) && (event.motion.y >155) && (event.motion.y <165) )
            {
		menu(screen,newgame,load1,options,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
		t[0]=0;
                t[1]=1;
                t[2]=0;
                t[3]=0;
                t[4]=0;
            }
            else if((event.motion.x >50) && (event.motion.x <170) && (event.motion.y >190) && (event.motion.y <235) )
            {menu(screen,newgame,load,options1,credits,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
		t[0]=0;
                t[1]=0;
                t[2]=1;
                t[3]=0;
                t[4]=0;
            }
            else if ((event.motion.x >50) && (event.motion.x <170) && (event.motion.y >260) && (event.motion.y <310) )
            {
		menu(screen,newgame,load,options,credits1,quit,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
		t[0]=0;
                t[1]=0;
                t[2]=0;
                t[3]=1;
                t[4]=0;
            }
            else if((event.motion.x >50) && (event.motion.x <170) && (event.motion.y >335) && (event.motion.y <385) )
            {
		menu(screen,newgame,load,options,credits,quit1,pos_new,pos_load,pos_options,pos_credits,pos_quit,pos_back);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,effect,0);
		t[0]=0;
                t[1]=0;
                t[2]=0;
                t[3]=0;
                t[4]=1;
            }
            break;
        }
        }
	SDL_Flip(screen);
    }
liberation ( police ,screen, newgame, newgame1, load, load1, options, options1, credits, credits1, quit, quit1,text, background, musique);



}

