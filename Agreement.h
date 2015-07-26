//---------------------------------------------------------------------------
#ifndef AgreementH
#define AgreementH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TAgreementForm : public TForm
{
__published:	// IDE-managed Components
    TMemo *Memo;
    TRadioButton *AgreeYes;
    TRadioButton *AgreeNo;
    TButton *Cancel;
    TButton *Next;
    void __fastcall AgreeNoClick(TObject *Sender);
    void __fastcall AgreeYesClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TAgreementForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAgreementForm *AgreementForm;
//---------------------------------------------------------------------------
#endif
