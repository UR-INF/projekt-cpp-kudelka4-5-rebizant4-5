//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


int x=-3, y=-3;
int do_wygranej=19;
int punkty =0;
int rekord=0;

bool kolizja(TImage *pilka, TImage *cegla)
{
   if( pilka->Left >= cegla->Left-pilka->Width && pilka->Left <= cegla->Left+cegla->Width &&
       pilka->Top >= cegla->Top-pilka->Height && pilka->Top <= cegla->Top+cegla->Height)
      return true;
      else return false;
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TOkno::Timer_pilkaTimer(TObject *Sender)
{
    b->Left+=x; b->Top+=y;

    //odbij od lewej sciany
    if (b->Left-5 <= tlo->Left) x=-x;

    //odbij od górnej sciany
    if (b->Top-5 <= tlo->Top) y=-y;

   //odbij od prawej sciany
    if (b->Left+b->Width+5 >= tlo->Width) x=-x;

    //skucha!
    if (b->Top >= p->Top+p->Height+15)
    {
        Timer_pilka->Enabled = false;
        b->Visible=false;
        Button1->Caption = "Przegrales! Jeszcze chcesz?";
        Button1->Visible=true;
          if(punkty > rekord) rekord=punkty;
        points->Caption = "Zdoby³es: " + IntToStr( punkty) + " pkt";
        points-> Visible= True;
        Best-> Caption = "Twoj rekord to : " + IntToStr(rekord);
        Best -> Visible = True;
    }
    //odbicie pilki (b) od paletki (p)
    else if(b->Left > p->Left-b->Width/2 && b->Left < p->Left+p->Width &&
       b->Top+b->Height > p->Top)
       {
       sndPlaySound("sounds/sound1.wav", SND_ASYNC);
               if (y>0) y=-y;
       }
    //wygrana = zlikwidowanie wsyzstkich blokow
     if (do_wygranej<=0)
     {
        Timer_pilka->Enabled = false;
        b->Visible=false;
        if(punkty > rekord) rekord=punkty;
		Button1->Caption = "Wygrana! Jeszcze raz?";
        Button1->Visible = true;
         points->Caption = "Zdoby³es: " + IntToStr( punkty) + " pkt";
        points-> Visible= True;
		Best-> Caption = "Twoj rekord to : " + IntToStr(rekord);
        Best -> Visible = True;
}

    //blok1
    if (kolizja(b,Image1) && Image1->Visible==true) {x=-x; y=-y; do_wygranej--; Image1->Visible=false; punkty += 10;}
    //blok2
    if (kolizja(b,Image2) && Image2->Visible==true) {x=-x; y=-y; do_wygranej--; Image2->Visible=false; punkty += 10;}
    //blok3
    if (kolizja(b,Image3) && Image3->Visible==true) {x=-x; y=-y; do_wygranej--; Image3->Visible=false; punkty += 10;}
    //blok4
    if (kolizja(b,Image4) && Image4->Visible==true) {x=-x; y=-y; do_wygranej--; Image4->Visible=false; punkty += 10;}
    //blok5
    if (kolizja(b,Image5) && Image5->Visible==true) {x=-x; y=-y; do_wygranej--; Image5->Visible=false; punkty += 10;}
    //blok6
    if (kolizja(b,Image6) && Image6->Visible==true) {x=-x; y=-y; do_wygranej--; Image6->Visible=false; punkty += 10;}
    //blok7
    if (kolizja(b,Image7) && Image7->Visible==true) {x=-x; y=-y; do_wygranej--; Image7->Visible=false; punkty += 10;}
    //blok8
    if (kolizja(b,Image8) && Image8->Visible==true) {x=-x; y=-y; do_wygranej--; Image8->Visible=false; punkty += 10;}
    //blok9
    if (kolizja(b,Image9) && Image9->Visible==true) {x=-x; y=-y; do_wygranej--; Image9->Visible=false; punkty += 10;}
    //blok10
    if (kolizja(b,Image10)&& Image10->Visible==true) {x=-x; y=-y; do_wygranej--; Image10->Visible=false; punkty += 10;}
    //blok11
    if (kolizja(b,Image11) && Image11->Visible==true) {x=-x; y=-y; do_wygranej--; Image11->Visible=false; punkty += 10;}
    //blok12
    if (kolizja(b,Image12) && Image12->Visible==true) {x=-x; y=-y; do_wygranej--; Image12->Visible=false; punkty += 10;}

     if (kolizja(b,Image13) && Image13->Visible==true) {x=-x; y=-y; do_wygranej--; Image13->Visible=false; punkty += 10;}
     if (kolizja(b,Image14) && Image14->Visible==true) {x=-x; y=-y; do_wygranej--; Image14->Visible=false; punkty += 10;}
     if (kolizja(b,Image15) && Image15->Visible==true) {x=-x; y=-y; do_wygranej--; Image15->Visible=false; punkty += 10;}
     if (kolizja(b,Image16) && Image16->Visible==true) {x=-x; y=-y; do_wygranej--; Image16->Visible=false; punkty += 10;}
     if (kolizja(b,Image17) && Image17->Visible==true) {x=-x; y=-y; do_wygranej--; Image17->Visible=false; punkty += 10;}
     if (kolizja(b,Image18) && Image18->Visible==true) {x=-x; y=-y; do_wygranej--; Image18->Visible=false; punkty += 10;}
     if (kolizja(b,Image19) && Image19->Visible==true) {x=-x; y=-y; do_wygranej--; Image19->Visible=false; punkty += 10;}


}
//---------------------------------------------------------------------------
void __fastcall TOkno::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_LEFT) lewo->Enabled=true;
  if(Key==VK_RIGHT) prawo->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TOkno::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_LEFT) lewo->Enabled=false;
  if(Key==VK_RIGHT) prawo->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TOkno::lewoTimer(TObject *Sender)
{
    if (p->Left>10) p->Left-=10;

}
//---------------------------------------------------------------------------
void __fastcall TOkno::prawoTimer(TObject *Sender)
{
    if (p->Left+p->Width<tlo->Width-10) p->Left+=10;

}
//---------------------------------------------------------------------------

void __fastcall TOkno::Button1Click(TObject *Sender)
{
     b->Left=100; b->Top=100;
     p->Left=320;
     b->Visible=true;
     x=-8;
     y=-8;
     Timer_pilka->Enabled=true;
     Button1->Visible=false;
     do_wygranej=19;
     Image1->Visible=true; Image5->Visible=true; Image9->Visible=true;
     Image2->Visible=true; Image6->Visible=true; Image10->Visible=true;
     Image3->Visible=true; Image7->Visible=true; Image11->Visible=true;
     Image4->Visible=true; Image8->Visible=true; Image12->Visible=true;
     Image13->Visible=true; Image14->Visible=true; Image15->Visible=true;
     Image16->Visible=true; Image17->Visible=true; Image18->Visible=true;
     Image19->Visible=true;

      points-> Visible=false;
      punkty=0;

}


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

