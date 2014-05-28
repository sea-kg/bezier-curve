// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "seakgBezier.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

std::vector<coordPoint>user_points;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
  drawVector(user_points);
}

// ---------------------------------------------------------------------------

void TForm2::drawVector(std::vector<coordPoint> &vect) {

	// clear
	imgBezier->Canvas->Rectangle(0, 0, imgBezier->Width, imgBezier->Height);
	if (vect.size() == 0)
		return;

	// drawTops
	for (int i = 0; i < vect.size(); i++) {
		int w = 3;
		imgBezier->Canvas->Ellipse(vect[i].getX() - w, vect[i].getY() - w,
			vect[i].getX() + w, vect[i].getY() + w);
		imgBezier->Canvas->TextOutW(vect[i].getX() + w, vect[i].getY() + w,
			"p" + IntToStr(i));
	};

	seakgBezier bezier;
	bezier.calculate(vect, 4);
	std::vector<coordPoint>dest = bezier.getVectorBezier();
	// draw
	if (dest.size() > 1) {
		imgBezier->Canvas->MoveTo(dest[0].getX(), dest[0].getY());
		for (unsigned int i = 1; i < dest.size(); i++) {
			imgBezier->Canvas->LineTo(dest[i].getX(), dest[i].getY());
		};
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::btnRandomClick(TObject *Sender) {
	std::vector<coordPoint> random_points;

	// fill vector from random
	int max_x = imgBezier->Width - 40;
	int max_y = imgBezier->Height - 40;
	randomize();
	int count_point = random(8) + 3;
	for (int i = 0; i < count_point; i++) {
		int x = random(random(max_x)) + 20;
		int y = random(random(max_y)) + 20;
		coordPoint p(x, y);
		random_points.push_back(p);
	};
	drawVector(random_points);

}

// ---------------------------------------------------------------------------
void __fastcall TForm2::btnClearClick(TObject *Sender) {
	user_points.clear();
	drawVector(user_points);
}
// ---------------------------------------------------------------------------
void __fastcall TForm2::imgBezierMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	coordPoint p(X, Y);
	user_points.push_back(p);
	drawVector(user_points);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnDrawUsersPointsClick(TObject *Sender)
{
	drawVector(user_points);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnCloseClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

