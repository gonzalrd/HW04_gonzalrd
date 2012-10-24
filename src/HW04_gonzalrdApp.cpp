#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Starbucks.h"
#include <vector>


using namespace ci;
using namespace ci::app;
using namespace std;

class HW04_gonzalrdApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void read();
	

};


void HW04_gonzalrdApp::read()
{
	vector<Entry*> entries(10);
	
	ifstream in ("Starbucks_2006.csv");

	string line;
	double x;
	double y;

	for(int i = 0; i<=5; i++){
	getline(in , line, ',');
	in.get();
	in >> x;
	in.get();
	in >> y;

	Entry* newEntry = new Entry();
	
	newEntry->identifier = line;
	newEntry->x = x;
	newEntry->y = y;
	
	entries[i] = newEntry;
	

	}
	
}


void HW04_gonzalrdApp::setup()
{

	read();
}

void HW04_gonzalrdApp::mouseDown( MouseEvent event )
{
}

void HW04_gonzalrdApp::update()
{
}

void HW04_gonzalrdApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04_gonzalrdApp, RendererGl )
