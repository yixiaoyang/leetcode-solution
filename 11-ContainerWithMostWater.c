#include <stdio.h>
#include <stdlib.h>
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines
are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.
Note: You may not slant the container.
*/

// q11:Container With Most Water
int maxArea(int* heights, int heightSize) {
	int left = 0;
	int right = heightSize-1;
	int min_edge = heights[left]>heights[right] ? heights[right]: heights[left];
	int max_area = (right-left)*min_edge;
	int tmp = 0;

	while(left < right){
		if(heights[left] > heights[right]){
			while((left < right) && (heights[right] <= min_edge))
				right--;
		}else{
			while((left < right) && (heights[left] <= min_edge))
				left++;
		}

		// calculate area
		min_edge = heights[left]>heights[right] ? heights[right]: heights[left];
		tmp = (right-left)*min_edge;
		max_area = max_area >= tmp ? max_area : tmp;
	}

	return max_area;
}

int main()
{
	int heights[] = {4,5,2,5,9,8,6,1,3,4,8,3,5};
	int heightSize = sizeof(heights)/sizeof(heights[0]);
	printf("%d\n", maxArea(heights,heightSize));

	return 0;
}