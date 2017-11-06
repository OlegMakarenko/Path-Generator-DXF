//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ComCtrls.hpp>
#include <Graphics.hpp>
//------------------------
#include "Path.h"
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Header;
	TPanel *Body;
	TPanel *Menu;
	TButton *Button2;
	TOpenPictureDialog *OpenPictureDialog1;
	TScrollBox *ScrollBox1;
	TImage *Image1;
	TPanel *PFrontGround;
	TPanel *PBackGround;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TMemo *Memo1;
	TPanel *PanelFirst;
	TPanel *PanelSecond;
	TLabel *Label4;
	TLabel *Label6;
	TTrackBar *TrackBar1;
	TPanel *Footer;
	TPanel *Button_open;
	TPanel *Button_save;
	TImage *get_started;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TPanel *OlegMakarenko;
	TEdit *Edit_simplypoints;
	TEdit *Edit_simplylevel;
	TLabel *Label7;
	TLabel *Label8;
	TGroupBox *GroupBox1;
	TButton *Button1;
	TPanel *Button_help;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall PFrontGroundClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PBackGroundClick(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall Button_openClick(TObject *Sender);
	void __fastcall Button_saveClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseLeave(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Button_openMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall Button_openMouseLeave(TObject *Sender);
	void __fastcall Button_saveMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall Button_saveMouseLeave(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button_helpMouseLeave(TObject *Sender);
	void __fastcall Button_helpMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall Button_helpClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	Path path;
	int FindLight();
	int FindDark();
	int MouseX;
	int MouseY;

	String PictureFilename;
	int Radius;
	int Range;
	TPicture* ClearPicture;
	TColor FigureColor;
	TColor BackColor;
	bool FCClicked;
	bool BCClicked;
	bool PClicked;


	float eps;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
