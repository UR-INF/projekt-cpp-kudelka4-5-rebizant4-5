#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include<mmsystem.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;



bool skucha=false;
int x=-2, y=-2;
     int ys=-2;
int do_wygranej=0;
int punkty = 0;
int rekord = 0;

void __fastcall TForm1::pointsClick(TObject *Sender)
{
Caption = "Zdobyles : " + IntToStr(punkty) + " pkt";

}

bool kolizja(TImage *pilka, TImage *cegla)
{
   if( pilka->Left >= cegla->Left-pilka->Width && pilka->Left <= cegla->Left+cegla->Width &&
       pilka->Top >= cegla->Top-pilka->Height && pilka->Top <= cegla->Top+cegla->Height)
      return true;
      else return false;
      punkty+=10;

}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
     b->Top+=y;         b->Left+=x;

    //odbij od lewej sciany
    if (b->Left-5 <= tlo->Left -5 ) x=-x;

    //odbij od g�rnej sciany
    if (b->Top-10 <= tlo->Top -5) y=-y;

   //odbij od prawej sciany
    if (b->Left+b->Width +5 >= tlo->Width +5 ) x=-x;

    //skucha!
    if (b->Top >= p->Top+p->Height+15 )
    {
        Timer_pilka->Enabled = false;
        b->Visible=false;
        Button1->Caption = "Pora�ka! Jeszcze raz?";
        Button1->Visible=true;

        if(punkty > rekord) rekord=punkty;

        points-> Visible= True;
        points-> Caption = "Zdoby�es: " + IntToStr(punkty) + " pkt";

        Best -> Visible = True;
        Best-> Caption = "Twoj rekord to : " + IntToStr(rekord);
       }

    //odbicie pilki (b) od paletki (p)

    else if(b->Left > p->Left-b->Width/2 && b->Left < p->Left+p->Width &&
       b->Top+b->Height > p->Top && p->Visible==true )
       {
             sndPlaySound("sounds/sound1.wav",SND_ASYNC);
               if (y>0) { y=-y;  }
               x=(b->Left - p->Left) / 5 - 5;
       }

       //wygrana = zlikwidowanie wsyzstkich blokow

