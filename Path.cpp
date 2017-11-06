//---------------------------------------------------------------------------


#pragma hdrstop

#include "Path.h"

Path::Path()
{
}


Path::~Path()
{
}

std::vector<int> Path::getVectorX()
{
	return PathX;
}
std::vector<int> Path::getVectorY()
{
	return PathY;
}
std::vector<int> Path::getModifiedVectorX()
{
	return ModifiedPathX;
}
std::vector<int> Path::getModifiedVectorY()
{
	return ModifiedPathY;
}


bool Path::LoopError()
{
	for (int i = 2; i < PathX.size() / 2; i++)
		if(PathX[PathX.size()-1] == PathX[i] && PathY[PathY.size() - 1] == PathY[i])
		{
			ShowMessage(FloatToStr(PathX.size()-1)+" == "+FloatToStr(i));
			return 1;
		}

	return 0;
}

void Path::clear()
{
	PathX.clear();
	PathY.clear();
	ModifiedPathX.clear();
	ModifiedPathY.clear();
}


int Path::read(TImage *image, TColor FigureColor, TColor BackgroundColor)
{
	this->image = image;
	this->FigureColor = FigureColor;
	this->BackgroundColor = BackgroundColor;

	if (Begin())
		while (FindNewPoint())
		{
			if (PathX[PathX.size() - 1] == PathX[2] && PathY[PathY.size() - 1] == PathY[2] && PathX.size() - 1 != 2)
				break;
			if (LoopError())
			   	return 2;
		}
	else
		return 1;
	return 0;
}

void Path::show_original()
{
	for (int i = 0; i < PathX.size(); i++)
	{
		image->Canvas->Pen->Width = 1;
		image->Canvas->Pen->Color = clRed;
		image->Canvas->Ellipse(PathX[i] - 1, PathY[i] - 1, PathX[i] + 2, PathY[i] + 2);
	}
}

void Path::show_simplified()
{
	for (int i = 0; i < ModifiedPathX.size(); i++)
	{
		image->Canvas->Pen->Width = 1;
		image->Canvas->Pen->Color = clBlue;
		if (i + 1 != ModifiedPathX.size())
		{
			image->Canvas->MoveTo(ModifiedPathX[i], ModifiedPathY[i]);
			image->Canvas->LineTo(ModifiedPathX[i + 1], ModifiedPathY[i + 1]);
		}
		else
		{
			image->Canvas->MoveTo(ModifiedPathX[i], ModifiedPathY[i]);
			image->Canvas->LineTo(ModifiedPathX[0], ModifiedPathY[0]);
		}
		image->Canvas->Pen->Width = 4;
		image->Canvas->Pen->Color = clRed;
		image->Canvas->Ellipse(ModifiedPathX[i] - 1, ModifiedPathY[i] - 1, ModifiedPathX[i] + 2, ModifiedPathY[i] + 2);
	}
}

bool Path::Begin()
{
	for (int i = 0; i < image->Height; i++)
		for (int j = 0; j < image->Width; j++)
			if (isFigure(j, i))
			{
				PathX.push_back(j);
				PathX.push_back(j);
				PathY.push_back(i);
				PathY.push_back(i);
				return 1;
			}
	return 0;
}

bool Path::isBackground(int x, int y)
{
	if (image->Canvas->Pixels[x][y] == BackgroundColor)
		return true;
	else
		return false;
}

bool Path::isFigure(int x, int y)
{
	if (image->Canvas->Pixels[x][y] == FigureColor)
		return true;
	else
		return false;
}

bool Path::CanBePoint(int x, int y)
{
	bool Requirement1 = false;  //умова, що потенційна нова точка кольору фігури
	bool Requirement2 = false;  //умова, що поряд з потенційною новою точкою знаходится точка кольору фону
	bool Requirement3 = false;  //умова, що потенційна нова точка не є поточною точкою контуру
	bool Requirement4 = false;  //умова, що потенційна нова точка не є попередньою точкою контуру

	if (isFigure(x, y))
		Requirement1 = true;

	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if (isBackground(i, j))
				Requirement2 = true;

	if (!(PathX[PathX.size() - 1] == x && PathY[PathY.size() - 1] == y))
		Requirement3 = true;

	if (!(PathX[PathX.size() - 2] == x && PathY[PathY.size() - 2] == y))
		Requirement4 = true;

	if (Requirement1 && Requirement2 && Requirement3 && Requirement4)
		return 1;
	else
		return 0;
}

