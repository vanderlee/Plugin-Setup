//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <checklst.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *Status;
	TPanel *Panel1;
	TLabel *Title;
	TLabel *Version;
	TLabel *Text;
    TEdit *Custom;
	TCheckBox *DoCustom;
	TSpeedButton *Browse;
	TButton *Cancel;
	TButton *Install;
    TSpeedButton *Rescan;
	TSpeedButton *Copyright;
	TCheckListBox *Detected;
	TPanel *ImagePanel;
	TImage *Image;
    void __fastcall BrowseClick(TObject *Sender);
    void __fastcall CancelClick(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall InstallClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall DetectedMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall RescanClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
	void __fastcall CopyrightClick(TObject *Sender);
    void __fastcall ImageClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void __fastcall         ShowStatusHint(TObject *Sender);
    void __fastcall         SetupWindow(void);
    AnsiString __fastcall   GetRegistryString(HKEY asRootKey, AnsiString asDir,
                                              AnsiString asKey);
    void __fastcall         SetTemp(AnsiString asKey, AnsiString asValue);
    void __fastcall         DeleteAllTemp(void);
    void __fastcall         CopyFiles(int iApp);
    AnsiString __fastcall   GetIni(AnsiString asSection, AnsiString asKey);
    AnsiString __fastcall   GetIniDefault(AnsiString asSection, AnsiString asKey, AnsiString);
    bool __fastcall         CheckEnabled(int iApp);
//Pre-detecting specific applications
    void __fastcall         DetectAll(void);
    void __fastcall         DetectApplication(int iApp);
    void __fastcall         DetectFreehand8(void);
    void __fastcall         DetectPhotoline5(void);
    void __fastcall         DetectPhotodraw2000(void);
    void __fastcall         DetectPhotoPaint9(void);
    void __fastcall         DetectPhotoPaint12(void);
    void __fastcall         DetectPhotoImpact(void);
    void __fastcall         DetectPainter(void);
    void __fastcall         DetectFireworks(void);
    void __fastcall         DetectCanvas(void);
	void __fastcall		    DetectXaraXtreme(void);
    void __fastcall         ScanForFiles(void);
    bool __fastcall         FileScan(AnsiString asPath, int iDepth, TSearchRec srFind);
    void __fastcall         CheckFile(AnsiString asPath, AnsiString asFile);
//End of predetection
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
