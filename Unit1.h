//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *p;
        TImage *b;
        TTimer *Timer_pilka;
        TTimer *lewo;
        TTimer *prawo;

        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TImage *Image5;
        TImage *Image6;
        TImage *Image7;
        TImage *Image8;
        TImage *Image9;
        TImage *Image10;
        TImage *Image11;
        TImage *Image12;
        TButton *Button1;
        TShape *tlo;
        TImage *Image13;
        TImage *Image15;
        TImage *Image16;
        TImage *Image17;
        TImage *Image18;
        TImage *Image19;
        TImage *Image20;
        TImage *Image21;
        TLabel *points;
        TLabel *Best;
        TImage *Image14;
        TImage *Image22;
        TImage *Image23;
        TImage *Image24;
        TImage *Image25;
        TImage *Image26;
        TImage *star1;
        TTimer *Timer1;
        TShape *tlo2;
        TImage *tlo3;
        TImage *star2;
        TImage *star3;
        TImage *star4;
        TTimer *Timer2;
        TTimer *Timer3;
        TShape *tlo4;
   
        void __fastcall Timer_pilkaTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall lewoTimer(TObject *Sender);
        void __fastcall prawoTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall pointsClick(TObject *Sender);
        void __fastcall BestClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall Timer3Timer(TObject *Sender);
 
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
