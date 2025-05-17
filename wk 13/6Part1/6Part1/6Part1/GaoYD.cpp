#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159

class Rectangle {
protected:
    double width;
    double height;
    double center_x;
    double center_y;

public:
    // 构造函数，初始化矩形的宽度、高度和中心坐标
    Rectangle(double w, double h, double cx, double cy)
        : width(w), height(h), center_x(cx), center_y(cy) {}

    // 计算矩形的面积
    double area() const {
        return width * height;
    }

    // 获取矩形的中心坐标
    double getCenterX() const {
        return center_x;
    }

    double getCenterY() const {
        return center_y;
    }
};

class SolarPanel : public Rectangle {
private:
    int panel_id;  // 光伏板编号
    double angle;  // 光伏板角度

public:
    // 构造函数，初始化光伏板的编号、宽度、高度和中心坐标，并调用基类构造函数
    SolarPanel(int id, double w, double h, double cx, double cy)
        : Rectangle(w, h, cx, cy), panel_id(id), angle(0) {}

    // 设置光伏板角度
    void setAngle(double a) {
        angle = a;
    }

    // 获取巡检点位X坐标
    double inspectionPointX() const {
        double drone_height = 20.0;  // 无人机巡检高度
        if (angle == 0) {
            return center_x;  // 光伏板角度为0时，不进行X坐标修正
        }
        return center_x + drone_height / tan((90.0 - angle) * PI / 180.0); // 计算巡检点位X坐标
    }

    // 获取巡检点位Y坐标（光伏板中心Y坐标）
    double inspectionPointY() const {
        return getCenterY();
    }

    // 计算无人机云台俯仰角度
    double gimbalAngle() const {
        if (angle == 0) {
            return -90.0;  // 光伏板角度为0时，俯仰角为-90度
        }
        return -(90.0 - angle);  // 修正的俯仰角度计算
    }

    // 估算光伏板的发电功率
    double estimatedPower() const {
        const double conversionEfficiency = 0.20;  // 转化效率20%
        double area_cm2 = area() * 10000;  // 将面积从平方米转换为平方厘米
        return area_cm2 * 0.1 * conversionEfficiency;  // 计算功率
    }

    // 获取光伏板编号
    int getId() const {
        return panel_id;
    }

    // 获取光伏板角度
    double getAngle() const {
        return angle;
    }
};

int main() {
    const int num_panels = 4;
    // 初始化光伏板数组
    SolarPanel panels[num_panels] = {
        {1, 1.65, 0.991, 5, 10},
        {2, 1.956, 0.991, 10, 10},
        {3, 2.172, 1.303, 5, 5},
        {4, 2.384, 1.303, 10, 5}
    };

    // 从键盘输入获取每个光伏板的角度
    for (int i = 0; i < num_panels; ++i) {
        double angle;
        cout << "请输入光伏板" << panels[i].getId() << "角度(0, 30, 45, 60°): ";
        cin >> angle;
        panels[i].setAngle(angle);
    }

    double totalPower = 0;
    // 计算并输出每个光伏板的巡检点位坐标、云台角度和估算发电功率
    for (int i = 0; i < num_panels; ++i) {
        double inspection_point_x = panels[i].inspectionPointX();
        double inspection_point_y = panels[i].inspectionPointY();
        double gimbal_angle = panels[i].gimbalAngle();
        double power = panels[i].estimatedPower();
        totalPower += power;

        cout << "光伏板（" << panels[i].getId() << "）：巡检点位坐标（" << inspection_point_x << "，" << inspection_point_y
            << "）；无人机云台俯仰角" << gimbal_angle << "度" << endl;
    }

    // 输出光伏电厂的总发电功率
    cout << "光伏电厂发电功率：" << totalPower << " W" << endl;

    return 0;
}
