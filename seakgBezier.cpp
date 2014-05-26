#include <math.h>
#include <vcl.h>
#include <vector.h>

/*
  this is code work for c++ builder 6. (and may be later)
*/

//helper class
class coordPoint
{
    public:
        coordPoint() : x(0), y(0) {};
        coordPoint(double X, double Y) : x(X), y(Y) {};

        void setXY(double X, double Y) { x = X; y = Y; };
        void setX(double X) { x = X; };
        void setY(double Y) { y = Y; };
        double getX() { return x; };
        double getY() { return y; };
        //--------------------------------------------------------------------
        double lengthTo(double X, double Y)
        {
            double dX = X - x, dY = Y - y;
            if( ( dX == 0 ) && ( dY == 0 ) ) return 0;
            return sqrt(dX*dX + dY*dY);
        };
        //--------------------------------------------------------------------
        double lengthTo(coordPoint p)
        {
            return lengthTo(p.getX(), p.getY());
        };
        //--------------------------------------------------------------------
        coordPoint midpointLine(coordPoint toPoint)
        {
            coordPoint point;
            point.setX( (toPoint.getX() - x) / 2.0 + x);
            point.setY( (toPoint.getY() - y) / 2.0 + y);
            return point;
        };
    private:
        double x,y;
};

//impl class:
class seakgBezier
{
    public:
        void draw(TCanvas *canvas)
        {
            canvas->MoveTo( dest[0].getX(), dest[0].getY());
            for(unsigned int i = 1; i < dest.size(); i++)
            {
                canvas->LineTo( dest[i].getX(), dest[i].getY() );
            };
        };
        vector<coordPoint> &getVectorBezier()
        {
            return dest;
        };
        bool calculate(vector<coordPoint> &points, int max)
        {
            if(points.size() < 2) return false;
            dest.clear();
            recurs(points, 0, max);
            return true;
        };
    private:
        vector<coordPoint> dest;
        void recurs(vector<coordPoint> points, int sch, int max)
        {
            if(sch <= max)
            {
                vector<coordPoint> left, right, buf1, buf2;
                //записываем крайние точки изначального вектора
                left.push_back( points[0] );
                right.push_back( points[points.size() - 1] );
                //рассчитываем половинные значения
                unsigned int pointsSize = points.size();
                for(unsigned int i = 1; i < pointsSize; i++)
                {
                    buf2.clear();
                    for(unsigned int b1 = 0; b1 < points.size() - 1; b1++)
                        buf2.push_back(points[b1].midpointLine( points[b1 + 1] ));
                    //записываем крайние точки
                    left.push_back( buf2[0] );
                    right.push_back( buf2[ buf2.size() - 1 ] );
                    //копируем из buf2 в points
                    points.clear();
                    for(unsigned int i = 0; i < buf2.size(); i++)
                        points.push_back( buf2[i] );
                };
                //инвертируем вектор right
                buf2.clear();
                for(unsigned int i = 0; i < right.size() ; i++)
                    buf2.push_back( right[right.size() - i - 1] );
                //вызываем следующие функцию
                sch++;
                recurs( left, sch, max);
                recurs( buf2, sch, max);
            }
            else
            {
                //записываем результат
                for(unsigned int i = 0; i < points.size(); i++)
                    dest.push_back(points[i]);
            };
        };
};


//example usage
/*
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    vector<coordPoint> random_points;


    //заполняем массив случайными значениями
    int max_x = Image1->Width - 40;
    int max_y = Image1->Height - 40;
    randomize();
    int count_point = random(12) + 3;
    for(int i = 0; i < count_point; i++)
    {
        int x = random(random(max_x)) + 20;
        int y = random(random(max_y)) + 20;

        coordPoint p( x, y );
        drawTop(Image1, p, 3, "p" + IntToStr(i) );
        random_points.push_back(p);
    };

   
    seakgBezier bezier;
    bezier.calculate(random_points,4);
    bezier.draw(Image1->Canvas);
}
*/
