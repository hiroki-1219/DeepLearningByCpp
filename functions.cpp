#include<iostream>
#include<vector>
#include<math.h>
#include "./header/LinearAlgebra.hpp"
#include "./header/Plot.hpp"
#include "./header/DeepLearning.hpp"
using namespace DeepLearning;

int main(void){
    LinearAlgebra::Vector x = LinearAlgebra::arange(-5.0, 5.0, 0.1);
    LinearAlgebra::Vector y_step = Functions::Activation::step_function(x);
    LinearAlgebra::Vector y_sigmoid = Functions::Activation::sigmoid(x);

    Plot::PlotGraph plot("gnuplot -persist");
    plot.plot_start();
    plot.plot(x, y_step, {-6.0, 6.0}, {-0.1, 1.1}, {"x", "y"}, "red", false);
    plot.replot(x, y_sigmoid, "blue", false);
    plot.plot_end();

    LinearAlgebra::Vector y_ReLU = Functions::Activation::ReLU(x);
    plot.plot_start();
    plot.plot(x, y_ReLU, {-6.0, 6.0}, {-1.0, 5.5}, {"x", "y"}, "red", false);
    plot.plot_end();

    LinearAlgebra::Vector a = LinearAlgebra::array({1010, 1000, 990});
    LinearAlgebra::Vector softmax_a = Functions::Activation::softmax(a);
    a.show(); softmax_a.show();

    LinearAlgebra::Vector t = LinearAlgebra::array({0, 0, 1, 0, 0, 0, 0, 0, 0, 0});
    LinearAlgebra::Vector y1 = LinearAlgebra::array({0.1, 0.05, 0.6, 0.0, 0.05, 0.1, 0.0, 0.1, 0.0, 0.0});
    LinearAlgebra::Vector y2 = LinearAlgebra::array({0.1, 0.05, 0.1, 0.0, 0.05, 0.1, 0.0, 0.6, 0.0, 0.0});
    float ans;
    ans = Functions::Loss::sum_squared_loss(y1, t);
    std::cout << ans << "\n";
    ans = Functions::Loss::sum_squared_loss(y2, t);
    std::cout << ans << "\n";

    y1.show(); y2.show();
    ans = Functions::Loss::cross_entropy_loss(y1, t);
    std::cout << ans << "\n";
    ans = Functions::Loss::cross_entropy_loss(y2, t);
    std::cout << ans << "\n";

    float diff_value = Differential::numerical_differential([](float x){return 0.01*x*x + 0.1*x;}, 5);
    std::cout << diff_value << "\n";

    LinearAlgebra::Vector diff_x = LinearAlgebra::arange(0, 20, 0.1);
    LinearAlgebra::Vector diff_y = diff_x.map([](float x)->float{return 0.01*x*x + 0.1*x;});
    LinearAlgebra::Vector diff_y_end = diff_x.map([&diff_value](float x)->float{return diff_value * (x - 5) + 0.75;});
    plot.plot_start();
    plot.plot(diff_x, diff_y, {0, 20}, {0, 6}, {"x", "y"}, "red", false);
    plot.replot(diff_x, diff_y_end, "blue", false);
    plot.plot_end();
    return 0;
}