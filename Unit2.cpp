//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "String.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSave *FormSave;
//---------------------------------------------------------------------------
__fastcall TFormSave::TFormSave(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void Line(float x1, float y1, float x2, float y2)
{
	 FormSave->Memo1->Lines->Add("0");
	 FormSave->Memo1->Lines->Add("LINE");
	 FormSave->Memo1->Lines->Add("8");
	 FormSave->Memo1->Lines->Add("Polygon");

	 FormSave->Memo1->Lines->Add("10");
	 FormSave->Memo1->Lines->Add(FloatToStr(x1)+".0");
	 FormSave->Memo1->Lines->Add("20");
	 FormSave->Memo1->Lines->Add(FloatToStr(y1)+".0");
	 FormSave->Memo1->Lines->Add("30");
	 FormSave->Memo1->Lines->Add("0.0");
	 FormSave->Memo1->Lines->Add("11");
	 FormSave->Memo1->Lines->Add(FloatToStr(x2)+".0");
	 FormSave->Memo1->Lines->Add("21");
	 FormSave->Memo1->Lines->Add(FloatToStr(y2)+".0");
	 FormSave->Memo1->Lines->Add("31");
	 FormSave->Memo1->Lines->Add("0.0");

}

void WriteFile(std::vector<int> ArrX, std::vector<int> ArrY)
{
	 int count=ArrX.size() - 1;

	 FormSave->Memo1->Lines->Add("0");
	 FormSave->Memo1->Lines->Add("SECTION");
	 FormSave->Memo1->Lines->Add("2");
	 FormSave->Memo1->Lines->Add("ENTITIES");

	 for(int i=0; i<count; i++)
	 {
	 if(i==count-1)
	 Line(ArrX[i],ArrY[i],ArrX[0],ArrY[0]);
	 else
	 Line(ArrX[i],ArrY[i],ArrX[i+1],ArrY[i+1]);
	 }

	 FormSave->Memo1->Lines->Add("0");
	 FormSave->Memo1->Lines->Add("ENDSEC");
	 FormSave->Memo1->Lines->Add("0");
	 FormSave->Memo1->Lines->Add("EOF");


}

bool Save(String FileName)
{
	if (Form1->CheckBox2->Checked)
		WriteFile(Form1->path.getModifiedVectorX(), Form1->path.getModifiedVectorY());
	else
		WriteFile(Form1->path.getVectorX(), Form1->path.getVectorY());

	FormSave->Memo1->Lines->SaveToFile(FileName + ".dxf");
}
void __fastcall TFormSave::FormShow(TObject *Sender)
{
	if (Form1->CheckBox2->Checked)
	Edit1->Text=Form1->eps;
	else
	Edit1->Text = FloatToStr(0);
}
//---------------------------------------------------------------------------
void __fastcall TFormSave::Button1Click(TObject *Sender)
{
	ProgressBar1->Visible=true;
	if (SaveDialog1->Execute())
	{
	Save(SaveDialog1->FileName);
	}
	FormSave->Hide();
}
//---------------------------------------------------------------------------


