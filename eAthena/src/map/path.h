// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef _PATH_H_
#define _PATH_H_

// calculates destination cell for knockback
int path_blownpos(int m,int x0,int y0,int dx,int dy,int count);

// tries to find a walkable path
bool path_search(struct walkpath_data *wpd,int m,int x0,int y0,int x1,int y1,int flag,cell_chk cell);

// tries to find a shootable path
bool path_search_long(struct shootpath_data *spd,int m,int x0,int y0,int x1,int y1,cell_chk cell);


// distance related functions
int check_distance(int dx, int dy, int distance);
#define check_distance_bl(bl1, bl2, distance) check_distance((bl1)->x - (bl2)->x, (bl1)->y - (bl2)->y, distance)
#define check_distance_blxy(bl, x1, y1, distance) check_distance((bl)->x-(x1), (bl)->y-(y1), distance)
#define check_distance_xy(x0, y0, x1, y1, distance) check_distance((x0)-(x1), (y0)-(y1), distance)

unsigned int distance(int dx, int dy);
#define distance_bl(bl1, bl2) distance((bl1)->x - (bl2)->x, (bl1)->y - (bl2)->y)
#define distance_blxy(bl, x1, y1) distance((bl)->x-(x1), (bl)->y-(y1))
#define distance_xy(x0, y0, x1, y1) distance((x0)-(x1), (y0)-(y1))

#endif /* _PATH_H_ */