if(do_wygranej==10 ) {
     if(Image1->Visible==false)  Image1->Visible=true;
     if(Image2->Visible==false)  Image2->Visible=true;
     if(Image3->Visible==false)  Image3->Visible=true;
     if(Image4->Visible==false)  Image4->Visible=true;
     if(Image5->Visible==false)  Image5->Visible=true;
     if(Image6->Visible==false)  Image6->Visible=true;
          x=-3; y=-3;
                      tlo->Visible=false;
                      tlo2->Visible=true;
        }
     if(do_wygranej==15) {
     if(Image5->Visible==false)  Image5->Visible=true;
     if(Image6->Visible==false)  Image6->Visible=true;
     if(Image7->Visible==false)  Image7->Visible=true;
     if(Image8->Visible==false) Image8->Visible=true;
     if(Image9->Visible==false)  Image9->Visible=true;
     if(Image10->Visible==false) Image10->Visible=true;
     if(Image1->Visible==false)  Image1->Visible=true;
     if(Image2->Visible==false)  Image2->Visible=true;

           tlo2->Visible=false;
           tlo3->Visible=true;
            y=-4; x=-4;
        }
        if(do_wygranej==20)
        {
     if(Image9->Visible==false)  Image9->Visible=true;
     if(Image10->Visible==false) Image10->Visible=true;
     if(Image11->Visible==false)  Image11->Visible=true;
     if(Image12->Visible==false)  Image12->Visible=true;
     if(Image1->Visible==false)  Image1->Visible=true;
     if(Image2->Visible==false)  Image2->Visible=true;
     if(Image3->Visible==false)   Image3->Visible=true;
     if(Image4->Visible==false)  Image4->Visible=true;
     if(Image8->Visible==false) Image8->Visible=true;
     if(Image9->Visible==false)  Image9->Visible=true;
     if(Image10->Visible==false) Image10->Visible=true;

               y=-5; x=-5;
        }
         if(do_wygranej==25)
        {
     if(Image13->Visible==false)  Image13->Visible=true;
     if(Image14->Visible==false) Image14->Visible=true;
     if(Image15->Visible==false)  Image15->Visible=true;
     if(Image16->Visible==false)  Image16->Visible=true;
      if(Image1->Visible==false)  Image1->Visible=true;
     if(Image2->Visible==false)  Image2->Visible=true;
     if(Image3->Visible==false)   Image3->Visible=true;
     if(Image4->Visible==false)  Image4->Visible=true;
     if(Image5->Visible==false)  Image5->Visible=true;
     if(Image6->Visible==false)  Image6->Visible=true;

        }
        if(do_wygranej==30)
        {
     if(Image17->Visible==false)  Image17->Visible=true;
     if(Image18->Visible==false)  Image18->Visible=true;
     if(Image18->Visible==false)  Image19->Visible=true;
     if(Image20->Visible==false)  Image20->Visible=true;
     if(Image11->Visible==false)  Image11->Visible=true;
     if(Image12->Visible==false)  Image12->Visible=true;
     if(Image1->Visible==false)   Image1->Visible=true;
     if(Image2->Visible==false)   Image2->Visible=true;
     if(Image3->Visible==false)   Image3->Visible=true;
     if(Image4->Visible==false)   Image4->Visible=true;
          tlo3->Visible=false;
           tlo4->Visible=true;
            y=-6; x=-6;
        }
        if(do_wygranej==35)
        { if(Image5->Visible==false)  Image5->Visible=true;
     if(Image6->Visible==false)  Image6->Visible=true;
     if(Image7->Visible==false)  Image7->Visible=true;
     if(Image8->Visible==false) Image8->Visible=true;
     if(Image9->Visible==false)  Image9->Visible=true;
     if(Image10->Visible==false) Image10->Visible=true;
     if(Image11->Visible==false)  Image11->Visible=true;
     if(Image12->Visible==false)  Image12->Visible=true;
     if(Image15->Visible==false)  Image15->Visible=true;
     if(Image16->Visible==false)  Image16->Visible=true;
      y=-7; x=-7;
}
        if(do_wygranej==40) {
     if(Image1->Visible==false)  Image1->Visible=true;
     if(Image2->Visible==false)  Image2->Visible=true;
     if(Image3->Visible==false)  Image3->Visible=true;
     if(Image4->Visible==false)  Image4->Visible=true;
     if(Image17->Visible==false) Image17->Visible=true;
     if(Image18->Visible==false) Image18->Visible=true;
     if(Image19->Visible==false) Image19->Visible=true;
     if(Image20->Visible==false) Image20->Visible=true;
     if(Image8->Visible==false)  Image8->Visible=true;
     if(Image9->Visible==false)  Image9->Visible=true;
        }

          if(do_wygranej==45) {
     if(Image5->Visible==false)  Image5->Visible=true;
     if(Image6->Visible==false)  Image6->Visible=true;
     if(Image7->Visible==false)  Image7->Visible=true;
     if(Image8->Visible==false)  Image8->Visible=true;
     if(Image11->Visible==false) Image11->Visible=true;
     if(Image18->Visible==false) Image18->Visible=true;
     if(Image19->Visible==false) Image19->Visible=true;
     if(Image20->Visible==false) Image20->Visible=true;
     if(Image13->Visible==false)  Image13->Visible=true;
     if(Image9->Visible==false)  Image9->Visible=true;
      if(Image22->Visible==false) Image22->Visible=true;
     if(Image14->Visible==false)  Image14->Visible=true;
     if(Image16->Visible==false)  Image16->Visible=true;
      y=-8; x=-8;
        }


//blok1
if (kolizja(b,Image1) && Image1->Visible==true)
     {x=-x; y=-y; do_wygranej++;
     Image1->Visible=false;
      punkty += 10;
      sndPlaySound("sounds/sound2.wav",SND_ASYNC); }
//blok2
if (Image2-> Visible==true){Image24->Visible=false;}
if (kolizja(b,Image2) && Image2->Visible==true)
    {x=-x; y=-y; do_wygranej++;
    Image2->Visible=false; punkty += 10;
    sndPlaySound("sounds/sound2.wav",SND_ASYNC);
      Image24->Visible=true;}
    //blok3
if (kolizja(b,Image3) && Image3->Visible==true) {x=-x; y=-y; do_wygranej++; Image3->Visible=false;
 punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC); star3->Visible=true;}
    //blok4
