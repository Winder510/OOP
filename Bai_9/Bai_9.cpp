#include <iostream>
#include <cmath>

class cDiem {
private:
    float x, y;

public:
    cDiem() : x(0), y(0) {}
    cDiem(float _x, float _y) : x(_x), y(_y) {}

    float getX() const { return x; }
    float getY() const { return y; }
    void setX(float _x) { x = _x; }
    void setY(float _y) { y = _y; }

    float tinhKhoangCach(const cDiem& d) const {
        float dx = x - d.x;
        float dy = y - d.y;
        return sqrt(dx * dx + dy * dy);
    }

    void diChuyen(float dx, float dy) {
        x += dx;
        y += dy;
    }

    void veDiem() const {
        std::cout << "(" << x << ", " << y << ")";
    }
    friend class cTamGiac;
};

class cTamGiac {
private:
    cDiem A, B, C;

public:
    cTamGiac() : A(),B(), C(){}
    cTamGiac(const cDiem& _A, const cDiem& _B, const cDiem& _C) : A(_A), B(_B), C(_C) {}

    float tinhChuVi() const {
        float AB = A.tinhKhoangCach(B);
        float BC = B.tinhKhoangCach(C);
        float AC = A.tinhKhoangCach(C);
        return AB + BC + AC;
    }

    float tinhDienTich() const {
        float AB = A.tinhKhoangCach(B);
        float BC = B.tinhKhoangCach(C);
        float AC = A.tinhKhoangCach(C);
        float p = tinhChuVi() / 2;
        return sqrt(p * (p - AB) * (p - BC) * (p - AC));
    }

    cDiem timTrongTam() const {
        float x = (A.getX() + B.getX() + C.getX()) / 3;
        float y = (A.getY() + B.getY() + C.getY()) / 3;
        return cDiem(x, y);
    }

    void nhap() {
        int x;
        std::cout << "Nhap toa do diem A:\n";
        std::cout << "x = ";  std::cin >> x; A.setX(x);
        std::cout << "y = "; std::cin >> x; A.setY(x);

        std::cout << "Nhap toa do diem B:\n";
        std::cout << "x = "; std::cin >> x; B.setX(x);
        std::cout << "y = "; std::cin >> x; B.setY(x);

        std::cout << "Nhap toa do diem C:\n";
        std::cout << "x = "; std::cin >> x; C.setX(x);
        std::cout << "y = "; std::cin >> x; C.setY(x);
    }

    void xuat() const {
        std::cout << "Tam giac co dinh tai diem A"; A.veDiem();
        std::cout << ", diem B"; B.veDiem();
        std::cout << ", diem C"; C.veDiem();
        std::cout << ".\n";
    }
};

int main() {


    cDiem A, B(2, 2), C(3, 3);
    cTamGiac tg1(A, B, C);
    std::cout << "Chu vi tam giac: " << tg1.tinhChuVi() << std::endl;
    std::cout << "Dien tich tam giac: " << tg1.tinhChuVi() << std::endl;
    cTamGiac tg;
    tg.xuat();




}

