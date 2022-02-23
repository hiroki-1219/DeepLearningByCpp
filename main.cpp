#include<iostream>
#include<vector>
#include "./header/LinearAlgebra.hpp"
#include "./header/Plot.hpp"

int main(void){
    LinearAlgebra::Vector a({1, 3, 5, 7, 9});
    LinearAlgebra::Vector b({2, 4, 6, 8, 10});
    LinearAlgebra::Vector add;
    float c;
    a.show(); b.show();
    add = a + b;
    c = a.dot(b);
    a.show();
    add.show();
    std::cout << c << "\n";

    LinearAlgebra::Matrix f({{1, 2, 3}, {4, 5, 6}});
    LinearAlgebra::Matrix g({{2, 3}, {5, 6}, {7, 8}});
    LinearAlgebra::Matrix l;
    f.show(); g.show();
    l = f.dot(g);
    l.show();

    LinearAlgebra::Matrix rand1({10, 10}, 0, 10);
    LinearAlgebra::Matrix rand2({10, 10}, 0, 10);
    LinearAlgebra::Matrix dot;
    rand1.show(); rand2.show();
    dot = rand1.dot(rand2);
    dot.show();

    LinearAlgebra::Matrix rand3({10, 1}, 0, 10);
    rand3.show();


    LinearAlgebra::Vector test1(10, 0, 10);
    LinearAlgebra::Matrix M_test1_1, M_test1_2;
    M_test1_1 = test1.vec_to_matrix(0);
    M_test1_2 = test1.vec_to_matrix(1);
    test1.show();
    M_test1_1.show(); M_test1_2.show();

    LinearAlgebra::Vector test2(10, 0, 10);
    LinearAlgebra::Vector test2_2;
    test2.show();
    test2_2 = test2 * 10;
    test2_2.show();

    test2_2 = test2 / 10;
    test2_2.show();

    test2_2 = 10 / test2;
    test2_2.show();

    LinearAlgebra::Matrix test3({10, 10}, 0, 10);
    LinearAlgebra::Matrix test3_2;
    test3.show();
    test3_2 = test3 * 10; test3_2.show();
    test3_2 = 10 * test3; test3_2.show();
    test3_2 = test3 / 10; test3_2.show();
    test3_2 = 10 / test3; test3_2.show();

    LinearAlgebra::Vector test4;
    test4 = LinearAlgebra::arange(0, 10, 0.1);
    test4.show();

    LinearAlgebra::Vector plot_x({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    LinearAlgebra::Vector plot_y({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    LinearAlgebra::Vector plot_y2({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    LinearAlgebra::Vector plot_y3({1, 5, 2, 4, 5, 6, 1, 3, 5, 6});
    Plot::PlotGraph plot("gnuplot -persist");
    plot.plot_start();
    plot.plot(plot_x, plot_y, {0, 11}, {0, 11}, {"x", "y"});
    plot.replot(plot_x, plot_y2, "blue");
    plot.replot(plot_x, plot_y3, "green");
    plot.plot_end();
    return 0;
}