if (kolizja(b,Image4) && Image4->Visible==true) {x=-x; y=-y; do_wygranej++; Image4->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    //blok5
if (kolizja(b,Image5) && Image5->Visible==true) {x=-x; y=-y; do_wygranej++; Image5->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    //blok6
if (kolizja(b,Image6) && Image6->Visible==true) {x=-x; y=-y; do_wygranej++; Image6->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    //blok7
if (Image7-> Visible==true){Image25->Visible=false;}
if (kolizja(b,Image7) && Image7->Visible==true) {x=-x; y=-y; do_wygranej++;
Image7->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);
     Image25->Visible=true;}
    //blok8
if (kolizja(b,Image8) && Image8->Visible==true)
    {x=-x; y=-y; do_wygranej++; Image8->Visible=false;
    punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);  }
        //blok9
if (kolizja(b,Image9) && Image9->Visible==true) {x=-x; y=-y; do_wygranej++; Image9->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    //blok10
if (kolizja(b,Image10)&& Image10->Visible==true) {x=-x; y=-y; do_wygranej++; Image10->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    //blok11
if (kolizja(b,Image11) && Image11->Visible==true) {x=-x; y=-y; do_wygranej++; Image11->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    //blok12
if (kolizja(b,Image12) && Image12->Visible==true) {x=-x; y=-y; do_wygranej++; Image12->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}

if (Image13-> Visible==true){Image22->Visible=false;}
if (kolizja(b,Image13) && Image13->Visible==true)
   {x=-x; y=-y; do_wygranej++; Image13->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);
   Image22->Visible=true; }
if (kolizja(b,Image15) && Image15->Visible==true) {x=-x; y=-y; do_wygranej++; Image15->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    if (kolizja(b,Image16) && Image16->Visible==true) {x=-x; y=-y; do_wygranej++; Image16->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    if (kolizja(b,Image17) && Image17->Visible==true) {x=-x; y=-y; do_wygranej++; Image17->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    if (kolizja(b,Image18) && Image18->Visible==true) {x=-x; y=-y; do_wygranej++; Image18->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    if (kolizja(b,Image19) && Image19->Visible==true)
    {x=-x; y=-y; do_wygranej++; Image19->Visible=false;
    punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC); star1->Visible=true;}

    if (kolizja(b,Image20) && Image20->Visible==true) {x=-x; y=-y; do_wygranej++;
     Image20->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC); star2->Visible=true;}
          if (Image21-> Visible==true){Image26->Visible=false;}
    if (kolizja(b,Image21) && Image21->Visible==true) {x=-x; y=-y; do_wygranej++;
    Image21->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);
       Image26->Visible=true;  }
    if (kolizja(b,Image22) && Image22->Visible==true) {x=-x; y=-y; do_wygranej++;
    Image22->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    if (kolizja(b,Image23) && Image23->Visible==true) {x=-x; y=-y; do_wygranej++;
    Image23->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC); }
    if (kolizja(b,Image24) && Image24->Visible==true) {x=-x; y=-y; do_wygranej++; Image24->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);}
    if (kolizja(b,Image25) && Image25->Visible==true) {x=-x; y=-y; do_wygranej++;
    Image25->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);
    }
    if (kolizja(b,Image26) && Image26->Visible==true) {x=-x; y=-y; do_wygranej++;
    Image26->Visible=false; punkty += 10; sndPlaySound("sounds/sound2.wav",SND_ASYNC);
    }
}


//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_LEFT) lewo->Enabled=true;
  if(Key==VK_RIGHT) prawo->Enabled=true;
}

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_LEFT) lewo->Enabled=false;
  if(Key==VK_RIGHT) prawo->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewoTimer(TObject *Sender)
{
    if (p->Left>10) p->Left-=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawoTimer(TObject *Sender)
{
    if (p->Left+p->Width<tlo->Width-10) p->Left+=10;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
     b->Left=360; b->Top=400;
     p->Left=320;
     b->Visible=true;
     x=-2;
     y=-2;
     Timer_pilka->Enabled=true;
     Button1->Visible=false;
     do_wygranej=0;
     Image1->Visible=true; Image5->Visible=true; Image9->Visible=true;
     Image2->Visible=true; Image6->Visible=true; Image10->Visible=true;
     Image3->Visible=true; Image7->Visible=true; Image11->Visible=true;
     Image4->Visible=true; Image8->Visible=true; Image12->Visible=true;
     Image13->Visible=true;  Image15->Visible=true;
     Image16->Visible=true; Image17->Visible=true; Image18->Visible=true;
     Image19->Visible=true; Image20->Visible=true; Image21->Visible=true;
     Image22->Visible=true; Image23->Visible=true; Image24->Visible=true;
     Image25->Visible=true; Image26->Visible=true;
punkty=0;
points-> Visible= False;
Best -> Visible = False;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BestClick(TObject *Sender)
{
Best-> Caption = "Twoj rekord to : " + IntToStr(rekord);
}
//---------------------------------------------------------------------------

  void __fastcall TForm1::Timer1Timer(TObject *Sender)
{ if(star1->Visible==true) star1->Top-=ys;

if(star1->Left > p->Left-star1->Width/2 && star1->Left < p->Left+p->Width &&
       star1->Top+star1->Height > p->Top && p->Visible==true )
       { star1-> Visible=false; punkty+=50; }
}
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{ if(star2->Visible==true) star2->Top-=ys;
       if(star2->Left > p->Left-star2->Width/2 && star2->Left < p->Left+p->Width &&
       star2->Top+star2->Height > p->Top && p->Visible==true )
       { star2-> Visible=false; punkty+=50; }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{ if(star3->Visible==true) star3->Top-=ys;


       if(star3->Left > p->Left-star3->Width/2 && star3->Left < p->Left+p->Width &&
       star3->Top+star3->Height > p->Top && p->Visible==true )
       { star3-> Visible=false;
       punkty+=50; }
}
//---------------------------------------------------------------------------

