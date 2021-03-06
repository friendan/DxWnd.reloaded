#include <windows.h>
#include "syslibs.h"

typedef enum {
	VIRTUAL_UNDEFINED = 0,
	VIRTUAL_ON_WINDOW,
	VIRTUAL_ON_DDRAW,
	VIRTUAL_ON_D3D,
	VIRTUAL_ON_OPENGL,
	VIRTUAL_ERROR
} Virtual_type;

class dxwSDC
{
// Construction/destruction
public:
    dxwSDC();
    virtual ~dxwSDC();

// Operations
public: // methods
	HDC		GetPrimaryDC(HDC);
	HDC		GetPrimaryDC(HDC, HDC);
	HDC		GetHdc(void);
	BOOL	PutPrimaryDC(HDC, BOOL, int, int, int, int);
	BOOL	PutPrimaryDC(HDC, BOOL);
	void	SetOrigin(int, int);

private:
	void copyDcAttributes(HDC, HDC, POINT);
	void setClippingRegion(HDC, HDC, POINT);

	HDC PrimaryDC;
	HDC VirtualHDC;
	HDC CurrentHDC;
	HDC CurrentHDCSrc;
	HWND CurrenthWnd;
	LPDIRECTDRAWSURFACE lpDDSPrimary;
	HBITMAP VirtualPic;
	HGDIOBJ origFont;
	HGDIOBJ origBrush;
	HGDIOBJ origPen;
	POINT WinOffset;
	POINT VirtualOffset;
	int ScreenWidth, ScreenHeight;
	int LastScreenWidth, LastScreenHeight;
	HDC LastHDC;
	Virtual_type VirtualSurfaceType;
	struct ExcludeClipRectsData
	{
		HDC compatDc;
		POINT origin;
		HWND rootWnd;
	};
	int HybridX;
	int HybridY;

};

extern dxwSDC sdc;