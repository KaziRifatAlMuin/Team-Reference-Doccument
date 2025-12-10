typedef long long ll;
typedef long double ld;
#define PI acos(-1.0)
#define eps 1e-7
#define point pair <double,double>
#define x first
#define y second

point operator + (point a, point b) { return {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) { return {a.x - b.x, a.y - b.y}; }
double operator | (point a, point b) { return a.x * b.x + a.y * b.y; }
double operator * (point a, point b) { return a.x * b.y - a.y * b.x; }

point operator * (point a, double m) { return {a.x * m, a.y * m}; }
point operator / (point a, double m) { return {a.x / m, a.y / m}; }
double val(point a) { return sqrt(a | a); }
tuple <double, double, double> pointToLine(point a, point b){ 
    return {( b.y - a.y), (a.x - b.x), (a.y * (b.x - a.x) - a.x * (b.y - a.y)) };
}
pair <point, point> lineToPoint(double a, double b, double c){
    if(a == 0) return {{1, -1 * c/b}, {0, -1 * c/b}};
    else if(b == 0) return {{-1 * c/a, 1}, {-1 * c/a, 0}};
    else return {{-1 * c/a, 0}, {0, -1 * c/b}};
}

double pointLineDistance(point p, double a, double b, double c){
    return fabs(a * (p.x) + b * (p.y) + c) / (sqrt(a*a + b*b));
}
double pointLineDistance(point p, point a, point b){
    return fabs((p-a) * (b-a)) / val(b-a);
}
double pointRayDistance(point p, point a, point b){
    if(((p-a)|(b-a)) < 0) return val(p-a); 
    else return fabs((p-a) * (b-a)) / val(b-a);
}
double pointSegmentDistance(point p, point a, point b){
    if(((p-a)|(b-a)) < 0 && ((p-b)|(a-b)) > 0) return val(p-a);
    else if(((p-a)|(b-a)) > 0 && ((p-b)|(a-b)) < 0) return val(p-b);
    else return fabs((p-a) * (b-a)) / val(b-a);
}
double segmentSegmentDistance(point a, point b, point c, point d){
    bool dif1 = ((b-a)*(c-a) >= 0 && (b-a)*(d-a) <= 0) || ((b-a)*(c-a) <= 0 && (b-a)*(d-a) >= 0);
    bool dif2 = ((d-c)*(a-c) >= 0 && (d-c)*(b-c) <= 0) || ((d-c)*(a-c) <= 0 && (d-c)*(b-c) >= 0);
    if(dif1 == true && dif2 == true) return 0;
    else return min({
        pointSegmentDistance(a,c,d), pointSegmentDistance(b,c,d), 
        pointSegmentDistance(c,a,b), pointSegmentDistance(d,a,b)
    });
}
point intersection(double a1, double b1, double c1, double a2, double b2, double c2){
    double x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
    double y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
    return {x, y};
}
point intersection(point a, point b, point c, point d){
    auto [a1, b1, c1] = pointToLine(a, b);
    auto [a2, b2, c2] = pointToLine(c, d);
    return intersection(a1,b1,c1,a2,b2,c2);
}
bool isOnLine(point p, double a, double b, double c){ return fabs(a*p.x + b*p.y + c) <= eps; }
bool isOnRay(point p, point a, point b){ return fabs((p-a)*(b-a)) <= eps && ((p-a)|(b-a)) >= 0; }
bool isOnSegment(point p, point a, point b){ return fabs(val(p-a) + val(b-p) - val(b-a)) <= eps; }
bool isParallel(point a, point b, point c, point d) { return fabs((b-a)*(d-a)) <= eps; }
bool isSameSide(point p, point q, point p1, point p2){
    if(((p-p1) * (p2-p1)) * ((q-p1) * (p2-p1)) >= 0) return true;
    else return false;
}
bool isSameSide(point p, point q, double a, double b, double c){
    return (a*p.x + b*p.y + c) * (a*q.x + b*q.y + c) >= 0;
}
double rayRayDistance(point a, point b, point c, point d){
    double ans = min(pointRayDistance(a,c,d), pointRayDistance(c,a,b));
    if(isParallel(a,b,c,d)) return ans;
    else if(isOnRay(intersection(a,b,c,d), a, b) && isOnRay(intersection(a,b,c,d), c, d)) return 0;
    else return ans;
}
double area_of_triangle(point a, point b, point c){
    return fabs((a - c) * (b - c)) / 2.0;
}
double area_of_polygon(vector<point> &p){
    double area = 0.0;
    int n = p.size();
    for(int i = 0; i < n; i++){
        area += (p[i] * p[(i+1)%n]) / 2.0; // anticlockwise = +ve area, clockwise = -ve area
    }
    return fabs(area);
}
// Angle Bisector 
point p = ((y - x) * val(z - x)) / val(y-x); // vector towards (y-x) with length |z-x|
p = p + (z - x); // resultant vector
p = p + x; // translating start point at x from (0,0)
auto [a, b, c] = pointToLine(x, p);


// Formula for Basic Geometry Operations
circumradius = (a * b * c) / (4 * area); //pori
inradius = area / s; //onto
isosceles_side = (b / 4) * sqrt(4 * a * a - b * b); // a same
equilateral_area = (sqrt(3) / 4) * a * a;
regular_polygon_area = (n * a * a / 4) * (1 / tan(M_PI / n));
point_line_distance = abs(a*x + b*y + c) / sqrt(a*a + b*b);
two_point_distance = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
area_triangle_sine = 0.5 * a * b * sin(C);
line_intercept = y1 - (perpendicular_slope * x1);
perpendicular_slope = -1 / line_slope;
sine_rule = a / sin(A) == b / sin(B) == c / sin(C) == 2 * circumradius;
cosine_rule = c * c = a * a + b * b - 2 * a * b * cos(C);
herons_area = sqrt(s * (s - a) * (s - b) * (s - c)); // s = (a+b+c)/2
centroid = ( (x1 + x2 + x3) / 3 , (y1 + y2 + y3) / 3 )
orthocenter = (tanA*x1 + tanB*x2 + tanC*x3) / (tanA + tanB + tanC) , (tanA*y1 + tanB*y2 + tanC*y3) / (tanA + tanB + tanC) )  
incenter = ( (a*x1 + b*x2 + c*x3) / (a + b + c) , (a*y1 + b*y2 + c*y3) / (a + b + c) )
circumcenter = intersection of perpendicular bisectors of any two sides
median = ( (x1 + x2) / 2 , (y1 + y2) / 2 )
