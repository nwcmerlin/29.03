#include <iostream>
#include <windows.h>

using namespace std;
  /*ѕ–ј “» ј1:
   добавить ещЄ один класс - наследник фигуры, Ellipse.

   создать объект такого типа(Ёллипс), вызвать дл€ него метод Draw

   добавить в базовый класс ‘игуры пол€ borderColor и fillColor(цвет контура и цвет заливки),

   дл€ этих полей сделать геттеры и сеттеры.*/
class Figure abstract
{
protected:
    int x;
    int y;
    string borderColor;
    string fillColor;
public:
    Figure(int x = 0, int y = 0, string borderColor = "", string fillColor = "")
    {
        this->x = x;
        this->y = y;
        this->borderColor = borderColor;
        this->fillColor = fillColor;
    }

    void SetX(int x)
    {
        this->x = x;
    }

    void SetY(int y)
    {
        this->y = y;
    }

    void SetFillColor(string fillColor)
    {
        this->fillColor = fillColor;
    }

    void SetBorderColor(string borderColor)
    {
        this->borderColor = borderColor;
    }

    int GetX() const
    {
        return x;
    }

    int GetY() const
    {
        return y;
    }

    string GetBorderColor() const
    {
        return borderColor;
    }

    string GetFillColor() const
    {
        return fillColor;
    }

    // чисто виртуальный метод
    virtual void Draw() = 0;
    virtual double GetSquare() = 0;
    virtual double GetPerimeter() = 0;
};

class MyRectangle : public Figure
{
protected:
    int x2;
    int y2;
    string borderColor;
    string fillColor;

public:
    MyRectangle(int x = 0, int y = 0, int x2 = 0, int y2 = 0, string borderColor = "", string fillColor = "") : Figure(x, y)
    {
        this->x2 = x2;
        this->y2 = y2;
        this->borderColor = borderColor;
        this->fillColor = fillColor;
    }

    void SetX2(int x2)
    {
        this->x2 = x2;
    }

    void SetY2(int y2)
    {
        this->y2 = y2;
    }

    void SetFillColor(string fillColor)
    {
        this->fillColor = fillColor;
    }

    void SetBorderColor(string borderColor)
    {
        this->borderColor = borderColor;
    }


    int GetX2() const
    {
        return x2;
    }

    int GetY2() const
    {
        return y2;
    }


    string GetBorderColor() const
    {
        return borderColor;
    }

    string GetFillColor() const
    {
        return fillColor;
    }

    virtual void Draw() override
    {
        int height = abs(y2 - y);
        int width = abs(x2 - x);

        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                cout << "#";
            }
            cout << "\n";
        }
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (GetFillColor() == "Red")
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        }
        else if (GetFillColor() == "Green")
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        }
        cout << "Rectangle with " << GetFillColor() << " fill color\n";
        if (GetBorderColor() == "Red")
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        }
        else if (GetBorderColor() == "Green")
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        }
        cout << GetBorderColor() << " border color\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    virtual double GetSquare() override
    {
        return abs(y2 - y) * abs(x2 - 2);
    }
    virtual double GetPerimeter() override
    {
        return abs(y2 - y) * 2 + abs(x2 - 2) * 2;
    }
};

class MyEllipse : public Figure
{
protected:
    int x2;
    int y2;
    string borderColor;
    string fillColor;

public:
    MyEllipse(int x = 0, int y = 0, int x2 = 0, int y2 = 0, string borderColor = "", string fillColor = "") : Figure(x, y)
    {
        this->x2 = x2;
        this->y2 = y2;
        this->borderColor = borderColor;
        this->fillColor = fillColor;
    }

    void SetX2(int x2)
    {
        this->x2 = x2;
    }

    void SetY2(int y2)
    {
        this->y2 = y2;
    }

    void SetFillColor(string fillColor)
    {
        this->fillColor = fillColor;
    }

    void SetBorderColor(string borderColor)
    {
        this->borderColor = borderColor;
    }

    int GetX2() const
    {
        return x2;
    }

    int GetY2() const
    {
        return y2;
    }

    string GetBorderColor() const
    {
        return borderColor;
    }

    string GetFillColor() const
    {
        return fillColor;
    }virtual void Draw() override
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (GetFillColor() == "Red")
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        }
        else if (GetFillColor() == "Green")
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        }
        cout << "Ellipse with " << GetFillColor() << " fill color\n";
        if (GetBorderColor() == "Red")
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        }
        else if (GetBorderColor() == "Green")
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        }
        cout << GetBorderColor() << " border color\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
       /*ѕ–ј “» ј2:

        добавить ‘игуре чисто виртуальные методы GetSquare и 
        
        GetPerimeter(получить площадь и периметр).

        в классах - наследниках(ѕр€моугольник и Ёллипс) переопределить эти методы.*/
    virtual double GetSquare() override
    {
        return abs(y2) * abs(x2 / 2) * 3.14;
    }
    virtual double GetPerimeter() override
    {
        return 3.14 * (x2 + y2 / 2) * (1 + ((3 * pow((x2 - y2 / 2) / (x2 + y2 / 2), 2)) / (10 + sqrt(4 - (3 * pow((x2 - y2 / 2) / (x2 + y2 / 2), 2))))));
    }
};

int main()
{
    // Figure f; // C3622: класс, объ€вленный как "abstract", не предусматривает создание экземпл€ров
    MyRectangle r(5, 5, 20, 10, "Red", "Green"); // Red, or Green, or Blue
    r.Draw();
    MyEllipse e(10, 10, 20, 20, "Green", "Blue");// Red, or Green, or Blue
    e.Draw();
    cout << "Perimeter: " << r.GetPerimeter() << "\nSquare: " << r.GetSquare() << endl;
    cout << "Perimeter: " << e.GetPerimeter() << "\nSquare: " << e.GetSquare();
}