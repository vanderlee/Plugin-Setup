//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Progress.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProgressForm *ProgressForm;
//---------------------------------------------------------------------------
__fastcall TProgressForm::TProgressForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
