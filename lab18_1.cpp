#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect &r1, Rect &r2){
	
	double start_vertex_x_of_r1 = r1.x;
	double start_vertex_x_of_r2 = r2.x;
	double end_vertex_x_of_r1 = r1.x + r1.w;
	double end_vertex_x_of_r2 = r2.x + r2.w;
	double rightmost_start_vertex_x = max(start_vertex_x_of_r1, start_vertex_x_of_r2);
	double leftmost_end_vertex_x = min(end_vertex_x_of_r1, end_vertex_x_of_r2);
	
	double overlap_width_x = leftmost_end_vertex_x - rightmost_start_vertex_x;
	if (overlap_width_x <= 0){
		return 0;
	}
	
	double start_vertex_y_of_r1 = r1.y - r1.h;
	double start_vertex_y_of_r2 = r2.y - r2.h;
	double end_vertex_y_of_r1 = r1.y;
	double end_vertex_y_of_r2 = r2.y;
	double topmost_start_vertex_y = max(start_vertex_y_of_r1, start_vertex_y_of_r2);
	double bottommost_end_vertex_y = min(end_vertex_y_of_r1, end_vertex_y_of_r2);
	
	double overlap_height_y = bottommost_end_vertex_y - topmost_start_vertex_y;
	if (overlap_height_y <= 0){
		return 0;
	}
	
	return overlap_width_x * overlap_height_y;
}

int main(){
		
	Rect R1 = {-1,2,6.9,9.6};
	Rect R2 = {0,0,1.2,2.5};
	
	cout << "The area of overlap is " << overlap(R1,R2) << endl;
}