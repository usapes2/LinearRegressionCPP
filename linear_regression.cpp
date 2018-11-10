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
       m_x_vals(m_x_vals_), m_y_vals(m_y_vals_),m_num_elems(m_y_vals_.size()),
		       m_old_err(std::numeric_limits<double>::max()) {};


	void trainAlgorithm(int num_iters_,double a_init_, double b_init_) {
		int iter = 0;
		m_a = a_init_;
		m_b = b_init_;

		while (!isConverged() && iter < num_iters_) {
			double step = 0.02;
			double a_grad = 0;
			double b_grad = 0;

			for (int i = 0; i < m_num_elems; i++) {
				a_grad += m_x_vals[i] * ((m_a * m_x_vals[i] + m_b) -
						m_y_vals[i]);
			}
			a_grad = (2 * a_grad) / m_num_elems;

			for (int i = 0; i < m_num_elems; i++) {
				b_grad += ((m_a * m_x_vals[i] + m_b) 
						- m_y_vals[i]);
			}
			b_grad = (2 * b_grad) / m_num_elems;

			// step
			m_a = m_a - (step * a_grad);
			m_b = m_b - (step * b_grad);

			cout << "a:\t" << m_a << ", b:\t" << m_b << "\r\n";
			cout << "grad_a:\t" <<a_grad <<", b_grad:\t"<<b_grad<<"\r\n";
			iter++;
		}

	}

	double regress(double x_){
		double res = m_a * x_ + m_b;
		return res;
	}

private:
	vector<double> m_x_vals;
	vector<double> m_y_vals;

	double m_num_elems;
	double m_a;
	double m_b;
	double m_old_err;
	
	bool isConverged() {
		double error = 0;
		double thresh = 0.1;
		for (int i = 0; i < m_num_elems; i++) {
			error+= pow(((m_a * m_x_vals[i] + m_b) - m_y_vals[i]),2);
		}
		error /= m_num_elems;
		cout << "Error" << error << "\r\n";
		bool res = (abs(error) > m_old_err - thresh && abs(error) < m_old_err + thresh) ? true : false;
		m_old_err = abs(error);
		return res;
	}


protected: 
};

int main(int argc, const char *argv[])
{
	vector<double> y({2.8,2.9,7.6,9,8.6});
	vector<double> x({1,2,3,4,5});
	Linear_Regression lr(x,y);
	lr.trainAlgorithm(1000,3,-10);
	cout << lr.regress(3)<<endl;

	
	return 0;
}
