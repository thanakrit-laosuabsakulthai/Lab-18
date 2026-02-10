#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *pr1 , Rect *pr2){
	double &x1 = pr1->x;
	double &y1 = pr1->y;
	double &w1 = pr1->w;
	double &h1 = pr1->h;
	double &x2 = pr2->x;
	double &y2 = pr2->y;
	double &w2 = pr2->w;
	double &h2 = pr2->h;
	
	double start_vertex_x_of_r1 = x1;
	double start_vertex_x_of_r2 = x2;
	double end_vertex_x_of_r1 = x1 + w1;
	double end_vertex_x_of_r2 = x2 + w2;
	double rightmost_start_vertex_x = max(start_vertex_x_of_r1, start_vertex_x_of_r2);
	double leftmost_end_vertex_x = min(end_vertex_x_of_r1, end_vertex_x_of_r2);
	
	double overlap_width_x = leftmost_end_vertex_x - rightmost_start_vertex_x;
	if (overlap_width_x <= 0){
		return 0;
	}
	
	double start_vertex_y_of_r1 = y1 - h1;
	double start_vertex_y_of_r2 = y2 - h2;
	double end_vertex_y_of_r1 = y1;
	double end_vertex_y_of_r2 = y2;
	double topmost_start_vertex_y = max(start_vertex_y_of_r1, start_vertex_y_of_r2);
	double bottommost_end_vertex_y = min(end_vertex_y_of_r1, end_vertex_y_of_r2);
	
	double overlap_height_y = bottommost_end_vertex_y - topmost_start_vertex_y;
	if (overlap_height_y <= 0){
		return 0;
	}
	
	return overlap_width_x * overlap_height_y;

}