bool Path::FindNewPoint()
{
	float matrix[2][8];
	bool isNewPoint = 0;
	float newX = 0; //Нова точка. Координата Х
	float newY = 0; //Нова точка. Координата У
	int NewCounter = 0;
	float NewPoints[2][8]; //Масив під потенційні нові точки
	matrix[0][0] = PathX[PathX.size() - 1] - 1;
	matrix[0][1] = PathX[PathX.size() - 1] - 1;
	matrix[0][2] = PathX[PathX.size() - 1] - 1;
	matrix[0][3] = PathX[PathX.size() - 1];
	matrix[0][4] = PathX[PathX.size() - 1] + 1;
	matrix[0][5] = PathX[PathX.size() - 1] + 1;
	matrix[0][6] = PathX[PathX.size() - 1] + 1;
	matrix[0][7] = PathX[PathX.size() - 1];

	matrix[1][0] = PathY[PathY.size() - 1] - 1;
	matrix[1][1] = PathY[PathY.size() - 1];
	matrix[1][2] = PathY[PathY.size() - 1] + 1;
	matrix[1][3] = PathY[PathY.size() - 1] + 1;
	matrix[1][4] = PathY[PathY.size() - 1] + 1;
	matrix[1][5] = PathY[PathY.size() - 1];
	matrix[1][6] = PathY[PathY.size() - 1] - 1;
	matrix[1][7] = PathY[PathY.size() - 1] - 1;

	for (int i = 0; i < 8; i++)
	{
		if (CanBePoint(matrix[0][i], matrix[1][i]))
		{
			NewPoints[0][NewCounter] = matrix[0][i];
			NewPoints[1][NewCounter] = matrix[1][i];
			NewCounter++;
			isNewPoint = 1;
		}
	}

	if (isNewPoint)
		for (int i = 0; i < NewCounter; i++)  //Визначення та задання нової точки з масиву потенційних точок. Критерієм відбору є умова, що нова точка повинна бути сусідньою з поточною точкою по горизонталі, або вертикалі, а не по діагоналі. Але якщо ж умова не виконується, вибирається найперша точка з масиву потенційних точок (та, що знаходиться по діагоналі)
		{
			if (PathX[PathX.size() - 1] == NewPoints[0][i] || PathY[PathY.size() - 1] == NewPoints[1][i])
			{
				newX = NewPoints[0][i];
				newY = NewPoints[1][i];
				break;
			}
			else
			{
				newX = NewPoints[0][0];
				newY = NewPoints[1][0];
			}
		}

	if (isNewPoint)
	{
		PathX.push_back(newX);  //Додання нової точки (координата Х) до масиву точок контуру
		PathY.push_back(newY);  // -//- У
		return 1;
	}
	else
		return 0;
}


void Path::simplify(float eps)
{
	ModifiedPathX.clear();
	ModifiedPathY.clear();
	int N = PathX.size() - 1;
	int i, j, p, q, t;
	float D;
	i = 0; j = 1; p = 2; t = 0;
	ModifiedPathX.push_back(PathX[0]);
	ModifiedPathY.push_back(PathY[0]);

	while (p < N)
	{
		for (q = j; q < p; q++)
		{
			D = Delta(PathX[i], PathY[i], PathX[p], PathY[p], PathX[q], PathY[q]);
			if (D>eps)
			{
				ModifiedPathX.push_back(PathX[p - 1]);
				ModifiedPathY.push_back(PathY[p - 1]);
				i = p - 1; j = p; p++; t = 0;
				break;
			}
			else t++;
		}
		if (t == p - i - 1)
		{
			p++; t = 0;
		}
	}
	ModifiedPathX.push_back(PathX[N - 1]);
	ModifiedPathY.push_back(PathY[N - 1]);
}


float Path::Delta(float Xa, float Ya, float Xb, float Yb, float Xc, float Yc)
{
	double A, B, C, D, R1, R2;
	A = Yb - Ya;
	B = Xa - Xb;
	C = Xb*Ya - Xa*Yb;
	R1 = fabs(A*Xc + B*Yc + C);
	R2 = powl((A*A + B*B), 0.5);
	D = R1 / R2;
	//D=fabs(A*Xa+B*Ya+C)/powl((A*A+B*B),0.5);

	return D;
}

void My::Graphics::Threshold(TImage *image, int value)
{
	int R = 0;
	int G = 0;
	int B = 0;
	int color = 0;
	for (int x = 0; x < image->Width; x++)
		for (int y = 0; y < image->Height; y++)
		{
			R = GetRValue(image->Canvas->Pixels[x][y]);
			G = GetGValue(image->Canvas->Pixels[x][y]);
			B = GetBValue(image->Canvas->Pixels[x][y]);
			color = (R + G + B) / 3;
			if (color <= value)
				image->Canvas->Pixels[x][y] = (TColor)RGB(0, 0, 0);
			else
				image->Canvas->Pixels[x][y] = (TColor)RGB(255, 255, 255);
		}
}
#pragma package(smart_init)
