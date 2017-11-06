//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSave : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TEdit *Edit1;
	TMemo *Memo1;
	TSaveDialog *SaveDialog1;
	TProgressBar *ProgressBar1;
	TLabel *Label1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSave(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSave *FormSave;
//---------------------------------------------------------------------------
#endif
