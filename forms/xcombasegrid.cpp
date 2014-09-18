#include "xcombasegrid.h"
#include "../framework/framework.h"
#include "../game/resources/gamecore.h"

const int WIDTH = 32;
const int HEIGHT = 32;
const int ROW = 8;
const int COL = 8;

const std::string pck_string_front = "PCK:UFODATA/BASE.PCK:UFODATA/BASE.TAB:";
const std::string pck_string_back = ":TACDATA/TACTICAL.PAL";

XComBaseGrid::XComBaseGrid(Control* Owner) : Control( Owner )
{
	this->facilities = new std::vector<int>(ROW * COL);
	LoadResources();
}

XComBaseGrid::~XComBaseGrid()
{

}

void XComBaseGrid::LoadResources()
{
	if ( baseGridImage == nullptr )
	{
		baseGridImage = al_create_bitmap(WIDTH * COL, HEIGHT * ROW);
	}

	if ( baseFacilityImage == nullptr )
	{
		baseFacilityImage = GAMECORE->GetImage(pck_string_front + "6" + pck_string_back);
	}

	std::cout << "baseGridImage is : " << baseGridImage << std::endl;
	std::cout << "baseFacilityImage is : " << baseFacilityImage << std::endl;

}

void XComBaseGrid::OnRender()
{
	if ( this->baseGridImage == nullptr || baseFacilityImage == nullptr )
	{
		return;
	}

	al_hold_bitmap_drawing(true);
	for ( int i = 0 ; i < ROW * COL ; i++ )
	{
		al_draw_bitmap_region(baseFacilityImage,
							  0,
							  0,
							  WIDTH,
							  HEIGHT,
							  GetGridX(i) * WIDTH,
							  GetGridY(i) * HEIGHT,
							  0);
	}
	al_hold_bitmap_drawing(false);
}

int XComBaseGrid::GetGridX(int num)
{
	return num / ROW;
}

int XComBaseGrid::GetGridY(int num)
{
	return num % ROW;
}

int XComBaseGrid::GetGridXFromMouseVector(int xPos)
{
	return xPos / WIDTH;
}

int XComBaseGrid::GetGridYFromMouseVector(int yPos)
{
	return yPos / HEIGHT;
}

void XComBaseGrid::EventOccured( Event* e )
{
	if( e->Data.Forms.EventFlag == FormEventType::MouseClick )
	{
		std::cerr << "click position on basegrid : " << "("
				  << e->Data.Mouse.X << ", " << e->Data.Mouse.Y << "), ("
				  << GetGridXFromMouseVector(e->Data.Mouse.X) << ", "
				  << GetGridYFromMouseVector(e->Data.Mouse.Y) << ")" << std::endl;
	}

	Control::EventOccured( e );
}

void XComBaseGrid::Update()
{
	Control::Update();
}

void XComBaseGrid::UnloadResources()
{
	if( baseGridImage != nullptr )
	{
		al_destroy_bitmap( baseGridImage );
		baseGridImage = nullptr;
	}
	if( baseFacilityImage != nullptr )
	{
		al_destroy_bitmap( baseFacilityImage );
		baseFacilityImage = nullptr;
	}
	delete facilities;
	Control::UnloadResources();
}
