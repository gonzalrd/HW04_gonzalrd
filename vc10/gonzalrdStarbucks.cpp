#pragma once
#include "gonzalrdStarbucks.h"


	
 void gonzalrdStarbucks::build(Entry* c, int n){
	
	 entries = new Entry[n];

	 entries[1] = c[1]; //move over the first

	 for(int i = 1; i<n; i++){
		 double xoffset = abs(c[i-1].x - c[i].x);
		 double yoffset = abs(c[i-1].y - c[i].y);

		 if(xoffset > 0.00001 && yoffset > 0.00001){
			 entries[i] = c[i];
		 }
	 }
	
	}

Entry*  gonzalrdStarbucks::getNearest(double x, double y){


}




