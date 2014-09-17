#include "xcombasegrid.h"
#include "../framework/framework.h"
#include "../game/resources/gamecore.h"

const int WIDTH = 32;
const int HEIGHT = 32;
const int ROW = 8;
const int COL = 8;

const std::string pck_string_front = "PCK:UFODATA/NEWBUT.PCK:UFODATA/NEWBUT.TAB:";
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
		al_set_target_bitmap(baseGridImage);
		al_clear_to_color(al_map_rgba(0, 0, 0, 0));
	}
}

void XComBaseGrid::OnRender()
{
	if ( this->baseGridImage == nullptr )
	{
		return;
	}

	for (auto i = 0 ; i < COL ; i++) {
		for (auto j = 0 ; j < ROW ; j++) {
			auto idx = i * COL + j;
			auto sx = 0;
			auto sy = 0;
			auto sw = WIDTH;
			auto sh = HEIGHT;
			auto dx = i * WIDTH;
			auto dy = j * HEIGHT;
			auto facility = this->facilities->at(idx);
			auto facility_image = GAMECORE->GetImage(pck_string_front + std::to_string(facility) + pck_string_back);

			al_draw_bitmap_region(facility_image, sx, sy, sw, sh, dx, dy, 0);
		}
	}


}

void XComBaseGrid::EventOccured( Event* e )
{
	Control::EventOccured( e );
}

void XComBaseGrid::Update()
{
	Control::Update();
}

void XComBaseGrid::UnloadResources()
{
	Control::UnloadResources();
}
