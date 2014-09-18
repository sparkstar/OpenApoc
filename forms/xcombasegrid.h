#pragma once

#include "control.h"
#include <iostream>

class XComBaseGrid: public Control
{
	private:
		std::vector<int >* facilities;
		ALLEGRO_BITMAP* baseGridImage;
		ALLEGRO_BITMAP* baseFacilityImage;

		int GetGridX(int );
		int GetGridY(int );

		int GetGridXFromMouseVector(int );
		int GetGridYFromMouseVector(int );

	protected:
		virtual void OnRender();

	public:
		XComBaseGrid( Control* Owner );
		virtual ~XComBaseGrid();

		virtual void EventOccured( Event* e );
		virtual void Update();
		virtual void LoadResources();
		virtual void UnloadResources();
};

