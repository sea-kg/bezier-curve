// ---------------------------------------------------------------------------

#ifndef mainH
#define mainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "seakgBezier.h"

// ---------------------------------------------------------------------------
class TForm2 : public TForm {
__published: // IDE-managed Components

	TImage *imgBezier;
	TButton *btnRandom;
	TButton *btnClear;
	TButton *btnDrawUsersPoints;
	TButton *btnClose;

	void __fastcall btnRandomClick(TObject *Sender);
	void __fastcall btnClearClick(TObject *Sender);
	void __fastcall imgBezierMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btnDrawUsersPointsClick(TObject *Sender);
	void __fastcall btnCloseClick(TObject *Sender);

private: // User declarations
	void drawVector(std::vector<coordPoint> &vect);

public: // User declarations
	__fastcall TForm2(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
// ---------------------------------------------------------------------------
#endif
