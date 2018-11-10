#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<valarray>
using namespace std;

/*! \class KMeans
 *  \brief Brief class description
 *
 *  Detailed description
 */
class KMeans
{
public:
	KMeans(){};
        ~KMeans(){};
	void clusterData(valarray<pair<double,double>>& init_means_, int num_iters_){
		m_means = init_means_;
		this->assignLabels();

		int i = 0;
		while (i < num_iters_) {
			cout << "Running iteration: " << i << "\r\n";
			this->computeMeans();
			this->assignLabels();
			i++;
		}

	}

	void printClusters() const {

	}

private:
	bool computeMeans() {
		bool res = true;
		for (int i = 0; i < m_k; i++) {
			pair<double,double> mean(0,0);
			int num_features_of_k = m_data[k].size();
			for (auto const & it : m_data[k]) {
				get<0>(mean) += get<0>(it);
				get<1>(mean) += get<1>(it);
			}
			get<0>(mean) /= num_features_of_k;
			get<1>(mean) /= num_features_of_k;
			// check for conv
			res = (m_means[k] == means && res == true) ? true: false;
			m_means[k] = mean;
			cout << "Cluster centroid << "<<k <<":\tx"<<get<0>(mean)<<
				","<< get<1>(mean)<<"\t";
		} 
		cout << "\r\n";
		return res;

	}

	void assignLabels() {

	}
	
	int computeClosestCentroid() {

	}
	// data members
	int m_k;
	int m_features;
	valarray<pair<double,double>> m_means;
	valarray< vector<pair<double,double> > > m_data;

};
int main(int argc, const char *argv[])
{
	
	return 0;
}
