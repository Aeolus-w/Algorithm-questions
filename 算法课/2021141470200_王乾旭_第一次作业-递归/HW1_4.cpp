#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
using namespace std;

const double PI = acos(-1);

// 辅助函数：FFT算法（递归分治）
void FFT(vector<complex<double>>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    // 将序列分成偶数和奇数下标的两个部分
    vector<complex<double>> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; ++i) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    // 递归求解
    FFT(a0, invert);
    FFT(a1, invert);

    // 计算当前阶段的FFT
    double ang = 2 * PI / n * (invert ? -1 : 1);
    complex<double> w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

int main() {
    // 图像像素值为 [0, 1, 2, 3, 4, 5, 6, 8]
    vector<complex<double>> pixels = {0, 1, 2, 3, 4, 5, 6, 8};

    // 输出原始数据
    cout << "Raw Data:" << endl;
    for (const auto& p : pixels) {
        cout << p << " ";
    }
    cout << endl;

    // 进行FFT变换
    FFT(pixels, false);

    // 输出FFT结果
    cout << "FFT Results:" << endl;
    for (const auto& p : pixels) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
