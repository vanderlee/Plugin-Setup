//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Agreement.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAgreementForm *AgreementForm;
//---------------------------------------------------------------------------
__fastcall TAgreementForm::TAgreementForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAgreementForm::AgreeNoClick(TObject *Sender)
{
    AgreeYes->Checked   = false;
    Next->Enabled       = false;
}
//---------------------------------------------------------------------------
void __fastcall TAgreementForm::AgreeYesClick(TObject *Sender)
{
    AgreeNo->Checked    = false;
    Next->Enabled       = true;
}
//---------------------------------------------------------------------------


