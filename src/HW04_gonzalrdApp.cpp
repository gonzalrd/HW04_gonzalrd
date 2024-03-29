
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Starbucks.h"
#include "../vc10/gonzalrdStarbucks.h"



using namespace ci;
using namespace ci::app;
using namespace std;


class HW04_gonzalrdApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	Entry*read();
	int size;
	

};

Entry* HW04_gonzalrdApp::read()
{
	
	Entry* entries = new Entry[size];
	
	ifstream in ("Starbucks_2006.csv");

	string line;
	double x;
	double y;
	int i = 0;
	
	
	while(!in.eof()){
	
	getline(in , line, ',');
	in.get();
	in >> x;
	in.get();
	in >> y;

	entries[i].identifier = line;
	entries[i].x =x;
	entries[i].y = y;

	i++;
	
	
}

	return entries;
	
}


void HW04_gonzalrdApp::setup()
{
	gonzalrdStarbucks star;
	size = 7655; //temporary solution

	Entry* mylocs = read();

	star.build(mylocs,size);

	Entry* BEST = star.getNearest(.534, .345);

	

	
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
