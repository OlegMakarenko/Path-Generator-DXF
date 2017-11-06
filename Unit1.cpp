//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "GUIMethods.h";

#include <Math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm1::Button_openClick(TObject *Sender)//Кнопка відкриття растрового зображення
{
	if(OpenPictureDialog1->Execute())
	{
		path.clear();
				
		PictureFilename = OpenPictureDialog1->FileName;
		ClearPicture->LoadFromFile(PictureFilename);
		Image1->Picture = ClearPicture;
		
		Menu->Visible=true;
		PanelFirst->Visible=true;
		PanelSecond->Visible=false;
		get_started->Visible=false;
		Button_save->Visible=false;
	}
	if(ScrollBox1->Height > Image1->Height)
		Image1->Top = (ScrollBox1->Height - Image1->Height) / 2;
		else
		Image1->Top = 0;
	if(ScrollBox1->Width > Image1->Width)
		Image1->Left = (ScrollBox1->Width - Image1->Width) / 2;
		else
		Image1->Left = 0;
}

void __fastcall TForm1::Button_saveClick(TObject *Sender)
{
	FormSave->Show();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) //Кнопка запуску зчитування контуру
{
	int error = path.read(Image1, PFrontGround->Color, PBackGround->Color);
	if (!error) 
	{
		path.show_original();

		PanelFirst->Visible=false;
		PanelSecond->Visible=true;
		Button_save->Visible=true;
		TrackBar1->Position = 0;
	}
	else if (error == 1)
	{
		ShowMessage("Error:\nUnable to generate a path \n\nSolution:\nTry to change a color of the figure and/or background");
	}
	else if (error == 2)
	{
		ShowMessage("Error:\nUnable to generate a path \n\nSolution:\nTry another image. Figure should be one color");
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)//Показати / приховати контур на зображенні
{
	if (CheckBox1->Checked) 
	{
		path.show_original();
		
		CheckBox2->Enabled=true;
		TrackBar1->Position = 0;	
	}
	else
	{
		Image1->Picture = ClearPicture;
		CheckBox2->Enabled=false;	
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox2Click(TObject *Sender)//Дозволити / заборонити упрощення контуру
{
	if (CheckBox2->Checked) 
	{
		TrackBar1->Position = 0;
		TrackBar1->Enabled=true;
		Edit_simplylevel->Color = clGrayText;
		Edit_simplypoints->Color = clGrayText;	
	}
	else
	{
		path.show_original();
		
		Edit_simplylevel->Color = clMedGray;
		Edit_simplypoints->Color = clMedGray;
		TrackBar1->Position = 0;
		TrackBar1->Enabled = false;
		Image1->Picture = ClearPicture;
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)//Зміна рівня зпрощення контуру
{
	eps=TrackBar1->Position;
	path.simplify(eps);
	path.show_simplified();
	
	Image1->Picture = ClearPicture;
	Edit_simplylevel->Text = FloatToStr(eps);
	Edit_simplypoints->Text = FloatToStr(path.getModifiedVectorX().size());
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)//Застосувати подифікатор "Threshold" до растрового зображення
{
	My::Graphics::Threshold(Image1, 127);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button_helpClick(TObject *Sender)//Відкрити довідку
{
	ShowMessage("Developed by Oleh Makarenko\n  olegmakarenko.at.ua\n  e-mail: olegomm@gmail.com\n\n-- Image requirement --\nImage must be in bitmap file format;\nImage should be bicolor witout noise.");	
}

//---------------------------------------------------------------------------


