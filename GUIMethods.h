//---------------------------------------------------------------------------

#ifndef GUIMethodsH
#define GUIMethodsH
#include "Unit1.h"

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	ClearPicture = new Graphics::TPicture;
	FCClicked=false;
	BCClicked=false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::PFrontGroundClick(TObject *Sender)
{
	FCClicked=true;
	BCClicked=false;
	Image1->Cursor = crCross;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::PBackGroundClick(TObject *Sender)
{
	FCClicked=false;
	BCClicked=true;
	Image1->Cursor = crCross;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
	if(ScrollBox1->Height > Image1->Height)
		Image1->Top = (ScrollBox1->Height - Image1->Height) / 2;
		else
		Image1->Top = 0;
	if(ScrollBox1->Width > Image1->Width)
		Image1->Left = (ScrollBox1->Width - Image1->Width) / 2;
		else
		Image1->Left = 0;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender) //Відпрацювання кліку по зображенню. Використовується для задання кольору фігури та фону
{
	if (FCClicked)
		PFrontGround->Color = Image1->Canvas->Pixels[MouseX][MouseY];
	if (BCClicked)
		PBackGround->Color = Image1->Canvas->Pixels[MouseX][MouseY];

	FCClicked=false;
	BCClicked=false;
	PClicked=false;
	Image1->Cursor = crDefault;
}

//---------------------------------------------------------------------------

int mx, my;
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X, //Відпрацювання положення курсору миші
		  int Y)
{
	MouseX=X;
	MouseY=Y;

	if (!FCClicked && !BCClicked && (ScrollBox1->Height < Image1->Height || ScrollBox1->Width < Image1->Width))
	Image1->Cursor = crSizeAll;

	if(PClicked)
		ScrollBox1->HorzScrollBar->Position -= X-mx;

	if(PClicked)
		ScrollBox1->VertScrollBar->Position -= Y-my;

}

//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	PClicked = true;
	mx = X; my = Y;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseLeave(TObject *Sender)
{
	PClicked = false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button_openMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	Button_open->Color=clInactiveCaptionText;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button_openMouseLeave(TObject *Sender)
{
	Button_open->Color=clBackground;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button_saveMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Button_save->Color=clInactiveCaptionText;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button_saveMouseLeave(TObject *Sender)
{
	Button_save->Color=clBackground;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button_helpMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Button_help->Color=clInactiveCaptionText;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button_helpMouseLeave(TObject *Sender)
{
	Button_help->Color=clBackground;
}


#endif
