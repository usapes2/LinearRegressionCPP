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

	KMeans(int k_, vector<pair<double,double>> & data_): m_k(k_), m_means(k_), m_data(k_) {
		m_data[0] = data_;
	};

	void clusterData(valarray<pair<double,double>>& init_means_, int num_iters_){
		m_means = init_means_;
		this->assignLabels();

		int i = 0;
		while (i < num_iters_ && !this->computeMeans()) {
			cout << "Running iteration: " << i << "\r\n";
			this->assignLabels();
			i++;
		}

	}

	void printClusters() const {
		for (int k = 0; k < m_k; k++) {
			for(const auto & it : m_data[k]){
				cout << " [" << get<0>(it) <<" , " << get<1>(it) << "]";
			}
			cout << "\n";
		}

	}

private:
	bool computeMeans(){
		bool res = true;
		for(int i = 0; i < m_k ; i++ ) {
			pair<double,double> mean(0,0);
			int num_features_of_k = m_data[i].size();
			for(auto const & it: m_data[i]) {
				get<0>(mean) += get<0>(it);
				get<1>(mean) += get<1>(it);
			}
			get<0>(mean) /= num_features_of_k;
			get<1>(mean) /= num_features_of_k;
			res = (m_means[i] == mean && res == true) ? true : false;
			m_means[i] = mean;
			cout << " Cluster Centroid << " << i << ":\tx" << get<0>(mean) << " , y " << get<1>(mean) << "\t";

		}
		cout <<"\r\n";
		return res;
	}
	void assignLabels() {
		valarray<vector<pair<double,double>>> new_data(m_k);
		for( auto const & clust : m_data) {
			for(auto const & feature : clust) {
				int closest_mean = this->computeClosestCentroid(feature);
				new_data[closest_mean].push_back(feature);
			}
		}
		m_data = new_data;
	}

	int computeClosestCentroid( const pair<double,double> & point_){
		valarray<double> distances(m_k);
		for(int k = 0; k < m_k; k++ ) {
			double del_x = get<0>(point_) - get<0>(m_means[k]);
			double del_y = get<1>(point_) - get<1>(m_means[k]);
			double dist = sqrt((del_x * del_x) + (del_y * del_y));
			distances[k] = dist;
		}
		auto closest_mean = distance(begin(distances),min_element(begin(distances),end(distances)));
		return closest_mean;
		
	}


	// Private data members
	int m_k;
	int m_features;
	valarray<pair<double,double>> m_means;
	valarray<vector<pair<double,double>>> m_data;
	

};
int main(int argc, const char *argv[])
{
	vector<pair<double,double>> data = {
		{1.1,1}, {1.4,2}, {3.8,7}, {5.0,8}, {4.3,6},
		{8,5.0},{6,8.5},{3,2.0},{9,6},{9.1,4}
	};
	KMeans km(3,data);
	valarray<pair<double,double>> init_means_ = {
		{1,1},{3,4},{8,8}
	};

	km.clusterData(init_means_,20);
	km.printClusters();

	
	return 0;
}
