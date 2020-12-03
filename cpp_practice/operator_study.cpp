/*
* CopyRight (C) 2020 by LiWenqiang. All rights reserved.
* Li Wenqiang <liwq93@163.com>
*/

#include <vector>
#include <iostream>
#include <string>
#include <cmath>

struct PointXYZ {
    double x;
    double y;
    double z;
    PointXYZ() = default;
    PointXYZ(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}
    PointXYZ operator-(const PointXYZ& p) {
        return PointXYZ(x - p.x, y - p.y, z - p.y);
    }
    void operator/=(double d) {
        x /= d;
        y /= d;
        z /= d;
    }
    inline void Normalized() {
        double norm = Norm();
        if (norm < 0.000000001) {
            std::cout << "[ERROR] point normilize, division by zero\n";
            return;
        }
        *this /= norm;
    }
    double Norm() const { return sqrt(x * x + y * y + z * z); }
};

int main(int argc, char** argv) {
    PointXYZ p1(2, 3, 4);
    PointXYZ p2(4, 5, 6);
    printf("p1 norm %.2f \n", p1.Norm());
    p1.Normalized();
    printf("p1 normalized, x %.2f y %.2f z %.2f\n", p1.x, p1.y, p1.z);
    printf("p1 normalized, norm %.2f\n", p1.Norm());
    PointXYZ p3(0, 0, 0);
    p3.Normalized();

    return 0;
}
