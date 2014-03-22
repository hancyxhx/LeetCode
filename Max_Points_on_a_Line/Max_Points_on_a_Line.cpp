// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.



/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b){
	a = abs(a), b = abs(b);
	return b?gcd(b, a%b):a;
    }

    int maxPoints(vector<Point> &points) {
	int result=0;
	for (int i = 0; i < points.size(); i++){
	    unordered_map<string, int> count;
	    int same=1, mx=0;
	    for (int j = i+1; j < points.size(); j++){
		int x = points[j].x - points[i].x;
		int y = points[j].y - points[i].y;
		int a = gcd(x,y);
		if (a == 0){same++;continue;}

		if (x == 0)
		    y = abs(y)/a;
		else{
		    a = a*(x>0?1:-1);
		    x /= a, y /= a;
		}
		mx = max(mx, ++count[to_string(x) + " " + to_string(y)]);

	    }
	    result = max(result, mx+same);
	}
	return result;
    }

};

