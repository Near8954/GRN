#include <iostream>
#include <iomanip>

int64_t index(int64_t number, int64_t d) {
    return (number / (d * 0.05));
}


int64_t grn(int64_t a, int64_t b, int64_t c, int64_t d, int64_t x0, int64_t x1, int64_t x2) {
    return (a * x2 + b * x1 + c * x0) % d;
}

int main() {
    int64_t a, b, c, d, x0, x1, x2;
    std::cin >> a >> b >> c >> d >> x0 >> x1 >> x2;
    int64_t turtle_last, turtle_prelast, turtle_prev, turtle_curr;
    int64_t achilles_last, achilles_prelast, achilles_prev, achilles_curr;
    achilles_last = x0;
    achilles_prelast = x1;
    achilles_prev = x2;

    turtle_last = x0;
    turtle_prelast = x1;
    turtle_prev = x2;

    turtle_curr = grn(a, b, c, d, turtle_last, turtle_prelast, turtle_prev);
    turtle_last = turtle_prelast;
    turtle_prelast = turtle_prev;
    turtle_prev = turtle_curr;

    achilles_curr = grn(a, b, c, d, achilles_last, achilles_prelast, achilles_prev);
    achilles_last = achilles_prelast;
    achilles_prelast = achilles_prev;
    achilles_prev = achilles_curr;

    achilles_curr = grn(a, b, c, d, achilles_last, achilles_prelast, achilles_prev);
    achilles_last = achilles_prelast;
    achilles_prelast = achilles_prev;
    achilles_prev = achilles_curr;

    while (!(achilles_last == turtle_last && achilles_prelast == turtle_prelast && achilles_prev == turtle_prev)) {
        turtle_curr = grn(a, b, c, d, turtle_last, turtle_prelast, turtle_prev);
        turtle_last = turtle_prelast;
        turtle_prelast = turtle_prev;
        turtle_prev = turtle_curr;

        achilles_curr = grn(a, b, c, d, achilles_last, achilles_prelast, achilles_prev);
        achilles_last = achilles_prelast;
        achilles_prelast = achilles_prev;
        achilles_prev = achilles_curr;

        achilles_curr = grn(a, b, c, d, achilles_last, achilles_prelast, achilles_prev);
        achilles_last = achilles_prelast;
        achilles_prelast = achilles_prev;
        achilles_prev = achilles_curr;
    }
    int64_t p = 1;
    turtle_curr = grn(a, b, c, d, turtle_last, turtle_prelast, turtle_prev);
    turtle_last = turtle_prelast;
    turtle_prelast = turtle_prev;
    turtle_prev = turtle_curr;
    while (!(achilles_last == turtle_last && achilles_prelast == turtle_prelast && achilles_prev == turtle_prev)) {
        turtle_curr = grn(a, b, c, d, turtle_last, turtle_prelast, turtle_prev);
        turtle_last = turtle_prelast;
        turtle_prelast = turtle_prev;
        turtle_prev = turtle_curr;
        ++p;
    }
    int64_t xp_last, xp_prelast, xp_prev, xp_curr;
    xp_last = x0;
    xp_prelast = x1;
    xp_prev = x2;
    xp_curr = grn(a, b, c, d, xp_last, xp_prelast, xp_prev);
    xp_last = xp_prelast;
    xp_prelast = xp_prev;
    xp_prev = xp_curr;
    for (int i = 0; i < p - 1; ++i) {
        xp_curr = grn(a, b, c, d, xp_last, xp_prelast, xp_prev);
        xp_last = xp_prelast;
        xp_prelast = xp_prev;
        xp_prev = xp_curr;
    }
    int64_t x0_last, x0_prelast, x0_prev, x0_curr;
    x0_last = x0;
    x0_prelast = x1;
    x0_prev = x2;

    int64_t n = 0;

    while (!(xp_last == x0_last && xp_prelast == x0_prelast && xp_prev == x0_prev)) {
        x0_curr = grn(a, b, c, d, x0_last, x0_prelast, x0_prev);
        x0_last = x0_prelast;
        x0_prelast = x0_prev;
        x0_prev = x0_curr;

        xp_curr = grn(a, b, c, d, xp_last, xp_prelast, xp_prev);
        xp_last = xp_prelast;
        xp_prelast = xp_prev;
        xp_prev = xp_curr;
        ++n;
    }
    double data[20];
    int64_t x;
    for (int i = 0; i < 20; ++i) {
        data[i] = 0;
    }
    ++data[index(x0, d)];
    ++data[index(x1, d)];
    ++data[index(x2, d)];
    for (int i = 0; i < 397; ++i) {
        x = grn(a, b, c, d, x0, x1, x2);
        x0 = x1;
        x1 = x2;
        x2 = x;
        ++data[index(x2, d)];
    }
    double z = 0;
    for (int i = 0; i < 20; ++i) {
        z += ((data[i] - 20.0) * (data[i] - 20.0)) / 400;
    }
    std::cout << "p = " << p << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << std::fixed << std::setprecision(3) << "z = " << z << std::endl;
    std::cout << "finished";
    return 0;
}
