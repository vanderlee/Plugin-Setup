//---------------------------------------------------------------------------
#ifndef ScanProgressH
#define ScanProgressH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TScanProgressForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Drive;
private:	// User declarations
public:		// User declarations
    __fastcall TScanProgressForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TScanProgressForm *ScanProgressForm;
//---------------------------------------------------------------------------
#endif
