#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
#include<tuple>
#include<cmath>
#include<limits>

using namespace std;
/*! \class Linear_Regression
 *  \brief Brief class description
 *
 *  Detailed description
 */
class Linear_Regression
{
public:
	Linear_Regression() {};

Linear_Regression(vector<double>& m_x_vals_, vector<double>& m_y_vals_):
       m_x_vals(m_x_vals_), m_y_vals(m_y_vals_),m_num_elems(m_y_vals_.size()) {};


	void trainAlgorithm() {
	}

	double regress(double x_){

	}
private:
	vector<double> m_x_vals;
	vector<double> m_y_vals;
	double m_num_elems;
	double m_a;
	double m_b;


protected:

};

int main(int argc, const char *argv[])
{
	vector<double> y({2.8,2.9,7.6,9,8.6});
	vector<double> x({1,2,3,4,5});
	
	return 0;
}
