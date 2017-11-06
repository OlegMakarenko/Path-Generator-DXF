//---------------------------------------------------------------------------

#ifndef PathH
#define PathH
#include <vector>
#include <Math.h>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>

class Path
{
public:
	Path();
	~Path();
	std::vector<int> getVectorX();
	std::vector<int> getVectorY();
	std::vector<int> getModifiedVectorX();
	std::vector<int> getModifiedVectorY();

	void clear();
	int read(TImage *image, TColor FigureColor, TColor BackgroundColor);
	void simplify(float eps);
	void show_original();
	void show_simplified();
private:
	std::vector<int> PathX;
	std::vector<int> PathY;
	std::vector<int> ModifiedPathX;
	std::vector<int> ModifiedPathY;
	TImage* image;
	TColor FigureColor;
	TColor BackgroundColor;

	bool LoopError();
	bool Begin();
	bool isBackground(int x, int y);
	bool isFigure(int x, int y);
	bool CanBePoint(int x, int y);
	bool FindNewPoint();


	float Delta(float Xa, float Ya, float Xb, float Yb, float Xc, float Yc);


};

namespace My
{
	class Graphics
	{
	public:
		static void Threshold(TImage *image, int value); //value [0; 255]
	};
}
#endif
