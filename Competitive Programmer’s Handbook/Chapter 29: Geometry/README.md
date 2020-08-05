# Geometry

## Complex Numbers
A complex number is a number of the form `x + yi` , where `i = sqrt(− 1)` is the imaginary unit.    
```c++
typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

P p = {4, 2};
cout << p.X << " " << p.Y << "\n"; // 4 2
```
The following code calculates the distance between points `(4, 2)` and `(3, − 1)`:
```c++
P a = {4,2};
P b = {3,-1};
cout << abs(b-a) << "\n"; // 3.16228
```
The following code calculates the angle of the vector `(4, 2)`, rotates it `1/2` radians counterclockwise, and then calculates the angle again:
```c++
P v = {4,2};
cout << arg(v) << "\n"; // 0.463648
v *= polar(1.0, 0.5);
cout << arg(v) << "\n"; // 0.963648
```

## Points and Lines
The following code calculates the cross product of `a = (4, 2)`, `b = (1, 2)` using the class complex:
```c++
P a = {4, 2};
P b = {1, 2};
C p = (conj(a) * b).Y; // 6
```

### Point Location
Cross products can be used to test whether a point `p` is located on the left or right side of a line that start from `s1` and end at `s2`. The cross product `z = (p − s1) × (p − s2)` tells us the location of the point `p`: 
* if `z > 0`, `p` is located on the left side.
* if `z < 0`, `p` is located on the right side.
* if `z = 0`, `p` is located on the same line.

### Line Segment Intersection
We can use cross products to check: 
* Case 1: The line segments are on the same line and they overlap each other.
* Case 2: The line segments have a common vertex that is the only intersection point.
* Case 3: There is exactly one intersection point that is not a vertex of any line segment.

### Point Distance from a Line
`d = (s1 - p) x (s2 - p) / |s2 - s1|`

### Point Inside a Polygon
A convenient way to solve the problem is to send a ray from the point to an arbitrary direction and calculate the number of times it touches the boundary of the polygon. If the number is odd, the point is inside the polygon, and if the number is even, the point is outside the polygon.

## Polygon Area
A general formula for calculating the area of a polygon, sometimes called the **shoelace formula**, is as follows:  
`SUM(p{i} x p{i+1}) / 2`   

### Pick’s Theorem
Pick’s theorem provides another way to calculate the area of a polygon provided that all vertices of the polygon have integer coordinates. According to Pick’s
theorem, the area of the polygon is **`a + b /2 − 1`**, where a is the number of integer points inside the polygon and b is the number of integer points on the boundary of the polygon.

## Distance Functions
The distance between points `(x1, y1)` and `(x2, y2)` is: 
* **Euclidean distance**: `sqrt((x2 - x1)^2 + (y2 - y1)^2`.
* **Manhattan distance**: `|x1 - x2| + |y1 - y2|`.

### Rotating Coordinates
Consider a problem where we are given `n` points in the two-dimensional plane and our task is to calculate the maximum **Manhattan distance** between any two points. A useful technique related to Manhattan distances is to rotate all coordinates 45 degrees so that a point `(x, y)` becomes `(x + y, y − x)`. Consider two points `p1 = (x1, y1)` and `p2 = (x2, y2)` whose rotated coordinates are `p1' = ( x1', y1')` and `p2' = (x2', y2')`. Now there are two ways to express the Manhattan distance between `p1` and `p2`: **`|x1 − x2| + |y1 − y2| = max(|x1' − x2'|, |y1' − y2'|)`**.


